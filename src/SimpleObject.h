/**
 * SimpleObject.h
 *
 * A SimpleObject is a structure created to represent actors in our scene.
 * A SimpleObject is drawn via the stockShaders
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

#ifndef SHR_SIMPLEOBJECT
#define SHR_SIMPLEOBJECT

#include <vector>
#include <string>

#include <GLTools.h>
#include <GLFrame.h>
#include <GLMatrixStack.h>

#include "Context.h"

using namespace std;

class SimpleObject{
public:
    SimpleObject();
    SimpleObject( const SimpleObject& obj );
    virtual ~SimpleObject();

    virtual const int Initialize( Context* ctx );
    virtual const int LoadContent();
    virtual const int Draw();
    virtual const int Draw( Camera* camera, GLShaderManager* shaderManager, TextureManager* textureManager, Light* light );
    virtual const int Update();
    virtual const int UnloadContent();

    /* Member variables */
    bool tBatch; // Used to distinguish between kinds of batches
    GLBatch batch;
    GLTriangleBatch triBatch;
    GLFrame frame;
    GLMatrixStack modelViewMatrix;

    /* float arrays for our data */
    vector<float> vertex;
    vector<float> index;
    vector<float> normal;
    vector<float> texture;
    vector<float> color;

    /* Texture used to draw this object */
    GLuint textureFile;
    string tFile;

    /* Shader File associated to this particular object */
    GLuint shaderFile;
    string vShader, fShader;

    /* Matrix transforms for everything */
    M3DMatrix44f mScaleMatrix;
    M3DVector3f scaleVector;
};

#include "Light.h"
#include "CubeMap.h"
#include "ReflectedObject.h"
#include "assimpMesh.h"

#endif
