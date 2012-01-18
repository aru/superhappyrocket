#ifndef VERTEXBUFFER_H
#define VERTEXBUFFER_H

#include "Buffer.h"

class VertexBuffer : public Buffer
{
	VertexBuffer();
	virtual ~VertexBuffer();

	void LoadFromFile();
protected:
	//GLunit    mBuffer; // the place where we will keep it
	GLfloat* vBuffer; // actual data to copy to gpu buffer
};

#endif