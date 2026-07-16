#include "Acces_manager.h"

    fingerprintDriver f;
    User_manager u;
    Preferences p;
    TimeService t;
    KeypadDriver k;
    WebCom w;
    StorageService s;

    void Acces_manager::init(){
        f.init();
        t.init();
        s.store_init();
        w.init();
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
            String d = t.getDate();
            Serial.println(d); 
            String e = s.construct_event(u.names_array[INDEX], INDEX, d, "granted", "fingerprint sensor");  
            w.send_event(e);
            if (!s.store_init()){
                Serial.println("Storage unavailable");
            }else{
                s.storeHistory(); 
            }
        }
        delay(5000);  
    }

    void Acces_manager::PinAuth(){
        Serial.println("Please enter your digicode");
        while(Serial.available())
        ;
        int result = k.getxtestPin();
        if(result == 0){
            Serial.println("-----Acces granted");
        }else{
            Serial.println("-----Acces refused");
        }
        Serial.println(result);
        delay(5000);
    }

    void Acces_manager::web(){

        w.send_event(s.getHistory());
    }

    void Acces_manager::Store(){

    }