#include "ShaderInfo.h"
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
	glm::mat4 trianglePos = glm::mat4();
	glm::vec3 rotation;
	glm::vec3 translation;
	glm::vec3 scale;

	glm::vec3 color;
	Logger * m_logs;
	std::string name;
	GLuint textureImage;
	
	ShaderInfo* shader;
	Renderable& setShaderInfo(ShaderInfo* shader);
	Renderable& setName(std::string names);
	//Renderable& setProgramID(GLuint* gameprogramID);
	Renderable& setShape(ShapeData* data);
	Renderable& setLogger(Logger* logs);
	Renderable& setTexture(std::string filename);
	void Draw();
	void Update(glm::vec3 transform, glm::vec3 rotates);
	Renderable();
	//Renderable(int gamewidth, int gameheight, GLuint *gameprogramID, ShapeData* datas, Logger* logs) :width(gamewidth), height(gameheight), programID(gameprogramID), data(datas), m_logs(logs) {}
	~Renderable();
};

#endif