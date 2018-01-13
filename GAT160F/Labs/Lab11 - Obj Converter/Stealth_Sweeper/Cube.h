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
	GLenum type;
	GLuint vertexBufferID;
	GLuint indexBufferID;
	GLuint vertexArrayObjectID;
	ShapeData* data;
	Cube() :color(1.0f, 1.0f, 1.0f) {};
	Cube(int gamewidth, int gameheight,GLuint *gameprogramID, ShapeData *s, GLenum type) :color(1.0f, 1.0f, 1.0f), width(gamewidth), height(gameheight),programID(gameprogramID), data(s),type(type) {};
	Cube(glm::vec3 Color) : color(Color) {};
	void Update(glm::vec3 trans, float rotates)
	{

		translation = glm::translate(glm::mat4(), trans);
		rotation = glm::rotate(glm::mat4(), rotates, glm::vec3(1.0f, 1.0f, 0.0f));

	}
	void Draw(glm::mat4 matrix)
	{
		GLint modelPositionUniformLocation = glGetUniformLocation(*programID, "modelPositionMatrix");
		GLint dominatingColorUniformLocation = glGetUniformLocation(*programID, "dominatingColor");
		trianglePos = translation * rotation;
		glm::mat4 transform = matrix * trianglePos;
		
		//glBindVertexArray(vertexArrayObjectID);
		
 		glUniformMatrix4fv(modelPositionUniformLocation, 1, GL_FALSE, &transform[0][0]);
		glUniform3fv(dominatingColorUniformLocation, 1, &color[0]);
		//glDrawElements(GL_TRIANGLES, data.numbInd, GL_UNSIGNED_SHORT, 0);
		glDrawElements(type, data->numbInd, GL_UNSIGNED_SHORT, 0);
	}
};

#endif