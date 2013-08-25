/**
 * Context.h
 *
 * The Game Context class, where we store things that are relevant 
 * to every object in the game, where the different managers are,
 * how to access all of the stuff. Can be saved to a file and loaded
 * for future support of many things, game saves, reloading, tab switching...
 * Window configuration, video mode is also stored in here
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

#ifndef SHR_CONTEXT
#define SHR_CONTEXT


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
// Better assimp support
class assimpMeshLoader;
class assimpMesh;
// Final assimp support
class shrMesh;
class shrMeshLoader;

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
#include "assimpMeshLoader.h"
#include "shrMeshLoader.h"
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
	// final assimp support
	shrMeshLoader* mLoader;
};

#endif