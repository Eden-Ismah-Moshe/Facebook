#pragma warning(disable: 4996)
#include <iostream>
using namespace std;

#include "User.h"
#include "Exception.h"

User::User(const string& name, const Date& birthDate) :birthDate(birthDate)//BASIC CREATION-Constructor
{
	if (name.size() == 0)
		throw NameException();
	this->name = name;
}

User::User(const User& other) : birthDate(other.birthDate)
{
	if (other.name.size() == 0)
		throw NameException();
	this->name = other.name;
	friendsList = other.friendsList;
	statusBoard = other.statusBoard;
	followerPages = other.followerPages;
}

User::User(const User&& other)noexcept(false) : birthDate(other.birthDate)
{
	if (other.name.size() == 0)
		throw NameException();
	this->name = std::move(other.name);
	friendsList = other.friendsList;
	statusBoard = std::move(other.statusBoard);
	followerPages = other.followerPages;
}


const string User::getName() const
{
	return name;
}

const Date& User::getBirthdate()const
{
	return birthDate;
}

int User::getFriendsListSize()const
{
	return friendsList.size();
}

void User::add_status(const Status& newData)
{//This function add status to status board of member.
	insert_new_status(newData);
}

void User::insert_new_status(const Status& requsted_status)
{//This function insert new status in to statusBoard array.

	statusBoard.push_back(requsted_status);
}

void User::print_statuses(int option) const
{//This function get intger that say if print all the statuses of member or that the first 10.
	int length = statusBoard.size();
	if (length > 0)
	{
		list<Status>::const_iterator trS = statusBoard.begin();
		list<Status>::const_iterator trSend = statusBoard.end();
		for (int i = 0; trS != trSend; ++trS, i++)
		{
			if (option == SHOW_10_STATUSES && i > 9)
				return;
			cout << (*(trS));
		}
	}
	else
		cout << "\nThe member " << name << " has no any existing statuses yet.";

}

void User::print_Friends_statuses() const
{//This function print the friends statuses.
	int length = friendsList.size();
	if (length > 0)
	{
		vector<User*>::const_iterator trU = friendsList.begin();
		vector<User*>::const_iterator trUend = friendsList.end();
		for (; trU != trUend; ++trU)
		{
			cout << "\nName's friend: " << (*(trU))->getName();
			(*(trU))->print_statuses(SHOW_10_STATUSES);
		}
	}
	else
		cout << "\nThe member " << name << " has no any existing friends yet.";
}

int  User::is_friendship_exist(const string name) const
{//This function check if there is friendship between two members.

	int found = NOT_FOUND, i = 0;
	string current_name;
	vector<User*>::const_iterator trU = friendsList.begin();
	vector<User*>::const_iterator trUend = friendsList.end();
	while (trU != trUend && found == NOT_FOUND)
	{
		current_name = (*(trU))->getName();
		if (name.compare(current_name) == 0)
		{
			found = i;
		}
		i++;
		++trU;
	}
	return found;
}

bool User::cancelfriendShip(User* mate)
{//This function remove friendShip between two members.

	int index = is_friendship_exist(mate->name);
	vector<User*>::const_iterator trU = friendsList.begin();
	if (index != NOT_FOUND)
	{
		for (int i = 0; i != index; ++i)
		{
			trU++;
		}
		friendsList.erase(trU);
		mate->cancelfriendShip(this);
		return true;
	}
	return false;
}

void User::removeFanPage(FanPage* page)
{//This function remove connection between member and fanPage.

	if (is_connected_exit(*page))
	{
		vector<FanPage*>::iterator trP = followerPages.begin();
		int ind = find_fanPage_ind(*page);
		for (int i = 0; i < ind; ++i)
		{
			trP++;
		}
		followerPages.erase(trP);
		page->removeMember(this);
	}
}

int  User::find_fanPage_ind(FanPage& page) const
{//This function find the index of the requested page in the follower Pages.
//The page is definitely on the array because there was check before.
	vector<FanPage*>::const_iterator trP = followerPages.begin();
	vector<FanPage*>::const_iterator trPend = followerPages.end();
	string current_name;
	for (int i = 0; trP != trPend; i++, ++trP)
	{
		current_name = (*(trP))->getName();
		if (page.getName().compare(current_name) == 0)
		{
			return i;
		}
	}
	return NOT_FOUND;
}

bool User::is_connected_exit(FanPage& page) const
{//This function check if there is connection between member and page and return true if there is, and flase else.

	string temp_name;
	vector<FanPage*>::const_iterator trP = followerPages.begin();
	vector<FanPage*>::const_iterator trPend = followerPages.end();
	for (; trP != trPend; ++trP)
	{
		temp_name = (*(trP))->getName();
		if (page.getName().compare(temp_name) == 0)
			return true;
	}
	return false;
}

void User::printFollowerPages() const
{
	vector <FanPage*>::const_iterator itr = followerPages.begin();
	vector <FanPage*>::const_iterator itrEnd = followerPages.end();

	cout << "These are all the pages " << this->name << " following:" << endl;
	for (; itr != itrEnd; ++itr)
	{
		cout << "***********************************" << endl;
		cout << "Page's name: " << (*itr)->getName() << endl;
		cout << "***********************************" << endl;
	}
}

const User& User::operator+=(User& other)//will change both users and no need to copy a user so we use a reference instead, we don't support mulitple use.
{//This function add friend to the friendsList of user.
	if (is_friendship_exist(other.name) == NOT_FOUND)
	{
		friendsList.push_back(&other);
		other += (*this);
	}
	return *this;
}

const User& User::operator+=(FanPage& other)
{//This function add fanpage to the followerPages list of user.
	if (!is_connected_exit(other))
	{
		followerPages.push_back(&other);
		other += (*this);
	}
	return *this;
}

bool User::operator>(const User& other)const
{//This function compare between the amount of friends of users.
	return this->friendsList.size() > other.friendsList.size();
}

bool User::operator>(const FanPage& other)const
{
	return this->friendsList.size() > other.getFriendsListSize();
}

ostream& operator<<(ostream& os, const User& user)
{//This function print the friends list of user.
	if (user.friendsList.size() == 0)
		os << "The member " << user.name << " doesn't have friends" << endl;
	else
	{
		vector<User*>::const_iterator trU = user.friendsList.begin();
		vector<User*>::const_iterator trUend = user.friendsList.end();
		os << "\nThese are all the friends of " << user.name << ":";
		for (; trU != trUend; ++trU) {
			os << "\n\n***********************************";
			os << "\n Name's friend: " << (*(trU))->getName() << "\n Birth date: " << (*(trU))->birthDate;
			os << "\n***********************************";
		}
	}
	return os;
}

