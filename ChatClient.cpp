#include "ChatClient.h"

ChatClient::ChatClient()
{
	//name = nullptr;
	foundationyear = NULL;
	usercounter = NULL;
}

ChatClient::ChatClient(string _name, int _foundationyear, ChatUser *_userbase[UsersCountSize], int _usercounter)
{
	name = _name;
	foundationyear = _foundationyear;
	usercounter = _usercounter;
	//userbase = new ChatUser[usercounter];
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
		ob.userbase[i]->Show();
	}
	os << " ============================== \n";
	return os;
}

ChatUser* ChatClient::operator[](const int &number)
{
	return userbase[number];
}

istream&operator>>(istream& os, ChatClient& ob)
{
	cout << "Input name: ";
	os >> ob.name;
	cout << "Input Foundation Year: ";
	os >> ob.foundationyear;
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

void ChatClient::ShowAdmins()const
{
	for (auto i = 0; i < usercounter; i++)
	{
		string temp = typeid(*(userbase[i])).name(); 
		if (temp == "class ChatAdmin")
		{
			userbase[i]->Show();
		}
	}
}
void ChatClient::ShowNotAdmins()const
{
	for (auto i = 0; i < usercounter; i++)
	{
		string temp = typeid(*(userbase[i])).name();
		if (!(temp == "class ChatAdmin"))
		{
			userbase[i]->Show();
		}
	}
}

int ChatClient::getYearSalaryBudget()const
{
	int res = 0;
	for (auto i = 0; i < usercounter; i++)
	{
		string temp = typeid(*(userbase[i])).name();
		if (temp == "class ChatAdmin")
		{
			res += userbase[i]->doCalculateSalaryForYear();
		}
	}
	return res;
}

ChatClient::~ChatClient()
{
	foundationyear = NULL;
	delete *userbase;
}
