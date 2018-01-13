#include "GL\glew.h"
#include <cassert>
#include "Game.h"
#include <iostream>
#include <fstream>
#include "MeGlWindow.h"
#include "Logger.h"

bool Game::Initialize(MeGlWindow* window)
{
	this->m_window = window;
	BufferBind();
	installShaders();
	m_logs->Log("Game Initalized", LOG_INFO);
	return true;
}

void Game::BufferBind()
{
	glClearColor(0.0f, 1.0f, 1.0f, 1.0f);
	GLenum errorCode = glewInit();
	assert(errorCode == 0);

	glGenBuffers(1, &vertexBufferID);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID);
	float verts[] = {
		0.0f,0.1f,
		0.0f,0.0f,1.0f,
		-1.0f,-1.0f,
		0.0f,1.0f,1.0f,
		1.0f,-1.0f,
		1.0f,0.0f,1.0f
	};
	glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);
	m_logs->Log("Buffer Initialized", LOG_INFO);
}
std::string readShaderCode(const char* filename)
{
	std::ifstream input(filename);
	if (!input.good())
	{
		std::cout << "File failed to load" << std::endl;//log
		exit(1);
	}
	std::string ret = std::string(std::istreambuf_iterator<char>(input), std::istreambuf_iterator<char>());
	input.close();
	return ret;
}

bool checkCompile(GLuint shaderID)
{
	GLint compileStatus;
	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &compileStatus);
	if (compileStatus != GL_TRUE)
	{
		GLint infoLogLength;
		glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &infoLogLength);
		char* buffer = new char[infoLogLength];
		GLsizei bufferSize;
		glGetShaderInfoLog(shaderID, infoLogLength, &bufferSize, buffer);
		std::cout << buffer << std::endl;
		delete buffer;
		return false;
	}
	return true;
}

bool checkLinker(GLuint programIDe)
{

	GLint linkStatus;
	glGetProgramiv(programIDe, GL_LINK_STATUS, &linkStatus);
	if (linkStatus != GL_TRUE)
	{
		GLint infoLogLength;
		glGetProgramiv(programIDe, GL_INFO_LOG_LENGTH, &infoLogLength);
		char* buffer = new char[infoLogLength];
		GLsizei bufferSize;
		glGetProgramInfoLog(programIDe, infoLogLength, &bufferSize, buffer);
		std::cout << buffer << std::endl;
		delete buffer;
		return false;
	}
	return true;
}

void Game::installShaders()
{
	GLuint vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

	const char* adapter[1];
	std::string vertexCode = readShaderCode("../Data/Shaders/PassThrough.vert.shader");
	//std::cout << vertexCode << std::endl;
	adapter[0] = vertexCode.c_str();
	glShaderSource(vertexShaderID, 1, adapter, 0);
	std::string fragmentCode = readShaderCode("../Data/Shaders/PassThrough.frag.shader");
	//std::cout << fragmentCode << std::endl;
	adapter[0] = fragmentCode.c_str();
	glShaderSource(fragmentShaderID, 1, adapter, 0);

	glCompileShader(vertexShaderID);
	glCompileShader(fragmentShaderID);
	if (!checkCompile(vertexShaderID) || !checkCompile(fragmentShaderID))
	{
		return;
	}

	GLuint programID = glCreateProgram();
	glAttachShader(programID, vertexShaderID);
	glAttachShader(programID, fragmentShaderID);
	glLinkProgram(programID);
	if (!checkLinker(programID))
	{
		return;
	}
	glUseProgram(programID);
	m_logs->Log("Shaders Intialized", LOG_INFO);
}


bool Game::Shutdown()
{
	m_window->Shutdown();
	m_logs->Log("Game Shutdown", LOG_INFO);
	return true;
}
bool Game::Update()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glViewport(0, 0, m_window->width(), m_window->height());
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 5*sizeof(GL_FLOAT), 0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 5*sizeof(GL_FLOAT), (char*)(2*sizeof(GL_FLOAT)));
	glDrawArrays(GL_TRIANGLES, 0, 3);
	return true;
}

