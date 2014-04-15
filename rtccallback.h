#ifndef _RTC_CALLBACK
#define _RTC_CALLBACK

//Callback used for interrupt events
class RtcCallback {
	
	virtual void callback() = 0;
	
};

#endif
