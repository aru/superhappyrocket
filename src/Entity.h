/**
 * Entity.h
 *
 * An entity is a spawnable object by our entity manager, 
 * it can be either a star or a building, and it will move accordingly
 * it has a bounding box to calculate collisions with.
 *
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details http://www.gnu.org/licenses/.
 */

#ifndef SHR_ENTITY
#define SHR_ENTITY

#include "Context.h"
#include "BoundingBox.h"


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