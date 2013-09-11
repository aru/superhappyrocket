/**
 * shrMesh.h
 *
 * A shrMesh is a structure containing soem data such as texture and shader
 * files assigned to a mesh.
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

#ifndef SHR_MESH
#define SHR_MESH

#include "Context.h"
#include <GLTools.h>
#include <GLFrame.h>
#include <GLTriangleBatch.h>
#include <vector>
#include <string>

class shrMesh{
public:

	shrMesh();
	shrMesh( const shrMesh& mesh );
	~shrMesh();

	// Save all of the data for this model
	//GLBatch data2;
	// Alternative way of saving data
	GLTriangleBatch data;
	// Put in a frame to move easily
	GLFrame			frame;
	// Save what texture/file this is using
	unsigned int	textureFile;
	unsigned int	shaderFile;
	// Texture attached to this mesh
	string          textureString; // File as in text
	Texture2D*      texture;

};

#endif