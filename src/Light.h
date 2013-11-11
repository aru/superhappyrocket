/**
 * Light.h
 *
 * Responsible of creating light sources on the scene.
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

#ifndef SHR_LIGHT
#define SHR_LIGHT

#include "SimpleObject.h"

class Light : public SimpleObject
{

public:

	Light();
	Light( GLfloat* pos, GLfloat* col );
	~Light();

	/* Member specific variables */
	M3DVector3f		position;
	M3DVector4f		color;

};

#endif