#include <Arduino.h>
# include "TimeService.h"

RTC_DS3231 rtc;

void TimeService::init(){
    if (!rtc.begin()) {
        Serial.println("RTC non detecte !");
        while (1);
  }

  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));

  Serial.println("RTC detecte !");
}

String TimeService::getDate(){
    DateTime now = rtc.now();
    String moment = String(now.day())+"/"+String(now.month())+"/"+String(now.year())+" at "+String(now.hour())+":"+String(now.minute())+":"+String(now.second());
    return moment;
}
