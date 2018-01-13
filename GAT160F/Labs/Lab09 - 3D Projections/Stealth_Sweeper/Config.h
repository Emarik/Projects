#ifndef CONFIG_H
#define CONFIG_H
#include <iostream>
#define MAX_KEY_PAIRS 50
class Logger;
class Config
{
private:
	Logger * logs;
	int used;
	std::string keys[MAX_KEY_PAIRS];
	std::string values[MAX_KEY_PAIRS];
public:
	bool readFile(std::string filename);
	bool Initialize(std::string filename);
	bool Shutdown();
	const char* FindValueForKey(const char* key);
	const char* FindNeededValueForKey(const char* key);
	float getFloatFromString(std::string s);
	int getIntFromString(std::string s);
	int getFloatsFromString(std::string str, float values[], int numValues)const;
	Config(Logger* log);
	~Config();
	bool IsBlankOrComment(std::string s);
	int findNextNonBlank(std::string s, int point);
	std::string findNextWord(std::string s, int* point);
	void LogConfig();
	void getKeyValuePair(std::string s);
};

#endif