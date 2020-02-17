#ifndef MQTTCLIENT_H

#define MQTTCLIENT_H

// This method initialization MQTT. 
void mqttClient_init(char* mqtt_server, uint16_t port);

// This method will reconnect to Broker MQTT.
void reConnect();

// This method will check is connected to Broker
void isConnectedToTopic();

/**
 * This method handle publish data to topic
 * @param Topic
 * @param Data
*/
void handlePublishData(char *topic, float data);

/**
 * This method handle subscribe data to topic
 * @param Topic
 * @param Data
*/
void handleSubscribeData();

/**
 * This method handle callback from topic
 * @param Topic
*/
void handleCallBack(char* topic, byte *payload, unsigned int length);

#endif /* MQTTCLIENT_H */