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
    while ( SDL_PollEvent ( &event ) )
    {
        switch(event.type)
        {
        case SDL_KEYDOWN:
            keysHeld[event.key.keysym.scancode] = true;
            break;

        case SDL_KEYUP:
            keysHeld[event.key.keysym.scancode] = false;
            break;

        case SDL_QUIT:
            ctxt->quit = true;
        default:
            break;
        }
    }
    return 0;
}
