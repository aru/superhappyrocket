#include "IndexBuffer.h"

IndexBuffer::IndexBuffer()
{
	glGenBuffers(1, &mBuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mBuffer);

	// Dynamic draw is temporal I swear
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, GetNumBytes(), iBuffer, GL_DYNAMIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
IndexBuffer::IndexBuffer( GLubyte* vData, int numElements )
	: Buffer( numElements, sizeof(GLubyte) )
{
	glGenBuffers(1, &mBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mBuffer);

	// Dynamic draw is temporal I swear
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, GetNumBytes(), vData, GL_DYNAMIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

IndexBuffer::~IndexBuffer()
{
}

void IndexBuffer::LoadFromFile()
{

}