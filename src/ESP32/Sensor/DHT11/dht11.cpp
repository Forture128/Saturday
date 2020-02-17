#include <Arduino.h>
#include <DHT.h>
#include "dht11.h"

#define PINDHT 26
#define DHTTYPE DHT11

float value_humidity_esp32 = 0;
float value_temperature_esp32 = 0;
float value_heatIndex_esp32 = 0;

DHT dht(PINDHT, DHTTYPE);

void esp32DHT11_init()
{
    dht.begin();
}

boolean checkValueNotNull(float param)
{
    if (isnan(param) && param == 0)
    {
        Serial.print(param);
        Serial.print(" is 0 or Nan");
        return false;
    }
    return true;
}

float getTempDHT11()
{
    value_temperature_esp32 = dht.readTemperature(false);
    if (checkValueNotNull(value_temperature_esp32))
    {
        return value_temperature_esp32;
    }
    return value_temperature_esp32;
}

float getHumiDHT11()
{
    value_humidity_esp32 = dht.readTemperature(false);
    if (checkValueNotNull(value_humidity_esp32))
    {
        return value_humidity_esp32;
    }
    return value_humidity_esp32;
}

float getHeatDHT11()
{
    value_heatIndex_esp32 = dht.computeHeatIndex(value_temperature_esp32, value_temperature_esp32, false);
    if (checkValueNotNull(value_heatIndex_esp32))
    {
        return value_heatIndex_esp32;
    }
    return value_heatIndex_esp32;
}
