#include "SDLApp.h"

SDLApp::SDLApp( Context* context )
    :ctxt(context), width(context->width), height(context->height),
     bpp(context->bpp), vMode(context->vMode), wantRedisplay(1),
     window(NULL), gContext(NULL)
{
}

SDLApp::~SDLApp()
{
    /* Unload All Content Created */
    UnloadContent();
    /* Destroy the SDL window and app */
    SDL_DestroyWindow( window );
    SDL_Quit();
}

int SDLApp::Initialize()
{
    /* Initialize SDL */
    if( SDL_Init( SDL_INIT_EVERYTHING ) < 0 )
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        return 1;
    }

    /* Create Window */
    window = SDL_CreateWindow( "SHR", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                               width, height,
                               SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE );
    if( window == NULL )
    {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        return 1;
    }

    /* Start our audio manager */
    ctxt->audio->Initialize();

    /* Set the OpenGL version we will be using, AT LEAST 2.1 */
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
#ifdef DEBUG
    /* Set it to debug mode */
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_DEBUG_FLAG);
#endif

    /* Create context */
    gContext = SDL_GL_CreateContext( window );
    if( gContext == NULL )
    {
        printf( "OpenGL context could not be created! SDL Error: %s\n", SDL_GetError() );
        return 1;
    }

    /* GLEW is initialized by the renderer, so initialize that */
    ctxt->renderer->Initialize();

    /* Set VSync in here */
    if( SDL_GL_SetSwapInterval( 1 ) < 0 )
    {
        printf( "Warning: Unable to set VSync! SDL Error: %s\n", SDL_GetError() );
        return 1;
    }

    /* Start our timer */
    ctxt->timer->start();

    /* Start our scene */
    ctxt->sceneManager->Initialize();

    return 0;

}
/* Load everything else required by the SDL App */
int SDLApp::LoadContent()
{
    ctxt->audio->LoadContent();
    ctxt->renderer->LoadContent();
    return 0;
}

int SDLApp::Draw()
{
    /* Draw the level */
    if( wantRedisplay )
    {
        //wantRedisplay = 0;
        ctxt->renderer->Draw();
    }
    /* Update the drawing */
    ctxt->renderer->Update( 0.0f );
    /* Update the level */
    ctxt->sceneManager->Update( ctxt->timer->get_ticks() );
    /* Swap buffers */
    SDL_GL_SwapWindow( window );
    return 0;
}

int SDLApp::Update()
{
    return 0;
}

int SDLApp::UnloadContent()
{
    ctxt->audio->UnloadContent();
    ctxt->renderer->UnloadContent();
    return 0;
}
