#include "InputManager.h"

InputManager::InputManager()
{
}

InputManager::InputManager( Context* context )
	:ctxt(context)
{
	for( int i = 0; i < SDLK_LAST; i++ )
	{
		keysHeld[i] = false;
	}
}

InputManager::~InputManager()
{
}

bool InputManager::isKeyPressed(Uint16 key){

	if( keysHeld[key] ){
		return true;
	}

	return false;
}

Uint16 InputManager::handleKeys()
{
	int x = 0, y = 0;

	while ( SDL_PollEvent ( &event ) )
    {
        switch(event.type){

			case SDL_KEYDOWN:
				keysHeld[event.key.keysym.sym] = true;

				//Handle keypress with current mouse position
				SDL_GetMouseState( &x, &y );
				printf("x: %d, y: %d\n", x, y);
				/*return event.key.keysym.unicode;*/
            break;
			
			case SDL_KEYUP:
				keysHeld[event.key.keysym.sym] = false;
				printf("lel\n");
            break;

			case SDL_QUIT:
				ctxt->quit = true;
			default:
				break;
		}
     }

	//while( SDL_PollEvent( &event ) )
	//{

	//	if( event.type == SDL_QUIT )
	//	{
	//		// Quit the program
	//		ctxt->quit = true;
	//	}

	//	switch( event.type )
	//	{

	//	case SDL_KEYDOWN:
	//			switch( event.key.keysym.sym )
	//			{
	//			case SDLK_UP:
	//				ctxt->renderer->cameraFrame->MoveForward(linear);
	//				break;
	//			case SDLK_DOWN:
	//				ctxt->renderer->cameraFrame->MoveForward(-linear);
	//				break;
	//			case SDLK_LEFT:
	//				ctxt->renderer->cameraFrame->RotateWorld(angular, 0.0f, 1.0f, 0.0f);
	//				break;
	//			case SDLK_RIGHT:
	//				ctxt->renderer->cameraFrame->RotateWorld(-angular, 0.0f, 1.0f, 0.0f);
	//					break;
	//			
	//			}
	//		break;
	//	case SDL_KEYUP:
	//		break;
	//	}
	//
	//}
	return 0;
}