#ifndef VERTEXBUFFER_H
#define VERTEXBUFFER_H

#include "Buffer.h"

class VertexBuffer : public Buffer
{
public:
	VertexBuffer();
	// To load with associated data
	VertexBuffer( GLfloat* vData, int numElements );
	virtual ~VertexBuffer();
	void LoadFromFile();
protected:
	//GLunit    mBuffer; // the place where we will keep it
	GLfloat* vBuffer; // actual data to copy to gpu buffer
};

#endif