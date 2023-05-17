#ifndef __FANPAGE_H
#define __FANPAGE_H

class User;
class Status;

#include <vector>
#include <list>
#include <String>
#include "Exception.h"

class FanPage
{
private:
	string name;
	vector<User*> friendsList;
	list<Status> statusBoard;

public:
	FanPage(const string& name)noexcept(false);//Constructor
	FanPage(const FanPage& other)noexcept(false);//Copy constructor
	FanPage(const FanPage&& other)noexcept(false);
	~FanPage() = default;//Distractor

	const  string& getName() const;
	int    getFriendsListSize()const;
	void   insert_new_status(const Status& requsted_status);
	void   print_fanPage(int option) const;
	bool   is_connected_exist(User& member) const;
	int    find_friend_ind(User& member) const;
	bool   removeMember(User* member);

	const  FanPage& operator+=(User& other);
	bool   operator>(const FanPage& other)const;//returns boolean var,doesnt change the object that excutes the function and no need to copy 'other' var
	bool   operator>(const User& other)const;
	friend ostream& operator<<(ostream& os, const FanPage& page);
};

#endif