#ifndef __EXCEPTION
#define __EXCEPTION

#include <iostream>


class DayException : public std::exception
{
public:

	virtual const char* what() const override
	{
		return "Failed because you enter invalid day!\n";
	}
};

class MonthException : public std::exception
{
public:

	virtual const char* what() const override
	{
		return "Failed because you enter invalid month!\n";
	}
};

class YearException : public std::exception
{
public:

	virtual const char* what() const override
	{
		return "Failed because you enter invalid year!\n";
	}

};

class NameException : public std::exception
{
public:

	virtual const char* what() const override
	{
		return "Failed while create the name!, name can't be empty\n";
	}

};

class HourException : public std::exception
{
public:

	virtual const char* what() const override
	{
		return "Failed because you enter invalid hour value!\n";
	}

};

class MinutesException : public std::exception
{
public:

	virtual const char* what() const override
	{
		return "Failed because you enter invalid minutes value!\n";
	}

};


#endif
