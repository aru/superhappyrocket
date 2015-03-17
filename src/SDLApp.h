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

#ifndef SHR_SDLAPP
#define SHR_SDLAPP

#include <SDL.h>
#include <SDL_thread.h>
#include <stdio.h>

#include "Context.h"

using namespace std;

/* Debugging macro */
#define DEBUG

class SDLApp
{
public:
    SDLApp();
    ~SDLApp();
    SDLApp( Context* context );

    int Initialize();
    int LoadContent();
    int Update();
    int Draw();
    int UnloadContent();
    //int Shutdown();

    Context* ctxt;

    //The window we'll be rendering to
    SDL_Window* window;

    //OpenGL context
    SDL_GLContext gContext;

    /* Window parameters */
    int width;
    int height;
    int bpp;
    int vMode;
    int wantRedisplay;
    void postRedisplay() { wantRedisplay = 0; };
};

#endif
