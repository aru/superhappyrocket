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
	unsigned int i,j,k;
	//int indexCount;

	// temporary places to store data
	std::vector<M3DVector3f> vertices;
	std::vector<M3DVector3f> normals;
	std::vector<M3DVector2f> textures;
	std::vector<GLushort> indices;

	// places to store materials?
	aiColor4D col;
	aiMaterial* mat = scene->mMaterials[ m->mMaterialIndex ];
	aiGetMaterialColor( mat, AI_MATKEY_COLOR_DIFFUSE, &col);

	// setting default color
	M3DVector3f defaultColor;
	m3dLoadVector3( defaultColor, col.r,col.g, col.b );

	// First off get the indexes, this is how we will make a new triangle
	for( i = 0; i < m->mNumFaces; i++)
	{
		aiFace face = m->mFaces[i];
		for( j = 0; j < face.mNumIndices; j++) //0..2
		{
			indices.push_back( face.mIndices[j] );
		}
	}

	// make a new mesh and push it back into the array
	shrMesh *tmpMesh;
	tmpMesh = new shrMesh();

	// push the vertex/colors/text data into this new mesh
	tmpMesh->data.BeginMesh( indices.size() );

	M3DVector3f tmpvert[3];
	M3DVector3f tmpnorm[3];
	M3DVector2f tmptext[3];
    unsigned int idx = -1;

	// With the indexes, we can now add triangles in order
	// As long as we have indexes, assuming everything is a triangle
	// we want to build triangles according to them
	for( i = 0; i < indices.size(); )
	{
		for( j = 0; j < 3; j++ )
		{
			idx = indices.at(i);
			//for( k = 0; k < 2; )
			{
				// Get everything for x
				tmpvert[j][0] = m->mVertices[idx].x;
				tmpnorm[j][0] = m->mNormals[idx].x;

				// Get everything for y
				tmpvert[j][1] = m->mVertices[idx].y;
				tmpnorm[j][1] = m->mNormals[idx].y;
				//tmptext[j][1] = 0.0f;

				// Get everything for z
				tmpvert[j][2] = m->mVertices[idx].z;
				tmpnorm[j][2] = m->mNormals[idx].z;

				// Get all of the text coords
				if(m->mTextureCoords[0])
				{
					tmptext[j][0] = m->mTextureCoords[0][j].x;
			        tmptext[j][1] = m->mTextureCoords[0][j].y;
				}
				else
				{
					tmptext[j][0] = tmptext[j][1] = 0.0f;
				}

			}
			if( (++i) % 3 == 0 )
				tmpMesh->data.AddTriangle(tmpvert,tmpnorm,tmptext);
		}
	}

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

		// Get texture coords
		/*if(m->mTextureCoords[0])
		{
			texts[0] = m->mTextureCoords[0][i].x;
			texts[1] = m->mTextureCoords[0][i].y;
		}else{
			texts[0] = texts[1] = 0.0f;
		}
		textures.push_back( texts );*/
	//}

	// Finally push this mesh back
	meshes.push_back(tmpMesh);

	// End the mesh maybe
	tmpMesh->data.End();
	
	for( i = 0; i < mat->GetTextureCount( aiTextureType_DIFFUSE ) || i < scene->HasMaterials(); i++)
	{
		aiString str;
		mat->GetTexture( aiTextureType_DIFFUSE, i, &str);
		assimpTextureData tmp;
		tmp.id = loadTexture( str.C_Str() );
		tmp.type = 0;
		//textures.push_back(tmp);
	}
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
