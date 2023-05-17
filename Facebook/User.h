#ifndef __FRIEND_H
#define __FRIEND_H

#include "Date.h"
#include "Status.h"
#include "FanPage.h"
#include <list>

class User
{
private:
	string name;
	Date birthDate;
	vector <User*> friendsList;
	list <Status> statusBoard;
	vector <FanPage*> followerPages;

public:
	static const int NOT_FOUND = -1;
	static const int SHOW_ALL_STATUSES = 1;
	static const int SHOW_10_STATUSES = 10;

	User(const string& name, const Date& birthDate)noexcept(false);//Constructor
	User(const User& other);//Copy constructor
	User(const User&& other);
	~User() = default;//Distractor

	const string getName()const;
	const Date& getBirthdate()const;
	int   getFriendsListSize()const;
	void  add_status(const Status& newData);
	void  print_statuses(int option) const;
	void  print_Friends_statuses() const;
	int   is_friendship_exist(const string name) const;
	bool  cancelfriendShip(User* mate);
	void  connectFanPage(FanPage* page);
	void  removeFanPage(FanPage* page);
	int   find_fanPage_ind(FanPage& page)const;
	bool  is_connected_exit(FanPage& page) const;
	void  insert_new_status(const Status& requsted_status);
	void  printFollowerPages() const;

	const  User& operator+=(User& other);//will change both users and no need to copy a user so we use a reference instead, we don't support mulitple use.
	const  User& operator+=(FanPage& other);
	bool   operator>(const User& other)const;//returns boolean var,doesnt change the object that excutes the function and no need to copy 'other' var
	bool   operator>(const FanPage& other)const;
	friend ostream& operator<<(ostream& os, const User& user);//prints user's data

};
#endif