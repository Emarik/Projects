#include "Machine.h"
#include "memtrack.h"


int main(int argc, char** argv)
{
	Machine* ATM = new Machine(argc, argv);
	delete ATM;
	print_memory();
	system("PAUSE");
}