#include "shrMeshLoader.h"

void shrMeshLoader::recursiveProcess(aiNode* node,const aiScene* scene)
{
	unsigned int i = 0;

	// process each mesh in the scene
	for( i = 0; i < ( node->mNumMeshes ); i++)
	{
		aiMesh* mesh = scene->mMeshes[ node->mMeshes[i] ];
		processMesh2( mesh,scene );
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
	shrMesh* tmpMesh;
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
						//tmptext[j][0] = 1.0f;						
						tmptext[j][0] = m->mTextureCoords[0][j].x;
						//tmptext[j][1] = 0.0f;
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
		if(m->mTangents)
		{
		//	tmpVec[0] = m->mTangents[i].x;
		//	tmpVec[1] = m->mTangents[i].y;
		//	tmpVec[2] = m->mTangents[i].z;
		//}else{
		//	tmpVec[0] = 1.0;
		//	tmpVec[1] = tmpVec[2] = 0;
		}
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

	// End the mesh maybe
	tmpMesh->data.End();

	// Get the textures
	// Temp vars
	aiString str;
	string tmp;
	//Texture2D* tmp2dtext;
	//for( i = 0; i < mat->GetTextureCount( aiTextureType_DIFFUSE ) /*|| i < scene->HasMaterials()*/; i++)
	if( mat->GetTextureCount(aiTextureType_DIFFUSE) > 0 )
	{
		// Get the name of this texture
		mat->GetTexture( aiTextureType_DIFFUSE, 0, &str);
		tmp = str.C_Str();
		if( tmp.find("tga") == string::npos && tmp.length() > 0 )
			tmp.append(".tga");
		// Save the texture obtained
		tmpMesh->textureString = tmp;
	}

	// Process the texture here for now
	if( tmpMesh->textureString.length() != 0 ){
		tmpMesh->texture = new Texture2D( (char*)(tmpMesh->textureString.c_str()), GL_LINEAR, GL_LINEAR, GL_REPEAT );
		tmpMesh->textureFile = ctxt->textMgr->addTexture( tmpMesh->texture );
	}
	// Finally push this mesh back
	meshes.push_back(tmpMesh);

	// If we found a texture, upload it
	//tmpMesh.textureFile = ctxt->textMgr->addTexture( tmpMesh.texture );
	//meshes.push_back(new shrMesh(&data,&indices,&textures));
}

void shrMeshLoader::processMesh2( aiMesh* m, const aiScene* scene )
{
	/* Variables that we use for counting elements and looping */
	unsigned int i,j;
	unsigned int numVertexes = 0;
	unsigned int numIndex = 0;
	unsigned int numTexts = 0;
	bool repeatedText = false;
	unsigned int offset = 0;
	// places to store materials
	aiColor4D col;
	aiMaterial* mat = scene->mMaterials[ m->mMaterialIndex ];

	/* Get the material color */
	aiGetMaterialColor( mat, AI_MATKEY_COLOR_DIFFUSE, &col);

	// Get the textures first as we will be sorting based on this
	// Temp vars
	aiString str;
	string tmp;
	Texture2D* tmp2dtext;
	// If this doesn't have a texture then we have untextured verts
	if( mat->GetTextureCount(aiTextureType_DIFFUSE) > 0 )
	{
		// Get the name of this texture
		mat->GetTexture( aiTextureType_DIFFUSE, 0, &str);
		tmp = str.C_Str();
		if( tmp.find(".") == string::npos && tmp.length() > 0 )
			tmp.append(".");
		if( tmp.find("tga") == string::npos && tmp.length() > 0 )
			tmp.append("tga");
		hasUntexturedVerts = false;
		// Save the texture obtained
		//tmp2dtext->textureString = tmp;
	}
	else if( m->mNumVertices > 0 )
		hasUntexturedVerts = true;

	// Process the texture here for now
	if( tmp.length() != 0 ){
		tmp2dtext = new Texture2D( tmp, GL_LINEAR, GL_LINEAR, GL_REPEAT );
		//tmp2dtext->textureString.copy( (char*)tmp.c_str(), tmp.size() );
		tmp2dtext->textureFile = ctxt->textMgr->addTexture( tmp2dtext );
	}
	
	// Now that we have the texture, aux here is gonna solve our life
	vector<int>::iterator it;
	unsigned int aux;
	if( hasUntexturedVerts )
	{
		aux = 0;
	}
	else
	{
		it = find( textures.begin(), textures.end(), tmp2dtext->textureFile );
		if( it == textures.end() )
		{
			textures.push_back( tmp2dtext->textureFile );
			aux = textures.size();
		}
		else
		{
			aux = *it;
		}
	}

	// Get the indexes
	// temporary places to store data
	std::vector<GLushort> tmpindices;
	bool exists = false;

	// If our current texture is below the index size, then we already have this array stored
	// we should only add values to that
	if( !(aux < verts.size()) )
	{
		verts.push_back( vector<float>() );
		norms.push_back( vector<float>() );
		texts.push_back( vector<float>() );
		indexes.push_back( vector<GLushort>() );
		maxIndex.push_back( GLushort() ); // initialize this thing
	}
	else
	{
		if( maxIndex.at(aux) != 0 )
			offset = maxIndex.at(aux)+1;
		else
			offset = maxIndex.at(aux);
		exists = true;
	}

	for( i = 0; i < m->mNumVertices; i++ )
	{ 

		verts.at(aux).push_back( m->mVertices[i].x );
		verts.at(aux).push_back( m->mVertices[i].y );
		verts.at(aux).push_back( m->mVertices[i].z );

		norms.at(aux).push_back( m->mNormals[i].x );
		norms.at(aux).push_back( m->mNormals[i].y );
		norms.at(aux).push_back( m->mNormals[i].z );

		if(m->mTextureCoords[0]) {
			texts.at(aux).push_back( m->mTextureCoords[0][i].x );
			texts.at(aux).push_back( m->mTextureCoords[0][i].y );
		}
	}

	/* Finally get the indexes of this mesh */
	for( i = 0; i < m->mNumFaces; i++)
	{
		aiFace face = m->mFaces[i];
		for( j = 0; j < face.mNumIndices; j++) //0..2
		{
			// Is this part of another mesh?
			if( exists )
				face.mIndices[j] += offset;

			// Push the index
			indexes[aux].push_back( face.mIndices[j] );

			// Set our new max index
			if( face.mIndices[j] > maxIndex.at(aux) )
				maxIndex.at(aux) = face.mIndices[j];
		}
	}

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

unsigned int shrMeshLoader::loadTGATexture(const char* filename)
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

shrMeshLoader::shrMeshLoader( const char* filename, Context* pctx )
	:verts(0), norms(0), texts(0), indexes(0), numVerts(0), numIndexes(0), numTextures(0), hasUntexturedVerts(false), verts3d(0), norms3d(0), texts3d(0)
{
	ctxt = pctx;
	// Set the offset right now!
	//offset = ctxt->textMgr->numTextures;
	const aiScene* scene = aiImportFile(filename, aiProcessPreset_TargetRealtime_Quality);
	//const aiScene* scene = aiImportFile(filename, aiProcess_GenSmoothNormals | aiProcess_Triangulate | aiProcess_CalcTangentSpace | aiProcess_FlipUVs);
	const char* error = aiGetErrorString();
	if( strcmp(error, "") != 0 )
	{
		std::cout << "The file wasn't successfully opened " << filename << std::endl;
		std::cout << "Error: " << error << std::endl;
		return;
	}

	/* Initialize our temporary arrays, overcompensate a bit because scene->mNumTextures is unreliable */
	numTextures = scene->mNumMaterials;

	// Add the first row as an empty vector
	verts.push_back( vector<float>() );
	norms.push_back( vector<float>() );
	texts.push_back( vector<float>() );
	indexes.push_back( vector<GLushort>() );
	maxIndex.push_back( GLushort() );

	recursiveProcess(scene->mRootNode,scene);
	// After gathering all the intel create batches
	createBatches();
}

shrMeshLoader::~shrMeshLoader()
{
	//unsigned int i = 0;
	//for( i = 0; i < numTextures + 1; i++ );
	//{
	//	free( verts[i] );
	//	free( norms[i] );
	//	free( texts[i] );
	//	free( indexes[i] );
	//}
	//if( verts != 0 ) free( verts );
	//if( verts != 0 ) free( norms );
	//if( texts != 0 ) free( texts );
	//if( indexes != 0 ) free( indexes );
	//if( numverts != 0 ) free( numverts );
	//if( numindexes != 0 ) free( numindexes );
}

void shrMeshLoader::draw()
{
	unsigned int i;

	for( i = 0; i < meshes.size(); i++ )
	{
		//meshes[i]->draw(programId);
		// In here, change the texture used according to the mesh
		// hopefully there's only one texture for the entire mesh
		//meshes[i]->textureFile;
		if( meshes.at(i)->textureFile > 0 )
			ctxt->textMgr->bindTexture(meshes.at(i)->textureFile - 1);
		//meshes.at(i)->data2.Draw();
		meshes.at(i)->data.Draw();
	}
}

void shrMeshLoader::createBatches()
{
	unsigned int i = 0, j = 0, k = 0;
	//M3DVector3f *v, *n, *t, *idx;

	// Just a little sanity check
	if( numTextures != verts.size() + 1 )
		printf("SOMETHING BAD HAPPENED");

	for( i = 0; i < verts.size(); i++ ) 
	{
		/* If array 0 is empty skip it */
		if( i == 0 && verts[i].size() == 0 )
			continue;

		// make a new mesh and push it back into the array
		shrMesh* tmpMesh;
		tmpMesh = new shrMesh();

		if( i != 0 )
			tmpMesh->textureFile = textures.at(i-1);

		// push the vertex/colors/text data into this new mesh
		//tmpMesh->data2.idxBegin( GL_TRIANGLES, (verts[i].size() / 3), indexes[i].size(), 1 );
		tmpMesh->data.BeginMesh( indexes[i].size() );

		// Please...
		k = 0;

		// Construct our vectors because lol
		M3DVector3f* tVert;
		tVert = (M3DVector3f*) calloc( (verts[i].size() / 3), sizeof(M3DVector3f) );
		M3DVector3f* tNorm;
		tNorm = (M3DVector3f*) calloc( (norms[i].size() / 3), sizeof(M3DVector3f) );
		M3DVector2f* tText;
		tText = (M3DVector2f*) calloc( (texts[i].size() / 2), sizeof(M3DVector2f) );

		for( j = 0; j < verts[i].size(); j += 3 )
		{
			tVert[k][0] = verts[i][j];
			tVert[k][1] = verts[i][j+1];
			tVert[k][2] = verts[i][j+2];

			tNorm[k][0] = norms[i][j];
			tNorm[k][1] = norms[i][j+1];
			tNorm[k][2] = norms[i][j+2];
			k++;
		}
		k = 0;
		if( i != 0 ) {
			for( j = 0; j < texts[i].size(); j += 2 )
			{
				tText[k][0] = texts[i][j];
				tText[k][1] = texts[i][j+1];
				k++;
			}
		}

		//tmpMesh->data2.CopyVertexData3f( tVert );
		//tmpMesh->data2.CopyNormalDataf( tNorm );
		//if( i != 0 )
		//	tmpMesh->data2.CopyTexCoordData2f( tText,0 );
		//tmpMesh->data2.CopyIndexDataf(indexes[i].data());

		//// End the mesh
		//tmpMesh->data2.End();

		// used for the next loop
		unsigned int k = 0;

		// Do the same but for triangles
		M3DVector3f v[3];
		M3DVector3f n[3];
		M3DVector2f t[3];

		for( j = 0; j < indexes[i].size(); j+=3 )
		{
			v[0][0] = tVert[ indexes[i][j] ][0];
			v[0][1] = tVert[ indexes[i][j] ][1];
			v[0][2] = tVert[ indexes[i][j] ][2];

			v[1][0] = tVert[ indexes[i][j+1] ][0];
			v[1][1] = tVert[ indexes[i][j+1] ][1];
			v[1][2] = tVert[ indexes[i][j+1] ][2];

			v[2][0] = tVert[ indexes[i][j+2] ][0];
			v[2][1] = tVert[ indexes[i][j+2] ][1];
			v[2][2] = tVert[ indexes[i][j+2] ][2];

			n[0][0] = tNorm[ indexes[i][j] ][0];
			n[0][1] = tNorm[ indexes[i][j] ][1];
			n[0][2] = tNorm[ indexes[i][j] ][2];

			n[1][0] = tNorm[ indexes[i][j+1] ][0];
			n[1][1] = tNorm[ indexes[i][j+1] ][1];
			n[1][2] = tNorm[ indexes[i][j+1] ][2];

			n[2][0] = tNorm[ indexes[i][j+2] ][0];
			n[2][1] = tNorm[ indexes[i][j+2] ][1];
			n[2][2] = tNorm[ indexes[i][j+2] ][2];

			t[0][0] = tText[ indexes[i][j] ][0];
			t[0][1] = tText[ indexes[i][j] ][1];

			t[1][0] = tText[ indexes[i][j+1] ][0];
			t[1][1] = tText[ indexes[i][j+1] ][1];

			t[2][0] = tText[ indexes[i][j+2] ][0];
			t[2][1] = tText[ indexes[i][j+2] ][1];

			tmpMesh->data.AddTriangle( v, n, t );
		}

		// End the triangle mesh
		tmpMesh->data.End();

		tmpMesh->texture = 0;
		tmpMesh->textureString = "dunno";
		// Finally push this mesh back
		meshes.push_back(tmpMesh);

		free(tVert);
		free(tNorm);
		free(tText);
	}
}