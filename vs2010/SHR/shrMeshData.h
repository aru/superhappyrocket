/**
 * shrMeshData.h
 *
 * Contains data related to each mesh, such as vertex and position data.
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
#ifndef SHR_MESH_DATA
#define SHR_MESH_DATA

#include "Context.h"
#include <GLFrame.h>
#include <GLTools.h>

class shrMesh{
	// vertex and position data
	GLBatch data;
	GLFrame frame;

};

#endif