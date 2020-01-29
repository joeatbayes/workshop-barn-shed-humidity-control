
/*  Demonstrates reading a BME280 sensor and making data data available as
    a server on a local network.    Tested on a wemos mini module. 
    For Webmos Mini-D Use the LOLIN(WEMOIS) D1 R2 & mini board 
    
    For ESP32 ESP32S CP2102 developement board use board DOIT ESP31 DevKit V1
    Also tested with ESP32 Dev Module */
#define esp32
#ifdef webmosd    
  #include "ESP8266WiFi.h"
#endif
#ifdef esp32
  #include <WiFi.h>
#endif
#include "humidity.h"
#include <BME280I2C.h> //https://github.com/finitespace/BME280
  // https://github.com/finitespace/BME280/blob/master/examples/BME_280_I2C_Test/BME_280_I2C_Test.ino
#include <Wire.h>  
IPAddress    apIP(42, 42, 42, 42);  // Defining a static IP address: local & gateway

const char* service_host = "192.168.1.111"; // I set this statically in the host where the server is running
const uint16_t service_port = 8091; // Change this for your listener


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
   BME280::SpiEnable_False
);

BME280I2C::Settings settings2(
   BME280::OSR_X1,
   BME280::OSR_X1,
   BME280::OSR_X1,
   BME280::Mode_Forced,
   BME280::StandbyTime_1000ms,
   BME280::Filter_8,
   BME280::SpiEnable_False, 
   0x77
);

BME280I2C bme(settings);    // Default : forced mode, standby time = 6000 ms
                            // Oversampling = pressure ×1, temperature ×1, humidity ×1, filter off,

BME280I2C bme2(settings2);

const char *ssid = "datalog";  // NOTE: Change to match your local Router
const char *password = "datalog123"; // NOTE: Change to match your local Router
float startAlt = -1.0;
unsigned long currentTime = millis();
unsigned long previousTime = 0; 
const long timeoutTime = 25000;
char dstr1[500], dstr2[500], dstr3[1000], httpBuff[1000];

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
} envRead1, envRead2;


void printHeapUsage() {
  uint32_t free;
  uint16_t max;
  uint8_t frag;
  ESP.getHeapStats(&free, &max, &frag);

  Serial.printf("free: %5d - max: %5d - frag: %3d%% <- \n", free, max, frag);
  // %s requires a malloc that could fail, using println instead:
}

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
  calcFromLastBMERead(read);
}


void makeRawDataStr(EnvReadings &read, char *target) {
  snprintf ( target, 500,
"Uptime=%02.2f,tempC=%3.1f,tempF=%3.1f,relHumid=%3.1f,dewC=%3.1f,dewF=%3.1f,absHumid=%3.2f,pascal=%3.1f,inHg=%3.2f,AltMeter=%3.1f,altFoot=%3.1f",
    float(read.mill / 1000.0),
    read.tempC, read.tempF, read.relHumid*100,  read.dewC, read.dewF, read.absHumid, read.pressurePA, read.inHg, read.altMeter, read.altFoot
  );
}

void printHumid(EnvReadings &read) {
  printHeapUsage();  
  Serial.printf("RH=%3.3f tempC=%3.1f F=%3.1f gramM3=%3.4f dewC=%3.1f dewF=%3.1f presPA=%3.1f Alt=%6.1f AltFoot=%6.1f\n", read.relHumid, read.tempC, read.tempF, read.absHumid, read.dewC, read.dewF, read.pressurePA, read.altMeter, read.altFoot); 
  // Wait a bit before scanning again
}

void disableWiFi() {
  WiFi.disconnect(true); delay(1); // disable WIFI altogether
  WiFi.mode(WIFI_OFF); delay(1);
  WiFi.forceSleepBegin(); delay(1);
}

bool enableWiFiSta() {   
  WiFi.persistent( false );
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
      delay(1450);
      Serial.printf(" numTry=%d", numTry);
      numTry++;
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


// Send updates to a remote server
// disable the WiFi except when we are
// sending updates.
// Makes request against remote http server.    
// if postStr is not NULL it will be sent 
// reads the server response which is returned
// try this approach instead: https://robojax.com/learn/arduino/?vid=robojax_ESP32_HTTP_client
bool httpRequest(const char *verb, const char *server, int port, const char *url, char *postStr, char *respStr, int maxRespLen,  char *headers) {
    //Serial.printf("HTTP #s %s:%d%s\n", verb, service_host, port, url);
    // Use WiFiClient class to create TCP connections
    WiFiClient client;
    if (!client.connect(server, port)) {
      Serial.println("connection failed");
      delay(100);
      return false;
    }
    // This will send a string to the server
    Serial.println("sending data to server");
    if (client.connected()) {
      Serial.println("connected]");
      client.print(verb);
      client.print(" ");
      client.print(url);      
      client.println(" HTTP/1.1");
      client.print("Host: "); 
      client.println(port);
      if (postStr != NULL) {
        client.print("Content-Length: ");
        client.println(strlen(postStr));
      }
      client.println(); // ends the headers
      if (postStr != NULL) {
        client.println(postStr);
      }
      Serial.println("sent postStr");
      
      //Serial.println("[Response:]");
      // This seems to block forever so need a different approach
      //client.setTimeout(1000);
      //while (client.connected() || client.available())
      //{
      //  if (client.available())
      //  {
      //    unsigned long startRead = millis();
      //    String line = client.readStringUntil('\n');
      ///    Serial.println(line);
      ///    if (millis() - startRead > 600) {
      //      break;
      //    }
      //  }
      //}
      
      client.stop();
      Serial.println("Disconnected");
      return true;
    }  else  {
      Serial.println("connection failed!");
      client.stop();      
      return false;
    }
    delay(1);

      //WiFi.disconnect();
      //disableWiFi();
}


// Send updates to a remote server
// disable the WiFi except when we are
// sending updates.
bool SendUpdate() {
    readBME(bme, envRead1);
    makeRawDataStr(envRead1, dstr1);
    
    readBME(bme2, envRead2);
    makeRawDataStr(envRead2, dstr2);
    snprintf ( dstr3, 1000, "sens1=%s\nsens2=%s", dstr1, dstr2);

    int respCode = httpRequest("POST", service_host, service_port, "/sensorReading", dstr3, NULL, -1, NULL);
    Serial.println("finished send update");
}


void setup() {
  Serial.begin(115200);
  Serial.println("Starting Config Setup");
  //disableWiFi();
  delay(5000); // place here to make it easier to catch and program
  Wire.begin(); delay(10);
  enableWiFiSta(); delay(10);
  
  int bmeTryCnt = 0;
  while((!bme.begin()) && (bmeTryCnt < 15))
  {
    Serial.println("Could not find BME280 sensor #0x76");
    delay(100);
    bmeTryCnt++;
  }
  Serial.println("BME280 init 0x76 complete\n");
  bme.setSettings(settings);
  BME280::TempUnit tempUnit(BME280::TempUnit_Celsius);
  BME280::PresUnit presUnit(BME280::PresUnit_Pa);

  int bmeTryCnt2=0;
  while((!bme2.begin()) && (bmeTryCnt2 < 15)) 
  {
    Serial.println("Could not find BME280 sensor #x077");
    delay(1000);
    bmeTryCnt2++;
  }
  Serial.println("BME280 init 0x77 complete\n");
  bme2.setSettings(settings2);
  
  // Listens as it's own access point to allow retrieval of
  // data from remote clients.

  
  wifi_set_sleep_type(LIGHT_SLEEP_T);
  Serial.println("Setup done"); 
}



unsigned long lastUpdate = 0;
const unsigned long sendUpdateEvery=25000; 
void loop() {  

    // TODO: Record updates to flash until you get 1/2 hour worth
    // and then post all of them at once then delete the file.
     
    long timeSinceLast =  millis() - lastUpdate;
    if (timeSinceLast > sendUpdateEvery) {
      int numWakeTry = 0;
      //wifi_set_sleep_type(NONE_SLEEP_T);
      //WiFi.forceSleepWake();
      //delay(1);
      //while ((WiFi.status() != WL_CONNECTED) && (numWakeTry < 50)) {
      //  delay(50);
      //  Serial.printf(" numTry=%d", numWakeTry);
      //  numWakeTry++;
      //}
      SendUpdate();
      lastUpdate = millis();      
    }

    //wifi_set_sleep_type(LIGHT_SLEEP_T);
    //WiFi.forceSleepBegin(sendUpdateEvery);    
    delay(sendUpdateEvery);    
    //WiFi.forceSleepWake();
}
