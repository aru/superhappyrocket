#ifndef SHR_BUILDING
#define SHR_BUILDING

#include "assimpMesh.h"
#include "BoundingBox.h"

class Building : public assimpMesh
{
public:
	Building( const char* fileName, Context* ctx );
	~Building();

	/* Every building has an assimp mesh with them */

	/* Every building has a bounding box */
	BoundingBox* box;
	/* Every building has a moving speed towards the player */
	float speed;
	/* For easiness, every kind of building will have an associated type */
	int type;
};

#endif