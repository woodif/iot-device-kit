#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiAP.h>
#include <WebServer.h>

#include "Servo.h"

Servo Servo1;

void setup() {
  /* setup code */
  pinMode(23, OUTPUT);
  digitalWrite(23, 0);

  /* block setup */
  Servo1.attach(13);
}

void loop() {
  /* loop code */
  Servo1.write(180);
  delay(1000);
  Servo1.write(0);
  delay(1000);

  /* block loop */
}
