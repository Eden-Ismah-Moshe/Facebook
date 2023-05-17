#pragma warning(disable: 4996)
#include <iostream>
using namespace std;

#include "Status.h"
#include "Date.h"
#include "Time.h"
#include "Exception.h"

Status::Status(const Date& date, const Time& time, string text) :date(date), time(time)//Constructor
{
	if (text.size() == 0)
		throw NameException();
	this->text = text;
}
Status::Status(const Status& other) : date(other.date), time(other.time)
{
	this->text = other.text;
}
Status::Status(const Status&& other) : date(other.date), time(other.time)
{
	this->text = std::move(other.text);
}
ostream& operator<<(ostream& os, const Status& other)
{
	os << "\n************************************";
	os << "\nDate: " << other.date << " Time: " << other.time;
	os << "\nText: " << other.text << endl;
	cout << "************************************" << endl << endl;
	return os;
}

bool Status::operator==(const Status& other)
{
	return (text.compare(other.text) == 0);
}

bool Status::operator!=(const Status& other)
{
	return !(*this == other);
}


void Status::operator=(const Status& other)
{
	if (this != &other)
	{
		text = other.text;
		date = other.date;
		time = other.time;
	}

}