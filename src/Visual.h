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

	/* Esoteric stuff */


public: 
	


};

#endif