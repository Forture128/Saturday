#ifndef ESP32_DHT11_H

#define ESP32_DHT11_H

// initialization dht11.
void esp32DHT11_init();

// get temparature from dht11
float getTempDHT11();

// get humidity from dht11
float getHumiDHT11();

// get heat from from dht11
float getHeatDHT11();

// this method check value of DHT11
boolean checkValueNotNull();

#endif