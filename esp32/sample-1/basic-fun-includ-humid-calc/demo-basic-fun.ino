#include "SPIFFS.h"
#include "WiFi.h"

uint64_t chipid;  

void setup() {
	Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
}

void loop() {
	chipid=ESP.getEfuseMac();//The chip ID is essentially its MAC address(length: 6 bytes).
	Serial.printf("ESP32 Chip ID = %04X",(uint16_t)(chipid>>32));//print High 2 bytes
	Serial.printf(" %08X\n",(uint32_t)chipid);//print Low 4bytes.
  Serial.printf("Free Heap=%d\n", ESP.getFreeHeap());


    Serial.println("scan start");
    // WiFi.scanNetworks will return the number of networks found
    int n = WiFi.scanNetworks();
    Serial.println("scan done");
    if (n == 0) {
        Serial.println("no networks found");
    } else {
        Serial.print(n);
        Serial.println(" networks found");
        for (int i = 0; i < n; ++i) {
            // Print SSID and RSSI for each network found
            Serial.print(i + 1);
            Serial.print(": ");
            Serial.print(WiFi.SSID(i));
            Serial.print(" (");
            Serial.print(WiFi.RSSI(i));
            Serial.print(")");
            Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN)?" ":"*");
            delay(10);
        }
    }
    Serial.println("");
    

 if(!SPIFFS.begin(true)){
        Serial.println("An Error has occurred while mounting SPIFFS");
        return;
   }

    /* Comment out because we do not want to wear
     *  out our strorage
     
    File file = SPIFFS.open("/test.txt", FILE_WRITE);
 
    if(!file){
        Serial.println("There was an error opening the file for writing");
        return;
    }
 
    if(file.print("TEST")){
        Serial.println("File was written");;
    } else {
        Serial.println("File write failed");
    }
 
    file.close();
    */

    // Read a file in a directory
    File file2 = SPIFFS.open("/test.txt");
    if(!file2){
        Serial.println("Failed to open file for reading");
        return;
    }
    Serial.println("File Content:");
    // print content from the file
    while(file2.available()){
        Serial.write(file2.read());
    }
    file2.close();



  // List Files Available in Directory
  File root = SPIFFS.open("/");
  File file3 = root.openNextFile();
  while(file3){
      Serial.print("FILE: ");
      Serial.println(file3.name());
      file3 = root.openNextFile();
  }
  // Wait a while to do anything else.




  // Convert Relative Humidity & Temp to Grams per cubic meter
  float Temperature = 20.0; // bme.getTemperature_C();
  float Humidity = 80.0; // bme.getHumidity();
  float AbsoluteHumidity = (6.112 * pow(2.71828,((17.67 * Temperature)/(Temperature + 243.5))) * Humidity * 2.1674) / (273.15 + Temperature);
  float pounds = AbsoluteHumidity / 453.92;
  float cubicFootPerCubicMeter = 35.3147;
  float poundsWaterPerCubicFoot = pounds / cubicFootPerCubicMeter;
  float TempF = (Temperature * 1.80) + 32;
  Serial.printf("RH=%3.3f temp C=%3.3f F=%3.3f AbsHumit=%3.3f\n", Humidity, Temperature, TempF, AbsoluteHumidity); 
  Serial.printf("pounds per cubic foot=%3.7f\n  kgPerM3=%3.9f", poundsWaterPerCubicFoot, AbsoluteHumidity / 1000.0);
  //Serial.println(bme.getPressure_MB());







  
  delay(3000);

}

 
