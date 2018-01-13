#include "ReadObj.h"
#include <string.h>
#include "sstream"
#define MAXVERTEXES 5000000
#define MAXINDEXES  5000000
int maxVerts = 0;
int maxIndex = 0;
float randomFloat()
{
	return (float)rand() / RAND_MAX;
}
float randomInRange(float min, float max)
{
	return randomFloat() * (max - min) + min;
}
void ReadObj::GetFiles()
{
	getConfigFeatures();
	if (maxVerts == 0)
	{
		maxVerts = MAXVERTEXES;
	}
	if (maxIndex == 0)
	{
		maxIndex = MAXINDEXES;
	}
	setArrays();
	if (!readFile.empty() && !writeFile.empty())
	{
		GoThroughFile();
	}
	else
	{
		m_logs->Log(LOG_ERROR, "Read or Write file not found");
	}
	BinaryOutput b;
	b.WriteCustomBinaryFile(writeFile.c_str(), IndexesUsed,Vertexs,Colors,Textures,Normals,Indexes,vertexType);
}

void ReadObj::getConfigFeatures()
{
	vertexType = PositionColorTextureNormal;
	for (int I = 0; I<m_config->usedValues; I++)
	{
		if (m_config->keys[I] == ("ObjConverter.ReadFile"))
		{
			readFile = m_config->values[I];
		}
		else if (m_config->keys[I] == ("ObjConverter.WriteFile"))
		{
			writeFile = m_config->values[I];
		}
		else if (m_config->keys[I] == ("ObjConverter.VertexSize"))
		{
			maxVerts = m_config->getIntFromString(m_config->values[I]);
		}
		else if (m_config->keys[I] == ("ObjConverter.IndexSize"))
		{
			maxIndex = m_config->getIntFromString(m_config->values[I]);
		}
		else if (m_config->keys[I] == ("ObjConverter.VertexType"))
		{
			vertexType = m_config->getIntFromString(m_config->values[I]);
		}
		else if (m_config->keys[I] == ("ObjConverter.Color"))
		{
			float colors[3];
			m_config->getFloatsFromString(m_config->values[I], colors, 3);
			color = glm::vec3(colors[0], colors[1], colors[2]);
			givenColor = true;
		}
	}
	std::string vertexWriteFileType;
	switch (vertexType)
	{
	case PositionOnly:
		vertexWriteFileType = ".P";
		break;
	case PositionColor:
		vertexWriteFileType = ".PC";
		break;
	case PositionColorTexture:
		vertexWriteFileType = ".PCT";
		break;
	case PositionColorTextureNormal:
		vertexWriteFileType = ".PCTN";
		break;
	case PositionTexture:
		vertexWriteFileType = ".PT";
		break;
	case PositionTextureNormal:
		vertexWriteFileType = ".PTN";
		break;
	case PositionNormal:
		vertexWriteFileType = ".PN";
		break;
	}
	int writeEndPeriod = writeFile.find_last_of('.');
	writeFile = writeFile.substr(0, writeEndPeriod) + vertexWriteFileType + writeFile.substr(writeEndPeriod);
}
//PCTN
//if(c&HasPosition){} and those, using and bitoperator
void ReadObj::setArrays()
{
	if (vertexType & HasPosition)
	{
		Vertexs = new glm::vec3[maxVerts];
	}
	if (vertexType & HasColor)
	{
		Colors = new glm::vec3[maxVerts];
	}
	if (vertexType & HasTexture)
	{
		Textures = new glm::vec2[maxVerts];
	}
	if (vertexType & HasNormal)
	{
		Normals = new glm::vec3[maxVerts];
	}
	Indexes = new Index[maxIndex];
	IndexesUsed	 = 0;
	VertexsUsed = 0;
	ColorsUsed = 0;
	TexturesUsed = 0;
	NormalsUsed = 0;
}

void ReadObj::GoThroughFile()
{
	std::ifstream inputStream(readFile, std::ios::in);
	std::string str;
	if (!inputStream.good())
	{
		m_logs->Log(LOG_ERROR, "Read file failed to stream good");
		return;
	}
	while (std::getline(inputStream, str))
	{
		if (!m_config->IsBlankOrCommentwithPound(str))
		{
			readData(str);
		}
	}
}

void ReadObj::readData(std::string str)
{
	int startType = m_config->findNextNonBlank(str, 0);
	int endType=str.find(' ', startType + 1);
	type stringType = checkType(str.substr(startType, endType - startType));
	std::string data = str.substr(m_config->findNextNonBlank(str, endType));
	switch (stringType)
	{
	case VERTEX:
		if (vertexType & HasPosition)
		{
			getVertex(data);
		}
		if (vertexType & HasColor)
		{                                
			if (givenColor)
			{
				Colors[ColorsUsed++] = color;
			}
			else
			{
				Colors[ColorsUsed++] = glm::vec3(randomInRange(0,1), randomInRange(0, 1),randomInRange(0, 1));
			}
		}
		break;
	case TEXTURE:
		if (vertexType & HasTexture)
		{
			getTextures(data);
		}
		break;
	case NORMAL:
		if (vertexType & HasNormal)
		{
			getNormals(data);
		}
		break;
	case INDEX:
		getIndexes(data);
		break;
	}
}

void ReadObj::getVertex(std::string str)
{
	float numbers[3];
	if (m_config->getFloatsFromString(str, numbers, 3) != 3)
	{
		m_logs->Log(LOG_INFO, "2D Vertex Data");
	}
	Vertexs[VertexsUsed++] = glm::vec3(numbers[0], numbers[1], numbers[2]);
}

void ReadObj::getNormals(std::string str)
{
	float numbers[3];
	if (m_config->getFloatsFromString(str, numbers, 3) != 3)
	{
		m_logs->Log(LOG_INFO, "2D Normals Data");
	}
	Normals[NormalsUsed++] = glm::vec3(numbers[0], numbers[1], numbers[2]);
}

void ReadObj::getTextures(std::string str)
{
	float numbers[2];
	if (m_config->getFloatsFromString(str, numbers, 2) != 2)
	{
		m_logs->Log(LOG_INFO, "Texture Data failed");
	}
	Textures[TexturesUsed++] = glm::vec2(numbers[0], numbers[1]);
}

void ReadObj::getIndexes(std::string str)
{
	int start = 0;
	int end = 0;
	start = m_config->findNextNonBlank(str, end);
	while (end !=-1 )
	{
		end = str.find(' ', start + 1);
		ReadIndex(str.substr(start, end - start));
		std::string temp = str.substr(start, end - start);
		if(end != -1)
			start = m_config->findNextNonBlank(str, end);
	}
}

void ReadObj::ReadIndex(std::string str)
{
	int first=str.find('/');
	int second = str.find('/', first + 1);
	if (first == -1)
	{
		Indexes[IndexesUsed].indicies[positionVari] = m_config->getIntFromString(str);
	}
	else if (second == first + 1)
	{
		Indexes[IndexesUsed].indicies[positionVari] = m_config->getIntFromString(str.substr(0, first));
		Indexes[IndexesUsed].indicies[normalVari] = m_config->getIntFromString(str.substr(second+1));
	}
	else if (second == -1)
	{
		Indexes[IndexesUsed].indicies[positionVari] = m_config->getIntFromString(str.substr(0, first));
		Indexes[IndexesUsed].indicies[textureVari] = m_config->getIntFromString(str.substr(first+1));
	}
	else
	{
		Indexes[IndexesUsed].indicies[positionVari] = m_config->getIntFromString(str.substr(0, first));
		Indexes[IndexesUsed].indicies[textureVari] = m_config->getIntFromString(str.substr(first+1,second-first));
		Indexes[IndexesUsed].indicies[normalVari] = m_config->getIntFromString(str.substr(second+1));
	}
	Indexes[IndexesUsed].indicies[colorVari] = Indexes[IndexesUsed].indicies[positionVari];
	IndexesUsed++;
}

type ReadObj::checkType(std::string str)
{
	if (str == "v")
	{
		return VERTEX;
	}
	else if (str == "vt")
	{
		return TEXTURE;
	}
	else if (str == "vn")
	{
		return NORMAL;
	}
	else if (str == "f")
	{
		return INDEX;
	}
	else if (str == "g")
	{
		return COMMAND;
	}
	else
	{
		return NONE;
	}
}

void ReadObj::cleanUp()
{
	delete[] Vertexs;
	delete[] Indexes;
	delete[] Normals;
	delete[] Textures;
}