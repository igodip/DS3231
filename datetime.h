#ifndef _DATE_TIME_H
#define _DATE_TIME_H

//Date class
class Date {
public:
	uint8_t dayOfWeek;
	uint8_t day;
	uint8_t month;
	uint16_t year;
	
};

//Time class
class Time {
public:
	uint8_t seconds;
	uint8_t minutes;
	uint8_t hours;
};

//DateTime class
class DateTime : public Time, public Date{
  
};

#endif
