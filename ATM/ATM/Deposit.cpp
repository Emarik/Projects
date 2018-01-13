#include "Deposit.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;


#define BUFSIZE 255
#define BUFSIZE_N BUFSIZE +1


Deposit::Deposit(string AccountNumb)
{
	ifstream in;
	in.open(AccountNumb + ".txt", ios::in);
	char buffer[BUFSIZE_N];
	memset(buffer, 0, BUFSIZE_N);
	in.getline(buffer, BUFSIZE);
	string temp = buffer;
	string some = temp.substr(0, temp.find("&"));
	int temps = std::stoi(some);
	temps += menu();
	ofstream out;
	out.open(AccountNumb + ".txt", ios::out | ios::trunc);
	out << temps << temp.substr(temp.find("&"),temp.find("\n")) << endl;
	out.close();
	in.close();
}

int Deposit::menu()
{
	cout << "Please enter the amount you would like to deposit" << endl;
	string numb;
	cin >> numb;
	int temper;
	try
	{
		temper = std::stoi(numb);
	}
	catch (exception e)
	{
		return this->menu();
	}
	return temper;
}

Deposit::~Deposit()
{
}
