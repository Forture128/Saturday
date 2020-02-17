#include <Arduino.h>
#include <WiFi.h>
#include "wifiEsp32.h"

const char* ssid = "Phuc";
const char* password = "06072015";


void setup_wifi() {
    delay(10);
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED)
    {
      delay(500);
      Serial.print(".");
    }
    
    Serial.println("");
    Serial.println("Wifi connected ");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
}
