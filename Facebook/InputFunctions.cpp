

#include "InputFunctions.h"


User& InputFunctions::getNewUser()
{
	bool isValidData = false;
	User* member = nullptr;
	while (!isValidData)
	{
		string friend_name;
		cout << "Please enter Friend's name: ";
		cin >> friend_name;
		int day, month, year;
		char c_temp;//for read '/' in the date insert.
		cout << "Enter friend birth date (dd/mm/yyyy): ";
		cin >> day >> c_temp >> month >> c_temp >> year;

		try
		{
			Date new_date(day, month, year);
			member = new User(friend_name, new_date);
			isValidData = true;
		}
		catch (DayException& e) {
			cout << e.what() << endl;
		}
		catch (MonthException& e) {
			cout << e.what() << endl;
		}
		catch (YearException& e) {
			cout << e.what() << endl;
		}
		catch (NameException& e) {
			cout << e.what() << endl;
		}
		catch (...)
		{
			cout << "Unknown Error!" << endl;
		}
		if (!isValidData)
			cout << "\n--- You need to enter the data again ---\n";
	}
	return *member;
}

int InputFunctions::getValidMenuChoice(int maxNumber)
{
	int userChoice = 0;
	do
	{
		cout << endl << "Your Choice: ";
		cin >> userChoice;
		if (userChoice > maxNumber || userChoice < 1)
			cout << "\nInvalid Choice! Please choose again! \n" << endl;
	} while (userChoice > maxNumber || userChoice < 1);
	cin.ignore();
	return userChoice;
}

FanPage& InputFunctions::getNewFanPage()
{
	bool isValidData = false;
	FanPage* page = nullptr;
	while (!isValidData)
	{
		string page_name;
		cout << "Please enter Page's name: ";
		cin >> page_name;
		try
		{
			page = new FanPage(page_name);
			isValidData = true;
		}
		catch (NameException& e) {
			cout << e.what() << endl;
		}
		catch (...)
		{
			cout << "Unknown Error!" << endl;
		}
		if (!isValidData)
			cout << "\n--- You need to enter the data again ---\n";
	}
	return *page;
}

Status& InputFunctions::getNewStatus()
{
	Status* status = nullptr;
	int day, month, year, minutes, hours;
	char c_temp;
	bool isValidData = false;
	string text;
	while (!isValidData)
	{
		try
		{
			cout << "Enter Status date (dd/mm/yyyy): ";
			cin >> day >> c_temp >> month >> c_temp >> year;
			Date new_date(day, month, year);
			cout << "Enter Time (HH:MM): ";
			cin >> hours >> c_temp >> minutes;
			Time new_time(hours, minutes);
			cout << "Enter your status: ";
			cin.ignore();
			getline(cin, text);
			status = new Status(new_date, new_time, text);
			isValidData = true;
		}
		catch (DayException& e) {
			cout << e.what() << endl;
		}
		catch (MonthException& e) {
			cout << e.what() << endl;
		}
		catch (YearException& e) {
			cout << e.what() << endl;
		}
		catch (HourException& e) {
			cout << e.what() << endl;
		}
		catch (MinutesException& e) {
			cout << e.what() << endl;
		}
		catch (NameException& e) {
			cout << e.what() << endl;
		}
		catch (...)
		{
			cout << "Unknown Error!" << endl;
		}
		if (!isValidData)
			cout << "\n--- You need to enter the data again ---\n";
	}
	return *status;
}

string InputFunctions::getMemeberName()
{
	string member_name;
	cout << "Please enter Member's name: ";
	cin >> member_name;
	while ((member_name).size() == 0)
	{
		cout << "Failed while create the name!, name can't be empty" << endl;
		cout << "Please enter Member's name: ";
		cin >> member_name;
	}
	return member_name;
}

string InputFunctions::getPageName()
{
	string page_name;
	cout << "Please enter Page's name: ";
	cin >> page_name;

	while (page_name.size() == 0)
	{
		cout << "Failed while create the name!, name can't be empty" << endl;
		cout << "Please enter Page's name: ";
		cin >> page_name;
	}
	return page_name;
}