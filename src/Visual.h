#ifndef PRIM_H
#define PRIM_H

#include "IndexArray.h"
#include "VertexArray.h"

class Visual
{

	/* Things everyone should know */

public:
	

protected: 
	Visual(); // default constructor

public: 
	/* we use a virtual destructor to prevent undefined problems by the C++ standard
		Ex.
			Base* base = new Derived();
			delete base;
	*/
	virtual ~Visual();
};

#endif