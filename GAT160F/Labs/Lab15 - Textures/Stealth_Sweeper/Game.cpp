//#include "GL\glew.h"
#include "ShapeGenerator.h"
#include "Renderable.h"
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
#include "..\ObjConverter\Vertexformats.h"
//#include "Helper.h"

//GLuint vertexBufferID;
GLuint programID;
GLuint programIDTexture;


bool Game::Initialize(MeGlWindow* window)
{
	m_window = window;
	generator = new ShapeGenerator(m_logs);
	BufferBind();
	installShaders(&programID);
	installShaders(&programIDTexture);
	m_renderEngine.initialize(m_logs, m_window->width(), m_window->height());

	cube.setLogger(m_logs).setProgramID(&programID).setShape(generator->MakeObject("../Data/Scenes/Dargon.pc.scene"));// .setTexture("../Data/Textures/world_texture.bmp");
	dragon .setLogger(m_logs).setProgramID(&programID).setShape(generator->MakeObject("../Data/Scenes/SpecialCube.pctn.scene"));
	dragon2.setLogger(m_logs).setProgramID(&programID).setShape(generator->MakeObject("../Data/Scenes/Dargon.pc.scene"));
	for (int I = 0; I < generator->usedGeometries; I++)
	{
		m_renderEngine.addShape(&generator->shapes[I]);
	}
	m_renderEngine.addRenderable(&cube);
	m_renderEngine.addRenderable(&dragon);
	m_renderEngine.addRenderable(&dragon2);
	//m_logs->Log(LOG_ERROR, (char*)grid->data.numbInd);
	cam.Initialize(m_logs,m_config);
//	enablingVertex();
	m_logs->Log(LOG_INFO,"Game Initalized");
	return true;
}

void Game::BufferBind()
{
	GLenum errorCode = glewInit();
	glEnable(GL_DEPTH_TEST);
	assert(errorCode == 0);
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
	//BufferInfo* b = &m_renderEngine.manage.buffers[0];
	//for (int I = 0; I < m_renderEngine.manage.usedBuffers; I++)
	//{
	//	glBindBuffer(GL_ARRAY_BUFFER, b->vertexBufferID);
	//}
	
	//glBufferSubData()	
	/*for (int I = 0; I < generator->usedGeometries; I++)
	{
		glGenBuffers(1, &generator->shapes[I].vertexBufferID);
		glBindBuffer(GL_ARRAY_BUFFER, generator->shapes[I].vertexBufferID);
		int points = 0;
		if (generator->shapes[I].format & HasPosition)
			points += 3;
		if (generator->shapes[I].format & HasColor)
			points += 3;
		if (generator->shapes[I].format & HasTexture)
			points += 2;
		if (generator->shapes[I].format & HasNormal)
			points += 3;
		glBufferData(GL_ARRAY_BUFFER, generator->shapes[I].numbVerts*sizeof(glm::vec3)*2, generator->shapes[I].verts, GL_STATIC_DRAW);
		
		glGenBuffers(1, &generator->shapes[I].indexBufferID);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, generator->shapes[I].indexBufferID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, generator->shapes[I].numbInd*sizeof(unsigned short), generator->shapes[I].indicies, GL_STATIC_DRAW);
	}*/
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

void Game::installShaders(GLuint *programIDs)
{
	GLuint vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

	const char* adapter[1];
	std::string vertexCode;
	std::string fragmentCode;
	if (programIDs == &programID)
	{
		vertexCode = readShaderCode("../Data/Shaders/PassThrough.vert.shader");
		fragmentCode = readShaderCode("../Data/Shaders/PassThrough.frag.shader");
	}
	else if(programIDs == &programIDTexture)
	{
		vertexCode = readShaderCode("../Data/Shaders/PassThrough.vert.texture.shader");
		fragmentCode = readShaderCode("../Data/Shaders/PassThrough.frag.texture.shader");
	}
	else
	{
		m_logs->Log(LOG_ERROR, "Something happened to the program ID, none connected correctly");
		return;
	}
	//std::cout << vertexCode << std::endl;
	adapter[0] = vertexCode.c_str();
	glShaderSource(vertexShaderID, 1, adapter, 0);
	//std::cout << fragmentCode << std::endl;
	adapter[0] = fragmentCode.c_str();
	glShaderSource(fragmentShaderID, 1, adapter, 0);

	glCompileShader(vertexShaderID);
	glCompileShader(fragmentShaderID);
	if (!checkCompile(vertexShaderID) || !checkCompile(fragmentShaderID))
	{
		m_logs->Log(LOG_FATAL, "Shaders failed to compile");
		std::cout << "Shaders Failed the compile, Shutting down" << std::endl;
		return;
	}

	*programIDs = glCreateProgram();
	glAttachShader(*programIDs, vertexShaderID);
	glAttachShader(*programIDs, fragmentShaderID);
	glLinkProgram(*programIDs);
	if (!checkLinker(*programIDs))
	{
		m_logs->Log(LOG_FATAL, " Program failed to link");
		std::cout << "Program failed to link, Shutting down" << std::endl;
		return;
	}
	glUseProgram(*programIDs);
	m_logs->Log(LOG_INFO,"Shaders Intialized");
}


bool Game::Shutdown()
{
	m_window->Shutdown();
	m_logs->Log(LOG_INFO,"Game Shutdown");
	return true;
}

void Game::drawingSetup()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glViewport(0, 0, m_window->width(), m_window->height());
}
void Game::enablingVertex()
{
	/*for (int I = 0; I < generator->usedGeometries; I++)
	{
		glGenVertexArrays(1, &generator->shapes[I].vertexArrayObjectID);
		glBindVertexArray(generator->shapes[I].vertexArrayObjectID);
		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);
		glEnableVertexAttribArray(2);
		glEnableVertexAttribArray(3);
		glBindBuffer(GL_ARRAY_BUFFER, generator->shapes[I].vertexBufferID);
		switch (generator->shapes[I].format)
		{
			case PositionOnly:
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, 0);
				glVertexAttribPointer(1, 0, GL_FLOAT, GL_FALSE, sizeof(float) * 3, (char*)(sizeof(float) * 3));
				glVertexAttribPointer(2, 0, GL_FLOAT, GL_FALSE, sizeof(float) * 3, (char*)(sizeof(float) * 3));
				glVertexAttribPointer(3, 0, GL_FLOAT, GL_FALSE, sizeof(float) * 3, (char*)(sizeof(float) * 3));
				break;
			case PositionColor:
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, 0);
				glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (char*)(sizeof(float) * 3));
				glVertexAttribPointer(2, 0, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (char*)(sizeof(float) * 6));
				glVertexAttribPointer(3, 0, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (char*)(sizeof(float) * 6));
				break;
			case PositionColorTexture:
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 8, 0);
				glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 8, (char*)(sizeof(float) * 3));
				glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 8, (char*)(sizeof(float) * 6));
				glVertexAttribPointer(3, 0, GL_FLOAT, GL_FALSE, sizeof(float) * 8, (char*)(sizeof(float) * 8));
				break;
			case PositionColorTextureNormal:
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 11, 0);
				glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 11, (char*)(sizeof(float) * 3));
				glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 11, (char*)(sizeof(float) * 6));
				glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 11, (char*)(sizeof(float) * 8));
				break;
			case PositionColorNormal:
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 9, 0);
				glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 9, (char*)(sizeof(float) * 3));
				glVertexAttribPointer(2, 0, GL_FLOAT, GL_FALSE, sizeof(float) * 9, (char*)(sizeof(float) * 6));
				glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 9, (char*)(sizeof(float) * 6));
				break;
			case PositionTexture:
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 5, 0);
				glVertexAttribPointer(1, 0, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (char*)(sizeof(float) * 3));
				glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (char*)(sizeof(float) * 3));
				glVertexAttribPointer(3, 0, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (char*)(sizeof(float) * 5));
				break;
			case PositionTextureNormal:
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 8, 0);
				glVertexAttribPointer(1, 0, GL_FLOAT, GL_FALSE, sizeof(float) * 8, (char*)(sizeof(float) * 3));
				glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 8, (char*)(sizeof(float) * 3));
				glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 8, (char*)(sizeof(float) * 5));
				break;
			case PositionNormal:
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, 0);
				glVertexAttribPointer(1, 0, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (char*)(sizeof(float) * 3));
				glVertexAttribPointer(2, 0, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (char*)(sizeof(float) * 3));
				glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (char*)(sizeof(float) * 3));
				break;
		}
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, generator->shapes[I].indexBufferID);
		
			//glGenVertexArrays(1, &generator->shapes[I].vertexArrayObjectID);
			//glBindVertexArray(generator->shapes[I].vertexArrayObjectID);
			//glEnableVertexAttribArray(0);
			//glEnableVertexAttribArray(1);
			//glBindBuffer(GL_ARRAY_BUFFER, generator->shapes[I].vertexBufferID);
			//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, 0);
			//glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (char*)(sizeof(float) * 3));
			//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, generator->shapes[I].indexBufferID);
	}*/
}

bool pDown = false;

void Game::mouseMoveEvent(QMouseEvent *e)
{
	if (e->buttons() & Qt::RightButton)
	{
		cam.mouseRotate(glm::vec2(e->x(), e->y()));
	}
}

void Game::checkKeys(float dt)
{
	if (GetAsyncKeyState(VK_ESCAPE) || GetAsyncKeyState('X'))
	{
		this->Shutdown();
	}
	if (GetAsyncKeyState('P'))
	{
		if (!pDown)
		{
			pDown = true;
			if (m_paused)
				m_paused = false;
			else
				m_paused = true;
		}
	}
	else
	{
		pDown = false;
	}
	if (!m_paused)
	{
		if (GetAsyncKeyState('A'))
		{
			cam.moveStrafe(-10 * dt);
		}
		if (GetAsyncKeyState('D'))
		{
			cam.moveStrafe(10 * dt);
		}
		if (GetAsyncKeyState('W'))
		{
			cam.moveForward(10 * dt);
		}
		if (GetAsyncKeyState('S'))
		{
			cam.moveForward(-10 * dt);
		}
		if (GetAsyncKeyState('R'))
		{
			cam.moveUp(10 * dt);
		}
		if (GetAsyncKeyState('F'))
		{
			cam.moveUp(-10 * dt);
		}
	}
}

bool Game::Update(float dt)
{
	
	//drawingSetup();
	m_renderEngine.draw();
	checkKeys(dt);
	if (!m_paused)
	{
		dragon .Update(glm::vec3(0.0f, 0.0f, -3.0f), 40.0f);
		dragon2.Update(glm::vec3(5.0f, 0.0f, -3.0f),40.0f);
	}
	//GLuint matrixToWorldViewUniformLocation = glGetUniformLocation(programID, "matrixToWorldView");
	//glUniformMatrix4fv(matrixToWorldViewUniformLocation, 1, GL_FALSE, &cam.getWorldtoViewMat()[0][0]);
	glm::mat4 projectionMatrix = glm::perspective(60.0f, 1.6f /*((float)width / (float)height)*/, .001f, 500.0f);
	glm::mat4 matrix = projectionMatrix*cam.getWorldtoViewMat();
	m_renderEngine.drawAllRenderables(matrix);
	//cube->Draw(matrix);
	//dragon->Draw(matrix);
	//dragon2->Draw(matrix);
	//grid->Draw(matrix);
	

	return true;
}


