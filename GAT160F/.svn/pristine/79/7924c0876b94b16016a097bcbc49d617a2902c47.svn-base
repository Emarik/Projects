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

Renderable & Renderable::setName(std::string names)
{
	this->name = names;
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
	glm::mat4 transform = glm::translate(glm::mat4(), translation);
	glm::mat4 rotatex = glm::rotate(glm::mat4(), rotation.x, glm::vec3(1, 0, 0));
	glm::mat4 rotatey = glm::rotate(glm::mat4(), rotation.y, glm::vec3(0, 1, 0));
	glm::mat4 rotatez = glm::rotate(glm::mat4(), rotation.z, glm::vec3(0, 0, 1));
	trianglePos = transform * rotatex * rotatey * rotatez;
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

void Renderable::Update(glm::vec3 transform, glm::vec3 rotates)
{
	translation += transform;
	rotation += rotates;
}

Renderable::Renderable()
{
}


Renderable::~Renderable()
{
}
