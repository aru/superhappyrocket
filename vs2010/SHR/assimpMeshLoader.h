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