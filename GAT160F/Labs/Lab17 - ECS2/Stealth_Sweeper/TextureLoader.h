#include "GL\glew.h"
#pragma once
#include "Logger.h"
class TextureLoader
{
public:
	Logger* m_logs;
	TextureLoader(Logger* log);
	GLuint loadBMP_custom(std::string filename);
	~TextureLoader();
};

