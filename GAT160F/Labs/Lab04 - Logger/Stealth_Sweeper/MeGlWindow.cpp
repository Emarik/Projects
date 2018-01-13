#include "MeGlWindow.h"
#include "Logger.h"
#include "Game.h"
#include "Qt\qapplication.h"

bool MeGlWindow::Initialize()
{
	if (!m_game->Initialize(this))
	{
		m_logs->Log("Window Initialize Failed", LOG_FATAL);
		return Shutdown();
	}
	m_logs->Log("Window Initialize Success", LOG_INFO);
	return true;
}

void MeGlWindow::paintGL()
{
	m_game->Update();
}

bool MeGlWindow::Shutdown()
{
	m_logs->Log("Window Shutdown Success", LOG_INFO);
	m_app->exit();
	return true;
}