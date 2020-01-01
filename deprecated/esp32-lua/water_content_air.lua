-- WARNING: As of 2019-12-30 the binary I downloaded
-- for firmware did not include math libary so switching
-- to adurino which does include it for the same module. 
--

-- Return grams of water per cubic foot of air
-- based on input temperature in C and relative
-- humidity between 0.0 and 1.0
function gramsPerM3(tempC, relHumid)
   return (6.112 * math.pow(2.71828,((17.67 * tempC)/(tempC + 243.5))) * (relHumid * 100) * 2.1674) / (273.15 + tempC)
end

-- Return ounces of water per cubic foot of air based
-- on input temperature in Celcius and relative humidity
-- between 0.0 and 1.0
function ouncePerCubicFoot(tempC, relHumid)
   return gramsPerM3(tempC, relHumid) / 1001.15359
end

-- Convert Celcius to Farenhite
function CToF(tempC)
   return (TempF / 1.8) + 32.0
end

-- Convert Farenhite temp to Celcius
function FToC(tempF)
   return (tempF - 32.0) / 1.8
end

-- Calculate Dewpoint from Input Temperature and Relative Humidity
-- relative humidity is expressed as float between 0.0 and 1.0
function calcDewPoint(tempC, relHumid)
  const1 = 17.27
  const2 = 237.7
  tempK = tempC + 237.7
  --# Approach #1
  --es0 = 6.11
  --#saturationVaporPressureES = es0 * math.pow(10,(7.5* TempC/TempK)) #B46 #=B42*10^(7.5*B5/B6)
  --#CurrentPressureE =(RelHumid*saturationVaporPressureES) #B47 # =(B3*B46)
  --#dew =(-430.22+237.7*math.log(CurrentPressureE))/(-math.log(CurrentPressureE)+19.08)  #B48 # =(-430.22+237.7*LN(B47))/(-LN(B47)+19.08)

  --# Approach #2
  comp1 = const2*(((const1*tempC)/tempK)+math.log(relHumid))
  comp2 = const1-(((const1*tempC)/tempK)+math.log(relHumid))
  return comp1 / comp2

end



function basicDemo()
  local TempF      = 60.0
  local TempC      =  FToC(TempF)
  local RelHumid   = 0.8
  local tempKelvin = TempC + 237.7
  local dewPoint = calcDewPoint(TempC, RelHumid)

  --gramPerCubicMeter = (6.112 * math.pow(2.71828,((17.67 * TempC)/(TempC + 243.5))) * (RelHumid * 100.0) * 2.1674) / (273.15 + TempC)
  local gramPerCubicMeter = gramsPerM3(TempC, RelHumid)
  local gramPerCubicFoot = gramPerCubicMeter / 35.3146667
  --ouncePerCubicFoot = gramPerCubicFoot / 28.3495231
  local OncePerFoot3 = ouncePerCubicFoot(TempC, RelHumid)
  local poundPerCubicFoot = OncePerFoot3 / 16.0

  print(string.format("TempF=%0.2f Tempc=%0.2f RH=%0.1f dewPoint=%0.2f gramPerM3=%0.2f OuncePerCubicFoot=%0.4f poundPerCubicFoot=%0.7f", TempF, TempC, RelHumid, dewPoint, gramPerCubicMeter,OncePerFoot3, poundPerCubicFoot))
end

basicDemo()
