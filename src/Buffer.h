#ifndef BUFFER_H
#define BUFFER_H

#include "Object.h"

class Buffer : public Object
{
public:
	Buffer();
	Buffer( int numElements, int elementSize );
	virtual ~Buffer();

protected:
	int mNumElements;
    int mElementSize;
    int mNumBytes;
	char* mData;
};

#endif