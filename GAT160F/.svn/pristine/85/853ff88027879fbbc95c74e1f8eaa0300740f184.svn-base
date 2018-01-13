#include "ReadObj.h"
//#include "Config.h"
//#include "Logger.h"

int main(int argc, char** argv)
{
	Logger log;
	log.Initialize("../Data/ObjConverter.log");
	Config config(&log);
	config.Initialize("../Data/Config.txt");
	ReadObj obj(&log,&config);
	obj.GetFiles();
	
}