/*
 * Copyright (c) 2015 Wind River Systems, Inc.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License"); 
 * you may not use this file except in compliance with the License. 
 * You may obtain a copy of the License at 
 * 
 * http://www.apache.org/licenses/LICENSE-2.0 
 * 
 * Unless required by applicable law or agreed to in writing, software distributed 
 * under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES 
 * OR CONDITIONS OF ANY KIND, either express or implied. See the License for
 * the specific language governing permissions and limitations under the License. 
 */

#include "Serial.h"
#include "BluemixRocketClient.h"

#define BLUEMIX_QUICKSTART

#ifndef BLUEMIX_QUICKSTART    

#undef DEVICE_TYPE
#undef ORGANIZATION_ID 
#undef TOKEN

#ifndef DEVICE_TYPE
  #error The device type macro must be initialized for Bluemix Registered mode
#endif 
  
#ifndef ORGANIZATION_ID
  #error The organization id  macro must be initialized for Bluemix Registered mode
#endif
  
#ifndef TOKEN
  #error The token macro must be initialized for Bluemix Registered mode
#endif
    
#endif

#define PUB_WAIT_COUNT 20


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

Datapoint* datapoints[] = { &os, &board, &temp, };

int temp_input = A0;
int pubCount = 0;
const int B = 3975;
int input = 0;
float resistance;

#ifdef BLUEMIX_QUICKSTART
BluemixRocketClientClass BluemixClient;
#else

void MQTTMessageReceived(char* topic, byte* payload, unsigned int length) {
    Serial.print("Rocket received message  [");
    Serial.print(topic);
    Serial.print("] ");
  
    for (int i=0;i<length;i++) {
        Serial.print((char)payload[i]);
    }
  Serial.println(); 
}

BluemixRocketClientClass BluemixClient(DEVICE_TYPE, ORGANIZATION_ID, TOKEN, MQTTMessageReceived);
#endif


void setup() {
    pinMode(temp_input, INPUT);  
}

void loop() {    
    if (!BluemixClient.connected()) {
        if (!BluemixClient.connect()) {
            Serial.println("Connection Failed");
        } else {
            Serial.println("Connected");
        }
    } else {
        if (pubCount < PUB_WAIT_COUNT) {
             pubCount++;
        } else {
            pubCount = 0;
            
            input = analogRead(temp_input);
            resistance = (10230000 - (input * 10000)) / input;
            temperature = 1 / ( log(resistance/10000) / B + (1/298.15)) - 273.15;
            
            if (BluemixClient.publish(datapoints, 3)) {
                Serial.println("Publishing Failed");
            }
        }
    }
  delay(100);
}
