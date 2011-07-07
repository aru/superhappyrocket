#ifndef PRIM_H
#define PRIM_H

class Visual
{

	/* Things everyone should know */

public:
	enum PrimitiveType
    {
        PT_NONE,  // default constructor
        PT_POLYPOINT,
        PT_POLYSEGMENTS_DISJOINT,
        PT_POLYSEGMENTS_CONTIGUOUS,
        PT_TRIANGLES,  // abstract
        PT_TRIMESH,
        PT_TRISTRIP,
        PT_TRIFAN,
		// other primitive types go here
        PT_MAX_QUANTITY
    };

protected: 
	Visual( PrimitiveType type = PT_NONE); // default value
	//Visual( PrimitiveType type ); // more to add as time goes by

public: 
	/* we use a virtual destructor to prevent undefined problems by the C++ standard
		Ex.
			Base* base = new Derived();
			delete base;
	*/
	virtual ~Visual();
};

#endif