#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include "WebCom.h"


HTTPClient http;

void WebCom::init(){
    WiFi.mode(WIFI_STA);
    WiFi.begin(WiFi_ssid, WiFi_password);
    while (WiFi.status() != WL_CONNECTED){
        Serial.println("WiFi Connexion failed");
        delay(200);
    }
    Serial.println("WiFi Connection succeded");   
}

void WebCom::send_event(String ev){
    //if (WiFi.status() == WL_CONNECTED){
    http.begin(url); 
    http.addHeader("Content-Type", "application/json");
    int r = http.POST(ev);
    http.end();
    Serial.println(r);
    //}
}