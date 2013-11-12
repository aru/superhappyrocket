#include "assimpMesh.h"

assimpMesh::assimpMesh( const char* filename, Context* ctx )
	:ctxt(ctx), fileName( filename ), untexturedVerts( false ), numTextures(0)
{
	scaleVector[0] = 1.0f;
	scaleVector[1] = 1.0f;
	scaleVector[2] = 1.0f;
}

assimpMesh::assimpMesh( const assimpMesh& mesh )
{
	ctxt = mesh.ctxt;
	fileName = mesh.fileName;
}

assimpMesh::~assimpMesh()
{
	unsigned int i = 0;
	for( i = 0; objects.size(); i++ )
	{
		delete objects.at(i);
	}
	objects.clear();
	textures.clear();

}

const int assimpMesh::Initialize( Context* ctx ) 
{
	// Import the model from file
	const aiScene* scene = aiImportFile( fileName.c_str(), aiProcessPreset_TargetRealtime_Fast );
	// Check for errors
	const char* error = aiGetErrorString();
	if( strcmp( error, "" ) != 0 )
	{
		cout << "File " << fileName << "couldn't be open. Error: " << error << endl;
	}

	numTextures = scene->mNumMaterials;

	// Add the first row as an empty vector
	verts.push_back( vector<float>() );
	norms.push_back( vector<float>() );
	texts.push_back( vector<float>() );
	indexes.push_back( vector<GLushort>() );
	maxIndex.push_back( GLushort() );

	// Go through the mesh and load it into readable batches
	recursiveProcess( scene->mRootNode, scene );

	// Create drawable batches
	createBatches();

	return SHR_SUCCESS;
}
const int assimpMesh::LoadContent() 
{
	return SHR_SUCCESS;
}
const int assimpMesh::Draw( Camera* camera, GLShaderManager* shaderManager, TextureManager* textureManager, Light* light ) 
{
	unsigned int i = 0;

	camera->cameraFrame.GetCameraMatrix(camera->camera, false);
	/* Get the final transformation for this object */
	frame.GetMatrix( mScaleMatrix );
	m3dScaleMatrix44( mScaleMatrix, scaleVector );

	camera->modelViewMatrix.PushMatrix();

	camera->modelViewMatrix.MultMatrix( camera->camera );
	camera->modelViewMatrix.MultMatrix( frame );
	camera->modelViewMatrix.MultMatrix( mScaleMatrix );

	/* Do some transformations */

	for( i = 0; i < objects.size(); i++ )
	{
		camera->modelViewMatrix.PushMatrix();

		camera->modelViewMatrix.MultMatrix( objects.at(i)->frame );

		shaderManager->UseStockShader( GLT_SHADER_TEXTURE_POINT_LIGHT_DIFF,
			camera->modelViewMatrix.GetMatrix(),
			camera->transformPipeline.GetProjectionMatrix(),
			light->position,
			light->color,
			0 );

		if( objects.at(i)->textureFile > 0 )
			textureManager->bindTexture( objects.at(i)->textureFile - 1 );
		objects.at(i)->triBatch.Draw();

		camera->modelViewMatrix.PopMatrix();
	}

	camera->modelViewMatrix.PopMatrix();

	return SHR_SUCCESS;
}
const int assimpMesh::Update() 
{
	return SHR_SUCCESS;
}
const int assimpMesh::UnloadContent() 
{
	return SHR_SUCCESS;
}

void assimpMesh::recursiveProcess( aiNode* node, const aiScene* scene )
{
	unsigned int i,j;

	/* process every mesh in the current node */
	for( i = 0; i < (node->mNumMeshes); i++ )
	{
		aiMesh* mesh = scene->mMeshes[ node->mMeshes[i] ];
		processMesh( mesh, scene );
	}
	/* process each children in the scenegraph */
	for( j = 0; j < node->mNumChildren; j++ )
	{
		recursiveProcess( node->mChildren[j], scene );
	}
}

/*
 * Our mesh processing works like this:
 * - get all of the textures in the current mesh
 * - build that many arrays for data storage
 * - populate them as we go
 * - at the end create batches out of this data, 1 for every texture
 * NOTE: if we have no textures, we will at least have 1 array for everything
 */
void assimpMesh::processMesh( aiMesh* mesh, const aiScene* scene )
{
	/* variables to store materials */
	aiColor4D col;
	aiMaterial* mat = scene->mMaterials[ mesh->mMaterialIndex ];
	/* Get the material color */
	aiGetMaterialColor( mat, AI_MATKEY_COLOR_DIFFUSE, &col );

	/* Get the textures now */
	aiString str;
	string tmpStr( "../../content/models/" ); // Helper string to make some sense out of data thrown by assimp
	string tmpStr2;
	/* If this material has a texture */
	if( mat->GetTextureCount( aiTextureType_DIFFUSE ) > 0 )
	{
		/* Get its name */
		mat->GetTexture( aiTextureType_DIFFUSE, 0, &str );
		tmpStr2.append( str.C_Str() );
		if( tmpStr2.length() > 0 && tmpStr2.rfind(".") == string::npos )
			tmpStr2.append(".");
		if( tmpStr2.length() > 0 && tmpStr2.rfind("tga") == string::npos )
			tmpStr2.append("tga");
		tmpStr.append( tmpStr2 );
		untexturedVerts = false;
	}
	else if( mesh->mNumVertices > 0 )
		untexturedVerts = true;

	/* Load the texture for here now */
	Texture2D* tmpTexture;
	if( tmpStr.length() != 0 )
	{
		tmpTexture = new Texture2D( tmpStr, GL_LINEAR, GL_LINEAR, GL_REPEAT );
		tmpTexture->textureFile = ctxt->textureManager->addTexture( tmpTexture );
	}

	/* Now we now if we have textures or not, 
	 * point to the right array to start filling it up. 
	 */
	unsigned int numText;
	if( untexturedVerts )
	{
		numText = 0; // No texture is array 0
	}
	else // Find out what array this should be
	{
		bool found = false; // Is the texture in the array?
		for( unsigned int count = 0; count < textures.size(); count++ )
		{
			if( tmpTexture->textureFile == textures.at( count ) )
			{
				numText = count + 1; // Space 0 is always reserved for the 'untextured' case
				found = true;
				break;
			}
		}
		if( !found ) // texture not found, it's a new one! push it
		{
			textures.push_back( tmpTexture->textureFile );
			numText = textures.size();
		}
	}

	/* ******* Really go through the mesh now ******* */

	/* Get the indexes */
	vector<GLushort> tmpindices;
	bool exists = false;
	/* 
	 * We want to save all of our indices in one big array for every texture, to figure
	 * out which array we push the new indices into we go by the texture number, if there
	 * is no texture, then we use array 0.
	 * Thus, we can say that if our current texture is below the index size, 
	 * we already have this array stored, we should only add values to that.
	 */
	unsigned int offset = 0;
	if( !( numText < verts.size()) ) // do we already have data for this texture?
	{
		// add empty placeholder arrays
		verts.push_back( vector<float>() );
		norms.push_back( vector<float>() );
		texts.push_back( vector<float>() );
		indexes.push_back( vector<GLushort>() );
		maxIndex.push_back( GLushort() );
	}
	else
	{
		if( maxIndex.at( numText ) != 0 )
			offset = maxIndex.at( numText ) + 1;
		else
			offset = maxIndex.at( numText );
		exists = true;
	}

	unsigned int i = 0;
	for( i = 0; i < mesh->mNumVertices; i++ )
	{
		verts.at(numText).push_back( mesh->mVertices[i].x );
		verts.at(numText).push_back( mesh->mVertices[i].y );
		verts.at(numText).push_back( mesh->mVertices[i].z );

		norms.at(numText).push_back( mesh->mNormals[i].x );
		norms.at(numText).push_back( mesh->mNormals[i].y );
		norms.at(numText).push_back( mesh->mNormals[i].z );

		if(mesh->mTextureCoords[0]) {
			texts.at(numText).push_back( mesh->mTextureCoords[0][i].x );
			texts.at(numText).push_back( mesh->mTextureCoords[0][i].y );
		}
	}

	unsigned int j = 0;
	/* Finally get the indexes for this mesh */
	for( i = 0; i < mesh->mNumFaces; i++)
	{
		aiFace face = mesh->mFaces[i];
		for( j = 0; j < face.mNumIndices; j++) //0..2
		{
			// Is this part of another mesh?
			if( exists )
				face.mIndices[j] += offset;

			// Push the index
			indexes[numText].push_back( face.mIndices[j] );

			// Set our new max index
			if( face.mIndices[j] > maxIndex.at(numText) )
				maxIndex.at(numText) = face.mIndices[j];
		}
	}

	//delete tmpTexture;
}

void assimpMesh::createBatches()
{
	unsigned int i = 0, j = 0, k = 0;

	// Sanity check
	if( numTextures != verts.size() + 1 )
		SDL_assert(1);

	for( i = 0; i < verts.size(); i++ )
	{
		/* If array 0 is empty skip it */
		if( i == 0 && verts[i].size() == 0 )
			continue;

		/* make a new object and push it back into the array */
		SimpleObject* tmpObj;
		tmpObj = new SimpleObject();
		/* Set the object texture */
		if( i != 0 )
			tmpObj->textureFile = textures.at( i - 1 );
		/* push the data into this new mesh */
		tmpObj->triBatch.BeginMesh( indexes[i].size() );

		// start at 0 again
		k = 0;

		// Construct our temporary vectors
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

			tmpObj->triBatch.AddTriangle( v, n, t );
		}

		// End the triangle mesh
		tmpObj->triBatch.End();
		// Finally push this mesh back
		objects.push_back(tmpObj);

		free(tVert);
		free(tNorm);
		free(tText);
	}
}