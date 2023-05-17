#pragma warning(disable: 4996)
#include <iostream>
using namespace std;

#include "Date.h"
#include "Exception.h"

Date::Date(int day, int month, int year)noexcept(false)//constructor
{
	if (day < 1 || day>31)
		throw DayException();
	if (month < 1 || month>12)
		throw MonthException();
	if (year < 0 || year > 2023)
		throw YearException();
	this->day = day;
	this->month = month;
	this->year = year;
}
ostream& operator<<(ostream& os, const Date& other)
{
	os << other.day << "/" << other.month << "/" << other.year;
	return os;
}