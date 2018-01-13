#include "Logger.h"

char Logger::m_buffer[MAX_BUF_LEN];

bool Logger::Initialize(std::string filename)
{
	outputLog.open(filename, std::ofstream::out | std::ofstream::trunc);
	if (!outputLog.good())
	{
		std::cout << "Logger file failed to load" << std::endl;
		exit(1);
	}
	Log(LOG_INFO,"Logger Initialized");
	//outputLog << "INFO: ";
	//outputLog << "Logger Initialized" << std::endl;
	//outputLog.flush();
	return true;
}
#include "Time.h"
//#include <sys/time.h>
#include <stdio.h>

//#include <unistd.h>
bool Logger::Log(LogType type,char* message)
{
	time_t rawtime;
	time(&rawtime);
	tm timeinfo;
	localtime_s(&timeinfo,&rawtime);
	int hr = timeinfo.tm_hour;
	int min = timeinfo.tm_min;
	int sec = timeinfo.tm_sec;

	switch (type) {
	case LOG_WARNING:
		outputLog << hr << " : " << min << " : "<<sec <<" Warning : " << message << std::endl;
		break;
	case LOG_INFO:
		outputLog << hr << " : " << min << ":" << sec << " Info: " << message << std::endl;
		break;
	case LOG_FATAL:
		outputLog << hr << " : " << min << ":" << sec << " Fatal Error: " << message << std::endl;
		break;
	case LOG_ERROR:
		outputLog << hr << " : " << min << ":" << sec << " Error: " << message << std::endl;
		break;
	}
	outputLog.flush();
	return true;
}

bool Logger::Log(LogType type, unsigned int frame,char* message)
{
	time_t rawtime;
	time(&rawtime);
	tm timeinfo;
	localtime_s(&timeinfo, &rawtime);
	int hr = timeinfo.tm_hour;
	int min = timeinfo.tm_min;
	int sec = timeinfo.tm_sec;

	switch (type) {
	case LOG_WARNING:
		outputLog << frame << " : " << hr << " : " << min << " : " << sec << " Warning : " << message << std::endl;
		break;
	case LOG_INFO:
		outputLog << frame << " : " << hr << " : " << min << ":" << sec << " Info: " << message << std::endl;
		break;
	case LOG_FATAL:
		outputLog << frame << " : " << hr << " : " << min << ":" << sec << " Fatal Error: " << message << std::endl;
		break;
	case LOG_ERROR:
		outputLog << frame << " : " << hr << " : " << min << ":" << sec << " Error: " << message << std::endl;
		break;
	}
	outputLog.flush();
	return true;
}










bool Logger::Shutdown()
{
	Log(LOG_INFO,"Logger Shutdown");
	outputLog.close();
	return true;
}

Logger::Logger()
{
}


Logger::~Logger()
{
}
