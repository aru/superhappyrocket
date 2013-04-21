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

	Context* ctxt;
	SDL_Event event;
};

#endif