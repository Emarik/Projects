//#include "GL\glew.h"
#include "ShapeGenerator.h"
#include "Scene.h"
//#include "Helper.h"
//using namespace debugger;
static int cubeIndex = -1;
static int debugCubeIndex = -1;
static int lineIndex = -1;
static int gridIndex = -1;
static int planeIndex = -1;
static int filesUsed = 0;





ShapeData* ShapeGenerator::MakeCube()
{
	ShapeData ret;
	if (cubeIndex == -1)
	{
		Vertex verts[] = {
		Vertex(glm::vec3(-1.0f, +1.0f, +1.0f), // 0 
			   glm::vec3(+1.0f, +0.0f, +0.0f)), // Color
		Vertex(glm::vec3(+1.0f, +1.0f, +1.0f), // 1 
			   glm::vec3(+0.0f, +1.0f, +0.0f)), // Color
		Vertex(glm::vec3(+1.0f, +1.0f, -1.0f), // 2
			   glm::vec3(+0.0f, +0.0f, +1.0f)), // Color
		Vertex(glm::vec3(-1.0f, +1.0f, -1.0f), // 3  
			   glm::vec3(+1.0f, +1.0f, +1.0f)), // Color
		Vertex(glm::vec3(-1.0f, +1.0f, -1.0f), // 4  
			   glm::vec3(+1.0f, +0.0f, +1.0f)), // Color
		Vertex(glm::vec3(+1.0f, +1.0f, -1.0f), // 5  
			   glm::vec3(+0.0f, +0.5f, +0.2f)), // Color
		Vertex(glm::vec3(+1.0f, -1.0f, -1.0f), // 6  
			   glm::vec3(+0.8f, +0.6f, +0.4f)), // Color
		Vertex(glm::vec3(-1.0f, -1.0f, -1.0f), // 7
			   glm::vec3(+0.3f, +1.0f, +0.5f)), // Color
		Vertex(glm::vec3(+1.0f, +1.0f, -1.0f), // 8 
			   glm::vec3(+0.2f, +0.5f, +0.2f)), // Color
		Vertex(glm::vec3(+1.0f, +1.0f, +1.0f), // 9  
			   glm::vec3(+0.9f, +0.3f, +0.7f)), // Color
		Vertex(glm::vec3(+1.0f, -1.0f, +1.0f), // 10  
			   glm::vec3(+0.3f, +0.7f, +0.5f)), // Color
		Vertex(glm::vec3(+1.0f, -1.0f, -1.0f), // 11  
			   glm::vec3(+0.5f, +0.7f, +0.5f)), // Color
		Vertex(glm::vec3(-1.0f, +1.0f, +1.0f), // 12 
			   glm::vec3(+0.7f, +0.8f, +0.2f)), // Color
		Vertex(glm::vec3(-1.0f, +1.0f, -1.0f), // 13  
			   glm::vec3(+0.5f, +0.7f, +0.3f)), // Color
		Vertex(glm::vec3(-1.0f, -1.0f, -1.0f), // 14 
			   glm::vec3(+0.4f, +0.7f, +0.7f)), // Color
		Vertex(glm::vec3(-1.0f, -1.0f, +1.0f), // 15 
			   glm::vec3(+0.2f, +0.5f, +1.0f)), // Color
		Vertex(glm::vec3(+1.0f, +1.0f, +1.0f), // 16 
			   glm::vec3(+0.6f, +1.0f, +0.7f)), // Color
		Vertex(glm::vec3(-1.0f, +1.0f, +1.0f), // 17 
			   glm::vec3(+0.6f, +0.4f, +0.8f)), // Color
		Vertex(glm::vec3(-1.0f, -1.0f, +1.0f), // 18  
			   glm::vec3(+0.2f, +0.8f, +0.7f)), // Color
		Vertex(glm::vec3(+1.0f, -1.0f, +1.0f), // 19
			   glm::vec3(+0.2f, +0.7f, +1.0f)), // Color
		Vertex(glm::vec3(+1.0f, -1.0f, -1.0f), // 20 
			   glm::vec3(+0.8f, +0.3f, +0.7f)), // Color
		Vertex(glm::vec3(-1.0f, -1.0f, -1.0f), // 21  
			   glm::vec3(+0.8f, +0.9f, +0.5f)), // Color
		Vertex(glm::vec3(-1.0f, -1.0f, +1.0f), // 22  
			   glm::vec3(+0.5f, +0.8f, +0.5f)), // Color
		Vertex(glm::vec3(+1.0f, -1.0f, +1.0f), // 23  
			   glm::vec3(+0.9f, +1.0f, +0.2f)), // Color
		};
		unsigned short indicies[] = {
			0,   1,  2,  0,  2,  3, // Top 
			4,   5,  6,  4,  6,  7, // Front  
			8,   9, 10,  8, 10, 11, // Right  
			12, 13, 14, 12, 14, 15, // Left  
			16, 17, 18, 16, 18, 19, // Back 
			20, 22, 21, 20, 23, 22, // Bottom 
		};
		ret.numbVerts = sizeof(verts);
		ret.numbInd = sizeof(indicies);

		ret.verts = new Vertex[ret.numbVerts];
		memcpy(ret.verts, verts, ret.numbVerts);
		ret.indicies = new unsigned short[ret.numbInd];
		memcpy(ret.indicies, indicies, ret.numbInd);
		ret.type = GL_TRIANGLES; if (usedGeometries == MAXGEOMETRIES)
		{
			m_logs->Log(LOG_ERROR, "Not enough room for Geometries in array");
			return NULL;
		}
		ret.format = 3;
		cubeIndex = usedGeometries++;
		shapes[cubeIndex] = ret;
		
	}

	return &shapes[cubeIndex];
}

ShapeData *ShapeGenerator::MakeDebugCube(glm::vec3 color)
{
	ShapeData ret;
	if (debugCubeIndex == -1)
	{
		Vertex verts[]{
			Vertex(glm::vec3(-0.5f, 0.5f, -0.5f),color),
			Vertex(glm::vec3(-0.5f, -0.5f, -0.5f),color),
			Vertex(glm::vec3(0.5f, -0.5f, -0.5f),color),
			Vertex(glm::vec3(0.5f, 0.5f, -0.5f),color),
			Vertex(glm::vec3(-0.5f, 0.5f, 0.5f),color),
			Vertex(glm::vec3(-0.5f, -0.5f, 0.5f),color),
			Vertex(glm::vec3(0.5f, -0.5f, 0.5f),color),
			Vertex(glm::vec3(0.5f, 0.5f, 0.5f),color),
		};

		short indicies[] = { 1,2,2,3,4,5,5,6,4,7,7,3,5,1,0,1,0,3,0,4,7,6,6,2 };
		ret.numbVerts = sizeof(verts);
		ret.numbInd = sizeof(indicies);

		ret.verts = new Vertex[ret.numbVerts];
		memcpy(ret.verts, verts, sizeof(verts[0])*ret.numbVerts);
		ret.indicies = new unsigned short[ret.numbInd];
		memcpy(ret.indicies, indicies, sizeof(indicies[0])*ret.numbInd);
		ret.type = GL_LINES;
		if (usedGeometries == MAXGEOMETRIES)
		{
			m_logs->Log(LOG_ERROR, "Not enough room for Geometries in array");
			return NULL;
		}
		ret.format = 3;
		debugCubeIndex = usedGeometries++;
		shapes[debugCubeIndex] = ret;
	}
	return &shapes[debugCubeIndex];
}

ShapeData* ShapeGenerator::MakeLine(glm::vec3 pointA, glm::vec3 pointB, glm::vec3 color)
{
	ShapeData ret;
	if(lineIndex ==-1)
	{
		Vertex vert[] = {
		 Vertex(pointA,color),
		 Vertex(pointB,color)
		};
		unsigned short indicies[] = {
			 0, 1
		};
		ret.numbVerts = 2;
		ret.numbInd = 2;
		ret.verts = new Vertex[ret.numbVerts];
		ret.indicies = new unsigned short[ret.numbInd];
		memcpy(ret.verts, vert, sizeof(vert[0])*ret.numbVerts);
		memcpy(ret.indicies, indicies, sizeof(indicies[0])*ret.numbInd);
		ret.type = GL_LINES;
		if (usedGeometries == MAXGEOMETRIES)
		{
			m_logs->Log(LOG_ERROR, "Not enough room for Geometries in array");
			return NULL;
		}
		ret.format = 3;
		lineIndex = usedGeometries++;
		shapes[lineIndex] = ret;
	}
	return &shapes[lineIndex];
}


ShapeData * ShapeGenerator::MakeGrid(glm::vec3 color, int dim)
{
	if (gridIndex == -1)
	{
		if (usedGeometries == MAXGEOMETRIES)
		{
			m_logs->Log(LOG_ERROR, "Not enough room for Geometries in array");
			return NULL;
		}
		gridIndex = usedGeometries++;
		ShapeData* p = &shapes[gridIndex];
		p->numbInd = (dim + 1) * 4;
		p->numbVerts = (dim + 1) * 4;
		int point = dim / 2;
		Vertex *verts = new Vertex[shapes[gridIndex].numbVerts];
		p->verts = verts;
		p->format = 3;
		for (int I = 0; I < shapes[gridIndex].numbVerts; I+=4)
		{
			verts[I]   = Vertex(glm::vec3((float)point,      0.0f, (float)point - I/4),  color);
			verts[I+1] = Vertex(glm::vec3((float)-point,     0.0f, (float)point - I/4), color);
			verts[I+2] = Vertex(glm::vec3((float)point - I/4,  0.0f, (float)point),      color);
			verts[I+3] = Vertex(glm::vec3((float)point - I/4, 0.0f, (float)-point),     color);
		}
		shapes[gridIndex].indicies = new unsigned short[shapes[gridIndex].numbInd];
		for (int I = 0; I < shapes[gridIndex].numbInd; I++)
		{
			p->indicies[I] = (unsigned short)I;
		}
		shapes[gridIndex].type = GL_LINES;
		
	}
	return &shapes[gridIndex];
}


ShapeData* ShapeGenerator::MakePlane(glm::vec3 color)
{
	ShapeData ret;
	if (planeIndex == -1)
	{
		ret.numbVerts = 4;
		ret.numbInd = 6;
		Vertex verts[] = {
			Vertex(glm::vec3(1.0f,0.0f,1.0f),color),
			Vertex(glm::vec3(1.0f,0.0f,-1.0f),color),
			Vertex(glm::vec3(-1.0f,0.0f,1.0f),color),
			Vertex(glm::vec3(-1.0f,0.0f,-1.0f),color),
		};
		unsigned short indicies[] = {
			0,1,2,1,2,3
		};
		ret.verts = new Vertex[ret.numbVerts];
		ret.indicies = new unsigned short[ret.numbInd];
		memcpy(ret.verts, verts, sizeof(verts[0])*ret.numbVerts);
		memcpy(ret.indicies, indicies, sizeof(indicies[0])*ret.numbInd);
		ret.type = GL_TRIANGLES;
		if (usedGeometries == MAXGEOMETRIES)
		{
			m_logs->Log(LOG_ERROR, "Not enough room for Geometries in array");
			return NULL;
		}
		ret.format = 3;
		planeIndex = usedGeometries++;
		shapes[planeIndex] = ret;
	}
	return &shapes[planeIndex];
}

ShapeData* ShapeGenerator::MakeObject(std::string filename)
{
	int index = checkFile(filename);
	if (index == -1)
	{
		std::ifstream inputStream(filename, std::ios::binary | std::ios::in);
		if (!inputStream.good())
		{
			printf("ERROR : Unable to open scene file %s.\n", filename.c_str());
			return 0;
		}

		GLuint dataLen;
		inputStream.read(reinterpret_cast<char*> (&dataLen), sizeof(dataLen));
		printf("Reading %d bytes.\n", dataLen);

		char* data = new char[dataLen];
		assert(data);
		std::fill(data, data + dataLen - 1, 0);

		inputStream.read(data, dataLen);
		inputStream.close();

		Scene* temp= reinterpret_cast<Scene*> (data);
		char* p = data;
		p += sizeof(Scene);
		temp->verts = reinterpret_cast<void*> (p);
		p += temp->numbInd * temp->sizeVerts;
		if (temp->numbInd != 0)
			temp->indicies = reinterpret_cast<unsigned short*> (p);
		else
			temp->indicies = NULL;
		//temp->numbInd = temp->numbVerts;
		//unsigned short*c = temp->indicies;
		//for (int I = 0; I < temp->numbVerts; I++)
		//{
		//	*c = (unsigned short)I;
		//	c++;
		//}
		index = getNewFile(filename);
		shapes[index].type = GL_TRIANGLES;
		shapes[index].format = temp->format;
		shapes[index].numbVerts = temp->numbVerts;
		shapes[index].numbInd = temp->numbInd;
		shapes[index].sizeVerts = temp->sizeVerts;
		shapes[index].sizeInd = temp->sizeInd;
		shapes[index].verts = temp->verts;
		shapes[index].indicies = temp->indicies;
	}
	return &shapes[index];
}

int ShapeGenerator::checkFile(std::string filename)
{
	for (int I = 0; I < filesUsed; I++)
	{
		if (files[I] == filename)
		{
			return fileIndex[I];
		}
	}
	return -1;
}

int ShapeGenerator::getNewFile(std::string filename)
{
	files[filesUsed] = filename;
	fileIndex[filesUsed] = usedGeometries++;
	return fileIndex[filesUsed++];
}

ShapeGenerator::ShapeGenerator(Logger* logs)
{
	this->m_logs = logs;
	//memset(files, 0, sizeof(files[0])*MAXGEOMETRIES);
	//memset(files, -1, sizeof(files[0])*MAXGEOMETRIES);
}



ShapeGenerator::~ShapeGenerator()
{
}