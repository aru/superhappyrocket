#include "Context.h"
#include "SDL_app.h"

int main( int argc, char* args[] )
{
	// Load the context
	Context* context = new Context("D:\\Git\\Super-Happy-Rocket\\vs2010\\Debug\\Context.txt");
	// Start SDL_app
	SDL_app* game = new SDL_app(context);

	game->Startup();
	game->Loop();

	delete game;
	delete context;

	return 0;
}