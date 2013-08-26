/**
 * Level.h
 *
 * Content is loaded depending of each level, after being loaded the
 * content is drawed, updated, and unloaded after being used.
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

#ifndef SHR_LEVEL
#define SHR_LEVEL

class Level;
#include "SceneManager.h"
#include "Texture2D.h"
#include "Timer.h"

class Level
{
public:
	Level();
	~Level();
	// Declare and load every asset in this part
	void LoadContent();
	// Set the initial values of things
	void Draw( int GameTimeElapsed );
	// Update the values of everything in the level
	void Update( int GameTimeElapsed );
	// Unload every asset in this part just to be safe
	void UnloadContent();

	vector<char*> songs;
	vector<char*> textures;
	vector<Texture2D*> texts;
	vector<SimpleObject*> objects;
	vector<SimpleObject*> actors;
	vector<GLBatch*> batches;
	vector<Light*> lights;

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