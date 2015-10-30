#include "ChatClient.h"


ChatClient::ChatClient()
{
	//name = nullptr;
	foundationyear = NULL;
	usercounter = NULL;
	userbase = new ChatUser[0];
}

ChatClient::ChatClient(string _name, int _foundationyear, ChatUser *_userbase, int _usercounter)
{
	name = _name;
	foundationyear = _foundationyear;
	usercounter = _usercounter;
	userbase = new ChatUser[usercounter];
	for (auto i = 0; i < usercounter; i++)
	{
		userbase[i] = _userbase[i];
	}
}

ostream&operator<<(ostream& os, const ChatClient& ob)
{
	os << "ChatClient name: " << ob.name;
	os << "\nChatClient Foundation Year: " << ob.foundationyear;
	os << "\n ============================== \n User's list: \n";
	for (auto i = 0; i < ob.usercounter; i++)
	{
		ob.userbase[i].Show();
	}
	return os;
}

void ChatClient::setName(string _name)
{
	name = _name;
}

void ChatClient::setFoundationYear(int _foundationyear)
{
	foundationyear = _foundationyear;
}

string ChatClient::getName()const
{
	return name;
}

int ChatClient::getFoundationYear()const
{
	return foundationyear;
}

int ChatClient::getUserCounter() const
{
	return usercounter;
}

ChatClient::~ChatClient()
{
	//name = nullptr;
	foundationyear = NULL;
	delete[]userbase;
}
