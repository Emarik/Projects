#ifndef GAME_H
#define GAME_H
#include "ShapeGenerator.h"

class MeGlWindow;
class Logger;
class Cube;
class Game
{
	MeGlWindow* m_window;
	Logger *m_logs;
	bool m_paused = false;
	ShapeGenerator generator;
public:
	Cube *cube;
	Game(Logger* log) :m_logs(log) {};
	bool Initialize(MeGlWindow* window);
	void installShaders();
	void BufferBind();
	bool Shutdown();
	void enablingVertex();
	void drawingSetup();
	void checkKeys(float dt);
	bool Update(float dt);
};
#endif
