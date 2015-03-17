/**
 * BaseLevel.h
 *
 * Content is loaded depending of each level, after being loaded the
 * content is drawn, updated, and unloaded after being used.
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

#ifndef SHR_BASELEVEL
#define SHR_BASELEVEL

#include <vector>
using namespace std;

#include "Context.h"

class BaseLevel
{
public:
    BaseLevel( Context* ctx );
    virtual ~BaseLevel();
    virtual const int Initialize();
    virtual const int LoadContent() = 0;
    virtual const int Draw();
    virtual const int Update( Uint32 gameTime );
    virtual const int UnloadContent();

    Context* ctxt;
    /* An array for all of our sounds */
    char* song; // A level should only have one song, for now
    vector<char*> sounds; // Different sounds across the level
    vector<SimpleObject*> actors; // Objects in the level
    vector<Texture2D*> textures; // Textures in the level
    Light* lightSource; // Light Source in the level

    /* Timing support */
    Timer* clock;
    Uint32 startTicks;   /* Time when level was started */
    Uint32 currentTicks; /* Difference between start and sdl_getticks */
    Uint32 deltaTicks;   /* place to save ticks passed since last time */
};

/* Include additional levels */
#include "Level1.h"

#endif
