#ifndef SDL_APP
#define SDL_APP

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "SDL_net.h"
#include "SDL_mixer.h"
#include "SDL_opengl.h"

#include "OpenGLRenderer.h"

#include <stdio.h>

class SDL{
	SDL();
	SDL( int w, int h, int b, int v );
	~SDL();

	int startup();
	int load();
	int update();
	int draw();
	int unload();
	int shutdown();

	int width;
	int height;
	int bpp;
	int vMode;

	Renderer* renderer;
};

#endif