/**
 * AssimpManager.h
 *
 * ASSIMP manager class that holds data on every model on the scene
 * In charge of loading and passing info to the renderer to render 3d models.
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

#ifndef SHR_ASSIMPMGR
#define SHR_ASSIMPMGR

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

#include <map>
#include <string>

using namespace std;

class AssimpManager {
public:
	AssimpManager();
	AssimpManager( Context *ctxt );
	~AssimpManager();

	void createAILogger();
	void destroyAILogger();
	void logInfo( std::string logString );
	void logDebug( const char* logString );
	bool Import3DFromFile( const std::string& pFile );
	void Color4f(const aiColor4D *color);
	void set_float4(float f[4], float a, float b, float c, float d);
	void color4_to_float4(const aiColor4D *c, float f[4]);
	void apply_material(const aiMaterial *mtl);
	void recursive_render(const struct aiScene *sc, const struct aiNode* nd, float scale);
	void drawAiScene(const aiScene* scene);

	// the global Assimp scene object
	const aiScene* scene;
	// number of scenes?
	GLuint scene_list;
	// vectors used for the scene?
	aiVector3D scene_min, scene_max, scene_center;

	// images / texture
	// map image filenames to textureIds
	std::map<std::string, GLuint*> textureIdMap;
	// pointer to texture Array
	GLuint*		textureIds;
	// Create an instance of the Importer class
	Assimp::Importer importer;
	// Pointer to the context
	Context *ctx;
};

#endif