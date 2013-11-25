/**
 * BoundingBox.h
 *
 * This class is used to create a bounding box that determines if an
 * object intersects with any other object with a collision detection 
 * method.
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