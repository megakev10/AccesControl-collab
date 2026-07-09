#ifndef User_services_H
#define User_services_H

#include <Arduino.h>

class User_manager{
    public:
        String take_name(uint8_t index);
        void save_name();
        String names_array[129];
};

#endif