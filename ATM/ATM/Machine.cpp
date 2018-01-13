#include "Machine.h"
#include "Transaction.h"
#include "Deposit.h"
#include "Withdraw.h"
#include "memtrack.h"
#include "Account.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#define BUFSIZE 255
#define BUFSIZE_N BUFSIZE +1

Machine::Machine(int argc, char** argv)
{
	bool adminMode = false;
	for (int I = 1; I < argc; I++)
	{
		if (string(argv[I]) == string("-admin") || string(argv[I]) == string("-Admin"))
		{
			adminMode = true;
			cout << "admin" << endl;
		}
	}
	if (adminMode)
	{
		this->RunAdmin();
	}
	else
	{
		this->Run();
	}


}
void Machine::Run()
{
	
	while (!LoggedIn)
	{
		LoggedIn = this->Login();
		if (!LoggedIn)
			cout << "Incorrect login information." << endl << "Please try again." << endl;
	}
	int response = 0;
	while (response != 4)
	{
		Transaction* tran;
		response = this->Menu();
		switch (response){
		case 1:
			this->checkBalance();
			break;
		case 2:
			tran = new Deposit(accountNumb);
			delete tran;
			print_memory();
			break;
		case 3:
			tran = new Withdraw(accountNumb);
			delete tran;
			print_memory();
			break;
		case 4:
			break;
		}
	}	
}

bool Machine::Login()
{
	string temp = "";
	string some;
	bool passed = false;
	while (!passed)
	{
		passed = true;
		string accNumb[4];
		for (int I = 0; I < 4; I++)
		{
			string temps;
			int temper;
			cout << "Please enter the " << I + 1 << " group of 4 digits of your account" << " or type exit to go back" << endl;
			cin >> temps;
			some = temps;
			if (sizeof(some) == 28 && some.length() == 4)
			{
				try
				{
					temper = std::stoi(some);
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
		try
		{
			ifstream in;
			in.open(temp + ".txt", ios::in);
		}
		catch (exception e)
		{
			passed = false;
			cout << "Invalid Account Number" << endl;
		}
	}
	this->accountNumb = temp;
	return true;
}

void Machine::RunAdmin()
{
	Account acc;
}

int Machine::Menu()
{
	int answer;
	cout << "Options of things you may do : " << endl;
	cout << "1. Check Balance" << endl;
	cout << "2. Deposit Transaction" << endl;
	cout << "3. Withdraw Transaction" << endl;
	cout << "4. Exit Account" << endl;
	cin >> answer;
	if (answer > 0 && answer < 5)
	{
		return answer;
	}
	else
	{
		cout << "This is an incorrect selection, please try again!" << endl;
		return this->Menu();
	}
}

int Machine::checkBalance()
{
	ifstream in;
	in.open(this->accountNumb+".txt", ios::in);
	char buffer[BUFSIZE_N];
	memset(buffer, 0, BUFSIZE_N);
	in.getline(buffer, BUFSIZE);
	string temp = buffer;
	temp=temp.substr(0, temp.find("&"));
	cout << temp << endl;
	int temps = std::stoi(temp);
	in.close();
	return temps;
}


Machine::~Machine()
{
}
