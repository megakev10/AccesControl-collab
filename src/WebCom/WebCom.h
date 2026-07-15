#ifndef WebCom_H
#define WebCom_H

#include <Arduino.h>

class WebCom{
    public:
        void init();
        void send_event(String ev);
    private:
        const char* WiFi_ssid = "Mega-Digi-2.4";
        const char* WiFi_password = "Mega.Guest.Doul.1";
        String url = "http://192.168.10.136:8000/api/fingerprint-log";
        String event;
};
#endif