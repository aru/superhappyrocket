#include <SDL.h>

int main( int argc, char* args[] ) { 

	// stuff
	SDL_Surface* hello = NULL;
	SDL_Surface* screen = NULL;

	//Start SDL
	SDL_Init( SDL_INIT_EVERYTHING );

	// Set up the screen
	screen = SDL_SetVideoMode( 640, 480, 32, SDL_SWSURFACE );

	// Apply image to screeen
	SDL_BlitSurface( hello, NULL, screen, NULL );

	// Update Screen
	SDL_Flip( screen );

	//Pause
	SDL_Delay( 2000 );

	//Free the loaded image 
	SDL_FreeSurface( hello );

	//Quit SDL
	SDL_Quit();

	return 0;
}