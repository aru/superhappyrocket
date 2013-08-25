/**
 * assimpMeshData.h
 *
 * Holds the data of every model on the scene
 * Contains data such as position, normal, tangent and color for each mesh.
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

#ifndef SHR_ASSIMPMESHDATA
#define SHR_ASSIMPMESHDATA

#include "Context.h"
#include <GLFrame.h>

struct assimpVertexData
{
	M3DVector3d position;
	M3DVector3d normal;
	M3DVector3d tangent;
	M3DVector3d color;
	double U,V;
};

struct assimpTextureData
{
	unsigned int id;
	unsigned int type;
};

#endif