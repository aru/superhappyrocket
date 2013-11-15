#ifndef SHR_ENTITY
#define SHR_ENTITY

#include "Context.h"
#include "BoundingBox.h"

/* An entity is a spawnable object by our entity manager 
 * it can be either a star or a building, and it will move accordingly
 * it has a bounding box to calculate collisions with
 */

class Entity
{
public:
	Entity( const int type, Context* ctx );
	~Entity();

	void Update( Uint32 gameTime );

	/* Has a pointer to the context */
	Context* ctxt;
	/* An entity is of one type */
	int entityType;
	/* Has an assimpMesh associated */
	assimpMesh* mesh;
	/* Has a collision box associated */
	BoundingBox* box;
	/* Has a variable to know when to move */
	bool move;
	/* Entity speed */
	float speed;
};

#endif