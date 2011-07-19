#include "GlExtensions.h"
#include <iostream>
#include "EventHandler.h"
#include "AudioHandler.h"

// Array containing the six vertices of the cube
	static GLfloat corners[] = { -25.0f, 25.0f, 25.0f, // 0 // Front of cube
								  25.0f, 25.0f, 25.0f, // 1
								  25.0f, -25.0f, 25.0f,// 2
								 -25.0f, -25.0f, 25.0f,// 3
								 -25.0f, 25.0f, -25.0f,// 4  // Back of cube
								  25.0f, 25.0f, -25.0f,// 5
								  25.0f, -25.0f, -25.0f,// 6
								 -25.0f, -25.0f, -25.0f };// 7

	// Array of indexes to create the cube
	static GLubyte indexes[] = { 0, 1, 2, 3,     // Front Face
								 4, 5, 1, 0,     // Top Face
								 3, 2, 6, 7,     // Bottom Face
								 5, 4, 7, 6,     // Back Face
								 1, 5, 6, 2,     // Right Face
								 4, 0, 3, 7 };   // Left Face

	// Rotation amounts
	static GLfloat xRot = 0.0f;
	static GLfloat yRot = 0.0f;

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
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);	// This Will Clear The Background Color To Black
	//glClearDepth(1.0);						// Enables Clearing Of The Depth Buffer
	//glDepthFunc(GL_LESS);					// The Type Of Depth Test To Do
	//glEnable(GL_DEPTH_TEST);				// Enables Depth Testing
	//glShadeModel(GL_SMOOTH);				// Enables Smooth Color Shading
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();						// Reset The Projection Matrix
	
	gluPerspective(35.0f,(GLfloat)Width/(GLfloat)Height,0.1f,1000.0f);	// Calculate The Aspect Ratio Of The Window
	
	glMatrixMode(GL_MODELVIEW);

	glColor3ub(0,0,0);
}

/* The main drawing function. */
void DrawGLScene()
{
    // Clear the window with current clearing color
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    // Make the cube wireframe
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    // Save the matrix state
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, -200.0f);

    // Rotate about x and y axes
    //glRotatef(xRot, 1.0f, 0.0f, 0.0f);
    //glRotatef(yRot, 0.0f, 0.0f, 1.0f);

    // Enable and specify the vertex array
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, corners);

    // Using Drawelements
    glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE, indexes);

	// Disable vertex array
	glDisableClientState(GL_VERTEX_ARRAY);

    glPopMatrix();
	
	// swap buffers to display, since we're double buffered.
	SDL_GL_SwapBuffers();
}

int main(int argc, char **argv) 
{  
	int done;
	EventHandler myEventHandler;	// Event Handler
	AudioHandler myAudioHandler;
	
	/* Initialize SDL for video output */
	if ( SDL_Init(SDL_INIT_VIDEO) < 0 ) {
		fprintf(stderr, "Unable to initialize SDL: %s\n", SDL_GetError());
		exit(1);
	}
	
	/* Create a 800x600 OpenGL screen */
	if ( SDL_SetVideoMode(800, 600, 0, SDL_OPENGL) == NULL ) {
		fprintf(stderr, "Unable to create OpenGL screen: %s\n", SDL_GetError());
		SDL_Quit();
		exit(2);
	}
	
	/* Set the title bar in environments that support it */
	SDL_WM_SetCaption("Jeff Molofee's GL Code Tutorial ... NeHe '99", NULL);
	
	/* Loop, drawing and checking events */
	InitGL(800, 600);
	done = 0;
	while ( done != 1 ) {
		// Event catching goes first to prioritize input over drawing as in God of War :3
		done = myEventHandler.Catch();
		if(done > 1){
			/*Replace OTHER_SOUND with any clasification from the enum in SoundHandler.h
			 see diagram of keys, in order to test this stuff.
			 1 | 2 | 3 | 4 | 5		--> Play sound 
			 Q | W | E | R | T		--> Stop Sound
			 A | S | D | F | G		--> Pause Sound
			 Z | X | C | V | B		--> Resume Sound
			 */
			if(done >= 10 && done <20)
				myAudioHandler.stopSound(done - 10,MUSIC_GAMEPLAY_SOUND);
			else if(done >= 20 && done < 30)
				myAudioHandler.pauseSound(done-20,MUSIC_GAMEPLAY_SOUND);
			else if(done >= 30)
				myAudioHandler.resumeSound(done-30,MUSIC_GAMEPLAY_SOUND);
			else
				myAudioHandler.playSound(done - 2,MUSIC_GAMEPLAY_SOUND);
		}
		/*Use done to your desired KB behaviour*/
		/*Use internal EventHandler attributes to get mouse stuff*/
		DrawGLScene();
	}
	myAudioHandler.closeAudio();
	SDL_Quit();
	return 1;
}

