## Wind River Rocket [**Arduino-lite**](https://github.com/Wind-River/rocket-arduino-lite) API

# Arduino-lite IBM Watson IoT Platform Sketch  
A device communicates with the [IBM Watson IoT Platform](http://www.ibm.com/internet-of-things/trial.html?cm_mmc=search-gsn-_-branded-watson-iot-search-_-watson%20iot-phrase-_-NA-iot-mkt-ow).    

*** 


##  Required Hardware
 * [**Intel Galileo Gen 2**](http://www.intel.com/content/www/us/en/embedded/products/galileo/galileo-overview.html) or [**NXP FRDM-K64F**](http://www.nxp.com/products/software-and-tools/hardware-development-tools/freedom-development-boards/freedom-development-platform-for-kinetis-k64-k63-and-k24-mcus:FRDM-K64F)  
 * [**Grove Starter Kit**](http://www.seeedstudio.com/deled/Grove-Starter-Kit-for-Arduino-p-1855.html)
   * **Temperature** sensor  (connected to **A0**).  
 
## Hardware Configuration

1. Power off the Intel Galileo Gen 2 or NXP FRDM-K64f before connecting shield or sensors  

2. Ensure that the **VCC** switch on the Grove Shield is appropriate for the device:  
* **5V** for Intel Galileo Gen 2; or   
* **3.3V** for the NXP FRDM-K64f. 

4. Locate the **Temperature sensor** and insert one end of a 4-pin cable into the connector.

5. On the Grove Shield, locate the connector labeled **A0** and insert the other end of the 4-pin cable.

6. Plug an Ethernet cable (attached to a network with Internet access) into the **RJ45** connector

## Running the Sketch in Quickstart Mode
* By default this sketch is configured for Quickstart mode.
* The library creates a unique Quickstart ID which is a 12 digit MAC address. This ID is displayed in the Bluemix connection message printed in the Console view of the Helix App Cloud IDE.  
```
publishing topic iot-2/evt/status/fmt/json payload {"d":{"iot os":"Wind River Rocket with Paho MQTT Embedded-C agent on top of Light Weight IP stack","board":"Intel Galileo Gen2 with Grove Sensor Shield","temp":25.04}}
TX: PUBLISH dup=0 qos=0 retain=1 len=189
sent acknowledge 192 bytes
publishing topic iot-2/evt/status/fmt/json payload {"d":{"iot os":"Wind River Rocket with Paho MQTT Embedded-C agent on top of Light Weight IP stack","board":"Intel Galileo Gen2 with Grove Sensor Shield","temp":24.87}}

```
* Open the Quickstart page at `https://quickstart.internetofthings.ibmcloud.com/#/device/' and enter the device ID.
* The connection status and data (including the temperature) is displayed in the web page.

## Running the Sketch in Registered mode
**You must sign up and register your device with [IBM Bluemix](https://console.ng.bluemix.net/registration/?cm_mc_uid=07707675699114348944831&cm_mc_sid_50200000=1464115687) first***
* The sketch (./application/src/arduino-bluemix.cpp) must be edited to connect to IBM Bluemix in Registered mode.
1. Comment out the definition of **BLUEMIX_QUICKSTART**: 
```
// #define BLUEMIX_QUICKSTART
```
2. Edit the **DEVICE_TYPE**, **ORGANIZATION_ID**, and **TOKEN** macros for your registered device.
```
#define DEVICE_TYPE <Your device type string>
#define ORGANIZATION_ID <Your orginization ID string>
#define TOKEN <Your token string>
```
3. Once you are connected to IBM Bluemix, you can view the connected device at   
  https://**ORGANIZATION_ID**.internetofthings.ibmcloud.com/dashboard/#/devices/browse   

     (Replace **ORGANIZATION_ID** with your Organization ID that was assigned when you registered with IBM Bluemix)

## Adding Datapoints
Three Datapoints (that send data to the Bluemix Cloud) are used in the example Sketch and are defined as follows:
```
// datapoints to sent to Bluemix

float temperature;
Datapoint temp("temp", &temperature);

#define IOT_OS "Wind River Rocket with Paho MQTT Embedded-C agent on top of Light Weight IP stack"
Datapoint os("iot os", IOT_OS);

#ifdef CONFIG_BOARD_GALILEO
#define BOARD "Intel Galileo Gen 2 with Grove Sensor Shield"
#endif // CONFIG_BOARD_GALILEO

#ifdef CONFIG_BOARD_FRDM_K64F
#define BOARD "NXP FRDM-K64F with Grove Sensor Shield"
#endif // CONFIG_BOARD_FRDM_K64F

Datapoint board("board", BOARD);

Datapoint* datapoints[] = { &os, &board, &temp };
```

The datapoint array and the number of datapoints is passed to the publish function as follows:
```
    if (BluemixClient.publish(datapoints, 3)) {
```

### Example of adding new datapoint to monitor **buttonState**:
```
int ButtonState;
DataPoint button("button", &buttonState);
```

```
Datapoint* datapoints[] = { &os, &board, &temp, &button };
```
    if (BluemixClient.publish(datapoints, 4)) {
```

