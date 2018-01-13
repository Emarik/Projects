#pragma once
#include <fstream>
#include <GL\glew.h>
#include "Vertexformats.h"
#pragma warning(push)
#pragma warning(disable : 4201)
#include <glm.hpp>
#pragma warning(pop)

class BinaryOutput
{
public:
	// higher level functions
	//void WriteCustomBinaryFile(const char * filename, int numVerts, int numIndices, glm::vec3* vertices, glm::vec3* colors, glm::vec2 *textures, glm::vec3* normals, unsigned short* indices);
	void WriteCustomBinaryFile(const char * filename, int numVerts,  glm::vec3 * vertices, glm::vec3 * colors,  glm::vec2 *textures, glm::vec3 * normals, Index * indices, int format);
	int  WriteHeader(std::ofstream& out, int numVerts, int numIndices, int sizeVerts, int sizeIndices, int format);
	int  WriteVertexData(std::ofstream& out, int numVerts, glm::vec3* verts, glm::vec3* colors,  glm::vec2 *textures, glm::vec3* normals, Index* indices, int format);
	int  WriteIndices(std::ofstream& out, int numIndices, unsigned short* indices);

	// helper functions
	int WriteInt(std::ofstream& out, int       value);
	int WritePointer(std::ofstream& out, int       count);
	int WriteGLushort(std::ofstream& out, unsigned short  value);
	int WriteVec3(std::ofstream& out, glm::vec3 vec);
	int WriteVec2(std::ofstream & out, glm::vec2 vec);
};

