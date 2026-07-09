#include <Arduino.h>
#include <Adafruit_Fingerprint.h>

#ifndef fingerprint_driver_H
#define fingerprint_driver_H

class fingerprintDriver{
    public:
        uint8_t getFingerprintEnroll(uint8_t id);
        uint8_t readID();
        uint8_t getFingerprintID();
        void init();
    private:
    
};
#endif
