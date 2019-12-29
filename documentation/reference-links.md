# Reference Links



* [Google Sheet to convert RH and Temp to grams per cubic meter](https://docs.google.com/spreadsheets/d/11SYzsOHdeb-T815AajQ4KBsV5wTH1mn9D_bi_d3uxyo/edit?usp=sharing)

* [Calculating Pressure and Density Height ](https://www.brisbanehotairballooning.com.au/calculating-pressure-and-density-height/) -  30 foot of altitude changes = 1hPa change.      1hPa = 100 pascal.  A such foot of change should equal to 3.3 pascal change.

* [Create a Iot Sensor with NodeMCU and Lua](https://blog.alexellis.io/iot-nodemcu-sensor-bme280/) includes reading BMP280 some comparison to Rasberry PI.  Claims upto a year on a a single 2500mAh LiPo battery. when in deep sleep.  Instructions on how to flash the firmware

* [Create A Simple ESP8266 Weather Station With BME280](https://lastminuteengineers.com/bme280-esp8266-weather-station/)

* [MicroPython: BME280 with ESP32 and ESP8266 Pressure, Temperature, Humidity](https://randomnerdtutorials.com/micropython-bme280-esp32-esp8266/)

* [bme280 sensor users guide](https://www.bosch-sensortec.com/media/boschsensortec/downloads/environmental_sensors_2/humidity_sensors_1/bme280/bst-bme280-ds002.pdf)

* [Calculating Pressure and Density Height](https://www.brisbanehotairballooning.com.au/calculating-pressure-and-density-height/) Air pressure in the ISA is 1013 hectoPascals at Mean Sea Level and the pressure decreases with altitude, at about 1 hPa per 30 feet gain in height in the lower levels of the atmosphere. Air temperature in the ISA is +15oC at Mean Sea Level and decreases at approximately 2oC per 1000 feet gain in altitude.

* [adafruit BME280 how to with schematic](https://learn.adafruit.com/adafruit-bme280-humidity-barometric-pressure-temperature-sensor-breakout?view=all)  includes formula to compute dewpoint in python

* [Create a simple weather station with BME280, ESP8266 and Arduino IDE](https://lastminuteengineers.com/bme280-esp8266-weather-station/)

* [Create an IoT sensor with NodeMCU and Lua](https://blog.alexellis.io/iot-nodemcu-sensor-bme280/) with BME 280 sensor

* [How to convert relative humidity to absolute humidity](https://carnotcycle.wordpress.com/2012/08/04/how-to-convert-relative-humidity-to-absolute-humidity/)

  * gif format (decimal separator = .)

    [![ah3](https://carnotcycle.files.wordpress.com/2014/09/ah3.gif?w=614)](https://carnotcycle.files.wordpress.com/2014/09/ah3.gif)

    gif format (decimal separator = ,)

    [![ah3a](https://carnotcycle.files.wordpress.com/2014/09/ah3a.gif?w=614)](https://carnotcycle.files.wordpress.com/2014/09/ah3a.gif)

    

    <iframe src="https://c0.pubmine.com/sf/0.0.1/html/safeframe.html" id="safeframe-sf-inline-ad-0" frameborder="no" scrolling="no" allowtranparency="true" hidefocus="true" tabindex="-1" marginwidth="0" marginheight="0" style="margin: 0px; padding: 0px; border: 0px; font-weight: inherit; font-style: inherit; font-size: 12px; font-family: inherit; vertical-align: baseline; display: block; height: 250px; left: 0px; position: absolute; top: 0px; visibility: inherit; width: 300px; z-index: 0;"></iframe>
REPORT THIS AD
    

    
jpg format (decimal separator = .)
    
[![ah1](https://carnotcycle.files.wordpress.com/2014/09/ah1.jpg?w=614)](https://carnotcycle.files.wordpress.com/2014/09/ah1.jpg)
    
jpg format (decimal separator = ,)
    
[![ah1a](https://carnotcycle.files.wordpress.com/2014/09/ah1a.jpg?w=614)](https://carnotcycle.files.wordpress.com/2014/09/ah1a.jpg)
    
***– – – –***
  
* [Calculate absolute humidity from temperature and relative humidity](https://github.com/atmos-python/atmos/issues/3)

  * ```
    es = 611.2*exp(17.67*(T-273.15)/(T-29.65))
    rvs = 0.622*es/(p - es)
    rv = RH/100. * rvs
    qv = rv/(1 + rv)
    AH = qv*rho
    ```

    

* [Silica Gel  & Molecular Sieve absorption curve](https://valdamarkdirect.com/product/silica-gel-sachets/)
  
  * ![Image result for silica gel absorption rate](http://valdamarkdirect.com/wp-content/uploads/2014/10/Screenshot020.jpg)



## ESP8266 and ESP32

* [Recomend Boards from Maker Advisor](https://makeradvisor.com/esp32-development-boards-review-comparison/)

* [Zerynth NodeMCU ESP-32S](https://docs.zerynth.com/latest/official/board.zerynth.nodemcu_esp32/docs/index.html)![NodeMCU ESP-32S](https://docs.zerynth.com/latest/_images/nodemcu_esp32_pin.jpg)

* [ESP-32 Establish Serial Connection and Drivers](https://docs.espressif.com/projects/esp-idf/en/latest/get-started/establish-serial-connection.html)

  * [Putty.org download](https://www.putty.org/)

  * [How to flash NodeMCU software](https://www.instructables.com/id/How-to-Flash-NodeMCU-Firmware-in-ESP8266/)

  * [ESP Explorer download](https://github.com/nodemcu/nodemcu-flasher/blob/master/Win64/Release/ESP8266Flasher.exe)

  * [NodeMCU Firmware for ESP32 and ESP8266](https://github.com/nodemcu/nodemcu-firmware)

  * [Uploading code to ESP32 and ESP Explorer & similar tools](https://nodemcu.readthedocs.io/en/master/upload/)

  * [micro python getting started language overview](https://docs.micropython.org/en/latest/wipy/quickref.html)

  * [esptool explained](https://github.com/espressif/esptool)

  * [expressif main docs site](https://docs.espressif.com/projects/esp-idf/en/latest/get-started/index.html#get-started-configure)

  * [Burn Python Firmware onto the Board using windows 10](https://micropython.org/download#esp32)

    * ```
      esptool.py --chip esp32 --port com3 erase_flash  
      ```

    * ```
      esptool.py --chip esp32 --port com3 --baud 115200 write_flash -z 0x1000 c:\jsoft\esp32\esp32-idf3-20191222-v1.12-5-g42e45bd69.bin
      ```

      

  * show free ram on micropython

    * ```
      import gc
      gc.collect()
      gc.mem_free()
      ```

      

* Flashing  the LUA runtime

  * Still have not found a Firmware taht does not error out on boot.
  * esptool.py --chip esp32 --port com3 erase_flash 
  * esptool.py --chip esp32 --port com3 --baud 115200 write_flash -z 0x1000 c:\jsoft\esp32\nodemcu-master-18-modules-2019-12-22-17-13-19-float.bin
  * [development tool online chillipepper](http://chilipeppr.com/esp32#com-chilipeppr-widget-serialport-download)

* [EPS-32 examples with code snipets](https://nodemcu.readthedocs.io/en/dev-esp32/lua-developer-faq/)

* [NodeMCDU ESP-32s documentation](https://docs.zerynth.com/latest/official/board.zerynth.nodemcu_esp32/docs/index.html) Pin Mapping,  Flash Layout,   512KB free for storage,   3.3 operating voltage,  28 DIO pins, 8 ADC pins,  2 DAC pins,  3 UART,  2 SPI, 3 I2C,  3 MB flash memory, SRAM 520KB,  WiFi 802.11, 

* )[Xiuxin Module $25.70 for 3](https://www.amazon.com/gp/product/B07DBNHJW2/ref=ox_sc_act_title_1?smid=A2NHKNRXF8LPRC&psc=1)  ESPC 32  with Bluetooth,  WiFi about 500K of data log space, embeded Lua and bluetooth.

* [Raspberry PI Zero W Kit with cables & power  26 base board 10.00](https://www.amazon.com/gp/product/B0748MPQT4/ref=ox_sc_act_title_3?smid=AHALS71WJO58T&psc=1)   Bblackberry running linux with WiFi and Bluetooth.  Running linux.  With SD Card.  Minimum power around 140 mw.   

* arduino-esp32

  * [express if site](https://github.com/espressif/arduino-esp32)

  * [Gets JSON Serial port server](https://github.com/chilipeppr/serial-port-json-server/releases)

  * [githup esp32 arduino site](https://github.com/espressif/arduino-esp32)

  * [installing esp32 board in arduino ide windows](https://randomnerdtutorials.com/installing-the-esp32-board-in-arduino-ide-windows-instructions/)

  * [ESP32 Pinout Reference](https://randomnerdtutorials.com/esp32-pinout-reference-gpios/) ![ESP32 DEVKIT V1 DOIT board with 36 pins Pinout](https://i1.wp.com/randomnerdtutorials.com/wp-content/uploads/2018/08/ESP32-DOIT-DEVKIT-V1-Board-Pinout-36-GPIOs-updated.jpg?w=813&ssl=1)

  * [Learn ESP32 with arduino IDE $39](https://randomnerdtutorials.com/learn-esp32-with-arduino-ide/#sign-up)

  * [Install ESP32 Filesystem Uploader in Arduino IDE](https://randomnerdtutorials.com/install-esp32-filesystem-uploader-arduino-ide/)

  * [ESP32 Web Server using SPIFFS (SPI Flash File System)](https://randomnerdtutorials.com/esp32-web-server-spiffs-spi-flash-file-system/)

  * [ESP32 OLED Display with Arduino IDE](https://randomnerdtutorials.com/esp32-ssd1306-oled-display-arduino-ide/) This is an external 0.96" display. 

  * [building a web server in esp32 arduino](https://randomnerdtutorials.com/esp32-web-server-arduino-ide/) 

  * [control pwm servo motor for esp32 via arduino](https://randomnerdtutorials.com/esp32-servo-motor-web-server-arduino-ide/)

  * [esp32 free heap from arduino](https://techtutorialsx.com/2017/12/17/esp32-arduino-getting-the-free-heap/)

  * [reading a file  using spiffs](https://techtutorialsx.com/2018/08/05/esp32-arduino-spiffs-reading-a-file/)

  * [ESP32 Tutorials](https://techtutorialsx.com/category/esp32/page/4/)

  * [build an all in one esp32 weather station](https://randomnerdtutorials.com/build-an-all-in-one-esp32-weather-station-shield/)  includes building schematic, pCB and getting it produced.

  * [Getting started with ESP32 Bluetooth Low Energy BLE on Arduino IDE](https://randomnerdtutorials.com/esp32-bluetooth-low-energy-ble-arduino-ide/)

  * [ESP32 Bluetooth Classic with Arduino IDE – Getting Started](https://randomnerdtutorials.com/esp32-bluetooth-classic-arduino-ide/)  Also includes using a one wire DS18B20

  * [ESP32 ADC – Read Analog Values with Arduino IDE](https://randomnerdtutorials.com/esp32-adc-analog-read-arduino-ide/)

  * [ESP32 with LoRa using Arduino IDE – Getting Started](https://randomnerdtutorials.com/esp32-lora-rfm95-transceiver-arduino-ide/)

  * [How to use ESP32 Dual Core with Arduino IDE](https://randomnerdtutorials.com/esp32-dual-core-arduino-ide/)

  * [ESP32 External Wakeup from Deep Sleep](https://randomnerdtutorials.com/esp32-external-wake-up-deep-sleep/)

  * [ESP32 Built-in OLED Board (Wemos Lolin32): Pinout, Libraries and OLED Control](https://randomnerdtutorials.com/esp32-built-in-oled-ssd1306/)

  * [Build a Multisensor Shield for ESP8266](https://randomnerdtutorials.com/esp8266-multisensor-shield/)

  * [ESP32 Data Logging Temperature to MicroSD Card](https://randomnerdtutorials.com/esp32-data-logging-temperature-to-microsd-card/)  Includes SDCard,  Fetch time from NTP SErver,  Timer Wakeup,  Deepsleep for 10 minutes, DS18B20 temp sensor.   Includes installing exernal library for the two sensors.

  * [ESP32 Publish Sensor Readings to Google Sheets BME280](https://randomnerdtutorials.com/esp32-esp8266-publish-sensor-readings-to-google-sheets/)  Includes BME280, wiring to support Deepsleep with auto wakeup,  

  * [ESP32 with BME280 Sensor using Arduino IDE (Pressure, Temperature, Humidity)](https://randomnerdtutorials.com/esp32-bme280-arduino-ide-pressure-temperature-humidity/#more-86478)  also [Adafruit BME280 Humidity + Barometric Pressure + Temperature Sensor Breakout](https://learn.adafruit.com/adafruit-bme280-humidity-barometric-pressure-temperature-sensor-breakout/overview) 

  * [ESP8266 NodeMCU Access Point (AP) for Web Server](https://randomnerdtutorials.com/esp8266-nodemcu-access-point-ap-web-server/)  Connect direct to ESP without having a router.  Could be useful for field downloading of data.

  * [EXTREME POWER SAVING (0µA) with Microcontroller External Wake Up: Latching Power Circuit](https://randomnerdtutorials.com/power-saving-latching-circuit/)  [EasyEDA](https://easyeda.com/) Online PCB Designer.  [fritzing](https://fritzing.org/home/) opensource schematic design

  * [ESP32 with DC Motor and L298N Motor Driver - Control Speed and Direction](https://randomnerdtutorials.com/esp32-dc-motor-l298n-motor-driver-control-speed-direction/)  Includes use of the HBridge and controlling speed with the HBridge.

  * [Sending data via email via posting through a service](https://randomnerdtutorials.com/esp32-esp8266-send-email-notification/)

  * [ESP32 Touch Wake Up from Deep Sleep](https://randomnerdtutorials.com/esp32-touch-wake-up-deep-sleep/)  Also introduces interrupts.

  * [ESP32 with DHT11/DHT22 Temperature and Humidity Sensor using Arduino IDE](https://randomnerdtutorials.com/esp32-dht11-dht22-temperature-humidity-sensor-arduino-ide/)

  * [Issues around RTC and crystals](https://github.com/espressif/arduino-esp32/issues/1225)

    * ```
      void app_main() {
      struct timespec tp;
      memset(&tp, 0, sizeof(tp));
      clock_gettime(CLOCK_REALTIME, &tp);
      
      printf("Got time %lus\n", tp.tv_sec);
      if (tp.tv_sec < 1573532) {
      	tp.tv_sec = 1573532;
      	tp.tv_nsec = 198;
      	clock_settime(CLOCK_REALTIME, &tp);
      	puts("Time set");
      }
      
      const int deep_sleep_sec = 10;
      printf("Entering deep sleep for %d seconds", deep_sleep_sec);
      esp_deep_sleep(1000000LL * deep_sleep_sec);
      }
      ```

  * [ESP32 I2C Communication: Set Pins, Multiple Bus Interfaces and Peripherals (Arduino IDE)](https://randomnerdtutorials.com/esp32-i2c-communication-arduino-ide/#more-89386)

  * 

## Raspberry PI

* [Control GPI pins for Rasberry PI](https://learn.sparkfun.com/tutorials/raspberry-gpio) Both Python and C based examples
* [Run Adruino sketch on Rasberry PI](https://www.deviceplus.com/how-tos/raspberrypi-guide/how-to-run-arduino-sketches-on-raspberry-pi/)
* 



# Wireless extended Range

* [nrf2401 real life range test claims over 100 meter range with good antena](https://hallard.me/nrf24l01-real-life-range-test/)

## Other Platforms

[**DART-6UL** : NXP iMX6UL / 6ULL / 6ULZ](https://www.variscite.com/product/system-on-module-som/cortex-a7/dart-6ul-freescale-imx-6ul/) 24 dollar,   WiFi, Bluetooth,  NXP cpu at 0.9 GHtz,  [datasheet](https://www.variscite.com/wp-content/uploads/2018/01/DART-6UL_DART-6UL-5G_Datasheet.pdf),  current under 5mA in supsend,  tons of IO,  Memory $128MB to 1024 MB DDR3L,  SLC NAND 128MB - 512MB,  eMMC 4-64GB.  8 Uart, 4 I2C, 4 SPI,  RTC, 2 CAN,  ADC 12 bit 2 X 10 chanel,  Eithernet,   [Eval kit 129](https://shop.variscite.com/product/evaluation-kit/dart-6ul-evaluation-kits/) 

[Node.js embedded Development on Espruino  35](https://www.adafruit.com/product/1887)



[STM with EPaper display 8K ram 65K flash and touch sensor](https://www.st.com/en/evaluation-tools/32l0538discovery.html)

[UG309: Thunderboard Sense 2 User's Guide](https://www.silabs.com/documents/public/user-guides/ug309-sltb004a-user-guide.pdf)  MBED,  Bluetooth, seven sensors,  4 LED,  8 MBit flash for data logging, Relative Humidity sensor,  gas quality sensor,  intertia sensor, BMP280, barometric pressure sensor.   Ultra low power,   [thunderboard sens 2 $36](https://www.silabs.com/products/development-tools/thunderboard/thunderboard-sense-two-kit)

[FRDM KL43Z $20](https://www.nxp.com/design/development-boards/freedom-development-boards/mcu-boards/freedom-development-platform-for-kinetis-kl43-kl33-kl27-kl17-and-kl13-mcus:FRDM-KL43Z?&&cof=0&am=0&tab=Buy_Parametric_Tab&fromSearch=false#buy) 48 Mhtz, 256KB flash, 32KB Ram,  Small 16 character LCD

[32L47GDiscovery $28] MBed, Ultra Low Power,  STM32, 128K Ram,  1MByte flash,  LCD 24 segments,  Gyroscope, Compas, 128 mBit Quad SPI flash, Able t run from a CR2032

[Feather M0 With WiFi  $34](https://www.adafruit.com/product/3061)  Atmel  12 Bit ADCC, 10 bit DOC,  losts of SPI, I2C,  12mA power usage,   Compared to ESP at 70mA much lower power usage.  32K ram,   3.7V lithium battery connector with built in batttery charing.   WiFi can draw 300mA during xmit

[Adafruit Feather M0 with  RFM95 LoRa Radio $35 with 1.2km range](https://www.adafruit.com/product/3179)  Built in battery charger   Arduino IDE.  Updto 20Km with directional antena a low bandwidth.

[Adat Fruit Feather Huzzah ESP8266 $16.95](https://www.adafruit.com/product/2821) WIFI 3.3V regulator,  9 GPI pins,  I2C, and SPI,  Built in LiPoly charger.  Li Poly 1200  mAh with rpotection circuity. $9.95,   2000 mAh - $12.50,   6600 mAh - $29.50,  4400mAh $19.95,   Also a charge circuit $6.95

[myirtech with linux moduels from 28 to 35 dollars](http://www.myirtech.com/list.asp?id=561)

[MYC-AM335X CPU Module  512MB Ram TI CPU $25](MYC-AM335X CPU Module)

[Adafruit SHARP Memory Display Breakout - 1.3" 168x144 Monochrome PRODUCT ID: 3502 $24.95](https://www.adafruit.com/product/3502)

[Pimoroni Inky pHAT - eInk Display - Black/White $24 2.13" EPD display (212x104 pixels)](https://www.adafruit.com/product/3934)

[crystal fonts epaper 200x200  1.54" $11](https://www.crystalfontz.com/product/cfap200200a10154-200x200-epaper-display?kw=&origin=pla&gclid=Cj0KCQiA6IHwBRCJARIsALNjViWbpj_wNFr7whcmcqSlgYIAFAUSfiwuFA2c-FC4Jwe_yN2-fXbHYYwaAjAxEALw_wcB)  includes schematic and arduino sketch

[1.54" Epaper 200x200 SPI 10 dollars](https://www.ebay.com/itm/WS-3-3V-1-54inch-e-paper-200x200-Raw-E-lnk-Display-SPI-Support-Partial-Refresh/262986384062?_trkparms=aid%3D555018%26algo%3DPL.SIM%26ao%3D1%26asc%3D40719%26meid%3D834272f966f74684ac7f66c8b28ea321%26pid%3D100005%26rk%3D1%26rkt%3D12%26mehot%3Dpf%26sd%3D253139669603%26itm%3D262986384062%26pmt%3D1%26noa%3D0%26pg%3D2047675&_trksid=p2047675.c100005.m1851)

[red 2.6 inch e-ink display SPI  152X296 14.39]









## Dam Construction



* [Aquadam.net water filled coffer dams](https://www.aquadam.net/residential-flood-control/)

* [quick dam flood barrier 3.5 in H,  6.5"W  x120" long.  $25.99](https://www.acehardware.com/departments/building-supplies/concrete-cement-and-masonry/flood-barriers/5681622)
* [Halsted white sand & Utility bags 30lb](https://www.acehardware.com/departments/building-supplies/concrete-cement-and-masonry/sand-and-gravel/5162797)
* [50 pack holds 45 pound sand $18.69](https://www.homedepot.com/p/Hercules-Sand-Bags-50-Pack-HP02071422b50g/100291336)
* [14 in X 26"  100 pack $35.73  Hold 50 pounds of sand,  1600 hour UV protection](https://www.homedepot.com/p/14-in-x-26-in-White-Polypropylene-Sandbag-100-Pack-14981-10-14/204277293?MERCH=REC-_-pipinstock-_-100291336-_-204277293-_-N)
* [100 bag 14" X 26" military grade $41.99](https://www.amazon.com/Sandbags-Flooding-Size-Barrier-Sandbaggy/dp/B075LWH47Z/ref=sm_n_ma_dka_US_pr_ran_0_0?adId=B075LQYV1Z&creativeASIN=B075LQYV1Z&linkId=6569c5ae9996efde1ed489a3e7ef7daa&tag=chainjourn-20&linkCode=w43&ref-refURL=https%3A%2F%2Fwww.chainsawjournal.com%2Fsandbags-for-flooding%2F&slotNum=0&imprToken=fezlsrb9CDiSH-gmhNpFyQ&adType=smart&adMode=manual&adFormat=grid&impressionTimestamp=1576974843344&th=1)    [5000 bags $1249.99](https://www.amazon.com/Sandbags-Flooding-Size-Barrier-Sandbaggy/dp/B075LTLK4G/ref=sm_n_ma_dka_US_pr_ran_0_0?adId=B075LQYV1Z&creativeASIN=B075LQYV1Z&linkId=6569c5ae9996efde1ed489a3e7ef7daa&tag=chainjourn-20&linkCode=w43&ref-refURL=https%3A%2F%2Fwww.chainsawjournal.com%2Fsandbags-for-flooding%2F&slotNum=0&imprToken=fezlsrb9CDiSH-gmhNpFyQ&adType=smart&adMode=manual&adFormat=grid&impressionTimestamp=1576974843344&th=1)  [20,000 bags $3999](https://www.amazon.com/Sandbags-Flooding-Size-Barrier-Sandbaggy/dp/B075LZMGY4/ref=sm_n_ma_dka_US_pr_ran_0_0?adId=B075LQYV1Z&creativeASIN=B075LQYV1Z&linkId=6569c5ae9996efde1ed489a3e7ef7daa&tag=chainjourn-20&linkCode=w43&ref-refURL=https%3A%2F%2Fwww.chainsawjournal.com%2Fsandbags-for-flooding%2F&slotNum=0&imprToken=fezlsrb9CDiSH-gmhNpFyQ&adType=smart&adMode=manual&adFormat=grid&impressionTimestamp=1576974843344&th=1) or $0.19 each.
* [Building Sandbag dams](https://science.howstuffworks.com/nature/natural-disasters/sandbag4.htm) For a 4 foot high wall bult in a pyramid will take about 78 per sq foot.  Wall have to be ina pymad shape.
