#include <Arduino.h>

#include "Core/Wifi/wifiEsp32.h"
#include "Core/MQTTClient/mqttClient.h"
#include "ESP32/Sensor/DHT11/dht11.h"
// #include "ESP32/Sensor/DS18B20/"

char* mqtt_server = "192.168.1.102";

char *temperatureTopic = "esp32/dht11/temperature";
char *humidityTopic = "esp32/dht11/humidity";
char *heatTopic = "esp32/dht11/heat";

void setup() {
  // CONFIG_MONITOR_BAUD = 115200
  Serial.begin(CONFIG_MONITOR_BAUD);

  // Connect to wifi
  setup_wifi();
  // Connect to broker
  mqttClient_init(mqtt_server, 1883);

  esp32DHT11_init();
}

void loop() {
  // put your main code here, to run repeatedly:
  isConnectedToTopic();
  handlePublishData(temperatureTopic, getTempDHT11());
  handlePublishData(humidityTopic, getHumiDHT11());
  handlePublishData(heatTopic, getHeatDHT11());
}