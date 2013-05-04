#include "SDL_app.h"

SDL_app::SDL_app()
{
}

SDL_app::SDL_app( int w, int h, int b, int v)
	: width(w), height(h), bpp(b), vMode(v), wantRedisplay(0)
{
	if( vMode && SDL_OPENGL )
		Startup();
}

SDL_app::SDL_app( Context* context )
	:ctxt(context), width(context->width), height(context->height), 
		bpp(context->bpp), vMode(context->vMode), wantRedisplay(0)
{
}

SDL_app::~SDL_app(){
	Shutdown();
	//delete renderer;
	//delete audio;
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
	ctxt->renderer = new Renderer( ctxt );

	// Was this properly initialized? If not -> abort
	if( !ctxt->renderer )
		return 1;

	if( ctxt->renderer->Init() != 0 )
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
	ctxt->audio = new AudioManager( ctxt );

	// Start the input handler
	ctxt->input = new InputManager( ctxt );

	// Start the scene manager
	ctxt->scene = new SceneManager( ctxt );
	ctxt->scene->Load();

	return 0;
}

int SDL_app::Shutdown()
{
	// Quit SDL_ttf
	printf("Shutting down fonts\n");
	TTF_Quit();

	ctxt->audio->shutDown();

	//Quit SDL_mixer
	printf("Shuttind down audio\n");
    Mix_CloseAudio();

    //Quit SDL
    SDL_Quit();

	return 0;
}

int SDL_app::Update()
{
	ctxt->renderer->Draw();
	SDL_GL_SwapBuffers();
	// postRedisplay() here
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
		//this->eventDispatcher();
		ctxt->scene->Update();
		this->Update();
		ctxt->audio->playMusic();
	}
	return 0;
}

int SDL_app::resize( SDL_ResizeEvent* e )
{
	if (!(window = SDL_SetVideoMode(e->w, e->h,
	window->format->BitsPerPixel, window->flags)))
	{
		exit(EXIT_FAILURE); /* failed to resize. */
		return 1;
	}
	ctxt->renderer->changeSize(e->w, e->h);
	postRedisplay();
	return 0;
}

void SDL_app::eventDispatcher()
{
	SDL_Event e;
	while( SDL_PollEvent( &e ) )
	{
		switch(e.type)
		{
		case SDL_VIDEORESIZE: resize(&e.resize); break;
		case SDL_VIDEOEXPOSE: postRedisplay(); break;
		}
	}
}