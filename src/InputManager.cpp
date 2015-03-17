#include "InputManager.h"

InputManager::InputManager()
{
}

InputManager::~InputManager()
{
}

InputManager::InputManager( Context* context )
    :ctxt( context )
{
    int i;

    for( i = 0; i < SDL_NUM_SCANCODES; i++ )
    {
        keysHeld[i] = false;
    }
}

bool InputManager::isKeyPressed(Uint32 key){

    if( keysHeld[key] ){
        return true;
    }

    return false;
}

Uint32 InputManager::handleKeys()
{
    int x = 0, y = 0;

    while ( SDL_PollEvent ( &event ) )
    {
        switch(event.type)
        {
        case SDL_KEYDOWN:
            keysHeld[event.key.keysym.scancode] = true;
            //Handle keypress with current mouse position
            //SDL_GetMouseState( &x, &y );
            //printf("x: %d, y: %d\n", x, y);
            /*return event.key.keysym.unicode;*/
            break;

        case SDL_KEYUP:
            keysHeld[event.key.keysym.scancode] = false;
            //printf("lel\n");
            break;

        case SDL_QUIT:
            ctxt->quit = true;
        default:
            break;
        }
    }
    return 0;
}
