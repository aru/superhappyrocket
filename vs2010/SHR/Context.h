#ifndef SHR_CONTEXT
#define SHR_CONTEXT

// Forward declare what we will use
class Context;
class AudioManager;
class InputManager;
class SceneManager;
class TextureManager;
class Renderer;

#include <stdio.h>
#include <iostream>
#include <fstream>

#include "AudioManager.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "OpenGLRenderer.h"
#include "TextureManager.h"

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
	TextureManager* textMgr;
	SceneManager* scene;

};

#endif