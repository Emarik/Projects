#ifndef GAME_H
#define GAME_H
#pragma warning(push)
#pragma warning(disable:4127)
#include "Qt/qtimer.h"
#pragma warning(pop)
class MeGlWindow;
class Logger;
class Game
{
	GLuint vertexBufferID;
	MeGlWindow* m_window;
	QTimer timer;
	Logger *m_logs;
public:
	Game(Logger* log) :m_logs(log) {};
	bool Initialize(MeGlWindow* window);
	void installShaders();
	void BufferBind();
	bool Shutdown();
	bool Update();
};
#endif
