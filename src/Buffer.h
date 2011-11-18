#ifndef BUFFER_H
#define BUFFER_H

/* Buffer is used to declare chunks of data
 * reusable to create not-so-simple arrays of data
 * while maintaning knowledge like objectName, numBytes,
 * etc...
 * works for 1D, 2D,3D,4D arrays use new0,1,2,3 accordingly
 * delete with delete0,1,2,3, too.
 */

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