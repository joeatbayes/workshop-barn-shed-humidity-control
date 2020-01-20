# Reference Links



## Humidity & Dewpoint

* [**Calculate Temperature, Dewpoint, or Relative Humidity Miami.edu**](https://bmcnoldy.rsmas.miami.edu/Humidity.html) includes for calculating Relative humidity, dewpoint and T when the other two are known.
* [omnicalculator.com physics dew-point](https://www.omnicalculator.com/physics/dew-point) - many other formula available at this site.
* [calculator.net dewpoint calculator](https://www.calculator.net/dew-point-calculator.html) includes absolute humidity, saturation vapor pressure, moisture concentration ppm and by weight.  (**Best of the Set**) 

* [Google Sheet to convert RH and Temp to grams per cubic meter](https://docs.google.com/spreadsheets/d/11SYzsOHdeb-T815AajQ4KBsV5wTH1mn9D_bi_d3uxyo/edit?usp=sharing)


* [How to convert relative humidity to absolute humidity](https://carnotcycle.wordpress.com/2012/08/04/how-to-convert-relative-humidity-to-absolute-humidity/),

  * gif format (decimal separator = .)

    [![ah3](https://carnotcycle.files.wordpress.com/2014/09/ah3.gif?w=614)](https://carnotcycle.files.wordpress.com/2014/09/ah3.gif)

    gif format (decimal separator = ,)

    [![ah3a](https://carnotcycle.files.wordpress.com/2014/09/ah3a.gif?w=614)](https://carnotcycle.files.wordpress.com/2014/09/ah3a.gif)

    

    <iframe src="https://c0.pubmine.com/sf/0.0.1/html/safeframe.html" id="safeframe-sf-inline-ad-0" frameborder="no" scrolling="no" allowtranparency="true" hidefocus="true" tabindex="-1" marginwidth="0" marginheight="0" style="margin: 0px; padding: 0px; border: 0px; font-weight: inherit; font-style: inherit; font-size: 12px; font-family: inherit; vertical-align: baseline; display: block; height: 250px; left: 0px; position: absolute; top: 0px; visibility: inherit; width: 300px; z-index: 0;"></iframe>



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

[Pressure to Altitude Conversion](https://www.brisbanehotairballooning.com.au/wp-content/uploads/PressuretoAltitudeConversion.pdf)



# Sensors

* [Create a Iot Sensor with NodeMCU and Lua](https://blog.alexellis.io/iot-nodemcu-sensor-bme280/) includes reading BMP280 some comparison to Rasberry PI.  Claims upto a year on a a single 2500mAh LiPo battery. when in deep sleep.  Instructions on how to flash the firmware

* [Create A Simple ESP8266 Weather Station With BME280](https://lastminuteengineers.com/bme280-esp8266-weather-station/)

* [MicroPython: BME280 with ESP32 and ESP8266 Pressure, Temperature, Humidity](https://randomnerdtutorials.com/micropython-bme280-esp32-esp8266/)

* [Create a simple weather station with BME280, ESP8266 and Arduino IDE](https://lastminuteengineers.com/bme280-esp8266-weather-station/)

* [Create an IoT sensor with NodeMCU and Lua](https://blog.alexellis.io/iot-nodemcu-sensor-bme280/) with BME 280 sensor




## Raspberry PI

* [Raspberry PI Zero W Kit with cables & power  26 base board 10.00](https://www.amazon.com/gp/product/B0748MPQT4/ref=ox_sc_act_title_3?smid=AHALS71WJO58T&psc=1)   Bblackberry running linux with WiFi and Bluetooth.  Running linux.  With SD Card.  Minimum power around 140 mw. 
* [Control GPI pins for Rasberry PI](https://learn.sparkfun.com/tutorials/raspberry-gpio) Both Python and C based examples
* [Run Adruino sketch on Rasberry PI](https://www.deviceplus.com/how-tos/raspberrypi-guide/how-to-run-arduino-sketches-on-raspberry-pi/) WiFi Station & AP,  GUI example, MSG example, Timer,  GPIO, PWM, Servo,  I2C clock reading, DS18B20 one wire,  graphics examples.
* [PC Run Basic](http://runbasic.com/)
* [Raspberrypi getting started ](https://projects.raspberrypi.org/en/projects/raspberry-pi-setting-up/2)
* 




## ESP8266 and ESP32

* [Wemos Mini interfaced to BME280](http://www.esp8266learning.com/esp8266-and-bme280-temperature-sensor-example.php) Includes software to interface with chip using only the wire interface rather than a external library.

* [how to set static IP for wemos mini](https://ice786pk.com/?p=652)

* [NodeMCDU ESP-32s documentation](https://docs.zerynth.com/latest/official/board.zerynth.nodemcu_esp32/docs/index.html) Pin Mapping,  Flash Layout,   512KB free for storage,   3.3 operating voltage,  28 DIO pins, 8 ADC pins,  2 DAC pins,  3 UART,  2 SPI, 3 I2C,  3 MB flash memory, SRAM 520KB,  WiFi 802.11, 

* Modules:

  * [Recomend Boards from Maker Advisor](https://makeradvisor.com/esp32-development-boards-review-comparison/)
  * [Zerynth NodeMCU ESP-32S](https://docs.zerynth.com/latest/official/board.zerynth.nodemcu_esp32/docs/index.html)
  * [Xiuxin Module $25.70 for 3](https://www.amazon.com/gp/product/B07DBNHJW2/ref=ox_sc_act_title_1?smid=A2NHKNRXF8LPRC&psc=1)  ESPC 32  with Bluetooth,  WiFi about 500K of data log space, embeded Lua and bluetooth.
  
* [EPS-32 examples with code snipets](https://nodemcu.readthedocs.io/en/dev-esp32/lua-developer-faq/)

*   

* ## arduino-esp32

  * [express if site](https://github.com/espressif/arduino-esp32)

  * [Gets JSON Serial port server](https://github.com/chilipeppr/serial-port-json-server/releases)

  * [githup esp32 arduino site](https://github.com/espressif/arduino-esp32)

  * [installing esp32 board in arduino ide windows](https://randomnerdtutorials.com/installing-the-esp32-board-in-arduino-ide-windows-instructions/)

  * [ESP32 Pinout Reference](https://randomnerdtutorials.com/esp32-pinout-reference-gpios/) ![ESP32 DEVKIT V1 DOIT board with 36 pins Pinout](https://i1.wp.com/randomnerdtutorials.com/wp-content/uploads/2018/08/ESP32-DOIT-DEVKIT-V1-Board-Pinout-36-GPIOs-updated.jpg?w=813&ssl=1)

  * Arduino examples

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
  
  * ### ESP LUA
  
  * [ESP32 Getting Started with working LUA download](https://iotdesignpro.com/projects/getting-started-with-lua-programming-on-esp32)  My Node ESP32 did not arrive with a working LUA interpreter that could be used from ESPExplorer so had to modify the following to flash a good image. Must modify the following:
  
    * **WARNING: NO MATH IN LUA ON ESP32**.  On On 2019-12-30 I found The LUA made available
      for the ESP32 does not include the math library. as such I decided it is not a valid application 
      for the Shed Dryer.   
    * This utility uses [esptool](https://github.com/espressif/esptool) from expressif.   
    * Download and install [explorer](https://github.com/4refr0nt/ESPlorer) [binary](https://www.esp8266.com/viewtopic.php?f=22&t=882)
    * After downloading the pre-built binary [esptool](https://github.com/chilipeppr/workspace-esp32-lua/files/1443578/esp32tool.zip) unzip it to a directory 
    * This is not the same as the installed esptool from expressif.  It happens to use a similar name but includes a pre-built version of the firmware that will run on the ESP32 chip.
    * Ensure you are running python 3.6.1 or latter.  If you have a python 2.7 earlier in the search path it will break.
      * I Got an error saying that the PIP version was wrong and it required version 2.1 but even when I reinstalled esptool version 2.1 is still got the error.
    * Ensure the path to the python executable is in the System PATH
    * Run ***python -m pip install --upgrade pip*** 
    * Run ***pip install --upgrade esptool*** 
    * Open a command window where you expanded the zip file.
    * Delete the files esptool.py.exe and esptool.py  they are the files that caused the error in pip version.
    * RUN  ***esptool.py --port COM3 write_flash 0x1000 bootloader.bin 0x10000 NodeMCU-esp32-adc-bit-bluetooth-can-dht-i2c-ledc-u8g2-ws2812.bin 0x8000 partitions_singleapp.bin***
      * Note you may need to change it to the correct COM port which you can find by looking in COM ports under the device manager.
      * It did not work when I only flashed a binary to only the 0x1000 address.   
    * You should see something like Connecting,  Then detecting chip,  Then uploading stub, etc.  The last line should be Hard Resetting via RTS pin.
      * Once  this was completed I could interact with the chip from PUTTY or ESExploer on COM3 at 115200 baud.
  
  * 
  
  * Flashing  the LUA runtime
  
    * *esptool.py --chip esp32 --port com3 erase_flash* 
    * *esptool.py --chip esp32 --port com3 --baud 115200 write_flash -z 0x1000 c:\jsoft\esp32\nodemcu-master-18-modules-2019-12-22-17-13-19-float.bin*
    * [development tool online chillipepper](http://chilipeppr.com/esp32#com-chilipeppr-widget-serialport-download)
  
  * ### ESP Basic
  
    * This looked very promising but it has not been updated in 3 years and I didn't want to take it over.  They seem to have made most of the right tradeoff with programming over the web after initial configuration.
    * [http://www.esp8266basic.com/](http://www.esp8266basic.com/)
    * [esp8266 basic examples](http://www.esp8266basic.com/examples.html) 
  
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
  
    * WARNING NO FLOAT:   As of Dec-2019 Micro python build did not include support for Float or python.  As such it is not terribly useful for water and humidity calculations.  
  
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
  
        
  
  * LUA Samples that I actually Used
  
    * **WARNING: NO MATH IN LUA ON ESP32**.  On On 2019-12-30 I found The LUA made available
      for the ESP32 does not include the math library. as such I decided it is not a valid application 
      for the Shed Dryer.   
  
    * Run a script in a file or [avoid a panic in init.lua](https://nodemcu.readthedocs.io/en/dev-esp32/lua-developer-faq/)
  
      ```
       dofile("script1.lua")
      ```
  
      Need this to allow programs to be tested and debugged before risking placing the file in the init.lua file.    Prior to running this step I created the file script1.lua and used the upload file option in [explorer](https://github.com/4refr0nt/ESPlorer)
  
    * [Save Execute and compile Script Files](https://bigdanzblog.wordpress.com/2015/04/21/esp8266-nodemculua-saving-executing-and-compiling-script-files/)
  
    * 



* 

## Other Platforms

- [**DART-6UL** : NXP iMX6UL / 6ULL / 6ULZ](https://www.variscite.com/product/system-on-module-som/cortex-a7/dart-6ul-freescale-imx-6ul/) 24 dollar,   WiFi, Bluetooth,  NXP cpu at 0.9 GHtz,  [datasheet](https://www.variscite.com/wp-content/uploads/2018/01/DART-6UL_DART-6UL-5G_Datasheet.pdf),  current under 5mA in supsend,  tons of IO,  Memory $128MB to 1024 MB DDR3L,  SLC NAND 128MB - 512MB,  eMMC 4-64GB.  8 Uart, 4 I2C, 4 SPI,  RTC, 2 CAN,  ADC 12 bit 2 X 10 chanel,  Eithernet,   [Eval kit 129](https://shop.variscite.com/product/evaluation-kit/dart-6ul-evaluation-kits/) 
- [Node.js embedded Development on Espruino  35](https://www.adafruit.com/product/1887)

- [STM with EPaper display 8K ram 65K flash and touch sensor](https://www.st.com/en/evaluation-tools/32l0538discovery.html)

- [UG309: Thunderboard Sense 2 User's Guide](https://www.silabs.com/documents/public/user-guides/ug309-sltb004a-user-guide.pdf)  MBED,  Bluetooth, seven sensors,  4 LED,  8 MBit flash for data logging, Relative Humidity sensor,  gas quality sensor,  intertia sensor, BMP280, barometric pressure sensor.   Ultra low power,   [thunderboard sens 2 $36](https://www.silabs.com/products/development-tools/thunderboard/thunderboard-sense-two-kit)

- [FRDM KL43Z $20](https://www.nxp.com/design/development-boards/freedom-development-boards/mcu-boards/freedom-development-platform-for-kinetis-kl43-kl33-kl27-kl17-and-kl13-mcus:FRDM-KL43Z?&&cof=0&am=0&tab=Buy_Parametric_Tab&fromSearch=false#buy) 48 Mhtz, 256KB flash, 32KB Ram,  Small 16 character LCD

- [32L47GDiscovery $28] MBed, Ultra Low Power,  STM32, 128K Ram,  1MByte flash,  LCD 24 segments,  Gyroscope, Compas, 128 mBit Quad SPI flash, Able t run from a CR2032

- [Feather M0 With WiFi  $34](https://www.adafruit.com/product/3061)  Atmel  12 Bit ADCC, 10 bit DOC,  losts of SPI, I2C,  12mA power usage,   Compared to ESP at 70mA much lower power usage.  32K ram,   3.7V lithium battery connector with built in batttery charing.   WiFi can draw 300mA during xmit

- [Adafruit Feather M0 with  RFM95 LoRa Radio $35 with 1.2km range](https://www.adafruit.com/product/3179)  Built in battery charger   Arduino IDE.  Updto 20Km with directional antena a low bandwidth.

- [Adat Fruit Feather Huzzah ESP8266 $16.95](https://www.adafruit.com/product/2821) WIFI 3.3V regulator,  9 GPI pins,  I2C, and SPI,  Built in LiPoly charger.  Li Poly 1200  mAh with rpotection circuity. $9.95,   2000 mAh - $12.50,   6600 mAh - $29.50,  4400mAh $19.95,   Also a charge circuit $6.95

- [myirtech with linux moduels from 28 to 35 dollars](http://www.myirtech.com/list.asp?id=561)

- [MYC-AM335X CPU Module  512MB Ram TI CPU $25](MYC-AM335X CPU Module)

- [Adafruit SHARP Memory Display Breakout - 1.3" 168x144 Monochrome PRODUCT ID: 3502 $24.95](https://www.adafruit.com/product/3502)

- [Pimoroni Inky pHAT - eInk Display - Black/White $24 2.13" EPD display (212x104 pixels)](https://www.adafruit.com/product/3934)

- [crystal fonts epaper 200x200  1.54" $11](https://www.crystalfontz.com/product/cfap200200a10154-200x200-epaper-display?kw=&origin=pla&gclid=Cj0KCQiA6IHwBRCJARIsALNjViWbpj_wNFr7whcmcqSlgYIAFAUSfiwuFA2c-FC4Jwe_yN2-fXbHYYwaAjAxEALw_wcB)  includes schematic and arduino sketch

- [1.54" Epaper 200x200 SPI 10 dollars](https://www.ebay.com/itm/WS-3-3V-1-54inch-e-paper-200x200-Raw-E-lnk-Display-SPI-Support-Partial-Refresh/262986384062?_trkparms=aid%3D555018%26algo%3DPL.SIM%26ao%3D1%26asc%3D40719%26meid%3D834272f966f74684ac7f66c8b28ea321%26pid%3D100005%26rk%3D1%26rkt%3D12%26mehot%3Dpf%26sd%3D253139669603%26itm%3D262986384062%26pmt%3D1%26noa%3D0%26pg%3D2047675&_trksid=p2047675.c100005.m1851)

- [red 2.6 inch e-ink display SPI  152X296 14.39]





