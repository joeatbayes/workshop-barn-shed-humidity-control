#include "SPIFFS.h"
#include "WiFi.h"
#include "math.h"

uint64_t chipid;  

#include "listAccessPoints.h"

void setup() {
	Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
  printAcccessPoints();
  testFileIO();
}


float  gramsPerM3(float tempC, float relHumid) {
   return (6.112 * pow(2.71828,((17.67 * tempC)/(tempC + 243.5))) * (relHumid * 100) * 2.1674) / (273.15 + tempC);
}

// Return ounces of water per cubic foot of air based
// on input temperature in Celcius and relative humidity
// between 0.0 and 1.0
float ouncePerCubicFoot(float tempC, float relHumid) {
   return gramsPerM3(tempC, relHumid) / 1001.15359;
}

// Convert Celcius to Fahren
float CToF(float tempC){
   return (tempC * 1.8) + 32.0;
}

// Convert Fahrenheit temp to Celcius
float FToC(float tempF) {
   return (tempF - 32.0) * 0.55555555555;
}

// Calculate Dewpoint from Input Temperature and Relative Humidity
// relative humidity is expressed as float between 0.0 and 1.0
float  calcDewPoint(float tempC, float relHumid) {
  float const1 = 17.27;
  float const2 = 237.7;
  float tempK = tempC + 237.7;
  // Approach #1
  //es0 = 6.11
  //saturationVaporPressureES = es0 * math.pow(10,(7.5* TempC/TempK)) #B46 #=B42*10^(7.5*B5/B6)
  //CurrentPressureE =(RelHumid*saturationVaporPressureES) #B47 # =(B3*B46)
  //dew =(-430.22+237.7*math.log(CurrentPressureE))/(-math.log(CurrentPressureE)+19.08)  #B48 # =(-430.22+237.7*LN(B47))/(-LN(B47)+19.08)

  // Approach #2
  float comp1 = const2*(((const1*tempC)/tempK)+log(relHumid));
  float comp2 = const1-(((const1*tempC)/tempK)+log(relHumid));
  return comp1 / comp2;

}


void loop() {

 
  // Convert Relative Humidity & Temp to Grams per cubic meter
  float tempC = 21.1; // bme.getTemperature_C();
  float relHumid = 0.8; // bme.getHumidity();
  float absHumid = gramsPerM3(tempC, relHumid);
  float cubicFootPerCubicMeter = 35.3147;
  float gramPerOunce = 28.3495;
  float ouncePerCubicFoot = (absHumid / cubicFootPerCubicMeter) / gramPerOunce;
  float poundPerCubicFoot = ouncePerCubicFoot / 16.0;
  float tempF = CToF(tempC);
  float dewC = calcDewPoint(tempC, relHumid);
  Serial.printf("RH=%3.3f temp C=%3.3f F=%3.3f AbsHumid=%3.3f ", relHumid, tempC, tempF, absHumid); 
  Serial.printf("OuncePerCubicFoot=%3.7f PoundPerCubicFoot=%3.9f dewPointC=%3.3f\n", ouncePerCubicFoot, poundPerCubicFoot,  dewC);
  //Serial.println(bme.getPressure_MB());


  
  delay(3000);

}




 
