#ifndef SCENE_MANAGER
#define SCENE_MANAGER

#include "Context.h"
#include "SimpleObject.h"
#include "AudioManager.h"
#include "InputManager.h"
#include "OpenGLRenderer.h"

class SceneManager {
public:
	SceneManager( Context* context, Renderer* render, 
				  InputManager* in, AudioManager* aud );
	~SceneManager();

	int Load();
	int Update();
	int Unload();

	Context* ctxt;
	Renderer* renderer;
	InputManager* input;
	AudioManager* audio;
	SimpleObject* object;
	GLBatch* batch;

};

#endif