#pragma once
#include "Transaction.h"
#include <string>
using namespace std;
class Withdraw :
	public Transaction
{
public:
	Withdraw(string AccountNumb);
	int menu(int);
	~Withdraw();
};

