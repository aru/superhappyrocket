#ifndef VERTEXARRAY_H
#define VERTEXARRAY_H

#include "Object.h"

class VertexBuffer : public Object
{
	VertexBuffer();
	~VertexBuffer();
protected:
	GLfloat* vbuffer;
};

#endif