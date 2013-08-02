#include "assimpMeshLoader.h"

void assimpMeshLoader::recursiveProcess(aiNode* node,const aiScene* scene)
{
	unsigned int i = 0;

	// process each mesh in the scene
	for( i = 0; i < ( node->mNumMeshes ); i++)
	{
		aiMesh* mesh = scene->mMeshes[ node->mMeshes[i] ];
		processMesh( mesh,scene );
	}

	// do them same (recursion) for every children in the scene
	for( i = 0; i < node->mNumChildren; i++)
	{
		recursiveProcess(node->mChildren[i],scene);
	}
}

void assimpMeshLoader::processMesh(aiMesh* m,const aiScene* scene)
{
	// used for loops
	unsigned int i,j;

	// temporary places to store data
	std::vector<assimpVertexData> data;
	std::vector<unsigned int> indices;
	std::vector<assimpTextureData> textures;
	aiColor4D col;
	aiMaterial* mat=scene->mMaterials[m->mMaterialIndex];
	aiGetMaterialColor(mat,AI_MATKEY_COLOR_DIFFUSE,&col);
	M3DVector3d defaultColor;
	m3dLoadVector3(defaultColor, col.r,col.g, col.b);

	for(i=0; i<m->mNumVertices; i++)
	{
			assimpVertexData tmp;
			M3DVector3d tmpVec;

			//position
			tmpVec[0] = m->mVertices[i].x;
			tmpVec[1] = m->mVertices[i].y;
			tmpVec[2] = m->mVertices[i].z;
			m3dCopyVector3(tmp.position, tmpVec);

			//normals
			tmpVec[0] = m->mNormals[i].x;
			tmpVec[1] = m->mNormals[i].y;
			tmpVec[2] = m->mNormals[i].z;
			m3dCopyVector3(tmp.normal, tmpVec);

			//tangent
			if(m->mTangents)
			{
				tmpVec[0] = m->mTangents[i].x;
				tmpVec[1] = m->mTangents[i].y;
				tmpVec[2] = m->mTangents[i].z;
			}else{
				tmpVec[0] = 1.0;
				tmpVec[1] = tmpVec[2] = 0;
			}
			m3dCopyVector3(tmp.tangent, tmpVec);

			//colors
			if(m->mColors[0])
			{
				//!= material color
				tmpVec[0] = m->mColors[0][i].r;
				tmpVec[1] = m->mColors[0][i].g;
				tmpVec[2] = m->mColors[0][i].b;
			}else{
				m3dCopyVector3(tmpVec, defaultColor);
			}
			m3dCopyVector3(tmp.color, tmpVec);

			//color
			if(m->mTextureCoords[0])
			{
				tmpVec[0] = m->mTextureCoords[0][i].x;
				tmpVec[1] = m->mTextureCoords[0][i].y;
			}else{
				tmpVec[0] = tmpVec[1] = tmpVec[2] = 0.0;
			}
			tmp.U = tmpVec[0];
			tmp.V = tmpVec[1];
			data.push_back(tmp);
	}

	for(i=0;i<m->mNumFaces;i++)
	{
		aiFace face=m->mFaces[i];
		for(j=0;j<face.mNumIndices;j++) //0..2
		{
			indices.push_back(face.mIndices[j]);
		}
	}


	for(i=0;i<mat->GetTextureCount(aiTextureType_DIFFUSE);i++)
	{
		aiString str;
		mat->GetTexture(aiTextureType_DIFFUSE,i,&str);
		assimpTextureData tmp;
		tmp.id=loadTexture(str.C_Str());
		tmp.type=0;
		textures.push_back(tmp);
	}
	meshes.push_back(new assimpMesh(&data,&indices,&textures));
}


unsigned int assimpMeshLoader::loadTexture(const char* filename)
{
	unsigned int num;
	glGenTextures(1,&num);
	SDL_Surface* img = IMG_Load(filename);
	if(img==NULL)
	{
		//std::cout << "img was not loaded" << std::endl;
		return -1;
	}
	SDL_PixelFormat form={NULL,32,4,0,0,0,0,0,0,0,0,0xff000000,0x00ff0000,0x0000ff00,0x000000ff,0,255};
	SDL_Surface* img2=SDL_ConvertSurface(img,&form,SDL_SWSURFACE);
	if(img2==NULL)
	{
		//std::cout << "img2 was not loaded" << std::endl;
		return -1;
	}
	glBindTexture(GL_TEXTURE_2D,num);

	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,img2->w,img2->h,0,GL_RGBA,GL_UNSIGNED_INT_8_8_8_8,img2->pixels);
	SDL_FreeSurface(img);
	SDL_FreeSurface(img2);
	return num;
}


assimpMeshLoader::assimpMeshLoader(const char* filename)
{
	const aiScene* scene = aiImportFile(filename, aiProcessPreset_TargetRealtime_Quality);
	//const aiScene* scene = aiImportFile(filename, aiProcess_GenSmoothNormals | aiProcess_Triangulate | aiProcess_CalcTangentSpace | aiProcess_FlipUVs);
	const char* error = aiGetErrorString();
	if( strcmp(error, "") != 0 )
	{
		std::cout << "The file wasn't successfully opened " << filename << std::endl;
		std::cout << "Error: " << error << std::endl;
		return;
	}

	recursiveProcess(scene->mRootNode,scene);
}

assimpMeshLoader::~assimpMeshLoader()
{
	unsigned int i;
	for(i=0;i<meshes.size();i++)
		delete meshes[i];
}

void assimpMeshLoader::draw(unsigned int programId)
{
	unsigned int i;
	for(i=0;i<meshes.size();i++)
		meshes[i]->draw(programId);
}

std::vector<assimpMesh*>& assimpMeshLoader::getMeshes()
{
	return meshes;
}
