#include <Wire.h>
#include <I2Cdev.h>
#include "ds3231.h"

DS3231 rtc;

void setup() {
  
  Serial.begin(9600);
  Wire.begin();
  
//  DateTime dateTime;
  
//  dateTime.seconds = 0;
//  dateTime.minutes = 55;
//  dateTime.hours = 0;
//  dateTime.dayOfWeek=4;
//  dateTime.day = 17;
//  dateTime.month = 4;
//  dateTime.year = 2014;
  
//  rtc.setDateTime(dateTime);
	
  
}


void loop() {
  
  
  DateTime dateTime = rtc.getDateTime();

  Serial.println("-------------------");
  Serial.print(dateTime.hours);
  Serial.print(":");
  Serial.print(dateTime.minutes);
  Serial.print(":");
  Serial.println(dateTime.seconds);
  Serial.print(dateTime.day);
  Serial.print("/");
  Serial.print(dateTime.month);
  Serial.print("/");
  Serial.println(dateTime.year);
  
  delay(5000);
  
}
