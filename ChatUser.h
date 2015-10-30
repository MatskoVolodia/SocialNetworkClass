#ifndef CHATUSER_H
#define CHATUSER_H

#include <string>

using namespace std;

class ChatUser
{
protected:
	string username;
	int password;
	int friendscounter;
	string *friends;

public:
	ChatUser();
	ChatUser(string _username, int _password, string *_friends, int _friendscounter);
	ChatUser(ChatUser& ob);

	ChatUser& operator=(const ChatUser &ob);

	virtual void Show()const;

	void setUsername(string _username);
	void setPassword(int _password);
	void setFriendsCounter(int _friendscounter);

	string getUsername()const;
	int getPassword()const;
	int getFriendsCounter()const;

	~ChatUser();
};

#endif
