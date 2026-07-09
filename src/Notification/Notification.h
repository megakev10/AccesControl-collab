#ifndef Notification_H
#define Notification_H
#include<Arduino.h>

class Notification{
    public:   
        void failnotification();
        void Succesnotification();
    private:
        int notif_pin =2;    
};

#endif