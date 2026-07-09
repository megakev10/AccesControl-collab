/***************************************************
  This is an example sketch for our optical Fingerprint sensor

  Designed specifically to work with the Adafruit BMP085 Breakout
  ----> http://www.adafruit.com/products/751

  These displays use TTL Serial to communicate, 2 pins are required to
  interface
  Adafruit invests time and resources providing this open source code,
  please support Adafruit and open-source hardware by purchasing
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.
  Update by KUIJI Brice for Mega-Ique Digital SARL.
  BSD license, all text above must be included in any redistribution

 ****************************************************/

/*#include <Arduino.h>
#include <Adafruit_Fingerprint.h>
#include <Preferences.h>
#include <RTClib.h>
#include <Wire.h>
#include <LittleFS.h>


HardwareSerial mySerial(2);
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);

void succesalarm(int buzpin){
  for(int j = 0; j < 2; j++){
  digitalWrite(buzpin,1);
  delay(200);
  digitalWrite(buzpin,0);
  delay(200);
}}

void failalarm(int buzpin){
  for(int i=0; i<3; i++){
    digitalWrite(buzpin,1);
    delay(500);
    digitalWrite(buzpin,0);
    delay(500);
}}

uint8_t getFingerprintID() {
  uint8_t p = finger.getImage();
  switch (p) {
  case FINGERPRINT_OK:
    Serial.println("Image taken");
    break;
  case FINGERPRINT_NOFINGER:
    Serial.println("No finger detected");
    return p;
  case FINGERPRINT_PACKETRECIEVEERR:
    Serial.println("Communication error");
    return p;
  case FINGERPRINT_IMAGEFAIL:
    Serial.println("Imaging error");
    return p;
  default:
    Serial.println("Unknown error");
    return p;
  }

  // OK success!

  p = finger.image2Tz();
  switch (p) {
  case FINGERPRINT_OK:
    Serial.println("Image converted");
    break;
  case FINGERPRINT_IMAGEMESS:
    Serial.println("Image too messy");
    return p;
  case FINGERPRINT_PACKETRECIEVEERR:
    Serial.println("Communication error");
    return p;
  case FINGERPRINT_FEATUREFAIL:
    Serial.println("Could not find fingerprint features");
    return p;
  case FINGERPRINT_INVALIDIMAGE:
    Serial.println("Could not find fingerprint features");
    return p;
  default:
    Serial.println("Unknown error");
    return p;
  }

  // OK converted!
  p = finger.fingerSearch();
  if (p == FINGERPRINT_OK) {
    Serial.println("Found a print match!");
    succesalarm(2);
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    Serial.println("Communication error");
    return p;
  } else if (p == FINGERPRINT_NOTFOUND) {
    Serial.println("Did not find a match");
    failalarm(2);
    return p;
  } else {
    Serial.println("Unknown error");
    return p;
  }

  // found a match!
  Serial.print("Found ID #");
  Serial.print(finger.fingerID);
  Serial.print(" with confidence of ");
  Serial.println(finger.confidence);

  return finger.fingerID;
}

// returns -1 if failed, otherwise returns ID #
int getFingerprintIDez() {
  uint8_t p = finger.getImage();
  if (p != FINGERPRINT_OK)
    return -1;

  p = finger.image2Tz();
  if (p != FINGERPRINT_OK)
    return -1;

  p = finger.fingerFastSearch();
  if (p != FINGERPRINT_OK)
    return -1;

  // found a match!
  Serial.print("Found ID #");
  Serial.print(finger.fingerID);
  Serial.print(" with confidence of ");
  Serial.println(finger.confidence);
  return finger.fingerID;
}

RTC_DS3231 rtc;

Preferences pref;

class identification{
    public:
    void display_name(uint16_t index );
    void Save_time(uint16_t index);
    void historic(uint16_t index);
    private:
    String names_array[129];
};

void identification::display_name(uint16_t index){
    pref.begin("users_infos", false);
        pref.getBytes("names", &names_array, sizeof(names_array));
        Serial.print("Bienvenue ");
        Serial.println(names_array[index]);
    pref.end();
}*/

/*void identification::Save_time(uint16_t index){
    DateTime now = rtc.now();
    String moment = String(now.day())+"/"+String(now.month())+"/"+String(now.year())+" at "+String(now.hour())+":"+String(now.minute())+":"+String(now.second());
    String Key = "emp_"+String(index);
    pref.begin("Historique", false);
        pref.putString(Key.c_str(),moment);
    pref.end();
    Serial.println(moment);*/
  
    /*void identification::historic(uint16_t index){
    DateTime now = rtc.now();
    String moment = String(index)+"___"+String(now.day())+"/"+String(now.month())+"/"+String(now.year())+" at "+String(now.hour())+":"+String(now.minute())+":"+String(now.second());
    File myfile = LittleFS.open("/hist_log", FILE_WRITE);
    myfile.println(moment);
    myfile.close();
    Serial.println(moment);
}

identification identify;


void setup() {
  pinMode(2, OUTPUT);
  pinMode(15, OUTPUT);  
  Serial.begin(115200);
  Wire.begin();

  while (!Serial);

  delay(100);

  Serial.println("\n\nAdafruit Fingerprint sensor enrollment");

  mySerial.begin(57600,SERIAL_8N1,RX2,TX2);

  finger.begin(57600);

  Serial.println("UART2 configure");
  delay(5);
  if (finger.verifyPassword()) {
    Serial.println("Found fingerprint sensor!");
  } else {
    Serial.println("Did not find fingerprint sensor :(");
    while (1) {
      delay(1);
    }
  }

  Serial.println(F("Reading sensor parameters"));
  finger.getParameters();
  Serial.print(F("Status: 0x"));
  Serial.println(finger.status_reg, HEX);
  Serial.print(F("Sys ID: 0x"));
  Serial.println(finger.system_id, HEX);
  Serial.print(F("Capacity: "));
  Serial.println(finger.capacity);
  Serial.print(F("Security level: "));
  Serial.println(finger.security_level);
  Serial.print(F("Device address: "));
  Serial.println(finger.device_addr, HEX);
  Serial.print(F("Packet len: "));
  Serial.println(finger.packet_len);
  Serial.print(F("Baud rate: "));
  Serial.println(finger.baud_rate);

  finger.getTemplateCount();

  if (finger.templateCount == 0) {
    Serial.print("Sensor doesn't contain any fingerprint data. Please run the "
                 "'enroll' example.");
  } else {
    Serial.println("Waiting for valid finger...");
    Serial.print("Sensor contains ");
    Serial.print(finger.templateCount);
    Serial.println(" templates");
  }

   if (!rtc.begin()) {
    Serial.println("RTC non detecte !");
    while (1);
  }

  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));

  Serial.println("RTC detecte !");
}

void loop() // run over and over again
{
  getFingerprintID();
  Serial.println(finger.fingerID);
  if(finger.fingerID){
    identify.display_name(finger.fingerID);
    //identify.Save_time(finger.fingerID);
    identify.historic(finger.fingerID);
    finger.fingerID = 0;
  }else{
  delay(5000); // don't need to run this at full speed.
  }  
}*/