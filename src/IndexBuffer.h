#ifndef INDEXBUFFER_H
#define INDEXBUFFER_H

#include "Buffer.h"

class IndexBuffer : public Buffer
{
public:
	IndexBuffer();
	virtual ~IndexBuffer();
	void LoadFromFile();

protected:
	// GLuint   mBuffer; // the place where this buffer will be bound to
	GLubyte* iBuffer; // the actual data to copy to the buffer
};

#endif