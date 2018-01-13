#include "BinaryOutput.h"

void BinaryOutput::WriteCustomBinaryFile(const char * filename, int numVerts, glm::vec3* vertices, glm::vec3* colors,glm::vec2 *textures, glm::vec3* normals, Index* indices, int format)
{
	int totalBytes = 0;
	std::ofstream outputStream(filename, std::ios::binary | std::ios::out);

	outputStream.seekp(0);
	WriteInt(outputStream, totalBytes);
	int dataSize = 0;
	if (format & HasPosition)
	{
		dataSize += sizeof(glm::vec3);
	}
	if (format & HasColor)
	{
		dataSize += sizeof(glm::vec3);
	}
	if (format & HasTexture)
	{
		dataSize += sizeof(glm::vec2);
	}
	if (format & HasNormal)
	{
		dataSize += sizeof(glm::vec3);
	}
	
	totalBytes += WriteHeader(outputStream, numVerts, 0, dataSize, sizeof(unsigned short),format);
	totalBytes += WriteVertexData(outputStream, numVerts, vertices, colors,textures, normals,indices,format);
	//totalBytes += WriteIndices(outputStream, numIndices, indices);

	outputStream.seekp(0);
	WriteInt(outputStream, totalBytes);
	outputStream.close();
	printf("Total : wrote %d bytes.\n", totalBytes);
}

int BinaryOutput::WriteHeader(std::ofstream & out, int numVerts, int numIndices, int sizeVerts, int sizeIndices, int format)
{
	int totalBytes = 0;
	totalBytes += WriteInt(out, format);
	totalBytes += WriteInt(out, numVerts);
	totalBytes += WriteInt(out, numIndices);
	totalBytes += WriteInt(out, sizeVerts);
	totalBytes += WriteInt(out, sizeIndices);
	totalBytes += WritePointer(out, 2);
	return totalBytes;
}

int BinaryOutput::WriteVertexData(std::ofstream & out, int numVerts, glm::vec3 * verts, glm::vec3 * colors, glm::vec2* textures, glm::vec3 * normals, Index* indices, int format)
{
	int totalBytes = 0;
	for (int j = 0; j < numVerts; ++j)
	{
		if (format & HasPosition)
			totalBytes += WriteVec3(out, verts[indices[j].indicies[positionVari]]);
		if (format & HasColor)
			totalBytes += WriteVec3(out, colors[indices[j].indicies[colorVari]]);
		if (format & HasNormal)
			totalBytes += WriteVec3(out, normals[indices[j].indicies[normalVari]]);
		if (format & HasTexture)
			totalBytes += WriteVec2(out, textures[indices[j].indicies[textureVari]]);
	}
	return totalBytes;
}

int BinaryOutput::WriteIndices(std::ofstream & out, int numIndices, unsigned short * indices)
{
	int totalBytes = 0;
	for (int j = 0; j < numIndices; ++j)
	{
		totalBytes += WriteGLushort(out, indices[j]);
	}
	return totalBytes;
}

// ----------------------------------------------------------------------
// Helper functions
// ----------------------------------------------------------------------

int BinaryOutput::WriteInt(std::ofstream & out, int value)
{
	int size = sizeof(int);
	out.write(reinterpret_cast<char*> (&value), size);
	return size;
}

int BinaryOutput::WritePointer(std::ofstream & out, int count)
{
	int    size = sizeof(void*);
	void* pointer = 0;
	for (int j = 0; j < count; ++j)
	{
		out.write(reinterpret_cast<char*> (&pointer), size);
	}
	return count * size;
}

int BinaryOutput::WriteVec3(std::ofstream & out, glm::vec3 vec)
{
	int size = sizeof(vec);
	out.write(reinterpret_cast<char*> (&vec), size);
	return size;
}
int BinaryOutput::WriteVec2(std::ofstream & out, glm::vec2 vec)
{
	int size = sizeof(vec);
	out.write(reinterpret_cast<char*> (&vec), size);
	return size;
}
int BinaryOutput::WriteGLushort(std::ofstream & out, unsigned short value)
{
	int size = sizeof(unsigned short);
	out.write(reinterpret_cast<char*> (&value), size);
	return size;
}

