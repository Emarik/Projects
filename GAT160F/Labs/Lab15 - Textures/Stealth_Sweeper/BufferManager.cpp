#include "ShapeData.h"
#include "BufferManager.h"
#include "..\ObjConverter\Vertexformats.h"


BufferManager::BufferManager()
{
}


BufferManager::~BufferManager()
{
}

BufferInfo * BufferManager::getBuffer(int format, ShapeData* s)
{
	int rightBuffer = checkBuffers(format, s->numbVerts, s->sizeVerts,s->numbInd,s->sizeInd);
	if (rightBuffer==-1)
	{
		return &buffers[addBuffer(format, s)];
	}
	else
	{
		addData(&buffers[rightBuffer], s);
		return &buffers[rightBuffer];
	}
}

int BufferManager::checkBuffers(int format, int vertexData,int vertSize, int indexData, int indexSize)
{
	BufferInfo* b = &buffers[0];
	for (int I = 0; I < usedBuffers; I++)
	{
		if ((b->vertexByteOffset + vertexData*vertSize) < b->MAX_BUFFER_SIZE && (b->indexByteOffset+indexData*indexSize) < b->MAX_BUFFER_SIZE&& b->format == format)
		{
			buffers[I];
			return I;
		}
		b++;
	}
	return -1;
}

int BufferManager::addBuffer(int format, ShapeData* s)
{
	if (usedBuffers < MAX_BUFFERS)
	{
		BufferInfo* b = &buffers[usedBuffers];
		b->format = format;
		glGenVertexArrays(1, &b->vertexArrayObjectID);
		glBindVertexArray(b->vertexArrayObjectID);
		glGenBuffers(1, &b->vertexBufferID);
		glGenBuffers(1, &b->indexBufferID);
		
		int points = 0;
		if (b->format & HasPosition)
			points += 3;
		if (b->format & HasColor)
			points += 3;
		if (b->format & HasTexture)
			points += 2;
		if (b->format & HasNormal)
			points += 3;
		glBindBuffer(GL_ARRAY_BUFFER,b->vertexBufferID);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, b->indexBufferID);
		glBufferData(GL_ARRAY_BUFFER, b->MAX_BUFFER_SIZE * sizeof(glm::vec3) * points, 0, GL_STATIC_DRAW);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, b->MAX_BUFFER_SIZE * sizeof(unsigned short), 0, GL_STATIC_DRAW);
		EnablingVertexPointers(format);
		addData(b, s);
	}
	else
	{
		m_logs->Log(LOG_ERROR, "Max number of Buffers used");
		return -1;
	}
	return usedBuffers++;
}

void BufferManager::EnablingVertexPointers(int format)
{
	switch (format)
	{
	case PositionOnly:
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, 0);
		//glVertexAttribPointer(1, 0, GL_FLOAT, GL_FALSE, sizeof(float) * 3, (char*)(sizeof(float) * 3));
		//glVertexAttribPointer(2, 0, GL_FLOAT, GL_FALSE, sizeof(float) * 3, (char*)(sizeof(float) * 3));
		//glVertexAttribPointer(3, 0, GL_FLOAT, GL_FALSE, sizeof(float) * 3, (char*)(sizeof(float) * 3));
		break;
	case PositionColor:
		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, 0);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (char*)(sizeof(float) * 3));
		//glVertexAttribPointer(2, 0, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (char*)(sizeof(float) * 6));
		//glVertexAttribPointer(3, 0, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (char*)(sizeof(float) * 6));
		break;
	case PositionColorTexture:
		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);
		glEnableVertexAttribArray(3);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 8, 0);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 8, (char*)(sizeof(float) * 3));
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 8, (char*)(sizeof(float) * 6));
		//glVertexAttribPointer(3, 0, GL_FLOAT, GL_FALSE, sizeof(float) * 8, (char*)(sizeof(float) * 8));
		break;
	case PositionColorTextureNormal:
		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);
		glEnableVertexAttribArray(2);
		glEnableVertexAttribArray(3);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 11, 0);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 11, (char*)(sizeof(float) * 3));
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 11, (char*)(sizeof(float) * 6));
		glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 11, (char*)(sizeof(float) * 8));
		break;
	case PositionColorNormal:
		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);
		glEnableVertexAttribArray(3);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 9, 0);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 9, (char*)(sizeof(float) * 3));
		//glVertexAttribPointer(2, 0, GL_FLOAT, GL_FALSE, sizeof(float) * 9, (char*)(sizeof(float) * 6));
		glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 9, (char*)(sizeof(float) * 6));
		break;
	case PositionTexture:
		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(2);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 5, 0);
		//glVertexAttribPointer(1, 0, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (char*)(sizeof(float) * 3));
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (char*)(sizeof(float) * 3));
		//glVertexAttribPointer(3, 0, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (char*)(sizeof(float) * 5));
		break;
	case PositionTextureNormal:
		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(2);
		glEnableVertexAttribArray(3);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 8, 0);
		//glVertexAttribPointer(1, 0, GL_FLOAT, GL_FALSE, sizeof(float) * 8, (char*)(sizeof(float) * 3));
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 8, (char*)(sizeof(float) * 3));
		glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 8, (char*)(sizeof(float) * 5));
		break;
	case PositionNormal:
		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(3);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, 0);
		//glVertexAttribPointer(1, 0, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (char*)(sizeof(float) * 3));
		//glVertexAttribPointer(2, 0, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (char*)(sizeof(float) * 3));
		glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (char*)(sizeof(float) * 3));
		break;
	}
}

void BufferManager::addRenderinfo(Renderable* rend)
{
	BufferInfo*b = &buffers[0];
	for (int I = 0; I < usedBuffers; I++)
	{
		if (rend->data->buffer == b)
		{
			b->renderables.add(rend);
		}
		b++;
	}
}
BufferInfo * BufferManager::getMatchingBuffer(Renderable* render)
{
	for (int I = 0; I < usedBuffers; I++)
	{
		Node* n = buffers[I].renderables.start.next;
		while (n->next != NULL)
		{
			if (n->next->r == render)
			{
				return &buffers[I];
			}
			n = n->next;
		}
	}
	return nullptr;
}
void BufferManager::addData(BufferInfo* buffer, ShapeData* s)
{
	s->vertexByteOffset = buffer->vertexByteOffset;
	s->indexByteOffset = buffer->indexByteOffset;
	glBindBuffer(GL_ARRAY_BUFFER, buffer->vertexBufferID);
	glBufferSubData(GL_ARRAY_BUFFER,buffer->vertexByteOffset,s->numbVerts*s->sizeVerts,s->verts);
	buffer->vertexByteOffset += s->numbVerts * s->sizeVerts;
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer->indexBufferID);
	glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, buffer->indexByteOffset, s->numbInd*s->sizeInd, s->indicies);
	buffer->indexByteOffset += s->numbInd * s->sizeInd;
}