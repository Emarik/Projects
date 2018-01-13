#pragma warning(push)
#pragma warning(disable:4127)
#include "qt/qapplication.h"
//#include "QtGui/qwidget.h"
#pragma warning(pop)
#include "MeGlWindow.h"
#include "Game.h"

int main(int argc, char**argv)
{
	QApplication app(argc, argv);
	Game game;
	MeGlWindow *gameWindow = new MeGlWindow(&app,&game);
	gameWindow->show();
	int appResult = app.exec();
	return appResult;
}