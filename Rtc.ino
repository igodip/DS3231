#include <Wire.h>
#include <I2Cdev.h>
#include "ds3231.h"

DS3231 rtc;
uint8_t buffer[8];

void setup() {
  
  Serial.begin(9600);
  Wire.begin();


  memset(buffer,0,8);
  
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
