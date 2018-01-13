#include "CameraComponent.h"



CameraComponent::CameraComponent()
{
}



Camera* CameraComponent::setActiveCamera()
{
	return &cam;
}

void CameraComponent::useMouseData(const glm::vec2 newMousePos)
{
	glm::vec2 mouseDelta(newMousePos - cam.oldMousePos);
	if (glm::length(mouseDelta) > 50.0f)
	{
		cam.oldMousePos = newMousePos;
		return;
	}
	float rot = 0.1f;
	glm::vec3 rightVector = glm::cross(cam.viewDirection, cam.UP);
	cam.viewDirection = glm::mat3(glm::rotate(glm::mat4(), -mouseDelta.x*rot, cam.UP))*
		glm::mat3(glm::rotate(glm::mat4(), -mouseDelta.y*rot, rightVector))*cam.viewDirection;
	cam.viewDirection = glm::normalize(cam.viewDirection);


	cam.oldMousePos = newMousePos;
}

void CameraComponent::mouseRotate(const glm::vec2 newMousePos)
{
	cam.mouseRotate(newMousePos);
}

void CameraComponent::moveStrafe(float move)
{
	cam.moveStrafe(move);
}

void CameraComponent::moveForward(float move)
{
	cam.moveForward(move);
}

void CameraComponent::moveUp(float move)
{
	cam.moveUp(move);
}

void CameraComponent::Initialize(Logger * logs, Config * config)
{
	cam.Initialize(logs, config);
}


CameraComponent::~CameraComponent()
{
}
