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