#ifndef VERTEXBUFFER_H
#define VERTEXBUFFER_H

#include "Object.h"

class VertexBuffer : public Object
{
	VertexBuffer();
	virtual ~VertexBuffer();
protected:
	GLfloat* vbuffer;
};

#endif