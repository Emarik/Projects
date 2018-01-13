#include "GameTimer.h"
#include "Logger.h"



GameTimer::GameTimer(Logger *log)
{
	this->m_log = log;
}


GameTimer::~GameTimer()
{
}

bool GameTimer::Initialize()
{
	m_log->Log(LOG_INFO, "Game Timer initialized");
	QueryPerformanceFrequency(&clockFrequency);
	return false;
}

bool GameTimer::Shutdown()
{
	m_log->Log(LOG_INFO, "Game Timer Shutdown");
	return false;
}

float GameTimer::getGameTime()
{
	QueryPerformanceCounter(&endTime);
	LARGE_INTEGER delta;
	delta.QuadPart = endTime.QuadPart - startTime.QuadPart;
	float dt = (float)delta.QuadPart / clockFrequency.QuadPart;
	QueryPerformanceCounter(&startTime);
	return dt;
}
