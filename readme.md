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
1. Custom version of the Makerfabs firmware for the LoRaWAN Soil Sensor. 
2. This allows for use on Helium and PlatformIO
3. Also added Debug button when held will send LoRaWAN packet or LoRaWAN join
4. Added better LoRaWAN join logic so it doesn't join everytime it tries to uplink

```
function Decoder(bytes, port, uplink_info) {
  var decoded = {};
  
  decoded.temp = bytes[0];
  decoded.humi = bytes[1];
  decoded.adc = bytes[2];
  decoded.bat = bytes[3];
  decoded.num = bytes[4] * 100 + bytes[5];
  
  return decoded;
}
```
