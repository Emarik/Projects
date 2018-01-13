#ifndef GAME_H
#define GAME_H
class MeGlWindow;
class Logger;
class Game
{
	GLuint vertexBufferID;
	MeGlWindow* m_window;
	Logger *m_logs;
public:
	Game(Logger* log) :m_logs(log) {};
	bool Initialize(MeGlWindow* window);
	void installShaders();
	void BufferBind();
	bool Shutdown();
	void enablingVertex();
	void drawingSetup();
	void checkKeys();
	bool Update();
};
#endif
