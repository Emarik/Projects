#include "Account.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

Account::Account()
{
	string temp = "";
	cout << "please enter an account number" << endl;
	string accNumb[4];
	for (int I = 0; I < 4; I++)
	{
		string temps;
		int temp;
		cout << "Please enter the " << I + 1 << " group of 4 digits of your account" << " or type exit to go back" << endl;
		cin >> temps;
		string some = temps;
		if (sizeof(some) == 28 && some.length() == 4)
		{
			try
			{
				temp = std::stoi(some);
			}
			catch
				(exception e)
			{
				I--;
				cout << "Invalid Input, try again" << endl;
			}
		}
		else
		{
			cout << "Invalid Input, try again" << endl;
			I--;
		}
		accNumb[I] = some;
	}
	for (int I = 0; I < 4; I++)
	{
		temp += accNumb[I];
	}

	cout << "Please enter you name" << endl;
	char names[200];
	cin.getline(names, 200);
	string name = names;

	bool passe = false;
	string sbalances;
	while (!passe)
	{
		passe = true;
		cout << "Please enter a starting balance" << endl;
		cin >> sbalances;

	}
	ofstream out;
	out.open(temp+".txt", ios::out | ios::trunc);//bitwise stuff because you are checking which bits are on and becuase its an or, both bits are on, that its an output file, and truncates an existing file
	out << sbalances + "&" + name << endl;
	out.close();
}



Account::~Account()
{
}
