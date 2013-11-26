/**
 * Context.h
 *
 * The Game Context class, where we store things that are relevant 
 * to every object in the game, where the different managers are,
 * how to access all of the stuff. Can be saved to a file and loaded
 * for future support of many things, game saves, reloading, tab switching, etc
 * Window configuration and video mode is also stored in here.
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

/* Forward Declarations of all classes */
class Context;
class AudioManager;
class InputManager;
class Renderer;
class Camera;
class SimpleObject;
class SceneManager;
class BaseLevel;
class Timer;
class Texture2D;
class TextureManager;
class Light;
class assimpMesh;
class Entity;
class EntityManager;
class Star;
class assimpMesh;

/* SHR Engine Includes */
#include "AudioManager.h"
#include "InputManager.h"
#include "OpenGLRenderer.h"
#include "Camera.h"
#include "SceneManager.h"
#include "BaseLevel.h"
#include "Timer.h"
#include "Texture2D.h"
#include "TextureManager.h"

/* GLTools Includes */
#include <GLShaderManager.h>

/* System Includes */
#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;

class Context
{
public:
	Context();
	~Context();

	/* Build a Context out of a text file */
	Context( char* file );

	/* Methods to load and save the context */
	int LoadContext(char* file);
	int SaveContext(char* file);

	/* Basepath of the game */
	static const string basepath;

	/* Global variables for an application */
	bool quit;
	int width, height, bpp, vMode;
	int level;

	/* Pointers to classes */
	AudioManager* audio;
	InputManager* input;
	Renderer* renderer;
	Camera*   camera;
	GLShaderManager* shaderManager;
	Timer* timer;
	SceneManager* sceneManager;
	TextureManager* textureManager;
};

/* All-purpose macros */
#define SHR_SUCCESS 0
#define SHR_FAIL    1

/* Enum for all of our levels */
enum GameLevels 
{
	MAIN_MENU,
	LEVEL1,
	LEVEL2,
	LEVEL3
};

#endif