/**
 * assimpMesh.h
 *
 * Holds the data of every model on the scene
 * Contains indices, vertex and texture data for each mesh.
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

#ifndef SHR_ASSIMPMESH
#define SHR_ASSIMPMESH

#include <vector>
#include <string>
#include <iostream>

#include "Context.h"
#include "assimpMeshData.h"


class assimpMesh
{
	std::vector<assimpVertexData> data;
	std::vector<assimpTextureData> textures;
	std::vector<unsigned int> indices;
	unsigned int VBO;
	unsigned int IND;
	public:
		assimpMesh(std::vector<assimpVertexData>* vd,std::vector<unsigned int>* id,std::vector<assimpTextureData>* td=NULL);
		~assimpMesh();
		void draw(unsigned int programId);
};

#endif