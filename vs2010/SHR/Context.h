#ifndef SHR_CONTEXT
#define SHR_CONTEXT

/* The Game Context class, where we store things that are relevant 
	to every object in the game, where the different managers are,
	how to access all of the stuff. Can be saved to a file and loaded
	for future support of many things, game saves, reloading, tab switching...

	Window configuration, video mode is also stored in here
*/

// Forward declare what we will use
class Context;
class AudioManager;
class InputManager;
class SceneManager;
class TextureManager;
class Renderer;
class Timer;
class Light;
class CameraManager;
class GLShaderManager;
class SimpleObject;
class AssimpManager;

#include <stdio.h>
#include <iostream>
#include <fstream>

#include "AudioManager.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "OpenGLRenderer.h"
#include "TextureManager.h"
#include "Timer.h"
#include "Light.h"
#include "CameraManager.h"
#include "AssimpManager.h"
#include <GLShaderManager.h>

/* Lazy getters for very crucial things */
#define shrCamera() ctxt->mCamera
#define shrLightArr() ctxt->renderer->lights

using namespace std;

class Context 
{
public:
	Context(char* file);
	Context();
	~Context();

	int LoadContext(char* file);
	int SaveContext(char* file);

	// Where are we?
	// currently these are hardcoded
	static const std::string basepath;

	bool quit;
	int width, height, bpp, vMode;
	int level;

	Renderer* renderer;
	AudioManager* audio;
	InputManager* input;
	TextureManager* textMgr;
	SceneManager* scene;
	GLShaderManager* mShader;
	Timer* timer;
	CameraManager* mCamera;
	AssimpManager* aManager;
};

#endif