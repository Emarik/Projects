#pragma once
#include "BufferInfo.h"
#include "Renderable.h"
#define MAX_BUFFERS 20
class ShapeData;
class BufferManager
{
public:
	Logger* m_logs;
	BufferManager();
	~BufferManager();
	int usedBuffers = 0;
	BufferInfo buffers[MAX_BUFFERS];
	BufferInfo* getBuffer(int format, ShapeData* s);
	int checkBuffers(int format, int vertexData, int vertSize, int indexData, int indexSize);
	int addBuffer(int format, ShapeData* s);
	void EnablingVertexPointers(int format);
	void addRenderinfo(Renderable* rend);
	BufferInfo* getMatchingBuffer(Renderable* render);
	void addData(BufferInfo * buffer, ShapeData* s);
	void initialize(Logger*logs)
	{
		m_logs = logs;
		m_logs->Log(LOG_INFO, "Buffer Manager Initialized");
	};
	void shutdown()
	{
		m_logs->Log(LOG_INFO, "Buffer Manager Shutdown");
	};
};

