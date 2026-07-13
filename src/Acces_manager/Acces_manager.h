#ifndef Acces_manager_H
#define Acces_manager_H

#include <Arduino.h>
#include <Adafruit_Fingerprint.h>
#include <Preferences.h>
#include "../drivers/fingerprintDriver.h"
#include "../User_manager/User_manager.h"
#include "../TimeService/TimeService.h"
#include "../KeypadDriver/KeypadDriver.h"
#include "../WebCom/WebCom.h"

        

class Acces_manager{
    public:
        void enrollProtocol();
        void BiometricalAuth();
        void init();
        void PinAuth();
        void web();
    private:
        uint8_t INDEX = 0;
};
#endif