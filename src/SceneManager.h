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

#ifndef SHR_SCENEMANAGER
#define SHR_SCENEMANAGER

#include "Context.h"
#include "SimpleObject.h"

#include <vector>

class SceneManager {
public:
	SceneManager( Context* ctx );
	~SceneManager();

	const int Initialize();
	const int LoadContent( const unsigned int level );
	const int Draw();
	const int Update( Uint32 gameTime );
	const int UnloadContent();

	Context* ctxt;
	int currentLevel;
	vector<BaseLevel*> levels;
};

#endif