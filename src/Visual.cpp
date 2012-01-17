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

void Visual::Draw()
{
	
    glBindBuffer(GL_ARRAY_BUFFER, bufferObjects[VERTEX_BUFFER]);
    glVertexPointer(3, GL_FLOAT,0,  0); // this number subject to change

    // Indexes
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferObjects[INDEX_BUFFER]);
	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_SHORT, 0);
}