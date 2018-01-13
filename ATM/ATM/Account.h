#pragma once
#include <string>

using namespace std;

class Account
{
public:
	Account();
	int getBalance();
	void changeBalance(int);
	string getAccNumb();
	int getpin();
	~Account();
private:
	string name;
	string AccNumb;
	int balance;
};

