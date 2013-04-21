#include "Context.h"
#include "SDL_app.h"

int main( int argc, char* args[] )
{
	// Load the context
	Context* context;
	context = new Context("./../../vs2010/Context.txt");

	// Start SDL_app
	SDL_app* game;
	game = new SDL_app(context);

	// Start the game
	game->Startup();
	// Get to the main loop
	game->Loop();

	// Clean what we've done
	delete game;
	delete context;

	return 0;
}