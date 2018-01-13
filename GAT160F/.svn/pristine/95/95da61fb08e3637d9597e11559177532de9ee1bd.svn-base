#pragma once
#include "GL\glew.h"
#include "ShapeData.h"
#include "Renderable.h"
#include "BufferManager.h"
class RenderEngine
{

public:
	int width,height;
	Logger* m_logs;
	BufferManager manage;
	RenderEngine() {};
	RenderEngine(int width, int height) :width(width), height(height) {};
	void addShape(ShapeData* s);
	void addRenderable(Renderable* renderable);
	void draw();
	void drawAllRenderables(glm::mat4);
	void initialize(Logger*m_logs, int width, int height);
	void shutdown();
	~RenderEngine();
};

