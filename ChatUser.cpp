#include "ChatUser.h"
#include <iostream>
using namespace std;

ChatUser::ChatUser()
{
	//username = nullptr;
	password = NULL;
	friends = new string[0];
	friendscounter = NULL;
}

ChatUser::ChatUser(string _username, int _password, string *_friends, int _friendscounter)
{
	username = _username;
	password = _password;
	friendscounter = _friendscounter;
	friends = new string[friendscounter];
	for (auto i = 0; i < friendscounter; i++)
	{
		friends[i] = _friends[i];
	}
}

ChatUser::ChatUser(ChatUser& ob)
{
	username = ob.username;
	password = ob.password;
	friendscounter = ob.friendscounter;
	friends = new string[friendscounter];
	for (auto i = 0; i < friendscounter; i++)
	{
		friends[i] = ob.friends[i];
	}
}

void ChatUser::Show()const
{
	cout << "\n *  *  * \n";  
	cout << "* Username: " << username;
	cout << "\n* Password: " << password;
	cout << "\n* Friends: \n";
	for (auto i = 0; i < friendscounter; i++)
	{
		cout << "   " <<friends[i] << '\n';
	}
	//cout << '\n';
}

void ChatUser::setUsername(string _username)
{
	username = _username;
}

void ChatUser::setPassword(int _password)
{
	password = _password;
}

string ChatUser::getUsername()const
{
	return username;
}

int ChatUser::getPassword()const
{
	return password;
}

void ChatUser::setFriendsCounter(int _friendscounter)
{
	_friendscounter = _friendscounter;
}

int ChatUser::getFriendsCounter()const
{
	return friendscounter;
}

ChatUser::~ChatUser()
{
	//username = nullptr;
	password = NULL;
	delete[]friends;
}