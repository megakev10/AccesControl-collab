#include <Arduino.h>
#include "Notification.h"

void Notification::Succesnotification(){
  for(int j = 0; j < 2; j++){
        digitalWrite(notif_pin,1);
        delay(200);
        digitalWrite(notif_pin, 0);
        delay(200);  
    }
}

void Notification::failnotification(){
    for(int i=0; i<3; i++){
        digitalWrite(notif_pin,1);
        delay(500);
        digitalWrite(notif_pin,0);
        delay(500);
    }
}