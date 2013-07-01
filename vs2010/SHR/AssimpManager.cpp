#include "AssimpManager.h"

AssimpManager::AssimpManager()
{
	// the global Assimp scene object
	const aiScene* scene = NULL;
	GLuint scene_list = 0;
}

AssimpManager::AssimpManager( Context* ctxt )
	: ctx( ctxt )
{
	// the global Assimp scene object
	const aiScene* scene = NULL;
	GLuint scene_list = 0;
}

AssimpManager::~AssimpManager()
{
	textureIdMap.clear(); /* no need to delete pointers in it manually here. 
						   * (Pointers point to textureIds deleted in next step) */

	// clear texture ids
	if (textureIds)
	{
		delete[] textureIds;
		textureIds = NULL;
	}

	destroyAILogger();
}

void AssimpManager::createAILogger()
{
	//Assimp::Logger::LogSeverity severity = Assimp::Logger::NORMAL;
	Assimp::Logger::LogSeverity severity = Assimp::Logger::VERBOSE;

	// Create a logger instance for Console Output
	Assimp::DefaultLogger::create("",severity, aiDefaultLogStream_STDOUT);

	// Create a logger instance for File Output (found in project folder or near .exe)
	Assimp::DefaultLogger::create("assimp_log.txt",severity, aiDefaultLogStream_FILE);

	// Now I am ready for logging my stuff
	Assimp::DefaultLogger::get()->info("this is my info-call");
}

void AssimpManager::destroyAILogger()
{
	// Kill it after the work is done
	Assimp::DefaultLogger::kill();
}

void AssimpManager::logInfo( std::string logString )
{
	//Will add message to File with "info" Tag
	Assimp::DefaultLogger::get()->info(logString.c_str());
}

void AssimpManager::logDebug( const char* logString )
{
	//Will add message to File with "debug" Tag
	Assimp::DefaultLogger::get()->debug(logString);
}

bool AssimpManager::Import3DFromFile( const std::string& pFile )
{
	//check if file exists
	std::ifstream fin(pFile.c_str());
	if( !fin.fail() )
	{
		fin.close();
	}
	else
	{
		MessageBox(NULL, ("Couldn't open file: " + pFile).c_str() , "ERROR", MB_OK | MB_ICONEXCLAMATION );
		logInfo( importer.GetErrorString() );
		return false;
	}

	scene = importer.ReadFile( pFile, aiProcessPreset_TargetRealtime_Quality );

	// If the import failed, report it
	if( !scene )
	{
		logInfo( importer.GetErrorString() );
		return false;
	}

	// Now we can access the file's contents.
	logInfo( "Import of scene " + pFile + " succeeded." );

	// We're done. Everything will be cleaned up by the importer destructor
	return true;
}

// Can't send color down as a pointer to aiColor4D because AI colors are ABGR.
void AssimpManager::Color4f(const aiColor4D *color)
{
	glColor4f(color->r, color->g, color->b, color->a);
}

void AssimpManager::set_float4( float f[4], float a, float b, float c, float d )
{
	f[0] = a;
	f[1] = b;
	f[2] = c;
	f[3] = d;
}

void AssimpManager::color4_to_float4( const aiColor4D *c, float f[4] )
{
	f[0] = c->r;
	f[1] = c->g;
	f[2] = c->b;
	f[3] = c->a;
}

void AssimpManager::apply_material( const aiMaterial *mtl )
{
	float c[4];

	GLenum fill_mode;
	int ret1, ret2;
	aiColor4D diffuse;
	aiColor4D specular;
	aiColor4D ambient;
	aiColor4D emission;
	float shininess, strength;
	int two_sided;
	int wireframe;
	unsigned int max;	// changed: to unsigned

	int texIndex = 0;
	aiString texPath;	//contains filename of texture

	if( AI_SUCCESS == mtl->GetTexture( aiTextureType_DIFFUSE, texIndex, &texPath ) )
	{
		//bind texture
		unsigned int texId = *textureIdMap[texPath.data];
		glBindTexture(GL_TEXTURE_2D, texId);
	}

	set_float4(c, 0.8f, 0.8f, 0.8f, 1.0f);
	if(AI_SUCCESS == aiGetMaterialColor(mtl, AI_MATKEY_COLOR_DIFFUSE, &diffuse))
		color4_to_float4(&diffuse, c);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, c);

	set_float4(c, 0.0f, 0.0f, 0.0f, 1.0f);
	if(AI_SUCCESS == aiGetMaterialColor(mtl, AI_MATKEY_COLOR_SPECULAR, &specular))
		color4_to_float4(&specular, c);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, c);

	set_float4(c, 0.2f, 0.2f, 0.2f, 1.0f);
	if(AI_SUCCESS == aiGetMaterialColor(mtl, AI_MATKEY_COLOR_AMBIENT, &ambient))
		color4_to_float4(&ambient, c);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, c);

	set_float4(c, 0.0f, 0.0f, 0.0f, 1.0f);
	if(AI_SUCCESS == aiGetMaterialColor(mtl, AI_MATKEY_COLOR_EMISSIVE, &emission))
		color4_to_float4(&emission, c);
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, c);

	max = 1;
	ret1 = aiGetMaterialFloatArray(mtl, AI_MATKEY_SHININESS, &shininess, &max);
	max = 1;
	ret2 = aiGetMaterialFloatArray(mtl, AI_MATKEY_SHININESS_STRENGTH, &strength, &max);
	if((ret1 == AI_SUCCESS) && (ret2 == AI_SUCCESS))
		glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shininess * strength);
	else {
		glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 0.0f);
		set_float4(c, 0.0f, 0.0f, 0.0f, 0.0f);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, c);
	}

	max = 1;
	if(AI_SUCCESS == aiGetMaterialIntegerArray(mtl, AI_MATKEY_ENABLE_WIREFRAME, &wireframe, &max))
		fill_mode = wireframe ? GL_LINE : GL_FILL;
	else
		fill_mode = GL_FILL;
	glPolygonMode(GL_FRONT_AND_BACK, fill_mode);

	max = 1;
	if((AI_SUCCESS == aiGetMaterialIntegerArray(mtl, AI_MATKEY_TWOSIDED, &two_sided, &max)) && two_sided)
		glEnable(GL_CULL_FACE);
	else
		glDisable(GL_CULL_FACE);
}

void AssimpManager::recursive_render(const struct aiScene *sc, const struct aiNode* nd, float scale)
{
	unsigned int i;
	unsigned int n=0, t;
	aiMatrix4x4 m = nd->mTransformation;

	aiMatrix4x4 m2;
	aiMatrix4x4::Scaling(aiVector3D(scale, scale, scale), m2);
	m = m * m2;

	// update transform
	m.Transpose();
	glPushMatrix();
	glMultMatrixf((float*)&m);

	// draw all meshes assigned to this node
	for (; n < nd->mNumMeshes; ++n)
	{
		const struct aiMesh* mesh = scene->mMeshes[nd->mMeshes[n]];

		apply_material(sc->mMaterials[mesh->mMaterialIndex]);


		if(mesh->mNormals == NULL)
		{
			glDisable(GL_LIGHTING);
		}
		else
		{
			glEnable(GL_LIGHTING);
		}

		if(mesh->mColors[0] != NULL)
		{
			glEnable(GL_COLOR_MATERIAL);
		}
		else
		{
			glDisable(GL_COLOR_MATERIAL);
		}



		for (t = 0; t < mesh->mNumFaces; ++t) {
			const struct aiFace* face = &mesh->mFaces[t];
			GLenum face_mode;

			switch(face->mNumIndices)
			{
				case 1: face_mode = GL_POINTS; break;
				case 2: face_mode = GL_LINES; break;
				case 3: face_mode = GL_TRIANGLES; break;
				default: face_mode = GL_POLYGON; break;
			}

			glBegin(face_mode);

			for(i = 0; i < face->mNumIndices; i++)		// go through all vertices in face
			{
				int vertexIndex = face->mIndices[i];	// get group index for current index
				if(mesh->mColors[0] != NULL)
					Color4f(&mesh->mColors[0][vertexIndex]);
				if(mesh->mNormals != NULL)

					if(mesh->HasTextureCoords(0))		//HasTextureCoords(texture_coordinates_set)
					{
						glTexCoord2f(mesh->mTextureCoords[0][vertexIndex].x, 1 - mesh->mTextureCoords[0][vertexIndex].y); //mTextureCoords[channel][vertex]
					}

					glNormal3fv(&mesh->mNormals[vertexIndex].x);
					glVertex3fv(&mesh->mVertices[vertexIndex].x);
			}

			glEnd();

		}

	}


	// draw all children
	for (n = 0; n < nd->mNumChildren; ++n)
	{
		recursive_render(sc, nd->mChildren[n], scale);
	}

	glPopMatrix();
}

void AssimpManager::drawAiScene(const aiScene* scene)
{
	logInfo("drawing objects");
	recursive_render(scene, scene->mRootNode, 0.5);
}