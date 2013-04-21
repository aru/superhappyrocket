#ifndef SHR_CONTEXT
#define SHR_CONTEXT

#include <stdio.h>
#include <iostream>
#include <fstream>

// Forward declare what we will use
class Context;
class AudioManager;
class InputManager;
class SceneManager;
class OpenGLRenderer;

#include "AudioManager.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "OpenGLRenderer.h"

using namespace std;

class Context 
{
public:
	Context(char* file);
	Context();
	~Context();

	int LoadContext(char* file);
	int SaveContext(char* file);

	bool quit;
	int width, height, bpp, vMode;
	int level;

	Renderer* renderer;
	AudioManager* audio;
	InputManager* input;
	SceneManager* scene;

};

#endif