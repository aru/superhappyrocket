/**
 * shrMeshLoader.h
 *
 * Loads and processes the meshes and textures associated with them.
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

#ifndef SHR_MESHLOAD
#define SHR_MESHLOAD

#include "Context.h"
#include "shrMesh.h"
#include <assimp/cimport.h>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

class shrMeshLoader {

public:
	
	std::vector<shrMesh*> meshes;
	std::vector<Texture2D> texts;

	void recursiveProcess(aiNode* node,const aiScene* scene);
	void processMesh(aiMesh* mesh,const aiScene* scene);
	unsigned int loadTexture(const char* filename);
	unsigned int loadTGATexture(const char* filename );
	
		Context* ctxt;
		shrMeshLoader(const char* filename, Context* pctx );
		shrMeshLoader(const char* filename);
		~shrMeshLoader();
		void draw();
		//std::vector<shrMesh*>& getMeshes();

};

#endif