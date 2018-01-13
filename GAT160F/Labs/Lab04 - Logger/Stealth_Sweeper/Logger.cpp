#include "Logger.h"


bool Logger::Initialize(std::string filename)
{
	outputLog.open(filename, std::ofstream::out | std::ofstream::trunc);
	if (!outputLog.good())
	{
		std::cout << "Logger file failed to load" << std::endl;
		exit(1);
	}
	Log("Logger Initialized",LOG_INFO);
	//outputLog << "INFO: ";
	//outputLog << "Logger Initialized" << std::endl;
	//outputLog.flush();
	return true;
}
#include "Time.h"
//#include <sys/time.h>
#include <stdio.h>
//#include <unistd.h>
bool Logger::Log(char* message, LogType type)
{
	time_t rawtime;
	time(&rawtime);
	tm timeinfo;
	localtime_s(&timeinfo,&rawtime);
	int hr = timeinfo.tm_hour;
	int min = timeinfo.tm_min;
	int sec = timeinfo.tm_sec;

	//long callTime = timeinfo.tm_hour * 3600 + timeinfo.tm_min * 60 + timeinfo.tm_sec;
	switch (type) {
	case LOG_WARNING:
		outputLog << hr << " : " << min << " : "<<sec <<" Warning : " << message << std::endl;
		break;
	case LOG_INFO:
		outputLog << hr << ":" << min << ":" << sec << " Info: " << message << std::endl;
		break;
	case LOG_FATAL:
		outputLog << hr << ":" << min << ":" << sec << " Fatal Error: " << message << std::endl;
		break;
	case LOG_ERROR:
		outputLog << hr << ":" << min << ":" << sec << " Error: " << message << std::endl;
		break;
	}
	outputLog.flush();
	return true;
}

bool Logger::Shutdown()
{
	Log("Logger Shutdown", LOG_INFO);
	outputLog.close();
	return true;
}

Logger::Logger()
{
}


Logger::~Logger()
{
}
