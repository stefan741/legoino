/**
 * A Legoino example to control a control plus hub
 * with a Motor connected on Port D
 * 
 * (c) Copyright 2020 - Cornelius Munz
 * Released under MIT License
 * 
 */

#include "ControlPlusHub.h"

// create a hub instance
ControlPlusHub myHub;
ControlPlusHub::Port _port = ControlPlusHub::Port::D;

void setup() {
    Serial.begin(115200);
} 


// main loop
void loop() {

  if (!myHub.isConnected() && !myHub.isConnecting()) 
  {
    myHub.init(); 
  }

  // connect flow. Search for BLE services and try to connect if the uuid of the hub is found
  if (myHub.isConnecting()) {
    myHub.connectHub();
    if (myHub.isConnected()) {
      Serial.println("Connected to HUB");
    } else {
      Serial.println("Failed to connect to HUB");
    }
  }

  // if connected, you can set the name of the hub, the led color and shut it down
  if (myHub.isConnected()) {

    char hubName[] = "myControlPlusHub";
    myHub.setHubName(hubName);
  
    myHub.setLedColor(GREEN);
    delay(1000);
    myHub.setLedColor(RED);
    delay(1000);
    myHub.setMotorSpeed(_port, 35);
    delay(1000);
    myHub.stopMotor(_port);
    delay(1000);
    myHub.setMotorSpeed(_port, -35);
    delay(1000);
    myHub.stopMotor(_port);
    delay(1000);

  } else {
    Serial.println("ControlPlus hub is disconnected");
  }
  
} // End of loop
