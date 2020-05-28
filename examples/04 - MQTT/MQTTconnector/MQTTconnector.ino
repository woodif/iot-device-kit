#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiAP.h>
#include <WebServer.h>

#include "MQTT.h"
#include "MqttConnector.h"
#include "PubSubClient.h"

int cmd;
int relayPin = 15;
int relayPinState = HIGH;
int LED_PIN = 18;
static char myName[80];
String DEVICE_NAME = "KB-001";
String MQTT_HOST = "mqtt.cmmc.io";
String MQTT_USERNAME = "";
String MQTT_PASSWORD = "";
String MQTT_CLIENT_ID = "";
String MQTT_PREFIX = "KBIDE/";
int MQTT_PORT = 1883;
int PUBLISH_EVERY = 10 * 1000;
int MQTT_CONNECT_TIMEOUT = 10;

MqttConnector *mqtt;

void setup() {
  /* setup code */
  pinMode(23, OUTPUT);
  digitalWrite(23, 0);

  /* block setup */
  Serial.begin(115200);
  WiFi.begin("ampere", "espertap");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

  strcpy(myName, DEVICE_NAME.c_str());
  mqtt = new MqttConnector(MQTT_HOST.c_str(), MQTT_PORT);
  mqtt->on_connecting([&](int counter, bool *flag) {
    if (counter >= MQTT_CONNECT_TIMEOUT) {
      ESP.restart();
    }
    Serial.println("MQTT Connecting..");
  });

  mqtt->on_subscribe([&](MQTT::Subscribe *sub) -> void {
    Serial.printf("myName = %s \r\n", myName);
    String t1 = MQTT_PREFIX + myName + "/$/+";
    String t2 = MQTT_PREFIX + MQTT_CLIENT_ID + "/$/+";
    Serial.println("START TOPIC SUBS");
    Serial.println(t1);
    Serial.println(t2);
    Serial.println("DONE TOPIC SUBS");

    sub->add_topic(t1);
    sub->add_topic(t2);
  });

  mqtt->on_prepare_configuration([&](MqttConnector::Config *config) -> void {
    MQTT_CLIENT_ID = String(WiFi.macAddress());
    config->clientId = MQTT_CLIENT_ID;
    config->channelPrefix = MQTT_PREFIX;
    config->enableLastWill = true;
    config->retainPublishMessage = false;
    /*
        config->mode
        ===================
        | MODE_BOTH       |
        | MODE_PUB_ONLY   |
        | MODE_SUB_ONLY   |
        ===================
    */
    config->mode = MODE_BOTH;
    config->firstCapChannel = false;

    config->username = String(MQTT_USERNAME);
    config->password = String(MQTT_PASSWORD);

    // FORMAT
    // d:quickstart:<type-id>:<device-id>
    // config->clientId  = String("d:quickstart:esp8266meetup:") + macAddr;
    config->topicPub = MQTT_PREFIX + String(myName) + String("/status");
  });

  mqtt->on_after_prepare_configuration(
      [&](MqttConnector::Config config) -> void {});

  mqtt->on_after_message_arrived([&](String topic, String cmd, String payload) {
    if (cmd == String("Hello World!")) {
    }
  });

  mqtt->on_prepare_data(
      [&](JsonObject *root) {
        JsonObject &data = (*root)["d"];
        JsonObject &info = (*root)["info"];
        data["myName"] = myName;
        data["value1"] = String("Hello World!");
      },
      PUBLISH_EVERY);
  mqtt->connect();
}

void loop() {
  /* loop code */

  /* block loop */
  mqtt->loop();
}
