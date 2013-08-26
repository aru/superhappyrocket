/**
 * assimpMeshLoader.h
 *
 * Loads each mesh into the scene, also loads the texture associated
 * with each mesh.
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

#ifndef SHR_MESHLOADER
#define SHR_MESHLOADER

#include <vector>
#include <assimp/cimport.h>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <SDL_image.h>
#include "assimpMesh.h"
#include <GLTools.h>

class assimpMeshLoader
{
	std::vector<assimpMesh*> meshes;
	void recursiveProcess(aiNode* node,const aiScene* scene);
	void processMesh(aiMesh* mesh,const aiScene* scene);
	unsigned int loadTexture(const char* filename);
	public:
		assimpMeshLoader(const char* filename);
		~assimpMeshLoader();
		void draw(unsigned int programId);
		std::vector<assimpMesh*>& getMeshes();
};

#endif