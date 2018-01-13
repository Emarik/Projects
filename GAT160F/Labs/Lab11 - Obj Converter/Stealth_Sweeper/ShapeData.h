#include "GL\glew.h"
#ifndef SHAPEDATA_H
#define SHAPEDATA_H
#pragma warning(push) 
#pragma warning(disable: 4201)
#include "glm.hpp"
#pragma warning(pop)
struct Vector
{
	glm::vec3 position;
	glm::vec3 color;
	Vector(glm::vec3 pos, glm::vec3 colors) :position(pos), color(colors) {};
	Vector() {};
};

class ShapeData
{
public:
	int numbInd;
	int numbVerts;
	unsigned short* indicies;
	Vector *verts;
	GLenum type;
	GLuint vertexBufferID;
	GLuint indexBufferID;
	GLuint vertexArrayObjectID;
	
	ShapeData() {};
	~ShapeData() {};
	void cleanUp() { delete verts; delete indicies; };
};

#endif