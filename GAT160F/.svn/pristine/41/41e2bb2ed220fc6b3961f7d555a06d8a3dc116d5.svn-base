#pragma once
#include "Component.h"
#include "MovementComponent.h"
class MouseComponent :
	public Component
{
public:
	MovementComponent* movement;
	void setMovementComponent(MovementComponent* move) { movement = move; };
	void mouseUpdate(const glm::vec2 newMousePos);
	MouseComponent();
	~MouseComponent();
};

