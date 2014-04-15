#ifndef _DATE_TIME_H
#define _DATE_TIME_H


class Date {
public:
	uint8_t dayOfWeek;
	uint8_t day;
	uint8_t month;
	uint16_t year;
	
};

class Time {
public:
	uint8_t seconds;
	uint8_t minutes;
	uint8_t hours;
};


class DateTime : public Time, public Date{
  
};

#endif
