#pragma once
#include "Component.h"
#include "MovementComponent.h"
class KeyboardComponent :
	public Component
{
public:
	MovementComponent* movement;
	void setMovementController(MovementComponent* move) { movement = move;};
	//void(*moveStrafe)(float);
	//void(*moveForward)(float);
	//void(*moveUp)(float);
	//void setMoveStrafe(void(*moveStrafes)(float))   { this->moveStrafe = moveStrafes; };
	//void setMoveForward(void(*moveForwards)(float)) {this->moveForward = moveForwards;};
	//void setMoveUp(void(*moveUps)(float))           { this->moveUp = moveUps; };
	KeyboardComponent();
	void checkKeys(float dt);
	~KeyboardComponent();
};

