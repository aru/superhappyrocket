#ifndef PRIM_H
#define PRIM_H

#include "IndexBuffer.h"
#include "VertexBuffer.h"

class Visual : public Object
{

	/* Things everyone should know */

public:
	
	/* we use a virtual destructor to prevent undefined problems by the C++ standard
		Ex.
			Base* base = new Derived();
			delete base;
	*/
	virtual ~Visual();
	Visual(); // default constructor

	/* Load Buffers from a File */
	void LoadVertexBuffer( std::fstream file );
	void LoadIndexBuffer( std::fstream file );

protected:
	IndexBuffer* ibuffer;
	VertexBuffer* vbuffer;
};

#endif