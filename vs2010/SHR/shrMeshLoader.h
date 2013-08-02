#ifndef SHR_MESHLOAD
#define SHR_MESHLOAD

#include "shrMesh.h"
#include <assimp/cimport.h>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

class shrMeshLoader {

	std::vector<shrMesh*> meshes;
	void recursiveProcess(aiNode* node,const aiScene* scene);
	void processMesh(aiMesh* mesh,const aiScene* scene);
	unsigned int loadTexture(const char* filename);
	public:
		shrMeshLoader(const char* filename);
		~shrMeshLoader();
		void draw();
		std::vector<shrMesh*>& getMeshes();

};

#endif