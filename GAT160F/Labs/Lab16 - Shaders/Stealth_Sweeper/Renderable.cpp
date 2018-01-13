#include "ShapeData.h"
#include "Renderable.h"
#include "gtc\matrix_transform.hpp"
#include "TextureLoader.h"


//Renderable& Renderable::setProgramID(GLuint * gameprogramID)
//{
//	this->programID = gameprogramID;
//	return(*this);
//}

Renderable & Renderable::setShaderInfo(ShaderInfo * shaders)
{
	this->shader = shaders;
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



void Renderable::Draw()
{
	trianglePos = translation * rotation * scale;
	glUseProgram(shader->programID);

	if (shader->callback)
	{
		shader->callback(this);
	}
	

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
