#include "ChatAdmin.h"
#include <iostream>
using namespace std;

ChatAdmin::ChatAdmin() : ChatUser()
{
	//work = nullptr;
	salary = NULL;
}

ChatAdmin::ChatAdmin(string _work, int _salary, string _username, int _password, string *_friends, int _friendscounter) : ChatUser(_username, _password, _friends, _friendscounter)
{
	work = _work;
	salary = _salary;
}

ChatAdmin::ChatAdmin(ChatAdmin&ob) : ChatUser(ob)
{
	salary = ob.salary;
	work = ob.work;
}

ChatAdmin &ChatAdmin::operator=(const ChatAdmin &ob) 
{
	/*username = ob.username;
	password = ob.password;
	friendscounter = ob.friendscounter;
	friends = new string[friendscounter];
	for (auto i = 0; i < friendscounter; i++)
	{
		friends[i] = ob.friends[i];
	}*/
	ChatUser::operator=(ob);
	salary = ob.salary;
	work = ob.work;
	return *this;
}

void ChatAdmin::Show()const 
{
	ChatUser::Show();
	cout << "* Work: " << getWork();
	cout << "* Salary: " << getSalary();
}

void ChatAdmin::setWork(string _work)
{
	work = _work;
}

void ChatAdmin::setSalary(int _salary)
{
	salary = _salary;
}

string ChatAdmin::getWork()const
{
	return work;
}

int ChatAdmin::getSalary()const
{
	return salary; 
}

ChatAdmin::~ChatAdmin()
{
	//work = nullptr;
	salary = NULL;
}
