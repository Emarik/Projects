#ifndef GAMETIMER_H
#define GAMETIMER_H
#include <Windows.h>
class Logger;
class GameTimer
{
public:
	LARGE_INTEGER clockFrequency;
	LARGE_INTEGER startTime;
	LARGE_INTEGER endTime;
	Logger *m_log;
	GameTimer(Logger *log);
	~GameTimer();
	bool Initialize();
	bool Shutdown();
	float getGameTime();
};
#endif
