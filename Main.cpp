#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "ChatClient.h"
using namespace std;

int main()
{
	ifstream workingfile;
	workingfile.open("DataBase.txt");
	
	string name;
	getline(workingfile,name);
	int year;
	workingfile >> year;
	string temp;
	int basesize = -1;
	int maincounter = -1;
	getline(workingfile, temp); getline(workingfile, temp); 
	workingfile >> basesize; 
	getline(workingfile, temp);
	ChatUser *base[UsersCountSize]; 
	getline(workingfile, temp); getline(workingfile, temp);
	while (workingfile)
	{
		++maincounter;
		string username;
		getline(workingfile, username);
		int password;
		workingfile >> password;
		getline(workingfile, temp);
		int friendbasesize = -1;
		int friendcounter = -1;
		workingfile >> friendbasesize;
		getline(workingfile, temp);
		string *friendsbase = new string[friendbasesize]; 
		getline(workingfile, temp);
		while (temp.compare("Work:") && !temp.empty() && workingfile)
		{
			++friendcounter;
			friendsbase[friendcounter] = temp;
			getline(workingfile, temp);
		}
		string work; int salary = -1;
		if (!temp.compare("Work:"))
		{
			getline(workingfile, temp);
			work = temp;
			workingfile >> salary;
			base[maincounter] = new ChatAdmin(work, salary, username, password, friendsbase, friendbasesize);
			getline(workingfile, temp); getline(workingfile, temp);
		}
		 else
		 {
			base[maincounter] = new ChatUser(username, password, friendsbase, friendbasesize);
		 }
		if (workingfile) { getline(workingfile, temp); }// getline(workingfile, temp);
	}
	
	ChatClient MyClient(name, year, base, basesize);
	
	cout << MyClient;
	system("pause");
	workingfile.close();
	return 0;
}