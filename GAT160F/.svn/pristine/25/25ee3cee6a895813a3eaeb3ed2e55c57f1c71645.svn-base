#ifndef MEGLWINDOW_H
#define MEGLWINDOW_H
#pragma warning(push)
#pragma warning(disable:4127)
#pragma warning(disable:4251)
#pragma warning(disable:4800)
#include "QtOpenGL/QGLWidget"
#pragma warning(pop)
#include "Game.h"
#include "Qt/qapplication.h"
class MeGlWindow : public QGLWidget
{
	Game* m_game;
	QApplication* m_app;
public:
	MeGlWindow(QApplication* app, Game* game) :m_app(app), m_game(game) {};
	bool Shutdown();
protected:
	void initializeGL() {	Initialize();};
	bool Initialize();
	void paintGL();
};
#endif
