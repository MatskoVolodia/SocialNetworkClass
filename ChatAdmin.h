#ifndef CHATADMIN_H
#define CHATADMIN_H

#include "ChatUser.h"
#include <string>

using namespace std;

class ChatAdmin :
	public ChatUser
{
protected:
	string  work; // pr, editor, founder
	int salary;

public:
	ChatAdmin();
	ChatAdmin(string _work, int _salary, string _username, int _password, string *_friends, int _friendscounter);
	ChatAdmin(ChatAdmin&ob);

	virtual void Show()const;

	void setWork(string _work);
	void setSalary(int _salary);

	int doCalculateSalaryForYear() const;
	
	string getWork()const;
	int getSalary()const;

	~ChatAdmin();
};

#endif