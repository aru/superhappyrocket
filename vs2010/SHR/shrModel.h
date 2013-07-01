#ifndef SHR_SHRMODEL
#define SHR_SHRMODEL

/* For a 3DModel we want to be able to:
 * Load/Draw/Load as easily as possible: Load(miku.3ds)
 * Clean everything ASSIMP does Destroy();
 */

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