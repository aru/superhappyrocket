#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "SDL_net.h"
#include "SDL_mixer.h"
#include "SDL_opengl.h"

#include <stdio.h>
#include <string>

// Things that need to go into a struct for the SDL app:
// app->member
const int width = 640;
const int height = 480;
const int bpp = 32;
const int vMode = SDL_OPENGL;

bool renderQuad = true;

// Test functions

bool initGL()
{
	//Initialize Projection Matrix
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();

    //Initialize Modelview Matrix
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();

    //Initialize clear color
    glClearColor( 0.f, 0.f, 0.f, 1.f );

    //Check for error
    GLenum error = glGetError();
    if( error != GL_NO_ERROR )
    {
        printf( "Error initializing OpenGL! %s\n", gluErrorString( error ) );
        return false;
    }

    return true;
}

bool init()
{
	//Start SDL
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
	{
		printf("Init failed\n");
		return false;
	}
    
	//Initialize SDL_ttf
    if( TTF_Init() == -1 )
    {
        return false;    
    }

	//Initialize SDL_mixer
    if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 )
    {
        return false;    
    }

	/* Create a 800x600 OpenGL screen */
	if ( SDL_SetVideoMode(width, height, bpp, vMode ) == NULL ) {
		fprintf(stderr, "Unable to create OpenGL screen: %s\n", SDL_GetError());
		SDL_Quit();
		exit(2);
	}

	//Enable unicode
    SDL_EnableUNICODE( SDL_TRUE );

	//Initialize OpenGL
    if( initGL() == false )
    {
        return false;
    }

	/* Set the title bar in environments that support it */
	SDL_WM_SetCaption("Thesis! ppl", NULL);

	return true;
}

void handleKeys( unsigned char key, int x, int y )
{
    //Toggle quad
    if( key == 'q' )
    {
        renderQuad = !renderQuad;
    }
}

void update()
{
}

void render()
{
	//Clear color buffer
    glClear( GL_COLOR_BUFFER_BIT );

    //Render quad
    if( renderQuad == true )
    {
        glBegin( GL_QUADS );
            glVertex2f( -0.5f, -0.5f );
            glVertex2f(  0.5f, -0.5f );
            glVertex2f(  0.5f,  0.5f );
            glVertex2f( -0.5f,  0.5f );
        glEnd();
    }

    //Update screen
    SDL_GL_SwapBuffers();
}

int main( int argc, char* args[] )
{

	bool quit = false;

	// Init
	if( !init() ) {
		printf("omg\n");
		goto cleanup;
	}

	//The images
	SDL_Surface* window = NULL;
	// Event stuff
	SDL_Event event;
	// The sound
	Mix_Music *music = NULL;

	// Load the window
	window = SDL_GetVideoSurface();
	//Load the music
    music = Mix_LoadMUS( "../../content/sounds/shr_gp_music_0.wav" );

	if( music == NULL )
		return false;

	while( quit == false )
	{
		while( SDL_PollEvent( &event ) )
		{
			if( event.type == SDL_QUIT )
			{
				// Quit the program
				quit = true;
			}
			else if( event.type == SDL_KEYDOWN )
            {
                //Handle keypress with current mouse position
                int x = 0, y = 0;
                SDL_GetMouseState( &x, &y );
                handleKeys( event.key.keysym.unicode, x, y );
            }

			update();
			render();

			//If there is no music playing
            if( Mix_PlayingMusic() == 0 )
            {
                    //Play the music
                    if( Mix_PlayMusic( music, -1 ) == -1 )
                    {
	                    return 1;
	                }    
            }
		}
	}

	cleanup:

	// Quit SDL_ttf
	TTF_Quit();

	// Free the music
    Mix_FreeMusic( music );
	//Quit SDL_mixer
    Mix_CloseAudio();

    //Quit SDL
    SDL_Quit();
    
    return 0;
}