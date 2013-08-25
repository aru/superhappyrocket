/**
 * InputManager.h
 *
 * This class is responsible for processing the user input such as keys
 * pressed or changes in the context.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details http://www.gnu.org/licenses/.
 */

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