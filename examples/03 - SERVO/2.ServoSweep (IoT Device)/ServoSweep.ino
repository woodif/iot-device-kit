#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiAP.h>
#include <WebServer.h>

#include "Servo.h"

int i;
Servo Servo1;

void setup() {
  /* setup code */
  pinMode(23, OUTPUT);
  digitalWrite(23, 0);

  /* block setup */
  Serial.begin(115200);

  Servo1.attach(13);
}

void loop() {
  /* loop code */
  for (i = 0; i <= 180; i++) {
    Servo1.write(i);
    Serial.println(i);
    delay(20);
  }
  for (i = 180; i >= 0; i--) {
    Servo1.write(i);
    Serial.println(i);
    delay(20);
  }

  /* block loop */
}
