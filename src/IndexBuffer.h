#ifndef INDEXBUFFER_H
#define INDEXBUFFER_H

#include "Buffer.h"
#include "Object.h"

class IndexBuffer : public Buffer
{
public:
	IndexBuffer();
	virtual ~IndexBuffer();
protected:
	GLubyte* ibuffer;
};

#endif