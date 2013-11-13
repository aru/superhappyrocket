#ifndef SHR_STAR
#define SHR_STAR

#include "assimpMesh.h"
#include "BoundingBox.h"

class Star : public assimpMesh
{
public:
	Star( Context* ctxt, float r0, float r1, float r2 );
	~Star();

	/* Methods for our star */

	/* Keep the star moving */
	const int Update( const float gameTime );
	/* Check if it collides with another object */
	const bool collidesWith( const assimpMesh& mesh );

	/* Every star also has a bounding box */
	BoundingBox* box;

	/* Every star has its speed */
	float speed;

};

#endif