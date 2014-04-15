/* ============================================
DS3231 device library code is placed under the MIT license
Copyright (c) 2014 Di Paolo Igor

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
===============================================
*/
#include <Wire.h>
#include <I2Cdev.h>

#include "ds3231.h"

//Constructors
DS3231::DS3231(){
	this->devAddr = DS3231_I2C_ADDR;
}

DS3231::DS3231(uint8_t address){
	this->devAddr = address;
}

//Init
void DS3231::initialize(){
	mode12= getMode12();
}

bool DS3231::testConnection() {
  return true;

}

//Hours Mode 12
uint8_t DS3231::getMode12() {
  I2Cdev::readBit(devAddr, DS3231_RA_HOURS, DS3231_HOURS_MODE_BIT,(uint8_t*) buffer);
  return buffer[0];
}

void DS3231::setMode12(uint8_t mode) {
  I2Cdev::writeBit(devAddr, DS3231_RA_HOURS, DS3231_HOURS_MODE_BIT, mode12);

}

//Seconds
uint8_t DS3231::getSeconds(){
  
    I2Cdev::readByte(devAddr, DS3231_RA_SECONDS,(uint8_t*) buffer);
    
    return (buffer[0] & 0xF) + ((buffer[0] &0x70) >> 4)*10;
  
}

void DS3231::setSeconds(uint8_t second){
	
	//I2Cdev::writeByte(devAddr,DS3231_RA_

}

//Minutes
uint8_t DS3231::getMinutes() {
	I2Cdev::readByte(devAddr,DS3231_RA_MINUTES,buffer);
	//BCD 
	return (buffer[0] & 0xF) + ((buffer[0] & 0x70)>>4)*10;
  
}

void DS3231::setMinutes(uint8_t minutes){
	
	//I2C
}

//Hours
uint8_t DS3231::getHours12() {
  I2Cdev::readByte(devAddr, DS3231_RA_HOURS,buffer);
  return (buffer[0] & 0xF) + ((buffer[0] & 0x10) >> 4)*10;
  
}

//Day
uint8_t DS3231::getDayOfWeek() {
	I2Cdev::readByte(devAddr,DS3231_RA_DAY,buffer);
	return (buffer[0] & 0x7);
}

void DS3231::setDayOfWeek(uint8_t day){

	day = day & 0x7;
	I2Cdev::writeByte(devAddr,DS3231_RA_DAY,day);

}

//Month
uint8_t DS3231::getMonth() {
  I2Cdev::readByte(devAddr,DS3231_RA_MONTH,buffer);
  
  return (buffer[0] & 0xF) + ((buffer[0] & 0x10)>> 4)*10;
  
}

void DS3231::setMonth(uint8_t month) {
	
	I2Cdev::writeByte(devAddr,DS3231_RA_MONTH,month);

}

//Year 


//DateTime

DateTime DS3231::getDateTime() {

	DateTime t;
	
	I2Cdev::readBytes(devAddr,DS3231_TIME_CAL_ADDR,7,buffer);

	t.seconds = BCD2DEC(buffer[0] & DS3231_SECONDS_MASK);
	t.minutes = BCD2DEC(buffer[1] & DS3231_MINUTES_MASK);
	//TODO: :O see doc
	t.hours = BCD2DEC(buffer[2] & 0x7F);

	//TODO: :O see doc
	t.dayOfWeek = buffer[3] & 0x7;

	t.day = BCD2DEC(buffer[4] & 0x3F);
	t.month = BCD2DEC(buffer[5] & 0x1F);
	t.year = BCD2DEC(buffer[6]);

	return t;


}

void DS3231::setDateTime(const DateTime & dateTime) {
	


}