#include "MeGlWindow.h"
#include "Logger.h"
#include "Game.h"
#include "Qt\qapplication.h"

bool MeGlWindow::Initialize()
{
	connect(&timer, SIGNAL(timeout()), this, SLOT(gameUpdate()));
	timer.start(0);
	if (!m_game->Initialize(this))
	{
		m_logs->Log(LOG_FATAL,"Window Initialize Failed");
		return Shutdown();
	}
	m_logs->Log(LOG_INFO,"Window Initialize Success");
	return true;
}

void MeGlWindow::gameUpdate()
{
	m_game->Update();
	repaint();
}

bool MeGlWindow::Shutdown()
{
	m_logs->Log(LOG_INFO,"Window Shutdown Success");
	m_app->exit();
	return true;
}