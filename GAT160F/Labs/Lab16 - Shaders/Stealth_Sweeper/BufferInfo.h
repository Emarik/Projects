#pragma once
#include "GL\glew.h"
#include "Renderable.h"
#include "LinkedList.h"
class BufferInfo
{
public:
	BufferInfo() {};
	BufferInfo(int formats) :format(formats) {};
	~BufferInfo() {};;
	int MAX_BUFFER_SIZE = 1000000;
	int vertexByteOffset = 0;
	int indexByteOffset = 0;
	GLuint vertexArrayObjectID;
	GLuint vertexBufferID;
	GLuint indexBufferID;
	int format;
	LinkedList renderables;
};

