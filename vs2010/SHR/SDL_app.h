/**
 * SDL_app.h
 *
 * This class is responsible of giving support to the SDL library,
 * initializes, updates and shuts down the application window depending 
 * on the selected context.
 * Manages events related to the window.
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

#ifndef SDL_APP
#define SDL_APP

#define _WINSOCKAPI_
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "SDL_net.h"
#include "SDL_mixer.h"

#include "Context.h"

#include <stdio.h>

class SDL_app{
public:
	SDL_app();
	SDL_app( int w, int h, int b, int v );
	SDL_app( Context* context );
	~SDL_app();

	int Startup();
	int Load();
	int Loop();
	int Update();
	int Draw();
	int Unload();
	int Shutdown();


	int resize(SDL_ResizeEvent* e);
	void eventDispatcher();
	int wantRedisplay;
	void postRedisplay() { wantRedisplay = 0; };

	int width;
	int height;
	int bpp;
	int vMode;

	Context* ctxt;
	SDL_Surface* window;
	SDL_Event event;

};

#endif