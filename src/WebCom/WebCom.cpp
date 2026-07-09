#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include "WebCom.h"

HTTPClient http;

void WebCom::init(){
    WiFi.begin(WiFi_ssid, WiFi_password);
    while (WiFi.status() != WL_CONNECTED){
        Serial.println("WiFi Connexion failed");
        delay(200);
    }
    Serial.println("WiFi Connection succeded");   
}

String WebCom::construct_event(String name, uint8_t id, String date, String Status, String method){
    event = "{";
    event += "\"name\" : \""+ name +"\",";
    event += "\"ID:\" : "+ String(id) +",";
    event += "\"date\" : \"" + date + "\",";
    event += "\"Status\" : \" granted \",";
    event += "\"method\" : \"" + method + "\",";
    event += "}";
} 

void WebCom::send_event(){
    http.begin(url); 
    http.addHeader("Content_Type", "application/json");
    http.POST(event);
}