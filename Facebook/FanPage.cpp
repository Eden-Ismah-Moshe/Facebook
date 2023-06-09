#pragma warning(disable: 4996)
#include <iostream>
using namespace std;

#include "FanPage.h"
#include "User.h"

FanPage::FanPage(const string& name)noexcept(false)
{//Constructor
	if (name.size() == 0)
		throw NameException();
	this->name = name;
}

FanPage::FanPage(const FanPage& other)noexcept(false)
{
	if (other.name.size() == 0)
		throw NameException();
	name = other.name;
	friendsList = other.friendsList;
	statusBoard = other.statusBoard;
}

FanPage::FanPage(const FanPage&& other)noexcept(false)
{
	if (other.name.size() == 0)
		throw NameException();
	this->name = std::move(other.name);
	friendsList = other.friendsList;
	statusBoard = std::move(other.statusBoard);
}


const string& FanPage::getName() const
{
	return name;
}

int FanPage::getFriendsListSize()const
{
	return friendsList.size();
}

void FanPage::insert_new_status(const Status& requsted_status)
{//This function insert new status in to statusBoard array.

	statusBoard.push_back(requsted_status);
}

void FanPage::print_fanPage(int option) const
{//This function print statuses of fanPage.

	if (statusBoard.size() > 0)
	{
		list<Status>::const_iterator itr = statusBoard.begin();
		list<Status>::const_iterator itrEnd = statusBoard.end();
		int counter = 0;
		for (; itr != itrEnd; ++itr)
		{

			if (option == User::SHOW_10_STATUSES && counter > 9)
				break;
			cout << *itr;
			counter++;
		}
	}
	else
		cout << "\nThe page " << name << " has no any existing statuses yet.";
}

bool FanPage::is_connected_exist(User& member) const
{//This function check if there is connection between member and page and return true if there is, and flase else.

	string temp_name;
	vector<User*>::const_iterator itr = friendsList.begin();
	vector<User*>::const_iterator itrEnd = friendsList.end();

	for (; itr != itrEnd; ++itr)
	{
		temp_name = (*itr)->getName();
		if (member.getName().compare(temp_name) == 0)
			return true;
	}
	return false;
}

int  FanPage::find_friend_ind(User& member) const
{//This function find the index of the requested friend in the friends list.
//The friend is definitely on the array because there was check before.

	string current_name;
	vector<User*>::const_iterator itr = friendsList.begin();
	vector<User*>::const_iterator itrEnd = friendsList.end();
	int counter = 0;

	for (; itr != itrEnd; ++itr)
	{
		current_name = (*itr)->getName();
		if (member.getName().compare(current_name) == 0)
		{
			return counter;
		}
		counter++;
	}
	return User::NOT_FOUND;
}

bool FanPage::removeMember(User* member)
{//This function remove connection between member and fanPage.

	if (is_connected_exist(*member))
	{
		vector<User*>::iterator itr = friendsList.begin();
		int ind = find_friend_ind(*member);
		friendsList.erase(itr + ind);
		member->removeFanPage(this);
		return true;
	}
	return false;
}

const FanPage& FanPage::operator+=(User& other)
{//This function add friend to the friendsList of fanpage.
	if (!is_connected_exist(other))
	{
		friendsList.push_back(&other);
		other += (*this);
	}
	return *this;
}

bool FanPage::operator>(const FanPage& other)const
{//This function compare between the amount of friends of fanpages.
	return this->friendsList.size() > other.friendsList.size();
}

bool FanPage::operator>(const User& other)const
{//This function compare between the amount of friends of fanpage and user.
	return this->friendsList.size() > other.getFriendsListSize();
}

ostream& operator<<(ostream& os, const FanPage& page)
{//This function print the friends list of fanpage.
	if (page.friendsList.size() == 0)
		os << "\nThe page " << page.name << " doesn't have friends" << endl;
	else
	{
		vector<User*>::const_iterator trU = page.friendsList.begin();
		vector<User*>::const_iterator trUend = page.friendsList.end();
		os << "\nThese are all the friends of " << page.name << ":";
		for (; trU != trUend; ++trU) {
			os << "\n\n***********************************";
			os << "\n Name's friend: " << (*(trU))->getName() << "\n Birth date: " << (*(trU))->getBirthdate();
			os << "\n***********************************";
		}
	}
	return os;
}
