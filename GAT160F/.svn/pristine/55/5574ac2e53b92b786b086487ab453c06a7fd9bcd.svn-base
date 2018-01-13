#include "RenderEngine.h"

void RenderEngine::addShape(ShapeData * s)
{
	s->buffer = manage.getBuffer(s->format, s);
}

void RenderEngine::addRenderable(Renderable * renderable)
{
	manage.addRenderinfo(renderable);
	//BufferInfo*b = &manage.buffers[0];
	//for (int I = 0; I < manage.usedBuffers; I++)
	//{
	//	if (renderable->data->buffer == b)
	//	{
	//		b->renderables.add(renderable);
	//	}
	//	b++;
	//}
}

void RenderEngine::draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glViewport(0, 0, width, height);

}
void RenderEngine::drawAllRenderables(glm::mat4 matrix)
{
	BufferInfo* m = &manage.buffers[0];
	for (int k = 0; k < manage.usedBuffers; k++)
	{
		Node* n = &m->renderables.start;
		while (n->next != NULL)
		{
			n->next->r->Draw(matrix);
			n = n->next;
		}
		m++;
	}
}
void RenderEngine::initialize(Logger*m_log,int widths,int heights)
{
	this->m_logs = m_log;
	this->width = widths;
	this->height = heights;
	m_logs->Log(LOG_INFO, "Render Engine Initialized");
	manage.initialize(m_logs);
}
void RenderEngine::shutdown()
{
	manage.shutdown();
	m_logs->Log(LOG_INFO, "Render Engine Shutdown");
}
;

RenderEngine::~RenderEngine()
{
}
