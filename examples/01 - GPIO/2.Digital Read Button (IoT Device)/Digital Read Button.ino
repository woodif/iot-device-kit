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
  Serial.begin(115200);
  pinMode(18, INPUT_PULLUP);
  pinMode(22, OUTPUT);
}

void loop() {
  /* loop code */
  Serial.println(digitalRead(18));
  if (digitalRead(18) == 0) {
    digitalWrite(22, 1);
  } else {
    digitalWrite(22, 0);
  }

  /* block loop */
}
