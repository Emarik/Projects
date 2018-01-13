#include "MeGlWindow.h"

bool MeGlWindow::Initialize()
{
	if (!m_game->Initialize(this))
	{
		return Shutdown();
	}
	return true;
}

void MeGlWindow::paintGL()
{
	m_game->Update();
}

bool MeGlWindow::Shutdown()
{
	m_app->exit();
	return true;
}