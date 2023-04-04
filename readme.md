```
                       _        ______          _                 
     /\               | |      |  ____|        | |                
    /  \   _ __  _ __ | | ___  | |__ _   _  ___| | _____ _ __ ___ 
   / /\ \ | '_ \| '_ \| |/ _ \ |  __| | | |/ __| |/ / _ \ '__/ __|
  / ____ \| |_) | |_) | |  __/ | |  | |_| | (__|   <  __/ |  \__ \
 /_/    \_\ .__/| .__/|_|\___| |_|   \__,_|\___|_|\_\___|_|  |___/
          | |   | |                                               
          |_|   |_|                                               
```
## About
1. Custom version of the Makerfabs firmware for the LoRaWAN Soil Sensor. 
2. This allows for use on Helium and PlatformIO
3. Also added Debug button when held will send LoRaWAN packet or LoRaWAN join
4. Added better LoRaWAN join logic so it doesn't join everytime it tries to uplink

## To join to LoRaWAN
Make sure to fill out the following in config.h
```
#define DEVEUI ""
#define APPEUI ""
#define APPKEY ""
```
You can generate these from your LNS of choice

## Calibrate soil sensor
You want to do some debugging, I pushed the numbers that work for me in my location, Canada. You want to test these by triggering an uplink multiple times with the probe in water and out while connected to serial console. Take note of the number that seems to be stable. Adjust these numbers in config.h
```
#define SOIL_ADC_WATER 694
#define SOIL_ADC_AIR 753
```
You can see ADC output when you connect your Makerfabs LoRaWAN sensor to a serial input.

## Helium Decoder
```
function Decoder(bytes, port, uplink_info) 
{
  var decoded = {};
  
  decoded.temp = bytes[0];
  decoded.temp_f = (bytes[0] * 1.8) + 32;
  decoded.humi = bytes[1];
  decoded.soil = bytes[2];
  decoded.bat = bytes[3] / 10;
  decoded.tx = bytes[4] * 100 + bytes[5];
  
  return decoded;
}
```
