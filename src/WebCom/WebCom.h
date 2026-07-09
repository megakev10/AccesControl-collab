#ifndef WebCom_H
#define WebCom_H

class WebCom{
    public:
        void init();
        String construct_event(String name, uint8_t id, String date, String Status, String method);
        void send_event();
    private:
        const char* WiFi_ssid = " ";
        const char* WiFi_password = " ";
        String url = " ";
        String event = " ";
};
#endif