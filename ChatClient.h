#ifndef CHATCLIENT_H
#define CHATCLIENT_H

#include <string>
#include <iostream>
#include "ChatUser.h"
#include "ChatAdmin.h"

using namespace std;
const int UsersCountSize = 2048; // well, I don't think than anybody need more ^^

class ChatClient
{
protected:
	string name;
	int foundationyear;
	int usercounter;
	ChatUser *userbase[UsersCountSize];
public:
	ChatClient();
	ChatClient(string _name, int _foundationyear, ChatUser *_userbase[UsersCountSize], int _usercounter);
	
	friend ostream&operator<<(ostream& os, const ChatClient& ob);
	friend istream&operator>>(istream& os, ChatClient& ob);
	ChatUser* operator[](const int &number);

	void ShowAdmins() const;
	void ShowNotAdmins() const;

	void setName(string _name);
	void setFoundationYear(int _foundationyear);
	
	int getYearSalaryBudget()const;

	string getName() const;
	int getFoundationYear()const;
	int getUserCounter() const;

	~ChatClient();
};

#endif