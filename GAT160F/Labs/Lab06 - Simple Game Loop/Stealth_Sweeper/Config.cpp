#include "Config.h"
#include "Logger.h"
#include "sstream"
#include <cassert>

Config::Config(Logger* log)
{
	this->logs = log;
}


Config::~Config()
{
}

bool Config::Initialize(std::string filenames)
{
	used = 0;
	std::ifstream inputStream(filenames, std::ios::in);
	std::string str;
	if (!inputStream.good())
	{
		logs->Log(LOG_FATAL, "Config file failed to read");
		return false;
	}
	while (std::getline(inputStream, str))
	{
		keys[used] = str.substr(0, str.find(" "));
		if (int quote = str.find("\"") != -1)
		{
			values[used] = str.substr(quote+1, str.find_last_of("\""));
		}
		else if (int comment = str.find("//"))
		{
			values[used] = str.substr(str.find(" ") + 1,comment);
		}
		else 
		{
			values[used] = str.substr(str.find(" ") + 1);
		}
		used++;
	}
	logs->Log(LOG_INFO, "Config Initialized");
	return true;
}

bool Config::Shutdown()
{
	logs->Log(LOG_INFO, "Config Shutdown");
	return true;
}

const char * Config::FindValueForKey(const char * key)
{
	for (int I = 0; I < used; I++)
	{
		if (keys[I] == key)
		{
			return values[I].c_str();
		}
	}
	return 0;
}

const char * Config::FindNeededValueForKey(const char * key)
{
	const char * result = FindValueForKey(key);
	if (result == 0)
	{
		logs->Log(LOG_FATAL, "Needed value failed");
	}
	return result;
}

float Config::getFloatFromString(std::string s)
{
	return stof(s);
}

int Config::getIntFromString(std::string s)
{
	return std::atoi(s.c_str());
}

int Config::getFloatsFromString(std::string str, float value[], int numValues) const
{
	int count = 0;
	int currentPos = 0;
	int nextPos = 0;
	while (count < numValues)
	{
		nextPos=str.find(" ", currentPos+1);
		if (nextPos==-1)
		{
			value[count] = stof(str.substr(currentPos));
			count++;
			break;
		}
		value[count]=stof(str.substr(currentPos, nextPos));
		currentPos = nextPos;
		count++;
	}
	return count;
}
