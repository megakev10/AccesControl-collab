#include <Arduino.h>
#include <LittleFS.h>
#include "StorageService.h"

void StorageService::store_init(){
    if (!LittleFS.begin(true)) {
        Serial.println("Fail to mount LittleFS");
    return;
    }
}

String StorageService::construct_event(String name, uint8_t id, String date, String Status, String method){
    event = "{";
    event += "\"name\" : \""+ name +"\",";
    event += "\"ID\" : "+ String(id) +",";
    event += "\"date\" : \"" + date + "\",";
    event += "\"Status\" : \" granted \",";
    event += "\"method\" : \"" + method + "\"";
    event += "}";
    Serial.println(event);
    return event;
}

void StorageService::storeHistory(){
    File file = LittleFS.open("/history.log", "a");
    if (!file) {
        Serial.println("Failed to open file for writing");
    return;
  }

  if (file.println(event)) {
    Serial.println("data stored");
  } else {
    Serial.println("storage failed");
  }
  file.close();
}

String StorageService::getHistory(){
    File file = LittleFS.open("/history.log", "r");
    String crash_message = "nothing in memory";
    String data;

    if (!file){
        Serial.println("fail to open the file");
    return crash_message;
    }
    while (file.available()){
        data = file.readStringUntil('\n');
        Serial.println(data);
    }
    
    file.close();
    return data;
}