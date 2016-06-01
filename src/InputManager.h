/**
 * InputManager.h
 *
 * This class is responsible for processing the user input such as keys
 * pressed or changes done to the current context.
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

#ifndef SHR_INPUTMANAGER
#define SHR_INPUTMANAGER

#include <SDL.h>
#include <map>

#include "Context.h"

class InputManager {
public:

    InputManager();
    InputManager( Context* context );
    ~InputManager();

    /* SDLK_LAST is dead in SDL2 because of Unicode support, good news and bad news
     * we now get to look for a specific KEY(CODE) in every possible keyboard layout, but
     * 'layout' keys have become SCANCODES, for now SCANCODES are the option since
     * we use keys depending on their position, not their actual value */
    bool keysHeld[ SDL_NUM_SCANCODES ];

    /* KEYCODES and SCANCODES are now 32-bits */
    bool isKeyPressed( Uint32 key );
    Uint32 handleKeys();

    /* Member variables */
    Context* ctxt;
    SDL_Event event;

};

#endif
