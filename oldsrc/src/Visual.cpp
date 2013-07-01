#include "Visual.h"

#define VERTEX_BUFFER   0
#define INDEX_BUFFER    1

// 
Visual::Visual()
	:
	ibuf(0),
	vbuf(0)
{
}
Visual::~Visual()
{
}

void Visual::LoadIndexBuffer( GLubyte* data, int size )
{
	ibuf = new IndexBuffer( data, size );
}

void Visual::LoadVertexBuffer( GLfloat* data, int size )
{
	vbuf = new VertexBuffer( data, size );
}

void Visual::Draw()
{
	// Vertexes
    glBindBuffer(GL_ARRAY_BUFFER, vbuf->mBuffer);
    glVertexPointer(3, GL_FLOAT,0,  0); // this number subject to change

    // Indexes
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibuf->mBuffer);
	glDrawElements(GL_QUADS, ibuf->GetNumElements(), GL_UNSIGNED_BYTE, 0);
}