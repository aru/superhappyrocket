#ifndef SCENE_MANAGER
#define SCENE_MANAGER

#include "Context.h"
#include "SimpleObject.h"
#include "AudioManager.h"
#include "InputManager.h"
#include "OpenGLRenderer.h"
#include "Level.h"

class SceneManager {
public:
	SceneManager( Context* context );
	~SceneManager();

	int Load();
	int Update();
	int Unload();

	Context* ctxt;
	SimpleObject* object;
	GLBatch* batch;
	GLBatch* bgBatch;
	vector<Level> levels;

};

#endif