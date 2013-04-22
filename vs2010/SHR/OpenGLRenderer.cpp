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
	GLenum err = glewInit();
	if (err != GLEW_OK)
		printf(":<\n"); // or handle the error in a nicer way
	glewGetString(err);
	if (!GLEW_VERSION_2_1)  // check that the machine supports the 2.1 API.
		printf(":<\n"); // or handle the error in a nicer way

	////Initialize Projection Matrix
 //   glMatrixMode( GL_PROJECTION );
 //   glLoadIdentity();

 //   //Initialize Modelview Matrix
 //   glMatrixMode( GL_MODELVIEW );
 //   glLoadIdentity();

	changeSize( ctxt->width, ctxt->height );

	glClearColor(0.0f, 0.0f, 1.0f, 0.0f);
	shader->InitializeStockShaders();

	glEnable(GL_DEPTH_TEST);
	/*glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);*/

    //Check for error
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
	return 0;
}

int Renderer::addObject( SimpleObject* obj )
{
	object.push_back(obj);
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