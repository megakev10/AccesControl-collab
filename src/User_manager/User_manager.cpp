#include <Arduino.h>
#include <Preferences.h>
#include "User_manager.h"

Preferences pref;

String User_manager::take_name(uint8_t index){
    while (!Serial.available()){}
    names_array[index] = Serial.readStringUntil('\n'); 
    return names_array[index];   
}

void User_manager::save_name(){
    pref.begin("users_infos", false);
        pref.putBytes("names", &names_array, sizeof(names_array));
        if(pref.isKey("names")){
          Serial.println("Your name is save with succes");
        }
    pref.end();
}