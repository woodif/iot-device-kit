#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiAP.h>
#include <WebServer.h>

#include "Adafruit_NeoPixel.h"

Number delayTime;
#define PIN 4
#define NUMPIXELS 3
Adafruit_NeoPixel pixels =
    Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  /* setup code */
  pinMode(23, OUTPUT);
  digitalWrite(23, 0);
  pixels.begin();
  /* block setup */
  pixels.setBrightness(255);
  pixels.show();

  for (int clearPixel = 0; clearPixel < pixels.numPixels(); clearPixel++) {
    pixels.setPixelColor(clearPixel, pixels.Color(0, 0, 0));
    pixels.show();
  }
}

void loop() {
  /* loop code */
  delayTime = 1000;
  pixels.setPixelColor(0, pixels.Color(255, 0, 0));
  pixels.show();
  pixels.setPixelColor(1, pixels.Color(255, 0, 0));
  pixels.show();
  pixels.setPixelColor(2, pixels.Color(255, 0, 0));
  pixels.show();
  delay(delayTime);
  pixels.setPixelColor(0, pixels.Color(51, 255, 51));
  pixels.show();
  pixels.setPixelColor(1, pixels.Color(51, 255, 51));
  pixels.show();
  pixels.setPixelColor(2, pixels.Color(51, 255, 51));
  pixels.show();
  delay(delayTime);
  pixels.setPixelColor(0, pixels.Color(51, 51, 255));
  pixels.show();
  pixels.setPixelColor(1, pixels.Color(51, 51, 255));
  pixels.show();
  pixels.setPixelColor(2, pixels.Color(51, 51, 255));
  pixels.show();
  delay(delayTime);

  /* block loop */
}
