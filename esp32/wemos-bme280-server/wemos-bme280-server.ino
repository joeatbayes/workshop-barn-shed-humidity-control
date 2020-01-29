
/*  Demonstrates reading a BME280 sensor and making data data available as
    a server on a local network.    Tested on a wemos mini module.  */
#include "ESP8266WiFi.h"
#include "humidity.h"
#include <BME280I2C.h> //https://github.com/finitespace/BME280
  // https://github.com/finitespace/BME280/blob/master/examples/BME_280_I2C_Test/BME_280_I2C_Test.ino
#include <Wire.h>  
IPAddress    apIP(42, 42, 42, 42);  // Defining a static IP address: local & gateway

const char* service_host = "192.168.1.101"; // I set this statically in the host where the server is running
const uint16_t service_port = 8091; // Change this for your listener

#undef BeAServer 1
#define BeAClient 1

#ifdef BeAClient
   //#include <WiFiClient.h>
   //ESP8266WiFiMulti WiFiClient;
#endif

/*
BME280I2C::Settings settings(
   BME280::OSR_X1,
   BME280::OSR_X1,
   BME280::OSR_X1,
   BME280::Mode_Forced,
   BME280::StandbyTime_6000ms,
   BME280::Filter_8,
   BME280::SpiEnable_False,
   BME280I2C::I2CAddr_0x76 // I2C address. I2C specific.
);
*/

// https://github.com/finitespace/BME280/tree/master/examples/BME280_Modes
// https://github.com/finitespace/BME280/blob/master/src/BME280.h
BME280I2C::Settings settings(
   BME280::OSR_X1,
   BME280::OSR_X1,
   BME280::OSR_X1,
   BME280::Mode_Forced,
   BME280::StandbyTime_1000ms,
   BME280::Filter_16,
   BME280::SpiEnable_False// I2C address. I2C specific.
);

BME280I2C bme(settings);    // Default : forced mode, standby time = 6000 ms
                            // Oversampling = pressure ×1, temperature ×1, humidity ×1, filter off,

#ifdef BeAServer
  #include <ESP8266WebServer.h>
  ESP8266WebServer server(80);
  WiFiServer server2(81);
#endif 

const char *ssid = "datalog";  // NOTE: Change to match your local Router
const char *password = "datalog123"; // NOTE: Change to match your local Router

float startAlt = -1.0;


//float tempC(NAN), relHumid(NAN), pressurePA(NAN);
//float dewC;
//float absHumid;
//float tempF;
//float dewF;
//float altMeter;
//float altFoot;
//int sec, minute, hr;
unsigned long currentTime = millis();
unsigned long previousTime = 0; 
const long timeoutTime = 25000;
char html[1000];

struct EnvReadings {
  float tempC; 
  float tempF;
  float relHumid;
  float absHumid;
  float dewC;
  float dewF;
  float pressurePA;
  float inHg;
  float altMeter;
  float altFoot;
  unsigned long mill;
  int sec, minute, hr;  
} envRead1, envRead2;


/*!
 *   Calculates the altitude (in meters) from the specified atmospheric
 *   pressure (in Pa), and sea-level pressure (in Pa).
 *   @param  seaLevel      Sea-level pressure in hPa
 *   @returns the altitude value read from the device
 */
const float seaStandardPressurePA =  101325; // sea level pressure in pascal.  Note: should be set based on current weather conditions
float calcAltitude(float atmospheric, float seaLevel) {
  return (double) 44330.0 * (1.0 - pow((double)atmospheric / (double) seaLevel, (double) 0.190263));
}



void calcFromLastBMERead(EnvReadings &read) {
  read.dewC = calcDewPoint(read.tempC, read.relHumid);
  read.absHumid = gramsPerM3(read.tempC, read.relHumid);
  read.tempF = CToF(read.tempC);
  read.dewF  = CToF(read.dewC);
  read.altMeter =  calcAltitude(read.pressurePA, seaStandardPressurePA);
  read.altFoot =  read.altMeter * 3.28084;  
  read.inHg = read.pressurePA * 0.0002953;
}

void readBME(BME280I2C &sens, EnvReadings &read) {
  sens.read(read.pressurePA, read.tempC, read.relHumid);  
  sens.read(read.pressurePA, read.tempC, read.relHumid);  // discard first read clears up some noise
  read.relHumid = read.relHumid / 100.0;  
  read.mill = millis();
  read.sec = read.mill / 1000;
  read.minute = read.sec / 60;
  read.hr = read.minute / 60;  
  calcFromLastBMERead(read);
}


void makeRawDataStr(EnvReadings &read) {
  snprintf ( html, 2500,
"Uptime=%02d:%02d:%02d,tempC=%3.1f,tempF=%3.1f,relHumid=%3.1f,dewC=%3.1f,dewF=%3.1f,absHumid=%3.2f,pascal=%3.1f,inHg=%3.2f,AltMeter=%3.1f,altFoot=%3.1f",
    read.hr, read.minute, read.sec,
    read.tempC, read.tempF, read.relHumid*100,  read.dewC, read.dewF, read.absHumid, read.pressurePA, read.inHg, read.altMeter, read.altFoot
  );
}

void printHumid(EnvReadings &read) {
  printHeapUsage();  
  Serial.printf("RH=%3.3f tempC=%3.1f F=%3.1f gramM3=%3.4f dewC=%3.1f dewF=%3.1f presPA=%3.1f Alt=%6.1f AltFoot=%6.1f\n", read.relHumid, read.tempC, read.tempF, read.absHumid, read.dewC, read.dewF, read.pressurePA, read.altMeter, read.altFoot); 
  // Wait a bit before scanning again
}


#ifdef BeAServer
void handleRaw() {
  digitalWrite (D4, 0); //turn the built in LED on pin DO of NodeMCU on
  /* Dynamically generate the LED toggle link, based on its current state (on or off)*/
  readBME(bme,envRead1);  
  makeRawDataStr(envRead1);
  server.send ( 200, "text/html", html );
  digitalWrite ( LED_BUILTIN, 1 );
  //printHumid();
}
#endif

#ifdef BeAServer
void handleRoot() {
  digitalWrite (D4, 0); //turn the built in LED on pin DO of NodeMCU on
  /* Dynamically generate the LED toggle link, based on its current state (on or off)*/
  readBME(bme, envRead1);
  snprintf ( html, 2500,
"<html>\
  <head>\
    <meta http-equiv='refresh' content='10'/>\
    <title>ESP8266 Humidity & Temp Sensor</title>\
    <style>\
      body { background-color: #cccccc; font-family: Arial, Helvetica, Sans-Serif; font-size: 12pt; Color: #000000; line-height:80%%; }\
      h1 { Color: #AA0000; }\
      pp { margin: 0px; }\
    </style>\
  </head>\
  <body>\
    <h1>ESP8266 Temperature Humidity & Sensor</h1>\
    <p>Uptime: %02d:%02d:%02d</p>\
    <p>tempC=<b>%3.1f</b>  tempF=<b>%3.1f</b></p>\
    <p>relHumid=%3.1f%%</p>\
    <p>dewC=<b>%3.1f</b>  dewF=<b>%3.1f</b></p>\
    <p>gramsCubicMeter=%3.2f</p>\
    <p>barometer=%3.1fP  %3.2f inHg</p>\
    <p>AltMeter=%3.1f foot=%3.1f</p>\    
  </body>\
</html>",
    envRead1.hr, envRead1.minute, envRead1.sec,
    envRead1.tempC, envRead1.tempF, envRead1.relHumid*100,
    envRead1.dewC, envRead1.dewF, envRead1.absHumid, envRead1.pressurePA, 
    envRead1.inHg, envRead1.altMeter, envRead1.altFoot
  );
  server.send ( 200, "text/html", html );
  digitalWrite ( D4, 1 );
  //printHumid();
}
#endif


void disableWiFi() {
  WiFi.disconnect(true); delay(1); // disable WIFI altogether
  WiFi.mode(WIFI_OFF); delay(1);
  WiFi.forceSleepBegin(); delay(1);
}

bool enableWiFiSta() {   
  if (WiFi.status() != WL_CONNECTED) {
    int numTry = 0;
    WiFi.forceSleepWake(); delay(1);
    WiFi.mode(WIFI_STA); delay(1);
    Serial.println("start wifi_station_connect");
    wifi_station_connect(); delay(1);      
    Serial.printf("Starting Connection to WiFi Router ssid=%s  pass=%s", ssid, password);
    WiFi.begin(ssid, password);
    // Wait for connection
    while ((WiFi.status() != WL_CONNECTED) && (numTry < 50)) {
      delay(450);
      Serial.printf(" numTry=%d", numTry);
    }
    Serial.println("finished wifi status check");
    if (WiFi.status() == WL_CONNECTED) {
      Serial.println("");
      Serial.print("Connected to ");
      Serial.print(ssid);
      Serial.print("  IP address: ");
      Serial.println(WiFi.localIP());  
      return true;
    } else {
      Serial.printf("Unabled to connect to ssid=%s pass=%s\n", ssid, password);
      return false;
    }
  } else {
    Serial.println("Already Connected to access point");
  }
}



void setup() {
  Serial.begin(115200);
  Serial.println("Starting Config Setup");
  disableWiFi();
  delay(5000); // place here to make it easier to catch and program
  Wire.begin();
  
  
  #ifndef BeAServer
    disableWiFi();
  #endif

 
  while(!bme.begin())
  {
    Serial.println("Could not find BME280 sensor!");
    delay(1000);
  }
  Serial.println("BME280 init complete\n");
  bme.setSettings(settings);
  BME280::TempUnit tempUnit(BME280::TempUnit_Celsius);
  BME280::PresUnit presUnit(BME280::PresUnit_Pa);


  // Listens as it's own access point to allow retrieval of
  // data from remote clients.
  
   
  #ifdef BeAServer
    // Soft Access Point Mode
    // WiFi.mode(WIFI_AP_STA);
    // -- WiFi.softAPConfig(apIP, apIP, IPAddress(255, 255, 255, 0));   // subnet FF FF FF 00  
    // -- IPAddress myIP = WiFi.softAPIP();
    // -- Serial.print("AP IP address: ");
    // -- Serial.println(myIP);
  

    // -- Join an existing Network
    enableWiFiSta();
      
    // Setup Basic HTTP Server Server 
    server.on ( "/", handleRoot );
    server.on ( "/raw", handleRaw );
    server.begin();
    Serial.println("HTTP server started");
  
    // Start our second server
    server2.begin();
  #endif
  

  
  Serial.println("Setup done");
  
  
}


#ifdef BeAClient
  // Send updates to a remote server
  // disable the WiFi except when we are
  // sending updates.
  bool SendUpdate() {
    WiFi.forceSleepWake(); delay(1);
    if (enableWiFiSta() == false) {
      Serial.println("Unabled to connect to router");
      return false;
    }
    Serial.print("connecting to ");
    Serial.print(service_host);
    Serial.print(':');
    Serial.println(service_port);

    // Use WiFiClient class to create TCP connections
    WiFiClient client;
    if (!client.connect(service_host, service_port)) {
      Serial.println("connection failed");
      delay(5000);
      return false;
    }
    readBME(bme, envRead1);
    makeRawDataStr(envRead1);

    // This will send a string to the server
    Serial.println("sending data to server");
    if (client.connected()) {
      Serial.println("connected]");
      Serial.println("[Sending a request]");
      client.print("POST /sensorReading");      
      client.println(" HTTP/1.1");
      client.print("Host: ");
      client.println(service_host);
      client.print("Content-Length: ");
      client.println(strlen(html));
      client.println(); // ends the headers
      client.println(html);
      
      //Serial.println("[Response:]");
      //while (client.connected() || client.available())
      //{
      //  if (client.available())
      //  {
      //    String line = client.readStringUntil('\n');
      //    Serial.println(line);
      //  }
      //}
      client.stop();
      Serial.println("\n[Disconnected]");
      return true;
    }  else  {
      Serial.println("connection failed!]");
      client.stop();      
      return false;
    }
    delay(5);

    #ifndef BeAServer
      WiFi.disconnect();
      disableWiFi();
    #endif
  }

#endif

#ifdef BeAServer
  // For basic RAW client when they connect to port send 
  // a formatted temperature & data string once every 2 seconds.
  void checkRawConnect() {
    WiFiClient client = server2.available();
    if (client) {                             // If a new client connects,
      Serial.println("New Client.");          // print a message out in the serial port
      String currentLine = "";                // make a String to hold incoming data from the client
      currentTime = millis();
      previousTime = currentTime;
      while (client.connected() && currentTime - previousTime <= timeoutTime) { // loop while the client's connected
        currentTime = millis();         
        while (client.available()) {             // if there's bytes to read from the client,
          char c = client.read();             // read a byte, then
          Serial.write(c);                    // print it out the serial monitor
        }
        readBME(bme, envRead1);
        makeRawDataStr(envRead1);      
        client.println(html);
        delay(5000);
      }
      client.stop();
      Serial.println("Client disconnected.");
      Serial.println("");
      
    }
  }
#endif



unsigned long lastUpdate = 0;
const unsigned long sendUpdateEvery=6000;
void loop() {  
  #ifdef BeAServer
    server.handleClient();
    checkRawConnect();
  #endif

  #ifdef BeAClient
     // TODO: Record updates to flash until you get 1/2 hour worth
     // and then post all of them at once then delete the file.
    long timeSinceLast =  millis() - lastUpdate;
    if (timeSinceLast > sendUpdateEvery) {
      SendUpdate();
      lastUpdate = millis();
    }
  #endif
}


void printHeapUsage() {
  uint32_t free;
  uint16_t max;
  uint8_t frag;
  ESP.getHeapStats(&free, &max, &frag);

  Serial.printf("free: %5d - max: %5d - frag: %3d%% <- \n", free, max, frag);
  // %s requires a malloc that could fail, using println instead:
}
