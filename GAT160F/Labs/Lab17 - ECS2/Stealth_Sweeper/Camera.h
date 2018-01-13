#ifndef CAMERA_H
#define CAMERA_H
#include "Logger.h"
#include "Config.h"
#pragma warning(push)
#pragma warning(disable:4201)
#include "glm.hpp"
#pragma warning(pop)
#include "gtc\matrix_transform.hpp"
class Camera
{
	Logger* m_logs;
	Config* m_config;
public:
	glm::vec3 viewDirection;
	glm::vec3 UP;
	glm::vec2 oldMousePos;
	glm::vec3 pos;
	Camera();
	~Camera();
	void mouseRotate(const glm::vec2 newMousePos);
	void moveStrafe(float move);
	void moveForward(float move);
	void moveUp(float move);
	bool Initialize(Logger* log,Config* config);
	bool Shutdown();
	glm::mat4 getWorldtoViewMat();
};

#endif