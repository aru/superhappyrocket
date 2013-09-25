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
	Light( GLfloat* pos, GLfloat* col );
	Light( M3DVector4f* vec, M3DVector4f* col );
	~Light();
	M3DVector3f* getPosition();
	M3DVector4f* getColor();
	void Draw();

	bool renderMe;
	bool tBatch;

	M3DVector3f          position;
	M3DVector4f          color; // Color of this light

	M3DMatrix44f		 lightMatrix;
	M3DVector4f          pos;
	GLFrame              lightFrame;
	GLTriangleBatch      triBatch;
	GLBatch              batch;
	GLMatrixStack		 modelViewMatrix;		// Modelview Matrix
	GLMatrixStack		 projectionMatrix;		// Projection Matrix
	GLGeometryTransform	 transformPipeline;		// Geometry Transform Pipeline
};

#endif