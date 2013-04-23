#ifndef SCENE_MANAGER
#define SCENE_MANAGER

#include "Context.h"
#include "SimpleObject.h"
#include "AudioManager.h"
#include "InputManager.h"
#include "OpenGLRenderer.h"

// Camera support etc
#include "GLShaderManager.h"
#include <GLFrustum.h>
#include <GLBatch.h>
#include <GLFrame.h>
#include <GLMatrixStack.h>
#include <GLGeometryTransform.h>
#include <StopWatch.h>

#include "Level.h"

class SceneManager {
public:
	SceneManager( Context* context );
	~SceneManager();

	int Load();
	int Update();
	int Unload();

	Context* ctxt;
	//GLBatch* rocketBatch;
	//GLBatch* bgBatch;
	vector<Level> levels;

	// Camera Support
	static CStopWatch    *rotTimer;
	GLFrame              *cameraFrame;
	M3DMatrix44f         *mCamera;
	GLMatrixStack		 *modelViewMatrix;		// Modelview Matrix
	GLMatrixStack		 *projectionMatrix;		// Projection Matrix
	GLFrustum			 *viewFrustum;			// View Frustum
	GLGeometryTransform	 *transformPipeline;		// Geometry Transform Pipeline

};

#endif