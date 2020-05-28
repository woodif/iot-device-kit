#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiAP.h>
#include <WebServer.h>

#include "Adafruit_NeoPixel.h"

#define PIN            4
#define NUMPIXELS      3
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
uint32_t Wheel(byte WheelPos) {WheelPos = 255 - WheelPos;
if (WheelPos < 85) {return pixels.Color(255 - WheelPos * 3, 0, WheelPos * 3);}
if (WheelPos < 170) {WheelPos -= 85;return pixels.Color(0, WheelPos * 3, 255 - WheelPos * 3);}
WheelPos -= 170; return pixels.Color(WheelPos * 3, 255 - WheelPos * 3, 0);}



void setup()
{
    /* setup code */
    pinMode(23, OUTPUT);
    digitalWrite(23, 0);
pixels.begin();
    /* block setup */
pixels.setBrightness(255);
    pixels.show();

    for(int clearPixel = 0; clearPixel < pixels.numPixels(); clearPixel++) {
      pixels.setPixelColor(clearPixel, pixels.Color(0,0,0));
      pixels.show();
    }
}

void loop()
{
  /* loop code */
      uint16_t i, j;
    for (j = 0; j < 256; j++) {
      for (i = 0; i < pixels.numPixels(); i++) {
        pixels.setPixelColor(i, Wheel((i + j) & 255));
      }
      pixels.show();
      delay(20);
    }

  /* block loop */
  
}
