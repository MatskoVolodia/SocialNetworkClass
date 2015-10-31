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

void ChatAdmin::Show()const 
{
	ChatUser::Show();
	cout << "* Work: " << getWork();
	cout << "\n* Salary: " << getSalary();
	cout << endl;
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

int ChatAdmin::doCalculateSalaryForYear() const
{
	return salary * 12;
}

ChatAdmin::~ChatAdmin()
{
	salary = NULL;
}
