#include <Arduino.h>
#include <Keypad.h>
#include "KeypadDriver.h"

int KeypadDriver::getxtestPin(){

  Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
  
  for(int i=0; i<6; i++){
    char customKey = keypad.getKey();
    if (customKey){
      Serial.print(customKey);
      code[i] = customKey; 
    }
  }
  char accessKey [6]= "12345";
  return (strcmp(code, accessKey));
}

