#include "Camera.h"



Camera::Camera() :viewDirection(0.0f, 0.0f, -1.0f), UP(0.0f, 1.0f, 0.0f)
{
}


Camera::~Camera()
{
}

void Camera::mouseRotate(const glm::vec2 newMousePos)
{
	//glm::vec2 mouseDelta(newMousePos - oldMousePos);
	//if (glm::length(mouseDelta) > 50.0f)
	//{
	//	oldMousePos = newMousePos;
	//	return;
	//}
	//float rot = 0.1f;
	//glm::vec3 rightVector = glm::cross(viewDirection, UP);
	//viewDirection = glm::mat3(glm::rotate(glm::mat4(),-mouseDelta.x*rot, UP))*
	//				glm::mat3(glm::rotate(glm::mat4(),-mouseDelta.y*rot, rightVector))*viewDirection;
	//viewDirection = glm::normalize(viewDirection);
	//
	//
	//oldMousePos = newMousePos;
}

void Camera::moveStrafe(float move)
{
	glm::vec3 strafeDirection = glm::cross(viewDirection, UP);
	pos += move*strafeDirection;
}

void Camera::moveForward(float move)
{
	pos += move*viewDirection;
}

void Camera::moveUp(float move)
{
	pos += move*UP;
}

bool Camera::Initialize(Logger* logs, Config* config)
{
	m_logs = logs;
	m_config = config;
	m_logs->Log(LOG_INFO, "Camera Initialize");
	return false;
}

bool Camera::Shutdown()
{
	m_logs->Log(LOG_INFO, "Camera Shutdown");
	return false;
}
glm::mat4 Camera::getWorldtoViewMat()
{
	glm::mat4 ret = glm::lookAt(pos, pos + viewDirection, UP);
	return ret;
}