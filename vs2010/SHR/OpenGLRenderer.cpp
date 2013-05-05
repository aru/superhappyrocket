#include "OpenGLRenderer.h"

Renderer::Renderer()
{
	shader = new GLShaderManager();
}

Renderer::Renderer( Context* ctx )
	:ctxt(ctx)
{
	shader = new GLShaderManager();
	cameraFrame = new GLFrame();
	modelViewMatrix = new GLMatrixStack();
	projectionMatrix = new GLMatrixStack();
	viewFrustum = new GLFrustum();
	transformPipeline = new GLGeometryTransform();
}

Renderer::~Renderer()
{
	delete shader;
}

int Renderer::Init()
{
	// Initialize glew
	GLenum err = glewInit();
	if (err != GLEW_OK)
		printf(":<\n"); // or handle the error in a nicer way
	glewGetString(err);

	if (!GLEW_VERSION_2_1)  // check that the machine supports the 2.1 API.
		printf(":<\n"); // or handle the error in a nicer way

	// Initialize the Projection Matrix/ModelView Matrix
	changeSize( ctxt->width, ctxt->height );

	// Set the clear color
	glClearColor(0.0f, 0.0f, 1.0f, 0.0f);

	// Init stock shaders
	shader->InitializeStockShaders();

	// Init textures (?)
	//glGenTextures(1, &uiTextures);
	//glBindTexture(GL_TEXTURE_2D, uiTextures);
    //LoadTGATexture("haruhi.tga", GL_LINEAR, GL_LINEAR, GL_REPEAT);

	// Set the camera (?)
	cameraFrame->MoveForward(-7.0f);

	// Enable depth testing
	glEnable(GL_DEPTH_TEST);
	// Polygon mode?
	/*glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);*/

    //Check for errors
    GLenum error = glGetError();
    if( error != GL_NO_ERROR )
    {
        //printf( "Error initializing OpenGL! %s\n", gluErrorString( error ) );
        return 1;
    }

    return 0;
}
int Renderer::Draw()
{

	static GLfloat vWhite[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	static GLfloat vLightPos[] = { 0.0f, 3.0f, 0.0f, 1.0f};

	//Clear buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

	// Save the current modelview matrix (the identity matrix)
	modelViewMatrix->PushMatrix();	

		// Get the camera
		cameraFrame->GetCameraMatrix(camera);

		// Apply camera transform
		modelViewMatrix->PushMatrix(camera);

	    //Draw objects (that don't move)
		for( unsigned int i = 0; i < object.size(); i++ )
		{
			shader->UseStockShader(GLT_SHADER_FLAT, 
								 transformPipeline->GetModelViewProjectionMatrix(),
								 vWhite);

			if( object.at(i)->renderMe == true )
				object.at(i)->Draw();
		}

		// Draw moving stuff (actors)
		for( unsigned int i = 0; i < actor.size(); i++ )
		{
			// Apply actor transform
			modelViewMatrix->PushMatrix();
			modelViewMatrix->MultMatrix(actor.at(i)->frame);

			//Bind texture if there is one
			if( actor.at(i)->textureFile > 0 )
				ctxt->textMgr->bindTexture(actor.at(i)->textureFile - 1);

			//Use the selected shader
			shader->UseStockShader(GLT_SHADER_TEXTURE_POINT_LIGHT_DIFF,
                                     modelViewMatrix->GetMatrix(),
                                     transformPipeline->GetProjectionMatrix(),
                                     vLightPos, 
                                     vWhite,
                                     0);

			// Draw actor geometry
			actor.at(i)->Draw2();
			// Restore camera transform
			modelViewMatrix->PopMatrix();
		}

		// Restore identity matrix		
		modelViewMatrix->PopMatrix();

	modelViewMatrix->PopMatrix();

	// Swap buffers
	// Post redisplay in SDL_app

	return 0;
}

int Renderer::Draw2()
{
	//Clear buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

	GLfloat vRed[] = { 1.0f, 0.0f, 0.0f, 1.0f };

	// Save the current modelview matrix (the identity matrix)
	modelViewMatrix->PushMatrix();	
    
    M3DMatrix44f mCamera;
    cameraFrame->GetCameraMatrix(mCamera);
    modelViewMatrix->PushMatrix(mCamera);

    //Render objects
	for( unsigned int i = 0; i < object.size(); i++ )
	{
		if( object.at(i)->renderMe == true )
			object.at(i)->Draw();
	}

	if( batch.size() )
	{
		//shader->UseStockShader(GLT_SHADER_IDENTITY, vRed);
		shader->UseStockShader(GLT_SHADER_FLAT,
								 transformPipeline->GetModelViewProjectionMatrix(),
								 vRed);	
	static GLfloat vWhite[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	static GLfloat vLightPos[] = { 0.0f, 3.0f, 0.0f, 1.0f};
	
	glBindTexture(GL_TEXTURE_2D, uiTextures);
    shader->UseStockShader(GLT_SHADER_TEXTURE_POINT_LIGHT_DIFF, 
                                     transformPipeline->GetModelViewMatrix(),
                                     transformPipeline->GetProjectionMatrix(), 
                                     vLightPos, vWhite, 0);
	}

	// Render batches
	for( unsigned int i = 0; i < batch.size(); i++ )
	{
		batch.at(i)->Draw();
	}

	modelViewMatrix->PopMatrix();
	modelViewMatrix->PopMatrix();   

	return 0;
}

int Renderer::Update()
{
	return 0;
}

int Renderer::Clear()
{
	return 0;
}

int Renderer::Shutdown()
{
	glDeleteTextures(1, &uiTextures);
	return 0;
}

int Renderer::addObject( SimpleObject* obj )
{
	object.push_back(obj);
	return 0;
}

int Renderer::addActor( SimpleObject* act )
{
	actor.push_back(act);
	return 0;
}

int Renderer::addBatch( GLBatch* bat )
{
	batch.push_back(bat);
	return 0;
}

int Renderer::clearObjects()
{
	object.clear();
	batch.clear();
	return 0;
}

/* Screen changes size or is initialized */
int Renderer::changeSize( int nWidth, int nHeight )
{
	glViewport(0, 0, nWidth, nHeight);
	
    // Create the projection matrix, and load it on the projection matrix stack
	viewFrustum->SetPerspective(35.0f, float(nWidth)/float(nHeight), 1.0f, 100.0f);
	projectionMatrix->LoadMatrix(viewFrustum->GetProjectionMatrix());
    
    // Set the transformation pipeline to use the two matrix stacks 
	transformPipeline->SetMatrixStacks(*modelViewMatrix, *projectionMatrix);

	return 0;
}

// Load a TGA as a 2D Texture. Completely initialize the state
bool Renderer::LoadTGATexture(const char *szFileName, GLenum minFilter, GLenum magFilter, GLenum wrapMode)
{
	GLbyte *pBits;
	int nWidth, nHeight, nComponents;
	GLenum eFormat;
	
	// Read the texture bits
	pBits = gltReadTGABits(szFileName, &nWidth, &nHeight, &nComponents, &eFormat);
	if(pBits == NULL) 
		return false;
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrapMode);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrapMode);
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, minFilter);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, magFilter);
    
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glTexImage2D(GL_TEXTURE_2D, 0, nComponents, nWidth, nHeight, 0,
				 eFormat, GL_UNSIGNED_BYTE, pBits);
	
    free(pBits);
    
    if(minFilter == GL_LINEAR_MIPMAP_LINEAR || 
       minFilter == GL_LINEAR_MIPMAP_NEAREST ||
       minFilter == GL_NEAREST_MIPMAP_LINEAR ||
       minFilter == GL_NEAREST_MIPMAP_NEAREST)
        glGenerateMipmap(GL_TEXTURE_2D);
    
	return true;
}