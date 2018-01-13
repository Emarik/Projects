#ifndef LOGGER
#define LOGGER

#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include "List.h"

using std::vector;
using std::string;

enum Severity { Info, Warning, Error };

#define LOG( severity, mesage) Logger::Log( severity, message, __LINE__, __FILE__ )
#define END_LOG Logger::shutDown();

#pragma warning ( disable : 4100)

class Logger
{
public:
#if LOG_ON
	Logger(void);
	~Logger(void);
	static void StringReplace(string& str, const string& from, const string& to);
	static string Sanitize(string str);
	static void Logg( Severity severity, const char* message, const char * logFile, int logLine);
	static void shutDown(){}
#else
	Logger(void){}
	~Logger(void){}
	static void StringReplace(string& str, const string& from, const string& to){}
	static string Sanitize(string str){}
	static void Log( Severity severity, const char* message, const char * logFile, int logLine){}
	static void shutDown(){}
#endif

private:
#if LOG_ON
	static vector <string> logList;
	static vector <Severity> severityList;
	static void WriteFile();
#endif
};

#pragma warning ( default : 4100)

#endif