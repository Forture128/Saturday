#include <Arduino.h>
#include <PubSubClient.h>
#include <WiFi.h>
#include "mqttClient.h"

WiFiClient esp32Client;
PubSubClient client(esp32Client);



void handleCallBack(char *topic, byte *payload, unsigned int length)
{
  Serial.print("Message arrived on topic: ");
  Serial.print(topic);
  Serial.print(". Message: ");
  String messageTemp;
  for (int i = 0; i < length; i++)
  {
    messageTemp += (char)payload[i];
  }
  Serial.print(messageTemp);
}

void mqttClient_init(char *mqtt_server, uint16_t port)
{
  client.setServer(mqtt_server, port);
  client.setCallback(handleCallBack);
}

void reConnect()
{
  // Condition check
  while (!client.connected())
  {
    Serial.print("Attempting connect to MQTT");
    Serial.print("\n");
    // Attemp connect
    if (client.connect("ESP32Client"))
    {
      Serial.print("Connected");
      client.subscribe("esp32/dht11/output");
    }
    else
    {
      Serial.print("Failed, rc=");
      Serial.print(client.state());
      Serial.print(" Try to connect in 5 seconds");
      delay(500);
    }
  }
}

// This function handle send data from ESP32 to broker
void handlePublishData(char *topic, float data)
{
  char temperaturStr[10];
  dtostrf(data, 1, 2, temperaturStr); // convert data from float to string.
  String topicStr;
  client.publish(topic, temperaturStr);
}

void isConnectedToTopic()
{
  delay(5000);
  if (!client.connected())
  {
    reConnect();
  }
  client.loop();
}