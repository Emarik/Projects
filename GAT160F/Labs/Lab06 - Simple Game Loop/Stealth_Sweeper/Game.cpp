#include "GL\glew.h"
#include <cassert>
#include "Game.h"
#pragma warning(push)
#pragma warning(disable:4201)
#pragma warning(disable:4458)
#include "glm.hpp"
#pragma warning(pop)
#include "gtc\matrix_transform.hpp"
//#include <iostream>
//#include <fstream>
#include "MeGlWindow.h"
#include "Logger.h"
#include <Qt\qapplication.h>
#include "Helper.h"
GLuint programID; 
glm::mat4 trianglePos;
float rotates = 0;
glm::vec3 vel;
glm::mat4x4 rotation;
glm::mat4x4 translation;
bool Game::Initialize(MeGlWindow* window)
{
	this->m_window = window;
	BufferBind();
	installShaders();
	m_logs->Log(LOG_INFO,"Game Initalized");
	return true;
}

	float verts[] = {
		0.0f,0.1f,
		0.0f,0.0f,1.0f,
		-0.10f,-0.10f,
		0.0f,1.0f,1.0f,
		0.10f,-0.10f,
		1.0f,0.0f,1.0f
	};

void Game::BufferBind()
{
	GLenum errorCode = glewInit();
	assert(errorCode == 0);
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
	glGenBuffers(1, &vertexBufferID);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);
	m_logs->Log(LOG_INFO,"Buffer Initialized");
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
		m_logs->Log(LOG_FATAL, "Shaders failed to compile");
		return;
	}

	programID = glCreateProgram();
	glAttachShader(programID, vertexShaderID);
	glAttachShader(programID, fragmentShaderID);
	glLinkProgram(programID);
	if (!checkLinker(programID))
	{
		m_logs->Log(LOG_FATAL, " Program failed to link");
		return;
	}
	glUseProgram(programID);
	m_logs->Log(LOG_INFO,"Shaders Intialized");
}


bool Game::Shutdown()
{
	m_window->Shutdown();
	m_logs->Log(LOG_INFO,"Game Shutdown");
	return true;
}
void drawing()
{

}
void Game::drawingSetup()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glViewport(0, 0, m_window->width(), m_window->height());
}
void Game::enablingVertex()
{
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 5*sizeof(GL_FLOAT), 0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 5*sizeof(GL_FLOAT), (char*)(2*sizeof(GL_FLOAT)));
}
void Rotate(float f)
{
	rotates += f;
}
void Movement(float f)
{
	vel.y += f;
}
void Game::checkKeys()
{
	if (GetAsyncKeyState(VK_ESCAPE) || GetAsyncKeyState('X'))
	{
		this->Shutdown();
	}
	if (GetAsyncKeyState(VK_LEFT))
	{
		Rotate(-0.10f);
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		Rotate(0.10f);
	}
	if (GetAsyncKeyState(VK_UP))
	{
		Movement(0.001f);
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		Movement(-0.001f);
	}
}
bool Game::Update()
{
	
	drawingSetup();
	enablingVertex();
	vel = glm::vec3();
	rotates = 0;
	checkKeys();
	
	
	rotation = glm::rotate(rotation, rotates, glm::vec3(0.0f, 0.0f, 1.0f));
	glm::vec4 temp = rotation*glm::vec4(vel,0.0f);
	vel = glm::vec3(temp);
	translation = glm::translate(translation,vel);
	trianglePos = translation * rotation;
	//debugger::printVari(trianglePos);
	GLint modelPositionUniformLocation = glGetUniformLocation(programID, "modelPositionMatrix");
	glUniformMatrix4fv(modelPositionUniformLocation, 1, GL_FALSE,&trianglePos[0][0] );
	//glUniformMatrix4fv(modelPositionUniformLocation, 1, GL_FALSE,(float*)&trianglePos );


	glDrawArrays(GL_TRIANGLES, 0, 3);
	return true;
}


