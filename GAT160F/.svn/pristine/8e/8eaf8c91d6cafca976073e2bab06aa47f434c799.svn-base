#include "GL\glew.h"
#ifndef SHAPEDATA_H
#define SHAPEDATA_H
#pragma warning(push) 
#pragma warning(disable: 4201)
#include "glm.hpp"
#pragma warning(pop)
#include "BufferInfo.h"
struct Vertex
{
	glm::vec3 position;
	glm::vec3 color;
	Vertex(glm::vec3 pos, glm::vec3 colors) :position(pos), color(colors) {}
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
	unsigned int vertexByteOffset;
	unsigned int indexByteOffset;
	GLenum type;
	//GLuint vertexBufferID;
	//GLuint indexBufferID;
	//GLuint vertexArrayObjectID;
	bool use16BitIndicies;
	BufferInfo* buffer;
	void *verts;
	unsigned short* indicies;
	
	
	//bool isIndexed()
	//{
	//	if (numbInd == 0)
	//	{
	//		return false;
	//	}
	//	else
	//		return true;
	//}
	//bool is16BitIndicies()
	//{
	//	return use16BitIndicies;
	//}
	ShapeData() {};
	~ShapeData() {};
	void cleanUp() { delete verts; delete indicies; };
};

#endif