#include "shrMeshLoader.h"

void shrMeshLoader::recursiveProcess(aiNode* node,const aiScene* scene)
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

void shrMeshLoader::processMesh( aiMesh* m, const aiScene* scene )
{
	// loop variables
	unsigned int i,j;

	// temporary places to store data
	std::vector<GLTriangleBatch> data;
	std::vector<unsigned int> indices;
	std::vector<assimpTextureData> textures;

	// places to store materials?
	aiColor4D col;
	aiMaterial* mat = scene->mMaterials[ m->mMaterialIndex ];
	aiGetMaterialColor( mat, AI_MATKEY_COLOR_DIFFUSE, &col);

	// setting default color
	M3DVector3f defaultColor;
	m3dLoadVector3( defaultColor, col.r,col.g, col.b );

	// make a new mesh and push it back into the array
	shrMesh *tmpMesh;
	tmpMesh = new shrMesh();
	meshes.push_back(tmpMesh);

	// Figure out what we have


	// push the vertex/colors/text data into this new mesh
	//tmpMesh->data.Begin( GL_TRIANGLES, m->mNumVertices );
	tmpMesh->data.BeginMesh( m->mNumVertices );

	for( i = 0; i < m->mNumVertices; i++)
	{

		M3DVector3f verts;
		M3DVector3f norms;
		M3DVector3f color;
		M3DVector2f texts;

		//position
		verts[0] = m->mVertices[i].x;
		verts[1] = m->mVertices[i].y;
		verts[2] = m->mVertices[i].z;

		//normals
		norms[0] = m->mNormals[i].x;
		norms[1] = m->mNormals[i].y;
		norms[2] = m->mNormals[i].z;

		////tangent
		//if(m->mTangents)
		//{
		//	tmpVec[0] = m->mTangents[i].x;
		//	tmpVec[1] = m->mTangents[i].y;
		//	tmpVec[2] = m->mTangents[i].z;
		//}else{
		//	tmpVec[0] = 1.0;
		//	tmpVec[1] = tmpVec[2] = 0;
		//}
		//m3dCopyVector3(tmp.tangent, tmpVec);

		// colors
		//if(m->mColors[0])
		//{
		//	//!= material color
		//	color[0] = m->mColors[0][i].r;
		//	color[1] = m->mColors[0][i].g;
		//	color[2] = m->mColors[0][i].b;
		//}else{
		//	m3dCopyVector3(color, defaultColor);
		//}

			// texture
			if(m->mTextureCoords[0])
			{
				texts[0] = m->mTextureCoords[0][i].x;
				texts[1] = m->mTextureCoords[0][i].y;
			}else{
				texts[0] = texts[1] = 0.0f;
			}
			//data.push_back(tmp);

			tmpMesh->data.AddTriangle(&verts, &norms, &texts);

			//tmpMesh->data.Normal3fv(norms);
			//tmpMesh->data.Vertex3fv(verts);

			//tmpMesh->data.MultiTexCoord2fv(texts);

	}

	tmpMesh->data.End();

	//for(i=0;i<m->mNumFaces;i++)
	//{
	//	aiFace face=m->mFaces[i];
	//	for(j=0;j<face.mNumIndices;j++) //0..2
	//	{
	//		indices.push_back(face.mIndices[j]);
	//	}
	//}


	//for(i=0;i<mat->GetTextureCount(aiTextureType_DIFFUSE);i++)
	//{
	//	aiString str;
	//	mat->GetTexture(aiTextureType_DIFFUSE,i,&str);
	//	assimpTextureData tmp;
	//	tmp.id=loadTexture(str.C_Str());
	//	tmp.type=0;
	//	textures.push_back(tmp);
	//}
	//meshes.push_back(new shrMesh(&data,&indices,&textures));
}


unsigned int shrMeshLoader::loadTexture(const char* filename)
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


shrMeshLoader::shrMeshLoader(const char* filename)
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

shrMeshLoader::~shrMeshLoader()
{
	unsigned int i;
	for( i = 0; i < meshes.size(); i++)
		delete meshes[i];
}

void shrMeshLoader::draw()
{
	unsigned int i;

	for( i = 0; i < meshes.size(); i++ )
	{
		//meshes[i]->draw(programId);
		meshes[i]->data.Draw();
	}
}

std::vector<shrMesh*>& shrMeshLoader::getMeshes()
{
	return meshes;
}
