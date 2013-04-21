#include "SDL_app.h"

SDL_app::SDL_app()
{
}

SDL_app::SDL_app( int w, int h, int b, int v)
	: width(w), height(h), bpp(b), vMode(v)
{
	if( vMode && SDL_OPENGL )
		Startup();
}

SDL_app::SDL_app( Context* context )
	:ctxt(context), width(context->width), height(context->height), 
		bpp(context->bpp), vMode(context->vMode)
{
}

SDL_app::~SDL_app(){
	Shutdown();
	delete renderer;
	delete audio;
}

int SDL_app::Startup()
{

	// Prove that we want opengl
	if( !(ctxt->vMode && SDL_OPENGL) )
		return 1;

	//Start SDL
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
	{
		printf("Init failed\n");
		return 1;
	}
    
	//Initialize SDL_ttf
    if( TTF_Init() == -1 )
    {
		printf("Font failed\n");
        return 1;    
    }

	//Initialize SDL_mixer
    if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 )
    {
		printf("Audio failed");
        return 1;    
    }

	/* Set values necessary for an OpenGL Context */
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE,        8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE,      8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE,       8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE,      8);
 
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE,      16);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE,        32);
 
	SDL_GL_SetAttribute(SDL_GL_ACCUM_RED_SIZE,    8);
	SDL_GL_SetAttribute(SDL_GL_ACCUM_GREEN_SIZE,    8);
	SDL_GL_SetAttribute(SDL_GL_ACCUM_BLUE_SIZE,    8);
	SDL_GL_SetAttribute(SDL_GL_ACCUM_ALPHA_SIZE,    8);
 
	//SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS,  1);
	//SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES,  2);

	/* Create an OpenGL screen */
	if ( SDL_SetVideoMode(width, height, bpp, vMode ) == NULL ) {
		fprintf(stderr, "Unable to create OpenGL screen: %s\n", SDL_GetError());
		Shutdown();
		return 1;
	}

	//Enable unicode
    SDL_EnableUNICODE( SDL_TRUE );

	//Initialize OpenGL
	renderer = new Renderer();
	if( renderer->Init() != 0 )
	{
		printf("OpenGL Failed somehow\n");
	}

	/* Set the title bar in environments that support it */
	SDL_WM_SetCaption("Thesis!", NULL);

	// Get out window handle
	window = NULL;

	// Load the window
	window = SDL_GetVideoSurface();

	// Start the audio
	audio = new AudioManager();
	audio->loadMusic( "../../content/sounds/shr_gp_music_0.wav" );

	// Start the input handler
	input = new InputManager( ctxt );

	// Start the scene manager
	scene = new SceneManager( ctxt, renderer, input, audio );
	scene->Load();

	return 0;
}

int SDL_app::Shutdown()
{
	// Quit SDL_ttf
	printf("Shutting down fonts\n");
	TTF_Quit();

	// Free the music
    // Mix_FreeMusic();
	//Quit SDL_mixer
	printf("Shuttind down audio\n");
    Mix_CloseAudio();

    //Quit SDL
    SDL_Quit();

	return 0;
}

int SDL_app::Update()
{
	renderer->Draw();
	SDL_GL_SwapBuffers();
	return 0;
}

int SDL_app::Draw()
{
	return 0;
}

int SDL_app::Loop()
{

	while( ctxt->quit == false )
	{
		this->Update();
		scene->Update();
		audio->playMusic();
	}
	return 0;
}