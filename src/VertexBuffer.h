#ifndef VERTEXBUFFER_H
#define VERTEXBUFFER_H

#include "Object.h"

class VertexBuffer : public Object
{
	VertexBuffer();
	~VertexBuffer();
protected:
	GLfloat* vbuffer;
};

#endif