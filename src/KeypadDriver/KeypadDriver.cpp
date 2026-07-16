#include <Arduino.h>
#include <Keypad.h>
#include "KeypadDriver.h"

int KeypadDriver::getxtestPin(){
  
  for(int i=0; i<5;){
    char customKey = keypad.getKey();
    if (customKey){
      Serial.print(customKey);
      code[i] = customKey; 
      i++;
    }
  }
  code[5] = '\0';
  char accessKey [6]= "12345";
  return (strcmp(code, accessKey));
}

