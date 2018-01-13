#pragma once
//#include "Money.h"

#include <string>

class Machine
{
public:
	Machine(int argc, char** argv);
	void Run();
	void RunAdmin();
	int Menu();
	bool Login();
	int checkBalance();
	int AdminMenu();
	~Machine();
private:
	bool LoggedIn = false;
	std::string accountNumb;
};

