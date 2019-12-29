import math
import fpformat

def calcDew(TempC, RelHumid):
  es0 = 6.11          # B42
  const1 = 17.27      # B43
  const2 = 237.7      # B44
  TempK = TempC + 237.7
  # Approach #1
  #saturationVaporPressureES = es0 * math.pow(10,(7.5* TempC/TempK)) #B46 #=B42*10^(7.5*B5/B6)
  #CurrentPressureE =(RelHumid*saturationVaporPressureES) #B47 # =(B3*B46)
  #dew =(-430.22+237.7*math.log(CurrentPressureE))/(-math.log(CurrentPressureE)+19.08)  #B48 # =(-430.22+237.7*LN(B47))/(-LN(B47)+19.08)
  # Approach #2
  comp1 = const2*(((const1*TempC)/TempK)+math.log(RelHumid)) #B52 # =B44*(((B43*B5)/B6)+LN(B3))
  comp2 = const1-(((const1*TempC)/TempK)+math.log(RelHumid)) #B53 # =B43-(((B43*B5)/B6)+LN(B3))
  dew =   comp1 / comp2 #B54 # B52/B53 
  return dew

  


def ouncePerCubicFoot(TempC, RelHumid):
  dewC = calcDew(TempC, RelHumid);
  A = 8.1332  # B60
  B = 1762.39 # B61
  C = 235.66  # B62

  CurrPartialPressure       = A - (B /(TempC + C))            #B64  =+$B$60-$B$61/(B5+$B$62)
  AmbTempPartPressureInmmHG =  math.pow(10.0,CurrPartialPressure)       #B65  =10^B64
  DewTempPartialPressure    =   A - (B /(dewC + C))  #B69 =+$B$60-$B$61/($B$54+$B$62) 
  DewPartialPressureInMMHg  = math.pow(10.0,DewTempPartialPressure)     #B70 =10^B69
  ConcentrationInPPM = DewPartialPressureInMMHg / 760 * 1000000  #B66  =+B70/760*1000000
  GramsWaterPerCubicMeter = ConcentrationInPPM*0.001*18/22.4  # B68
  GramsWaterPerCubicFoot = GramsWaterPerCubicMeter / 35.3146667
  OunceWaterPerCubicFoot = GramsWaterPerCubicFoot / 28.3495231

  #print "dewC=", dewC
  #print "CurrPartialPressure=", CurrPartialPressure
  #print "AmbTempPartPressureInmmHG=", AmbTempPartPressureInmmHG
  #print "DewTempPartialPressure=", DewTempPartialPressure
  #print "DewPartialPressureInMMHg=", DewPartialPressureInMMHg
  #print "ConcentrationInPPM=", ConcentrationInPPM
  #print "GramsWaterPerCubicMeter=",GramsWaterPerCubicMeter
  #print "GramsPerCubicFoot=", GramsWaterPerCubicFoot
  #print "OuncesWaterPerCubicFoot=", OunceWaterPerCubicFoot

  return OunceWaterPerCubicFoot

def FindTempForRecovery(TempC, RelHumid, RecoverRate):
  dewc = calcDew(TempC, RelHumid)
  currOunce = ouncePerCubicFoot(TempC, RelHumid)
  targetOunce = currOunce - (currOunce * RecoverRate)
  print "dewc=", dewc, " currOunce=", currOunce, " targetOunce=", targetOunce
  wrktmp = TempC;
  while wrktmp > 0:
    wrkOunce = ouncePerCubicFoot(wrktmp, 1.0)
    print "wrktmp=", wrktmp, " wrkOunce=", wrkOunce
    if (wrkOunce <= targetOunce):
      return wrktmp
    wrktmp -= 0.5
  return 0

    


TempC      = 20.0 # B5
RelHumid   = 0.80
TempKelvin = TempC + 237.7 #B6
DewPointC  = calcDew(TempC, RelHumid) #45.915321;
print "DewPointC=", DewPointC

opcf = ouncePerCubicFoot(TempC, RelHumid)
print "opcf=", opcf

targetTemp = FindTempForRecovery(TempC, RelHumid, 0.4);
print "targetTemp=", targetTemp


gramPerCubicMeter = (6.112 * math.pow(2.71828,((17.67 * TempC)/(TempC + 243.5))) * (RelHumid * 100) * 2.1674) / (273.15 + TempC)
gramPerCubicFoot = gramPerCubicMeter / 35.3146667
ouncePerCubicFoot = gramPerCubicFoot / 28.3495231
poundPerCubicFoot = ouncePerCubicFoot / 16.0

print "Alt Form temC=", TempC,  "RH=", RelHumid, "gramPerM3=", gramPerCubicMeter, "ouncePerCubicFoot=", fpformat.fix(ouncePerCubicFoot, 5), "poundPerCubicFoot=", fpformat.fix(poundPerCubicFoot,6)


