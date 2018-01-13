#pragma once
#include "Component.h"
#include "Renderable.h"
#include "ShapeGenerator.h"
class MeshComponent :
	public Component
{
public:
	MeshComponent();
	Renderable* renderable;
	void setRenderable(Renderable* render);
	~MeshComponent();
};

