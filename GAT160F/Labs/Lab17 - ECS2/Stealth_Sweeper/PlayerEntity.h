#pragma once
#include "Entity.h"
class PlayerEntity :
	public Entity
{
public:
	PlayerEntity();
	bool Draw();
	~PlayerEntity();
};

