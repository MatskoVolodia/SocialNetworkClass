#include <iostream>
#include <fstream>
#include <string>
#include "ChatClient.h"
using namespace std;

template <typename TT>
TT* PushBackAlternative(TT *temp, const TT &item, int &sizeb); // if i could use VECTOR then it wouldn't be necessary.Sorry for monkey-code

int main()
{
	ifstream workingfile;
	workingfile.open("DataBase.txt");

	string name;
	getline(workingfile,name);
	int year;
	workingfile >> year;
	string temp;
	getline(workingfile, temp); getline(workingfile, temp); getline(workingfile, temp); 
	ChatUser *base = new ChatUser[0];
	int basesize = 0; getline(workingfile, temp); getline(workingfile, temp);
	while (workingfile)
	{
		string username;
		getline(workingfile, username);
		int password;
		workingfile >> password;
		getline(workingfile, temp); getline(workingfile, temp);
		string *friendsbase = new string[0]; 
		int friendbasesize = 0;
		getline(workingfile, temp);
		while (temp.compare("Work:") && !temp.empty())
		{
			friendsbase = PushBackAlternative<string>(friendsbase, temp, friendbasesize);
			getline(workingfile, temp);
		}
		string work; int salary = -1;
		if (!temp.compare("Work:"))
		{
			getline(workingfile, temp);
			work = temp;
			workingfile >> salary;
			base = PushBackAlternative<ChatUser>(base, ChatAdmin(work, salary, username, password, friendsbase, friendbasesize), basesize);
		}
		 else
		 {
			 base = PushBackAlternative<ChatUser>(base, ChatUser(username, password, friendsbase, friendbasesize), basesize);
		 }
		getline(workingfile, temp);// getline(workingfile, temp);
	}

	ChatClient MyClient(name, year, base, basesize);

	cout << MyClient;
	system("pause");
	workingfile.close();
	return 0;
}

template <typename TT>
TT* PushBackAlternative(TT *temp, const TT &item, int &sizeb)
{
	TT *res; ++sizeb;
	res = new TT[sizeb];
	for (auto i = 0; i < sizeb - 1; i++)
	{
		res[i] = temp[i];
	}
	res[sizeb - 1] = item;
	return res;
}