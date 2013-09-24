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
#include <algorithm>
#include <assimp/cimport.h>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

class shrMeshLoader {

public:

	// The place where we will be storing our data at last
	std::vector<shrMesh*> meshes;
	std::vector<Texture2D*> tmpTexts; 

	void recursiveProcess(aiNode* node,const aiScene* scene);
	void processMesh(aiMesh* mesh,const aiScene* scene);
	void processMesh2( aiMesh* m, const aiScene* scene );
	unsigned int loadTexture(const char* filename);
	unsigned int loadTGATexture(const char* filename );
	void createBatches();
	
	Context* ctxt;
	// Global transform
	GLFrame frame;
	shrMeshLoader(const char* filename, Context* pctx );
	shrMeshLoader(const char* filename);
	~shrMeshLoader();
	void draw();
	//std::vector<shrMesh*>& getMeshes();

	/* To create as few vaos as possible, we need to create them at the end */
	vector<unsigned int> numVerts;
	vector<unsigned int> numIndexes;
	unsigned int numTextures;
	bool hasUntexturedVerts;

	vector<string> textStrings;
	Texture2D** textureStructs;

	vector<vector<GLfloat>> verts;
	vector<vector<GLfloat>> norms;
	vector<vector<GLfloat>> texts;
	vector<vector<GLushort>> indexes;
	vector<GLushort> maxIndex;

};

#endif