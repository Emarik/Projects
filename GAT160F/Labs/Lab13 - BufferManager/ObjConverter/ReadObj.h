#pragma once
#include "Config.h"
#include "Logger.h"
#include "glm.hpp"
#include "BinaryOutput.h"
#include "Vertexformats.h"
enum type
{
	VERTEX, NORMAL, COMMAND, INDEX, TEXTURE, NONE
};
class ReadObj
{
public:
	//BETTER WAY TO DO THIS COLOR?
	glm::vec3 color;
	bool givenColor = false;
	glm::vec3 *Vertexs;
	glm::vec3 *Colors;
	glm::vec2 *Textures;
	glm::vec3 *Normals;
	Index *Indexes;
	int VertexsUsed;
	int ColorsUsed;
	int TexturesUsed;
	int NormalsUsed;
	int IndexesUsed;
	int vertexType;
	Logger* m_logs;
	Config* m_config;
	std::string readFile;
	std::string writeFile;
	void GetFiles();
	void getConfigFeatures();
	void setArrays();
	void GoThroughFile();
	void readData(std::string str);
	void getVertex(std::string str);
	void getNormals(std::string str);
	void getTextures(std::string str);
	void getIndexes(std::string str);
	void ReadIndex(std::string str);
	type checkType(std::string str);
	void cleanUp();
	ReadObj(Logger* log, Config* config) :m_logs(log), m_config(config) {};
};

