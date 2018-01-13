#include "GL\glew.h"
#include <cassert>
#include "Game.h"
#include "MeGlWindow.h"

bool Game::Initialize(MeGlWindow* window)
{
	this->m_window = window;
	BufferBind();
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
		-1.0f,-1.0f,
		1.0f,-1.0f
	};
	glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);
}

bool Game::Shutdown()
{
	return true;
}
bool Game::Update()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glViewport(0, 0, m_window->width(), m_window->height());
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	return true;
}

