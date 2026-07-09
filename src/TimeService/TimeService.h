#ifndef TimeService_H
#define TimeService_H
#include <Arduino.h>
#include <RTClib.h>

class TimeService{
    public:
        void init();
        String getDate();
};

#endif