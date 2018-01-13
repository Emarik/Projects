#ifndef GAME_H
#define GAME_H
#include "Camera.h"
#include "Config.h"
#pragma warning(push)
#pragma warning(disable:4127)
#pragma warning(disable:4251)
#include <QtGui\qmouseevent>
#pragma warning(pop)
#include "RenderEngine.h"
class Renderable;
class ShapeGenerator;
class MeGlWindow;
class Logger;
class Game
{
	MeGlWindow* m_window;
	Logger *m_logs;
	bool m_paused = false;
	ShapeGenerator* generator;
	Camera cam;
	Config *m_config;
	RenderEngine m_renderEngine;
public:
	//Renderable grid;
	Renderable dragon;
	Renderable dragon2;
	Renderable cube;
	Game(Logger* log, Config* config) :m_logs(log), m_config(config) {};
	bool Initialize(MeGlWindow* window);
	void installShaders(GLuint* textures);
	void BufferBind();
	bool Shutdown();
	void enablingVertex();
	void drawingSetup();
	void mouseMoveEvent(QMouseEvent * e);
	void checkKeys(float dt);
	bool Update(float dt);
};
#endif
