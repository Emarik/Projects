#ifndef GAME_H
#define GAME_H
#pragma warning(push)
#pragma warning(disable:4127)
#include "Qt/qtimer.h"
#pragma warning(pop)
class MeGlWindow;
class Game
{
	GLuint vertexBufferID;
	MeGlWindow* m_window;
	QTimer timer;
public:
	bool Initialize(MeGlWindow* window);
	void installShaders();
	void BufferBind();
	bool Shutdown();
	bool Update();
};
#endif
