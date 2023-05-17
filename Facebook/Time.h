#ifndef __TIME
#define __TIME

class Time {
private:
	int hour, minute;
public:
	Time(int hour, int minute)noexcept(false);//constructor
	friend ostream& operator<<(ostream& os, const Time& other);

};
#endif