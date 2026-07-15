#include <Arduino.h>
#include <Acces_manager/Acces_manager.h>

Acces_manager A;

void setup(){
    Serial.begin(115200);
    while (!Serial); 
    delay(200);
    A.init();
}

void loop(){
    //A.enrollProtocol();
    A.BiometricalAuth();
    //A.PinAuth();
   // A.web();
    delay(3000);
}