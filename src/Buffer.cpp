#include "Buffer.h"

Buffer::Buffer()
	:	
	mNumElements(0),
	mElementSize(0),
    mNumBytes(0),
	mData(0)
{
	
}

Buffer::Buffer(int numElements, int elementSize)
	:
    mNumElements(numElements),
    mElementSize(elementSize),
    mNumBytes(numElements*elementSize)
{
	assert( mNumElements > 0 );
    assert( mElementSize > 0 );

	mData = new1<char>(mNumBytes);
}

Buffer::~Buffer()
{
	delete1(mData);
}

int Buffer::GetNumElements () const
{
    return mNumElements;
}