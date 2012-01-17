#ifndef PRIM_H
#define PRIM_H

#include "IndexBuffer.h"
#include "VertexBuffer.h"
#include "GlExtensions.h"

class Visual : public Object
{

	/* Things everyone should know */

public:
	
	/* we use a virtual destructor to prevent undefined problems by the C++ standard
		Ex.
			Base* base = new Derived();
			delete base;
	*/
	Visual(); // default constructor
	virtual ~Visual();

	/* Load Buffers from a File */
	void LoadVertexBuffer( std::fstream file );
	void LoadIndexBuffer( std::fstream file );

	void Draw(); // here for demo purposes, will be moved later, am I right?

protected:
	IndexBuffer* ibuf;
	VertexBuffer* vbuf;
	GLuint bufferObjects[2]; // super mega haxy
};

#endif