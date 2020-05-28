#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiAP.h>
#include <WebServer.h>

${EXTINC}

${VARIABLE}

${FUNCTION}

void setup()
{
    /* setup code */
    pinMode(23, OUTPUT);
    digitalWrite(23, 0);
${SETUP_CODE}
    /* block setup */
${BLOCKSETUP}
}

void loop()
{
  /* loop code */
  ${LOOP_CODE}
  /* block loop */
  ${LOOP_EXT_CODE}
}
