#include "ShapeData.h"
#ifndef SHAPEGENERATOR_H
#define SHAPEGENERATOR_H
#include "Logger.h"
#pragma warning(push)
#pragma warning(disable:4201)
#include "glm.hpp"
#pragma warning(pop)
#define MAXGEOMETRIES 10
//#include "Helper.h"
class ShapeGenerator
{
public:
	Logger* m_logs;
	ShapeData* MakeCube();
	ShapeData* MakeDebugCube(glm::vec3 color);
	ShapeData* MakeLine(glm::vec3 pointA, glm::vec3 pointB, glm::vec3 color);
	ShapeData* MakeGrid(glm::vec3 color, int dim);
	ShapeData * MakePlane(glm::vec3 color);
	ShapeData * MakeObject(std::string filename);
	int checkFile(std::string filename);
	int getNewFile(std::string filename);
	ShapeGenerator(Logger*logs);
	ShapeGenerator() {};
	~ShapeGenerator();
	int usedGeometries = 0;
	ShapeData shapes[MAXGEOMETRIES];
	std::string files[MAXGEOMETRIES];
	int fileIndex[MAXGEOMETRIES];
};

#endif