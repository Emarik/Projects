#ifndef MEGLWINDOW_H
#define MEGLWINDOW_H
#pragma warning(push)
#pragma warning(disable:4127)
#pragma warning(disable:4251)
#pragma warning(disable:4800)
#include "QtOpenGL/QGLWidget"
#pragma warning(pop)
#pragma warning(push)
#pragma warning(disable:4127)
#include "Qt/qtimer.h"
#pragma warning(pop)
//#include "Qt/qapplication.h"
class Logger;
class Game;
class QApplication;
class MeGlWindow : public QGLWidget
{
	Q_OBJECT

	Game* m_game;
	QApplication* m_app;
	QTimer timer;
	Logger *m_logs;
public:
	MeGlWindow(QApplication* app, Game* game, Logger *log) :m_app(app), m_game(game), m_logs(log) {};
	bool Shutdown();
protected:
	void initializeGL() {	Initialize();};
	bool Initialize();
	//void paintGL();
private slots:
	void gameUpdate();
};
#endif
