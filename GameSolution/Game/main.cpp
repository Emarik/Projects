#include "Engine.h"
#include "Core.h"
#include "Logger.h"

using Core::Input;
using Core::RGB;
using Core::Graphics;

const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 768;


bool Update( float )
{
	if ( Input::IsPressed( Input::KEY_ESCAPE ))
	{
		END_LOG
		return true;
	}
	return false;
}

void Draw( Graphics& graphics )
{
	graphics.SetColor( RGB(255,255,255) );
}


int main()
{
	LOG(Info, "Info <Message>");
	LOG(Warning, "Warning Message");
	LOG(Error, "Error Message");
	LOG(Severe, "Severe Message");
	Core::Init( "I Love Logging", SCREEN_WIDTH, SCREEN_HEIGHT );
	Core::RegisterUpdateFn( Update );
	Core::RegisterDrawFn ( Draw );
	Core::GameLoop();
}

