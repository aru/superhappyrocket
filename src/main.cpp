#include "SDLApp.h"

int main( int argc, char* args[] )
{
    /* Load the config file and create a context out of it */
    Context* context;
    context = new Context("./../content/files/context.txt");

    /* Create an SDL App out of this context */
    SDLApp* game;
    game = new SDLApp( context );

    /* Initialize this SDL App */
    game->Initialize();

    /* Main game loop */
    while( context->quit == false )
    {
        /* Update the time */
        /* Handle Input */
        context->input->handleKeys();
        /* Draw the SDL App */
        game->Draw();
        /* Play Music */
        /* Do our postReDisplay */
    }

    /* Delete our 2 things */
    delete game;
    delete context;

    /* Return success */
    return 0;
}
