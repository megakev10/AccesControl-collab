#ifndef KeypadDriver_H
#define KeypadDriver_H

#include <Arduino.h>
#include <Keypad.h>

class KeypadDriver{
    public: 
        const byte ROWS = 4;
        const byte COLS = 4; 
        char keys[4][4] = {
        {'1','2','3','A'},
        {'4','5','6','B'},
        {'7','8','9','C'},
        {'*','0','#','D'}
        };
        byte rowPins[4] = {13, 12, 14, 27}; 
        byte colPins[4] = {26, 25, 33, 32}; 
        char code[6];
        Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
        int getxtestPin();
};

#endif