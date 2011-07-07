#ifdef WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#endif
#if defined(__APPLE__) && defined(__MACH__)
#include <OpenGL/gl.h>	// Header File For The OpenGL32 Library
#include <OpenGL/glu.h>	// Header File For The GLu32 Library
#else
#include <GL/gl.h>	// Header File For The OpenGL32 Library
#include <GL/glu.h>	// Header File For The GLu32 Library
#endif
#include <iostream>
#include "SDL.h"

/* A  general OpenGL initialization function.  Sets all of the initial parameters. */
void InitGL(int Width, int Height)	        // We call this right after our OpenGL window is created.
{
	// General suggested outline
	// mcamera->setFrustum()
	// mcamera->setFrame( camPosition, camDVector, camUVector, camRVector );
	
	// CreateScene();
	
	// Set up the camera
	// Initial update of objects
	// scene->update();
	// Initial culling of scene.
	
	glViewport(0, 0, Width, Height);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);	// This Will Clear The Background Color To Black
	glClearDepth(1.0);						// Enables Clearing Of The Depth Buffer
	glDepthFunc(GL_LESS);					// The Type Of Depth Test To Do
	glEnable(GL_DEPTH_TEST);				// Enables Depth Testing
	glShadeModel(GL_SMOOTH);				// Enables Smooth Color Shading
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();						// Reset The Projection Matrix
	
	gluPerspective(45.0f,(GLfloat)Width/(GLfloat)Height,0.1f,100.0f);	// Calculate The Aspect Ratio Of The Window
	
	glMatrixMode(GL_MODELVIEW);
}

/* The main drawing function. */
void DrawGLScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		// Clear The Screen And The Depth Buffer
	glLoadIdentity();				// Reset The View
	
	glTranslatef(-1.5f,0.0f,-6.0f);		// Move Left 1.5 Units And Into The Screen 6.0
	
	// draw a triangle
	glBegin(GL_POLYGON);				// start drawing a polygon
	glVertex3f( 0.0f, 1.0f, 0.0f);		// Top
	glVertex3f( 1.0f,-1.0f, 0.0f);		// Bottom Right
	glVertex3f(-1.0f,-1.0f, 0.0f);		// Bottom Left	
	glEnd();					// we're done with the polygon
	
	glTranslatef(3.0f,0.0f,0.0f);		        // Move Right 3 Units
	
	// draw a square (quadrilateral)
	glBegin(GL_QUADS);				// start drawing a polygon (4 sided)
	glVertex3f(-1.0f, 1.0f, 0.0f);		// Top Left
	glVertex3f( 1.0f, 1.0f, 0.0f);		// Top Right
	glVertex3f( 1.0f,-1.0f, 0.0f);		// Bottom Right
	glVertex3f(-1.0f,-1.0f, 0.0f);		// Bottom Left	
	glEnd();					// done with the polygon
	
	// swap buffers to display, since we're double buffered.
	SDL_GL_SwapBuffers();
}

/*Getting modifier keys*/
void DisplayModifiers(SDL_KeyboardEvent *key)
{
	SDLMod modifier = key->keysym.mod;
	if( modifier & KMOD_NUM ) std::cout << "NUMLOCK" << std::endl;
	if( modifier & KMOD_CAPS ) std::cout << "CAPSLOCK" << std::endl;
	if( modifier & KMOD_MODE ) std::cout << "MODE" << std::endl;
	if( modifier & KMOD_LCTRL ) std::cout << "LCTRLn" << std::endl;
	if( modifier & KMOD_RCTRL ) std::cout << "RCTRL" << std::endl;
	if( modifier & KMOD_LSHIFT ) std::cout << "LSHIFT" << std::endl;
	if( modifier & KMOD_RSHIFT ) std::cout << "RSHIFT" << std::endl;
	if( modifier & KMOD_LALT ) std::cout << "LALT" << std::endl;
	if( modifier & KMOD_RALT ) std::cout << "RALT" << std::endl;
	if( modifier & KMOD_LMETA ) std::cout << "LMETA" << std::endl;
	if( modifier & KMOD_RMETA ) std::cout << "RMETA" << std::endl;
}

/* Just displaying the key name*/
void DisplayKey(SDL_KeyboardEvent *key)
{
	std::cout << SDL_GetKeyName(key->keysym.sym) << std::endl;
}

/*Keyboard key state*/
void DisplayState(SDL_KeyboardEvent *key)
{
	if (key->type == SDL_KEYUP)
		std::cout << "RELEASED: " << std::endl;
	else
		std::cout << "PRESSED: " << std::endl;
	
}

int main(int argc, char **argv) 
{  
	int done;
	
	/* Initialize SDL for video output */
	if ( SDL_Init(SDL_INIT_VIDEO) < 0 ) {
		fprintf(stderr, "Unable to initialize SDL: %s\n", SDL_GetError());
		exit(1);
	}
	
	/* Create a 640x480 OpenGL screen */
	if ( SDL_SetVideoMode(640, 480, 0, SDL_OPENGL) == NULL ) {
		fprintf(stderr, "Unable to create OpenGL screen: %s\n", SDL_GetError());
		SDL_Quit();
		exit(2);
	}
	
	/* Set the title bar in environments that support it */
	SDL_WM_SetCaption("Jeff Molofee's GL Code Tutorial ... NeHe '99", NULL);
	
	/* Loop, drawing and checking events */
	InitGL(640, 480);
	done = 0;
	while ( ! done ) {
		DrawGLScene();
		
		{ SDL_Event event;
			while ( SDL_PollEvent(&event) ) {

				/*Suppa basic event catcher*/
				switch (event.type) {
					case SDL_KEYDOWN:
					case SDL_KEYUP:
						DisplayState(&event.key);
						DisplayModifiers(&event.key);
						DisplayKey(&event.key);
						break;
					case SDL_QUIT:
						done = 1;
				}
				
				
			}
		}
	}
	SDL_Quit();
	return 1;
}

