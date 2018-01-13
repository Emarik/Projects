#include "GL\glew.h"
#ifndef SHAPEDATA_H
#define SHAPEDATA_H
#pragma warning(push) 
#pragma warning(disable: 4201)
#include "glm.hpp"
#pragma warning(pop)
//define struct shapeheader
struct Vertex
{
	glm::vec3 position;
	glm::vec3 color;
	Vertex(glm::vec3 pos, glm::vec3 colors) :position(pos), color(colors) {};
	Vertex() {};
};

class ShapeData
{
public:
	int format;
	int numbVerts;
	int numbInd;
	int sizeVerts;
	int sizeInd;
	GLenum type;
	GLuint vertexBufferID;
	GLuint indexBufferID;
	GLuint vertexArrayObjectID;
	void *verts;
	unsigned short* indicies;
	
	

	ShapeData() {};
	~ShapeData() {};
	void cleanUp() { delete verts; delete indicies; };
};

#endif