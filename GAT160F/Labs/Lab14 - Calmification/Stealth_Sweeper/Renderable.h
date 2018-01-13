#include "GL\glew.h"
#ifndef RENDERABLE_H
#define RENDERABLE_H
#include "Logger.h"
#pragma warning(push) 
#pragma warning(disable: 4201)
#include "glm.hpp"
#pragma warning(pop)
class ShapeData;
class Renderable
{
public:
	ShapeData* data;
	glm::mat4 trianglePos;
	glm::vec3 vel;
	glm::mat4x4 rotation;
	glm::mat4x4 translation;
	glm::mat4x4 scale;
	glm::vec3 color;
	Logger * m_logs;
	GLuint *programID;
	int width, height;
	void Draw(glm::mat4 matrix);
	void Update(glm::vec3 transform, float rotates);
	Renderable();
	Renderable(int gamewidth, int gameheight, GLuint *gameprogramID, ShapeData* datas, Logger* logs) :width(gamewidth), height(gameheight), programID(gameprogramID), data(datas), m_logs(logs) {}
	~Renderable();
};

#endif