#include "InputManager.h"

InputManager::InputManager()
{
}

InputManager::InputManager( Context* context )
	:ctxt(context)
{
}

InputManager::~InputManager()
{
}

Uint16 InputManager::handleKeys()
{
	while( SDL_PollEvent( &event ) )
	{

		if( event.type == SDL_QUIT )
		{
			// Quit the program
			ctxt->quit = true;
		}

		if( event.type == SDL_KEYDOWN )
		{
			//Handle keypress with current mouse position
			int x = 0, y = 0;
			SDL_GetMouseState( &x, &y );
			printf("x: %d, y: %d\n", x, y);
			return event.key.keysym.unicode;
		}
	
	}
	return 0;
}