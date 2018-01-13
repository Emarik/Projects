#pragma once
#include "Component.h"
#pragma warning(push)
#pragma warning(disable:4201)
#pragma warning(disable:4458)
#include "glm.hpp"
#pragma warning(pop)
#include "Camera.h"
class CameraComponent :
	public Component
{
public:
	CameraComponent();
	Camera cam;
	Camera* setActiveCamera();
	void useMouseData(const glm::vec2 newMousePos);
	void mouseRotate(const glm::vec2 newMousePos);
	void moveStrafe(float move);
	void moveForward(float move);
	void moveUp(float move);
	void Initialize(Logger* logs, Config* config);
	~CameraComponent();
};

