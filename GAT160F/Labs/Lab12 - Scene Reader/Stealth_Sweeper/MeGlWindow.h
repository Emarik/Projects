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
#pragma warning(push)
#pragma warning(disable:4127)
#pragma warning(disable:4251)
#include <QtGui\qmouseevent>
#pragma warning(pop)
//#include "Qt/qapplication.h"
class Logger;
class Game;
class QApplication;
class GameTimer;
class MeGlWindow : public QGLWidget
{
	Q_OBJECT

	
	Game* m_game;
	QApplication* m_app;
	QTimer timer;
	Logger *m_logs;
	GameTimer *m_gameTimer;
public:
	MeGlWindow(QApplication* app, Game* game, Logger *log,GameTimer *gameTimer) :m_app(app), m_game(game), m_logs(log), m_gameTimer(gameTimer) {};
	bool Shutdown();
protected:
	void initializeGL() {	Initialize();};
	bool Initialize();
	void mouseMoveEvent(QMouseEvent * e);
	//void paintGL();
private slots:
	void gameUpdate();
};
#endif
