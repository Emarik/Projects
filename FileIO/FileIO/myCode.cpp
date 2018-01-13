#include <iostream>
#include <fstream>
#include <stdlib.h>

#define ADD(x,y) x + y

using namespace std;

int add(int x, int y)
{
	static int accumulator = 0;
	accumulator++;
	cout << "ACC" <<accumulator << endl;
	return x + y;
}
void write()
{
	FILE* in;
	fopen_s(&in, "test2.txt", "w");
	fwrite("This is my second string", 1, 24, in);
	fclose(in);
	/*
	ofstream out;
	out.open("test.txt", ios::out | ios::trunc);//bitwise stuff because you are checking which bits are on and becuase its an or, both bits are on, that its an output file, and truncates an existing file
	out << "Hello this is my file" << endl;
	out.close();
	*/
}
void read_and_print()
{
#define BUFSIZE 255
#define BUFSIZE_N BUFSIZE +1
	char buffer[BUFSIZE_N];
	memset(buffer, 0, BUFSIZE_N);
	//FILE* in = fopen("test.txt", "r");
	FILE* in;
	fopen_s(&in, "test.txt", "r");
	fread(buffer, 1, 10, in);
	printf("String=%s", buffer);
	fclose(in);

	/*
	ifstream in;
	in.open("test.txt", ios::in);
	char buffer[BUFSIZE_N];
	memset(buffer, 0, BUFSIZE_N);//memset(buffer+40,0,10) sets last 10 bytes
	
	in >> buffer;
	cout << buffer << endl;
	in >> buffer;
	cout << buffer << endl;
	
	in.getline(buffer, BUFSIZE);
	cout << buffer << endl;
	*/
}


void main(int argc, char** argv)
{
	/*
	#define LOOPCOUNT 10
	for (int I = 0; I < LOOPCOUNT; I++)
	{
		cout << add(I, 1) << endl;
	}
	cout << ADD(2, 3) << endl;
	*/
	cout << "I am application " << argv[0];
	if (argc > 1)
	{
		cout << "Command line argument" << argv[1];// == "admin";
		read_and_print();
	}
	else
	write();
	cin.get();
	string something = "HI";
	if (strcmp(something.c_str(), something.c_str()) == 0)
	{

	}
	if (something.compare(something) == 0)
	{

	}


}