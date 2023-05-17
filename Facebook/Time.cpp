#pragma warning(disable: 4996)
#include <iostream>
using namespace std;

#include "Time.h"
#include "Exception.h"

Time::Time(int hour, int minute)noexcept(false)//Constructor
{
	if (hour < 0 || hour>23)
		throw HourException();
	if (minute < 0 || minute>59)
		throw MinutesException();
	this->hour = hour;
	this->minute = minute;
}

ostream& operator<<(ostream& os, const Time& other)
{
	cout << other.hour << ":" << other.minute;
	return os;
}