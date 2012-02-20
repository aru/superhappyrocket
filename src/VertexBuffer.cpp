#include "VertexBuffer.h"

VertexBuffer::VertexBuffer()
{
	glGenBuffers(1, &mBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, mBuffer);

	// I need to make this better fo sho
    glBufferData(GL_ARRAY_BUFFER, GetNumBytes(), vBuffer, GL_DYNAMIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
VertexBuffer::VertexBuffer( GLfloat* vData, int numElements )
	: Buffer( numElements, sizeof(GLfloat) )
{
	glGenBuffers(1, &mBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, mBuffer);

	// I need to make this better fo sho
	glBufferData(GL_ARRAY_BUFFER, GetNumBytes() * 3, vData, GL_DYNAMIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
VertexBuffer::~VertexBuffer()
{
}

void VertexBuffer::LoadFromFile()
{

}