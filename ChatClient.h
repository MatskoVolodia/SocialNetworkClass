#ifndef CHATCLIENT_H
#define CHATCLIENT_H

#include <string>
#include "ChatUser.h"
#include "ChatAdmin.h"

using namespace std;

class ChatClient
{
protected:
	string name;
	int foundationyear;
	int usercounter;
	ChatUser *userbase;
public:
	ChatClient();
	ChatClient(string _name, int _foundationyear, ChatUser *_userbase, int _usercounter);
	
	friend ostream&operator<<(ostream& os, const ChatClient& ob);

	void setName(string _name);
	void setFoundationYear(int _foundationyear);
	
	string getName() const;
	int getFoundationYear()const;
	int getUserCounter() const;

	~ChatClient();
};

#endif