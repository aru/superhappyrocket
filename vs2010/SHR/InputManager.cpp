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
	float linear = 0.1f;
	float angular = float(m3dDegToRad(5.0f));

	while( SDL_PollEvent( &event ) )
	{

		if( event.type == SDL_QUIT )
		{
			// Quit the program
			ctxt->quit = true;
		}

		if( event.type == SDL_KEYDOWN )
		{
			switch( event.key.keysym.sym )
			{
			case SDLK_UP:
				ctxt->renderer->cameraFrame->MoveForward(linear);
				break;
			case SDLK_DOWN:
				ctxt->renderer->cameraFrame->MoveForward(-linear);
				break;
			case SDLK_LEFT:
				ctxt->renderer->cameraFrame->RotateWorld(angular, 0.0f, 1.0f, 0.0f);
				break;
			case SDLK_RIGHT:
				ctxt->renderer->cameraFrame->RotateWorld(-angular, 0.0f, 1.0f, 0.0f);
					break;
			default:
				//Handle keypress with current mouse position
				int x = 0, y = 0;
				SDL_GetMouseState( &x, &y );
				printf("x: %d, y: %d\n", x, y);
				return event.key.keysym.unicode;
				break;
			}
		}
	
	}
	return 0;
}