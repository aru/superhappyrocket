/**
 * shrModel.h
 *
 * For a 3DModel we want to be able to Load, Draw and update models
 * as easily as possible.
 * Cleans everything ASSIMP does Destroy();
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

#ifndef SHR_SHRMODEL
#define SHR_SHRMODEL

// Our engine support
#include "Context.h"

// Assimp support
#include "assimp/Importer.hpp"
#include "assimp/cimport.h"
// assimp include files. These three are usually needed.
#include "assimp/PostProcess.h"
#include "assimp/Scene.h"
#include "assimp/DefaultLogger.hpp"
#include "assimp/LogStream.hpp"

using namespace std;

class shrModel 
{
public:
	shrModel();
	shrModel( string fileName );
	~shrModel();

	// Load
	int Load();
	// Draw
	int Draw();
	// Update
	int Update();
	// Destroy
	int Destroy();

	string fileName;
};

#endif