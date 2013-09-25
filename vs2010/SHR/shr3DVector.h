#ifndef SHR_3DVECTOR
#define SHR_3DVECTOR

#include "Context.h"
#include <math.h>

class shr3DVector
{
public:
	shr3DVector();
	shr3DVector( float x, float y, float z );
	shr3DVector( const shr3DVector& vector );
	~shr3DVector();
	shr3DVector& operator=( const shr3DVector rhs );
	shr3DVector& operator=( const shr3DVector* rhs );
	bool operator==( const shr3DVector rhs );
	bool operator!=( const shr3DVector rhs );

	float x, y, z;
};

#endif