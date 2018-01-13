#include "ShapeData.h"
#include "Renderable.h"
#include "gtc\matrix_transform.hpp"
#include "TextureLoader.h"


Renderable& Renderable::setProgramID(GLuint * gameprogramID)
{
	this->programID = gameprogramID;
	return(*this);
}

Renderable& Renderable::setShape(ShapeData* datas)
{
	this->data = datas;
	return(*this);
}

Renderable& Renderable::setLogger(Logger * logs)
{
	this->m_logs = logs;
	return(*this);
}

Renderable& Renderable::setTexture(std::string filename)
{
	TextureLoader t(m_logs);
	textureImage = t.loadBMP_custom(filename);
	return(*this);
}



void Renderable::Draw(glm::mat4 matrix)
{
	glUseProgram(*programID);
	GLint modelPositionUniformLocation = glGetUniformLocation(*programID, "modelPositionMatrix");
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, textureImage);
	//GLint dominatingColorUniformLocation = glGetUniformLocation(*programID, "dominatingColor");
	trianglePos = translation * rotation * scale;
	glm::mat4 transform = matrix * trianglePos;

	glBindVertexArray(data->buffer->vertexArrayObjectID);
	glBindBuffer(GL_ARRAY_BUFFER,data->buffer->vertexBufferID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, data->buffer->indexBufferID);

	glUniformMatrix4fv(modelPositionUniformLocation, 1, GL_FALSE, &transform[0][0]);
	//glUniform3fv(dominatingColorUniformLocation, 1, &color[0]);
	//glDrawElements(GL_TRIANGLES, data.numbInd, GL_UNSIGNED_SHORT, 0);
	if (data->numbInd == 0)
	{
		glDrawArrays(data->type,data->vertexByteOffset,data->numbVerts);
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
