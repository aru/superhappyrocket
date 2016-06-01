/**
 * assimpMesh.h
 *
 * Loads and processes the meshes and textures associated with them.
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

#ifndef SHR_ASSIMPMESH
#define SHR_ASSIMPMESH

/* SHR import */
#include "Context.h"
#include "SimpleObject.h"
#include "Texture2D.h"

/* Assimp imports */
#include <assimp/cimport.h>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

/* std imports */
#include <vector>
#include <string>

using namespace std;

class assimpMesh : public SimpleObject
{
public:
    assimpMesh( const char* filename, Context* ctx );
    assimpMesh( const assimpMesh& mesh );
    ~assimpMesh();

    /* Standard Object Methods */
    const int Initialize( Context* ctx );
    const int LoadContent();
    const int Draw( Camera* camera, GLShaderManager* shaderManager, TextureManager* textureManager, Light* light );
    const int Update();
    const int UnloadContent();

    /* Member specific methods */
    void recursiveProcess( aiNode* node, const aiScene* scene );
    void processMesh( aiMesh* mesh, const aiScene* scene );
    void createBatches();

    /* Member variables */
    Context *ctxt;
    string fileName;
    /* SimpleObjects owned by this mesh */
    vector<SimpleObject*> objects;
    /* Our loading algorithm requires us to traverse the scene graph from a model
     * while collecting all of the necessary data, at the end of our traversal, we
     * batch all the data into triangleBatches and erase our temporary arrays */
    vector< vector<GLfloat> >  verts;
    vector< vector<GLfloat> >  norms;
    vector< vector<GLfloat> >  texts;
    vector< vector<GLushort> > indexes;
    vector<GLushort> maxIndex; // This is to keep track of the max index value in an array
    /* We also need to keep track of all the textures used by the different batches */
    vector<GLuint> textures;
    vector<Texture2D*> textureStruct;
    unsigned int numTextures;
    bool untexturedVerts;
};

#endif
