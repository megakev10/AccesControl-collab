#ifndef StorageService_H
#define StorageService_H
#include <Arduino.h>

class StorageService{
    public:
    void store_init();
    String construct_event(String name, uint8_t id, String date, String Status, String method);
    void storeHistory();
    String getHistory();
    private:
        String event;
};

#endif