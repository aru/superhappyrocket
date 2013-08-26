/**
 * Light.h
 *
 * Responsible of creating light frames on the scene.
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

#include "Context.h"

class Light
{
public:
	Light();
	~Light();

	M3DMatrix44f		 light;
	M3DVector4f          color; // Color of this light
	GLFrame              *lightFrame;
	GLMatrixStack		 *modelViewMatrix;		// Modelview Matrix
	GLMatrixStack		 *projectionMatrix;		// Projection Matrix
	GLGeometryTransform	 *transformPipeline;		// Geometry Transform Pipeline
};

#endif