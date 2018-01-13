#ifndef LOGGER_H
#define LOGGER_H
#include <iostream>
#include <fstream>
enum LogType
{
	 LOG_WARNING, LOG_INFO, LOG_FATAL, LOG_ERROR
};
class Logger
{
	std::ofstream outputLog;
public:
	bool Initialize(std::string filename);
	bool Shutdown();
	bool Log(char* message, LogType type);
	Logger();
	~Logger();
};
#endif

