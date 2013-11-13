#ifndef SHR_BOUNDINGBOX
#define SHR_BOUNDINGBOX

class BoundingBox
{
public:
	BoundingBox( float c0, float c1, float c2, 
				 float r1, float r2, float r3 );
	BoundingBox( const BoundingBox& box );
	~BoundingBox();

	const bool intersectsWith( const BoundingBox& box );

	/* Actual member variables for AABB testing */
	float c[3];
	float r[3];
};

#endif