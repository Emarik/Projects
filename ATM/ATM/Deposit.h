#pragma once
#include "Transaction.h"
#include <string>
using namespace std;
class Deposit :
	public Transaction
{
public:
	Deposit(string);
	int menu();
	~Deposit();
};

