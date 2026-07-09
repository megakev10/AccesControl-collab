#ifndef Acces_manager_H
#define Acces_manager_H

#include <Arduino.h>
#include <Adafruit_Fingerprint.h>
#include <Preferences.h>
#include "../drivers/fingerprintDriver.h"
#include "../User_manager/User_manager.h"
#include "../TimeService/TimeService.h"

        

class Acces_manager{
    public:
        void enrollProtocol();
        void BiometricalAuth();
        void init();
    private:
        uint8_t INDEX = 0;
};
#endif