# Low Energy Barn, shop, shed drier

>  **CURRENT STATE:  PRE-ALPHA DO NOT USE UNTIL IT REACHES ALPHA LEVEL**
>

## Overview:

Reduce humidity related problems such as rust, mold, corrosion and rot in unheated structures such as Workshops,  warehouses, storage systems without heating the structure full time.    

Traditional approaches such a  roof vents can help but they have a design flaw where they often draw air more moist than what is already inside the structure in which actually increases humidity problems like mold.  The ventilation based systems also tend to draw in fog or mist particles which can cause increased rot, rust and corrosion.   

This solution takes two approaches controlled by an embedded computer and electronic sensors to control the system and activate the various fans, blowers and heaters needed to operate efficiently.

*  A)  Measure the absolute humidity (grams per cubic meter)  of interior and exterior air.  When the exterior air contains less moisture air from outside is moved inside by a fan.  The air is ran through a filter which captures and removes any mist particles.   In most instances the dew point will drop as ambient temperature so during the coldest parts of the morning the air is significantly more dry than it is latter in the day.   
* B)  The system draws interior air through a desiccant matrix that absorbs water from the air.  It periodically disposes excess moisture in one of two ways.  1)  It heats air surrounding the desiccant to separate the moisture from the desiccant and disposes of moist air  outside the structure. 2) Whenever the outside air contains less water than the desiccant exterior air is vented through the desiccant to remove the water.   Option #2 is substantially more energy efficient so it is used whenever possible.  

## Problem: 

In my area we ventilate unheated structures to avoid mold and condensation. We also have rust problems in ventilated unheated structures. I do not want to spend the money to heat the structure all the time but I do want it sealed up so it can retain heat when I want to work in it. I also want to reduce the risk of mold and rust on my expensive tools.  

We need a way to keep the humidity low enough to reduce surface rusting. To reduce condensation we need to reduce humidity so the internal dewpoint us much lower than the ambient low temperature   

#### TODO:

- Basic Schematic
- Basic software
- Getting Started
- Parts List
- Ordering pre-made kits



## Solution Approach #1: Draw air into the structure whenever exterior air is drier than the interior air.

A common approach to reducing mold risk in my area is adding lots of natural venting to minimize condensation that can encourage mold. The disadvantage of this approach is that the venting is always occurring and may in fact make the interior of the structure more moist under many conditions.  

This design essentially measures the humidity of the interior and exterior air and converts those readings to grams of water per cubic meter of air.  Converting to a common base allows comparison when the interior and exterior air are at substantially different temperature.   

When the system detects that the outdoor air is drier than it activates a fan and opens a louver that allows outdoor air to be drawn in through an optional filter creating overpressure in the building and pushing the more moist air out. For well sealed buildings it is necessary to also open a louver to exhaust the moist air.  Sealing the building to minimize undesired air exchange is absolutely essential since the blower or fan have a limited capacity.

This approach will work well in areas where the exterior air is dry enough to reduce overall humidity but there is no guarantee that it can deliver overall conditions keeping the humidity below 50% needed to reduce mold growth.  It works best in areas with large swings of day-night temperatures when the nighttime temperatures drop below the daytime dewpoint.

As an example when our daytime temperatures where       48F (8.9C) @ 78%RH  and the nighttime temperature dropped to 36F.    The  daytime air contained 6.8 grams of water per cubic meter with a dewpoint of  41.5F.   The cooling below 41.5F will result in fog or dew and will tend to draw total moisture down.  When the air reached 36F (2.2C) it will contain 4.4 grams of water.   The remaining 2.2 grams will have been removed as condensation such as fog or dew.    This means that if we draw exterior air into the structure when it contains 32% less moisture and seal the structure the structure will remain less moist or less humid than if allowed to equalize throughout the day.

One main advantage of this approach is that if the structure remains relatively close to the 2.2 grams of water per cubic meter then it remains below the dew point the next day until the temperature drops below that dewpoint.  Since the structure when well sealed will tend to cool at a lower rate rate it will never reach the dewpoint until outside air drops considerably below 

## Solution Approach #2: Desiccant and Heat

The chosen approach is to absorb water from the interior air into a desiccant and then use heat to extract that water into a smaller volume of air that is vented to the outside. We still need heat which is expensive but we need the heat for short periods of time and we do not need as much because we are only heating the desiccant chamber.

My structure contains 52 x 36 x 12 = 23,300 cubic foot (660 cubic meter) of air. Any matching processing 200 cfm of air would require 115 minutes to process the entire volume equivalent. We could cycle the air approximately 12.5 times per day.

Tonight out weather is 83% relative humidity at 30 F. This air can hold 3.76 grams per cubic meter.  At 100F the same humidity the air can hold 65.87 grams or 17.5 times as much water per cubic foot.  A property discovered during the design of the AirSolarWater AWG device was that many desiccants if exposed to ambient air at one humidity if then placed in a sealed chamber that is heated will cause the air in the sealed chamber to equalize at the humidity they were exposed to previously. We can use this to expose a dessicant to the air inside the structure by blowing it through a sealed chamber where the desiccant is located where the desiccant will absorb water until it becomes saturated. 

That means that desiccant allowed to equalize to air containing 3.76 grams per cubic meter that when we seal up the chamber and heat the air to 120F allowing the desiccant to equalize again then we can exhaust air containing 17 times more water per cubic foot of air exhausted. This also causes the desiccant to dry so it becomes capable of absorbing more moisture during the next absorption phase.  By keeping the volume that must be exhausted small it reduces heat lost and the associated reheating cost.

In our 660 cubic meter building it currently contains about 2481 grams of water. We want to reduce the humidity to 49% which is below the mold threshold where it would only contain 2.218 grams per cubic foot or 1464 grams of water. In other words we need to capture 1463 grams (3.2 pounds or 0.33 gallons) of water in the desiccant and then subsequently exhaust it.  During warmer conditions when mold is even a greater risk this value would be much higher.  An activated alumina desiccant can operate in this regime but it can only absorb about 15% by weight which means we need at least 3.2 / 15% = 21.3 pounds of gel. If we estimate that we could run 4 cycles per day with a 1 hour regeneration followed by 5 hours of absorption this could be reduced to 5.3 pounds of desiccant. 

Knowing that we need to evaporate roughly 0.33 gallons of water from the desiccant per day or 0.083 gallons per cycle and knowing that it requires roughly 3.8Kwh to evaporate 1 gallon of water we know that we will need roughly 3.8Kwh * 0.083 = 0.315kWh or 315 watts. Knowing that our regeneration cycle needs to operate in approximately 1 hour we would need at least 300 watts of heating and ideally 500 watts.  At 300 watts this would give us a cost of about 1200 watts per day or 1.2kWh. Evaporation from activated alumina is not an evaporation process so it’s energy requirements should be no worse. 

The system basically operates in two modes Absorption and regeneration.  During Absorption mode air from the structure is cycled through a chamber containing a desiccant until the desiccant becomes saturated and we see a significant reduction in moisture absorption.  Once this occurs the system switches to regeneration mode where louvers or valves seal it from the rest of the room and the interior chamber is heated to a target threshold such as 120F once the air exceeds the target threshold the moist warm air stream is vented to the exterior while new air is drawn in from the exterior. The rate of airflow is adjusted to keep the air slightly warmer than the target temperature. 

If the heated air is only exhausted to the exterior while replacement air is drawn from the building it will maximize exterior leakage that may be more humid than the interior air so it is optimal to always operate with a net zero pressure differential unless the exterior air is drier than the interior air. 

In general most chemical desiccants requires slightly more heat to liberate the moisture than it takes to evaporate distilled water which is about 3.7Kwh per gallon.  

 

In one embodiment the air is heated by a TEC (thermal electric coupler) with the warm side providing the heating energy and the cold side can be used to chill air that would normally be exhausted past the drewpoint to remove the water as a liquid. This requires draining the system which is undesirable however if a small heat pump with a COP > 3 can be used it can improve efficiency.  In another embodiment a liquid cooled heat exchanger can be used to extract the heat and the liquid can be cooled with a fluid loop or ground fluid loop reducing the need for venting but again this would produce a liquid waste product that must be drained. Simple AC or GAS heaters would also be acceptable sources of heat.

 

If should be obvious that the warmer we can heat the gas during the regeneration mode the more efficient the system will be because water gas will hold more water and any GAS vented must be replaced with exterior air which must be rewarmed. 

 

We calibrate humidity difference when in absorption mode by measuring inlet air humidity and exhaust air humidity. We calibrate the two sensors at the first of a run against each other and then can determine when the desiccant is nearing saturation when the humidity absorbed in the chamber drops to less than a threshold, such as 20% the starting delta. When we drop below the threshold the system transitions to recharge mode.

 

When in regeneration mode air is cycled through the chamber in a closed loop as heat is added. The airflow does not have to be fast but we do want to expose the desiccant to a moving stream of gas and we want to distribute the heat evenly.

 

It is always more efficient to replace air inside the structure with exterior air whenever the exterior air is substantially drier than the interior air. One embodiment of this system would use this fact by adding an exterior humidity sensor and choosing to draw exterior air into the structure through a filter.  The key optimization value is that it is not worth running the fan unless there is a sufficient difference between the interior air and the exterior air.  In fact it may be easier to build the first version of this system skipping the 

 

An obvious optimization is to discontinue heating at the tail end of the regeneration system and allow the exterior air to cool the desiccant bed. Care must be taken when the outdoor air is more humid than the interior air to ensure the desiccant does not cool too far and start absorbing moisture from the outdoor air.

 

# Reference

●   [Water per cubic foot of](https://www.process-heating.com/ext/resources/PH/2001/05/Files/PDFs/0501PHhartzell-tables1and2.pdf) air

●   [Online calculator for kg of air per Cubic Meter](https://planetcalc.com/2167/)