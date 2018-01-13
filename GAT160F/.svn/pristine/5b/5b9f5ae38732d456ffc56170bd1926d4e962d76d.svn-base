#pragma warning(push)
#pragma warning(disable:4127)
#include "qt/qapplication.h"
//#include "QtGui/qwidget.h"
#pragma warning(pop)
#include "MeGlWindow.h"
#include "Game.h"
#include "Logger.h"
#include "Config.h"

int main(int argc, char**argv)
{
	Logger logs;
	logs.Initialize("../Data/StealthSweeper.log");
	Config config(&logs);
	config.Initialize("../Data/Config.txt");
	QApplication app(argc, argv);
	Game game(&logs);
	MeGlWindow *gameWindow = new MeGlWindow(&app,&game,&logs);
	gameWindow->show();
	int appResult = app.exec();
	logs.Shutdown();
	return appResult;
}