#include "SDL_app.h"

SDL::SDL()
{
}

SDL::SDL( int w, int h, int b, int v)
	: width(w), height(h), bpp(b), vMode(v)
{
	if( vMode && SDL_OPENGL )
		startup();
}

SDL::~SDL(){
}

int SDL::startup()
{

	//Start SDL
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
	{
		printf("Init failed\n");
		return 1;
	}
    
	//Initialize SDL_ttf
    if( TTF_Init() == -1 )
    {
        return 1;    
    }

	//Initialize SDL_mixer
    if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 )
    {
        return 1;    
    }

	/* Create an OpenGL screen */
	if ( SDL_SetVideoMode(width, height, bpp, vMode ) == NULL ) {
		fprintf(stderr, "Unable to create OpenGL screen: %s\n", SDL_GetError());
		shutdown();
		return 1;
	}

	//Enable unicode
    SDL_EnableUNICODE( SDL_TRUE );

	//Initialize OpenGL
    /*if( initGL() == false )
    {
        return false;
    }*/

	/* Set the title bar in environments that support it */
	SDL_WM_SetCaption("Thesis! ppl", NULL);

	return 0;
}

int SDL::shutdown()
{
	// Quit SDL_ttf
	TTF_Quit();

	// Free the music
    // Mix_FreeMusic();
	//Quit SDL_mixer
    Mix_CloseAudio();

    //Quit SDL
    SDL_Quit();
}

int SDL::update()
{
	SDL_GL_SwapBuffers();
}

int SDL::draw()
{

}