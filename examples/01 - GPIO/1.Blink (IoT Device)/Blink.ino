#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiAP.h>
#include <WebServer.h>

void setup() {
  /* setup code */
  pinMode(23, OUTPUT);
  digitalWrite(23, 0);

  /* block setup */
  pinMode(22, OUTPUT);
}

void loop() {
  /* loop code */
  digitalWrite(22, 1);
  delay(1000);
  digitalWrite(22, 0);
  delay(1000);

  /* block loop */
}
