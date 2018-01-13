#ifndef CUBE_H
#define CUBE_H
#include "Game.h"
#include "glm.hpp"
#include "GL/glew.h"
#include "ShapeData.h"
#include "ShapeGenerator.h"
#include "gtc\matrix_transform.hpp"
class Cube
{
	glm::mat4 trianglePos;
	glm::vec3 vel;
	glm::mat4x4 rotation;
	glm::mat4x4 translation;
	glm::vec3 color; 
	int width, height;
	GLuint *programID;

	
public:
	ShapeData data;
	float rotates = 40;
	Cube() :color(1.0f, 1.0f, 1.0f) {};
	Cube(int gamewidth, int gameheight,GLuint *gameprogramID, ShapeData s) :color(1.0f, 1.0f, 1.0f), width(gamewidth), height(gameheight),programID(gameprogramID), data(s) {};
	Cube(glm::vec3 Color) : color(Color) {};
	void Draw()
	{
		GLint modelPositionUniformLocation = glGetUniformLocation(*programID, "modelPositionMatrix");
		GLint dominatingColorUniformLocation = glGetUniformLocation(*programID, "dominatingColor");
		GLint projectionMatrixUniformLocation = glGetUniformLocation(*programID, "projectionMatrix");
		translation = glm::translate(glm::mat4(), glm::vec3(0.0f, 0.0f, -3.0f));
		rotation = glm::rotate(glm::mat4(), rotates, glm::vec3(1.0f, 1.0f, 0.0f));
		trianglePos = translation * rotation;
		glm::mat4 projectionMatrix = glm::perspective(60.0f, ((float)width / (float)height), .1f, 10.0f);

		glUniformMatrix4fv(modelPositionUniformLocation, 1, GL_FALSE, &trianglePos[0][0]);
		glUniformMatrix4fv(projectionMatrixUniformLocation, 1, GL_FALSE, &projectionMatrix[0][0]);
		glUniform3fv(dominatingColorUniformLocation, 1, &color[0]);
		glDrawElements(GL_TRIANGLES, data.numbInd, GL_UNSIGNED_SHORT, 0);
	}
};

#endif