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

bool Config::IsBlankOrComment(std::string s)
{
	for (int I = 0; I < (int)s.length(); I++)
	{
		if (s[I] == ' ')
		{
			continue;
		}
		else if (s[I] == '\t')
		{
			continue;
		}
		else if (s[I] == '/')
		{
			return true;
		}
		else if (s[I] == '\\')
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	return true;
}

int Config::findNextNonBlank(std::string s, int point)
{
	for (int I = point; I < (int)s.length(); I++)
	{
		if (s[I] == ' ' || s[I] == '\t')
		{
			continue;
		}
		else if (s[I] == '/' || s[I] == '\\')
		{
			return -1;
		}
		else
		{
			return point;
		}
	}
	return -1;
}

std::string Config::findNextWord(std::string s, int *point)
{
	int start = findNextNonBlank(s, *point);
	int end;
	if (s[start] == '\"')
	{
		end=s.find('\"', start + 1);
	}
	else
	{
		end=s.find(' ', start + 1);
	}
	if (start == -1)
	{
		return NULL;
	}
	*point = end;
	if (end == -1)
	{
		return s.substr(start);
	}
	else
	{
		return s.substr(start, end - start);
	}
	
	
}

void Config::LogConfig()
{
	for (int I = 0; I < used; I++)
	{
		logs->LogErrors(LOG_INFO, "Key number %d: %s - %s", used, keys[used], values[used]);
	}
}
void Config::getKeyValuePair(std::string s)
{
	int point = 0;
	std::string key=findNextWord(s, &point);
	std::string value = findNextWord(s, &point);
	keys[used] = key;
	values[used] = value;
	used++;
}
bool Config::readFile(std::string filename)
{
	used = 0;
	std::ifstream inputStream(filename, std::ios::in);
	std::string str;
	if (!inputStream.good())
	{
		logs->Log(LOG_FATAL, "Config file failed to read");
		return false;
	}
	while (std::getline(inputStream, str))
	{
		if(!IsBlankOrComment(str))
		getKeyValuePair(str);
	}
	return true;
}

bool Config::Initialize(std::string filename)
{
	readFile(filename);
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
	assert(("Needed value failed",result==0));
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
