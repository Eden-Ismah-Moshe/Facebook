#ifndef __STATUS
#define __STATUS

#include "Time.h"
#include "Date.h"
#include <string>

class Status
{
private:
	string text;//use of string library so need to implement distractor
	Date date;
	Time time;
public:
	Status(const Date& date, const Time& time, string text);//Constructor
	Status(const Status& other);//Copy constructor
	Status(const Status&& other);
	friend ostream& operator<<(ostream& os, const Status& other);
	bool operator==(const Status& other);
	bool operator!=(const Status& other);
	void operator=(const Status& other);
};
#endif