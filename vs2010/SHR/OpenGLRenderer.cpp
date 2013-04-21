#include "OpenGLRenderer.h"

Renderer::Renderer()
{
	shader = new GLShaderManager();
}

Renderer::~Renderer()
{
}

int Renderer::Init()
{
	GLenum err = glewInit();
	if (err != GLEW_OK)
		printf(":<\n"); // or handle the error in a nicer way
	glewGetString(err);
	if (!GLEW_VERSION_2_1)  // check that the machine supports the 2.1 API.
		printf(":<\n"); // or handle the error in a nicer way

	//Initialize Projection Matrix
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();

    //Initialize Modelview Matrix
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();

	shader->InitializeStockShaders();

    //Initialize clear color
    glClearColor( 0.f, 0.f, 1.f, 1.f );

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

    //Render objects
	for( unsigned int i = 0; i < object.size(); i++ )
	{
		if( object.at(i)->renderMe == true )
			object.at(i)->Draw();
	}

	if( batch.size() )
	{
		shader->UseStockShader(GLT_SHADER_IDENTITY, vRed);
	}

	// Render batches
	for( unsigned int i = 0; i < batch.size(); i++ )
	{
		batch.at(i)->Draw();
	}

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
	//batch.clear();
	return 0;
}