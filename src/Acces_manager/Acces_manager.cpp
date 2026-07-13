#include "Acces_manager.h"

    fingerprintDriver f;
    User_manager u;
    Preferences p;
    TimeService t;
    KeypadDriver k;
    WebCom w;

    void Acces_manager::init(){
        f.init();
        t.init();
    }

    void Acces_manager::enrollProtocol(){
        Serial.println("Ready to enroll a fingerprint!");
        Serial.println("Please type in the ID # (from 1 to 127) you want to save "
                      "this finger as...");
        uint8_t id = f.readID();
        Serial.println("Please enter the name of the user concernate");
        u.names_array[id] = u.take_name(id);
        u.save_name();
        Serial.printf("Enrolling ID%u\n",id);

        while (!f.getFingerprintEnroll(id))
            delay(2000); 
            ;

    }

    void Acces_manager::BiometricalAuth(){
        Serial.println("please place your finger on the sensor");
        uint8_t INDEX = f.getFingerprintID();
        if (INDEX != 200){
            p.begin("users_infos", false);
                p.getBytes("names", &u.names_array, sizeof(u.names_array));
                Serial.print("Bienvenue ");
                Serial.println(u.names_array[INDEX]);
            p.end();
            Serial.println(t.getDate());    
        }
        delay(5000);  
    }

    void Acces_manager::PinAuth(){
        Serial.println("Please enter your digicode");
        while(Serial.available())
        ;
        if(k.getxtestPin()){
            Serial.println("Acces granted");
        }else{
            Serial.println("Acces refused");
        }
        Serial.println(k.getxtestPin());
        delay(5000);
    }

    void Acces_manager::web(){
        w.init();
        String event = w.construct_event("kevin", 12, "13/07/2026","granted", "fingerprint");
        w.send_event(event);
    }