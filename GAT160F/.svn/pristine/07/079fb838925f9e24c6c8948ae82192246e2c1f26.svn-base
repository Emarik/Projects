#pragma warning(push)
#pragma warning(disable:4127)
#include "qt/qapplication.h"
//#include "QtGui/qwidget.h"
#pragma warning(pop)
#include "MeGlWindow.h"
#include "Game.h"
#include "Logger.h"
#include "Config.h"
#include "GameTimer.h"

int main(int argc, char**argv)
{
	Logger logs;
	logs.Initialize("../Data/StealthSweeper.log");
	Config config(&logs);
	config.Initialize("../Data/Config.txt");
	GameTimer gametimer(&logs);
	gametimer.Initialize();
	QApplication app(argc, argv);
	Game game(&logs);
	MeGlWindow *gameWindow = new MeGlWindow(&app,&game,&logs,&gametimer);
	gameWindow->show();
	int appResult = app.exec();
	gametimer.Shutdown();
	config.Shutdown();
	logs.Shutdown();
	return appResult;
}