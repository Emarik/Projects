#include "Renderable.h"
#include "gtc\matrix_transform.hpp"



void Renderable::Draw(glm::mat4 matrix)
{
	GLint modelPositionUniformLocation = glGetUniformLocation(*programID, "modelPositionMatrix");
	GLint dominatingColorUniformLocation = glGetUniformLocation(*programID, "dominatingColor");
	trianglePos = translation * rotation * scale;
	glm::mat4 transform = matrix * trianglePos;

	glBindVertexArray(data->vertexArrayObjectID);

	glUniformMatrix4fv(modelPositionUniformLocation, 1, GL_FALSE, &transform[0][0]);
	glUniform3fv(dominatingColorUniformLocation, 1, &color[0]);
	//glDrawElements(GL_TRIANGLES, data.numbInd, GL_UNSIGNED_SHORT, 0);
	if (data->numbInd == 0)
	{
		glDrawArrays(data->type,0,data->numbVerts);
	}
	else
	glDrawElements(data->type, data->numbInd, GL_UNSIGNED_SHORT, 0);
}

void Renderable::Update(glm::vec3 transform, float rotates)
{
	translation = glm::translate(glm::mat4(), transform);
	rotation = glm::rotate(glm::mat4(), rotates, glm::vec3(1.0f, 1.0f, 0.0f));
}

Renderable::Renderable()
{
}


Renderable::~Renderable()
{
}
