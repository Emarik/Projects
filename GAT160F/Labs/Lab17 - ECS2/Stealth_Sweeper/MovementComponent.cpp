#include "MovementComponent.h"



MovementComponent::MovementComponent()
{
}

void MovementComponent::useMouseData(const glm::vec2 newMousePos)
{
	cam->useMouseData(newMousePos);
}

void MovementComponent::moveStrafe(float move)
{
	cam->moveStrafe(move);
}

void MovementComponent::moveForward(float move)
{
	cam->moveForward(move);
}

void MovementComponent::moveUp(float move)
{
	cam->moveUp(move);
}


MovementComponent::~MovementComponent()
{
}
