#ifndef INPUT_MANAGER
#define INPUT_MANAGER

#include "SDL.h"
#include "Context.h"

class InputManager {
public:
	InputManager();
	InputManager( Context* context );
	~InputManager();
	Uint16 handleKeys();
	bool isKeyPressed( Uint16 key );

	Context* ctxt;
	SDL_Event event;
	bool keysHeld[SDLK_LAST];
};

#endif