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

	float randomFloat()
	{
		return (float)rand() / RAND_MAX;
	}
	float randomInRange(float min, float max)
	{
		return randomFloat() * (max - min) + min;
	}

class Hill {
public:
	Hill() {};
	float timer = 0;
	glm::vec3 color = glm::vec3(1.0f, 1.0f, 1.0f);
	glm::mat4 trianglePos;
	void Update(float dt)
	{
		timer += dt;
		if (timer > 10)
		{
			timer = 0;
			float x = randomInRange(-.9f, .9f);
			float y = randomInRange(-.9f, .9f);
			trianglePos[3][0] = x;
			trianglePos[3][1] = y;
		}
	}
	void Draw()
	{
		GLint modelPositionUniformLocation = glGetUniformLocation(programID, "modelPositionMatrix");
		GLint dominatingColorUniformLocation = glGetUniformLocation(programID, "dominatingColor");

		glUniformMatrix4fv(modelPositionUniformLocation, 1, GL_FALSE, &trianglePos[0][0]);
		glUniform3fv(dominatingColorUniformLocation, 1, &color[0]);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_SHORT, 0);
	}

};
class Ship {
public:
	Ship() :color(1.0f, 1.0f, 1.0f) {};
	Ship(glm::vec3 Color) : color(Color) {};
	glm::mat4 trianglePos;
	float rotates = 0;
	int points = 0;
	glm::vec3 vel;
	glm::mat4x4 rotation;
	glm::mat4x4 translation;
	glm::vec3 color;
	bool win = false;
	void check(Hill* hill)
	{
		if (hill->trianglePos[3][0] > trianglePos[3][0] + .1  &&hill->trianglePos[3][0] > trianglePos[3][0] - .1 &&hill->trianglePos[3][1] > trianglePos[3][1] + .1  &&hill->trianglePos[3][1] > trianglePos[3][1] - .1)
		{
			points++;
		}
	}
	void Draw()
	{
		GLint modelPositionUniformLocation = glGetUniformLocation(programID, "modelPositionMatrix");
		GLint dominatingColorUniformLocation = glGetUniformLocation(programID, "dominatingColor");

		rotation = glm::rotate(rotation, rotates, glm::vec3(0.0f, 0.0f, 1.0f));
		glm::vec4 temp = rotation*glm::vec4(vel, 0.0f);
		vel = glm::vec3(temp);
		translation = glm::translate(translation, vel);
		trianglePos = translation * rotation;
		if (win)
		{
			trianglePos[3].z = -1.0f;
		}
		else
		{
			trianglePos[3].z = -.001f;
		}
		glUniformMatrix4fv(modelPositionUniformLocation, 1, GL_FALSE, &trianglePos[0][0]);
		glUniform3fv(dominatingColorUniformLocation, 1, &color[0]);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_SHORT, 0);
	}
};
Hill hill;
Ship ships[] = {
	Ship(glm::vec3(0.0f,1.0f,0.0f)),Ship(glm::vec3(1.0f,0.0f,0.0f))
};
//glm::mat4 trianglePos1;
//float rotates1 = 0;
//glm::vec3 vel1;
//glm::mat4x4 rotation1;
//glm::mat4x4 translation1;
//
//glm::mat4 trianglePos2;
//float rotates2 = 0;
//glm::vec3 vel2;
//glm::mat4x4 rotation2;
//glm::mat4x4 translation2;

bool Game::Initialize(MeGlWindow* window)
{
	this->m_window = window;
	BufferBind();
	installShaders();
	m_logs->Log(LOG_INFO,"Game Initalized");
	return true;
}

	GLfloat verts[] = {
		0.0f,0.1f, 0.0f,
		0.0f,0.0f,1.0f,
		-0.10f,-0.10f, 0.0f,
		1.0f,1.0f,1.0f,
		0.10f,-0.10f, 0.0f,
		1.0f,1.0f,1.0f
	};
	GLushort indicies[] = {
		0,1,2
	};

void Game::BufferBind()
{
	GLenum errorCode = glewInit();
	glEnable(GL_DEPTH_TEST);
	assert(errorCode == 0);
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
	glGenBuffers(1, &vertexBufferID);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);

	GLuint indexBufferID;
	glGenBuffers(1, &indexBufferID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indicies), indicies, GL_STATIC_DRAW);

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
		std::cout << "Shaders Failed the compile, Shutting down" << std::endl;
		return;
	}

	programID = glCreateProgram();
	glAttachShader(programID, vertexShaderID);
	glAttachShader(programID, fragmentShaderID);
	glLinkProgram(programID);
	if (!checkLinker(programID))
	{
		m_logs->Log(LOG_FATAL, " Program failed to link");
		std::cout << "Program failed to link, Shutting down" << std::endl;
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
//void drawing()
//{
//	GLint modelPositionUniformLocation = glGetUniformLocation(programID, "modelPositionMatrix");
//	GLint dominatingColorUniformLocation = glGetUniformLocation(programID, "dominatingColor");
//
//	ships[0].rotation = glm::rotate(ships[0].rotation, ships[0].rotates, glm::vec3(0.0f, 0.0f, 1.0f));
//	glm::vec4 temp = ships[0].rotation*glm::vec4(ships[0].vel, 0.0f);
//	ships[0].vel = glm::vec3(temp);
//	ships[0].translation = glm::translate(ships[0].translation, ships[0].vel);
//	ships[0].trianglePos = ships[0].translation * ships[0].rotation;
//	glUniformMatrix4fv(modelPositionUniformLocation, 1, GL_FALSE, &ships[0].trianglePos[0][0]);
//	glUniform3fv(dominatingColorUniformLocation, 1, &ships[0].color[0]);
//	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_SHORT, 0);
//
//	//Ship 2
//	ships[1].rotation = glm::rotate(ships[1].rotation, ships[1].rotates, glm::vec3(0.0f, 0.0f, 1.0f));
//	glm::vec4 temp2 = ships[1].rotation*glm::vec4(ships[1].vel, 0.0f);
//	ships[1].vel = glm::vec3(temp2);
//	ships[1].translation = glm::translate(ships[1].translation, ships[1].vel);
//	ships[1].trianglePos = ships[1].translation * ships[1].rotation;
//	glUniformMatrix4fv(modelPositionUniformLocation, 1, GL_FALSE, &ships[1].trianglePos[0][0]);
//	glUniform3fv(dominatingColorUniformLocation, 1, &ships[1].color[0]);
//	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_SHORT, 0);
//}
void Game::drawingSetup()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glViewport(0, 0, m_window->width(), m_window->height());
}
void Game::enablingVertex()
{
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6*sizeof(GL_FLOAT), 0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6*sizeof(GL_FLOAT), (char*)(3*sizeof(GL_FLOAT)));
}
void Rotate(float f,float* rotate)
{
	*rotate += f;
}
void Movement(float f,glm::vec3* vel)
{
	vel->y += f;
}
void Game::checkKeys(float dt)
{
	if (GetAsyncKeyState(VK_ESCAPE) || GetAsyncKeyState('X'))
	{
		this->Shutdown();
	}
	if (GetAsyncKeyState(VK_LEFT))
	{
		Rotate(50*dt,&ships[0].rotates);
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		Rotate(-50*dt, &ships[0].rotates);
	}
	if (GetAsyncKeyState(VK_UP))
	{
		Movement(2*dt,&ships[0].vel);
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		Movement(-2*dt,&ships[0].vel);
	}
	//Ship2
	if (GetAsyncKeyState('A'))
	{
		Rotate(100*dt, &ships[1].rotates);
	}
	if (GetAsyncKeyState('D'))
	{
		Rotate(-100*dt, &ships[1].rotates);
	}
	if (GetAsyncKeyState('W'))
	{
		Movement(1*dt, &ships[1].vel);
	}
	if (GetAsyncKeyState('S'))
	{
		Movement(-1*dt, &ships[1].vel);
	}
	if (GetAsyncKeyState('Q'))
	{
		ships[0].points += 100;
	}
	if (GetAsyncKeyState('E'))
	{
		ships[1].points += 100;
	}
}
bool Game::Update(float dt)
{
	
	drawingSetup();
	enablingVertex();
	ships[0].vel = glm::vec3();
	ships[0].rotates = 0;
	ships[1].vel = glm::vec3();
	ships[1].rotates = 0;
	checkKeys(dt);

	ships[0].check(&hill);
	ships[1].check(&hill);
	if (ships[0].points > ships[1].points && !ships[0].win)
	{
		ships[0].win = true;
		ships[1].win = false;
		std::cout << "Player One is in the lead!" << std::endl;
	}
	if (ships[0].points < ships[1].points && !ships[1].win)
	{
		ships[1].win = true;
		ships[0].win = false;
		std::cout << "Player Two is in the lead!" << std::endl;
	}
	ships[0].Draw();
	ships[1].Draw();
	hill.Update(dt);
	hill.Draw();
	

	return true;
}


