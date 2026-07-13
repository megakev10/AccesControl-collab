#ifndef WebCom_H
#define WebCom_H

#include <Arduino.h>

class WebCom{
    public:
        void init();
        String construct_event(String name, uint8_t id, String date, String Status, String method);
        void send_event(String ev);
    private:
        const char* WiFi_ssid = "Mega-Digi-5G";
        const char* WiFi_password = "Meg@-Ique.Doul.24";
        String url = "http://192.168.10.136:8000/api/fingerprint-log";
        String event;
};
#endif