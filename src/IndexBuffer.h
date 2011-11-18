#ifndef INDEXBUFFER_H
#define INDEXBUFFER_H

#include "Object.h"

class IndexBuffer
{
public:
	IndexBuffer();
	virtual ~IndexBuffer();
protected:
	GLubyte* ibuffer;
};

#endif