#include "OpenGLRenderer.h"

GLuint Renderer::unusedIds = 0;

Renderer::Renderer()
{
}

Renderer::Renderer( Context* ctx )
    : ctxt( ctx )
{
    camera = new Camera();
    ctxt->camera = camera;
    ctxt->shaderManager = &shaderManager;
}

Renderer::~Renderer()
{
    delete camera;
}

const int Renderer::Initialize()
{
    GLenum error;

    /* Initialize glew */
    error = glewInit();
    if( error != GLEW_OK )
    {
        glewGetString( error );
        printf( "GLEW Error: %d on Initialize()\n", error );
    }

    /* Check that we support the 2.1 API */
    if( !GLEW_VERSION_2_1 )
        printf("GLEW Version 2.1 not supported\n");

#ifdef DEBUG
    /* Now check if we can use ARB_debug_output */
    if( GLEW_ARB_debug_output ) {
        glDebugMessageCallbackARB( &Renderer::myErrorCallback, NULL );
        glEnable( GL_DEBUG_OUTPUT_SYNCHRONOUS );
        glDebugMessageControlARB(GL_DONT_CARE,
                                 GL_DONT_CARE,
                                 GL_DONT_CARE,
                                 0,
                                 &Renderer::unusedIds,
                                 true);
    }
#endif

    /************** OpenGL starts here *******************/

    /************** Initialize Stock Shaders ************/
    shaderManager.InitializeStockShaders();

    /* Enable depth testing */
    glEnable(GL_DEPTH_TEST);

    /* Set the clear color */
    glClearColor( 0.0f, 1.0f, 0.0f, 1.0f );

    /* Initialize the Projection Matrix/ModelView Matrix */
    camera->modelViewMatrix.LoadIdentity();

    ChangeSize( ctxt->width, ctxt->height );

    /* Enable polygon mode? */

    /* Check for errors */
    error = glGetError();
    if( error != GL_NO_ERROR )
    {
        printf("Error Initializing OpenGL on Renderer: %d\n", error );
        return SHR_FAIL;
    }

    /* Return Success */
    return SHR_SUCCESS;
}

const int Renderer::LoadContent()
{
    return SHR_SUCCESS;
}

const int Renderer::Draw()
{
    unsigned int numActors;

    /* Clear buffers */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

    /* Save the current modelview matrix( the identity matrix ) */
    camera->modelViewMatrix.PushMatrix();

    /* Get the camera matrix and push it */
    //camera->cameraFrame.GetCameraMatrix( camera->camera, true );
    //camera->modelViewMatrix.PushMatrix( camera->camera );

    /* Draw objects that don't move */
    for( numActors = 0; numActors < actors.size(); numActors++ )
    {
        actors.at( numActors )->Draw( camera, &shaderManager, ctxt->textureManager, light );
    }

    /* Pop the camera matrix */
    //camera->modelViewMatrix.PopMatrix();

    /* Restore the identity matrix */
    camera->modelViewMatrix.PopMatrix();

    return SHR_SUCCESS;
}

const int Renderer::Update( float delta )
{
    return SHR_SUCCESS;
}

const int Renderer::UnloadContent()
{
    return SHR_SUCCESS;
}

const int Renderer::ChangeSize( int nWidth, int nHeight )
{
    /* Set the viewport */
    glViewport( 0, 0, nWidth, nHeight );

    /* Create the projection matrix, and load it on the projection matrix stack */
    camera->viewFrustum.SetPerspective( 55.0f, float(nWidth) / float(nHeight), 1.0f, 200.0f);
    camera->projectionMatrix.LoadMatrix( camera->viewFrustum.GetProjectionMatrix() );

    /* Set the transformation pipeline to use the two matrix stacks */
    camera->transformPipeline.SetMatrixStacks(camera->modelViewMatrix, camera->projectionMatrix);

    return SHR_SUCCESS;

}

/* ARB_debug_output support */
void APIENTRY Renderer::myErrorCallback( GLenum _source,
                                         GLenum _type, GLuint _id, GLenum _severity,
                                         GLsizei _length, const char* _message,
                                         void* _userParam )
{
    printf( "%s\n", _message );
}
