#include <Wire.h>
#include <I2Cdev.h>
#include "ds3231.h"

DS3231 rtc;
uint8_t buffer[8];

void setup() {
  
  Serial.begin(9600);
  Wire.begin();
  //I2Cdev::writeByte(0x68,0x0E,0x4);
  memset(buffer,0,8);
  
}


void loop() {
  
//  Wire.beginTransmission(DS3231_I2C_ADDR);
//  Wire.write(DS3231_TIME_CAL_ADDR);
//  Wire.endTransmission();
//  
//  Wire.requestFrom(DS3231_I2C_ADDR,7);
//  
//  for(int i = 0; i < 7; i++){
//    Serial.println(Wire.read());
//  }
  
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
