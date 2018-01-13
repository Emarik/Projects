#ifndef LOGGER_H
#define LOGGER_H
#include <iostream>
#include <fstream>
#define MAX_BUF_LEN 200
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
	bool Log(LogType type,const char* message);
	bool Log( LogType type,unsigned int frame,char* message);
	Logger();
	~Logger();
	template <typename A>
	bool LogErrors(LogType type, const char* format, A a)
	{
		sprintf_s(m_buffer, MAX_BUF_LEN, format, a);
		Log(type, m_buffer);
		return false;
	}
	template <typename A, typename B>
	bool LogErrors(LogType type, const char* format, A a, B b)
	{
		sprintf_s(m_buffer, MAX_BUF_LEN, format, a, b);
		Log(type, m_buffer);
		return false;
	}
	template <typename A, typename B, typename C>
	bool LogErrors(LogType type, const char* format, A a, B b, C c)
	{
		sprintf_s(m_buffer, MAX_BUF_LEN, format, a, b, c);
		Log(type, m_buffer);
		return false;
	}
	template <typename A, typename B, typename C, typename D>
	bool LogErrors(LogType type, const char* format, A a, B b, C c, D d)
	{
		sprintf_s(m_buffer, MAX_BUF_LEN, format, a, b, c, d);
		Log(type, m_buffer);
		return false;
	}

	//Frame included
	template <typename A>
	bool LogErrors(LogType type, unsigned int frames, const char* format, A a)
	{
		sprintf_s(m_buffer, MAX_BUF_LEN, format, a);
		Log(type,frames, m_buffer);
		return false;
	}
	template <typename A, typename B>
	bool LogErrors(LogType type, unsigned int frames, const char* format, A a, B b)
	{
		sprintf_s(m_buffer, MAX_BUF_LEN, format, a, b);
		Log(type,frames, m_buffer);
		return false;
	}
	template <typename A, typename B, typename C>
	bool LogErrors(LogType type, unsigned int frames, const char* format, A a, B b, C c)
	{
		sprintf_s(m_buffer, MAX_BUF_LEN, format, a, b, c);
		Log(type,frames, m_buffer);
		return false;
	}
	template <typename A, typename B, typename C, typename D>
	bool LogErrors(LogType type,unsigned int frames, const char* format, A a, B b, C c, D d)
	{
		sprintf_s(m_buffer, MAX_BUF_LEN, format, a, b, c, d);
		Log(type,frames, m_buffer);
		return false;
	}
private:
	static char m_buffer[MAX_BUF_LEN];
};
#endif

