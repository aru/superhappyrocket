/**
 * SceneManager.h
 *
 * The scene manager is responsible of loading, updating and unloading
 * the content of the currently selected level.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details http://www.gnu.org/licenses/.
 */

#ifndef SCENE_MANAGER
#define SCENE_MANAGER

#include "Context.h"
#include "SimpleObject.h"
#include "AudioManager.h"
#include "InputManager.h"
#include "OpenGLRenderer.h"
#include "TextureManager.h"
//#include "ShadedObject.h"

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
	vector<Level> levels;

	// Camera Support
	static CStopWatch    *rotTimer;
	GLFrame              *cameraFrame;
	M3DMatrix44f         *mCamera;
	GLMatrixStack		 *modelViewMatrix;		// Modelview Matrix
	GLMatrixStack		 *projectionMatrix;		// Projection Matrix
	GLFrustum			 *viewFrustum;			// View Frustum
	GLGeometryTransform	 *transformPipeline;	// Geometry Transform Pipeline

};

#endif