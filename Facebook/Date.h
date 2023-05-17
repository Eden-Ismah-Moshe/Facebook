#ifndef __DATE
#define __DATE

#include <iostream> 
using namespace std;

class Date {
private:
	int day, month, year;
public:
	Date(int day, int month, int year)noexcept(false);//constructor
	friend ostream& operator<<(ostream& os, const Date& other);
};
#endif