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