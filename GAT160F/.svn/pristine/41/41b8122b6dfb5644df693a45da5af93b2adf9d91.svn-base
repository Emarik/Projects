#pragma once
#include "Component.h"
#include "CameraComponent.h"
class MovementComponent :
	public Component
{
public:
	CameraComponent* cam;
	MovementComponent();
	void useMouseData(const glm::vec2 newMousePos);
	void setCameraComponent(CameraComponent*cams)  { cam = cams; };
	void moveStrafe(float move);
	void moveForward(float move);
	void moveUp(float move);
	~MovementComponent();
};

