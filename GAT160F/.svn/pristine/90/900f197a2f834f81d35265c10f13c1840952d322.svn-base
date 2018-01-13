#include "KeyboardComponent.h"
#include "Windows.h"


KeyboardComponent::KeyboardComponent()
{
}
void KeyboardComponent::checkKeys(float dt)
{
	//if (GetAsyncKeyState(VK_ESCAPE) || GetAsyncKeyState('X'))
	//{
	//	this->Shutdown();
	//}
	//if (GetAsyncKeyState('P'))
	//{
	//	if (!pDown)
	//	{
	//		pDown = true;
	//		if (m_paused)
	//			m_paused = false;
	//		else
	//			m_paused = true;
	//	}
	//}
	//else
	//{
	//	pDown = false;
	//}
	//if (!m_paused)
	//{
	if (GetAsyncKeyState('A'))
	{
		movement->moveStrafe(-10 * dt);
	}
	if (GetAsyncKeyState('D'))
	{
		movement->moveStrafe(10 * dt);
	}
	if (GetAsyncKeyState('W'))
	{
		movement->moveForward(10 * dt);
	}
	if (GetAsyncKeyState('S'))
	{
		movement->moveForward(-10 * dt);
	}
	if (GetAsyncKeyState('R'))
	{
		movement->moveUp(10 * dt);
	}
	if (GetAsyncKeyState('F'))
	{
		movement->moveUp(-10 * dt);
	}
	//}
}

KeyboardComponent::~KeyboardComponent()
{
}
