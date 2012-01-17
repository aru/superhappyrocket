#ifndef VERTEXBUFFER_H
#define VERTEXBUFFER_H

#include "Buffer.h"

class VertexBuffer : public Buffer
{
	VertexBuffer();
	virtual ~VertexBuffer();
protected:
	GLfloat* vbuffer;
};

#endif