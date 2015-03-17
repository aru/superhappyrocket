/**
 * CubeMap.h
 *
 * The CubeMap class is used to create a cubemap or skybox to simulate
 * the world's sky, it generates the cubemap from 6 different texture files
 * each one representing the X, Y and Z positive and negative sides.

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

#ifndef SHR_CUBEMAP
#define SHR_CUBEMAP

#include "Context.h"
#include "SimpleObject.h"

class CubeMap : public SimpleObject
{

public:

    CubeMap();
    CubeMap( GLfloat size,
             const char* f1, const char* f2, const char* f3,
             const char* f4, const char* f5, const char* f6 );
    ~CubeMap();

    const int Initialize( Context* ctx );
    const int LoadContent();
    const int Draw( Camera* camera, GLShaderManager* shaderManager, TextureManager* textureManager, Light* light );
    const int UnloadContent();

    /* Standard member context pointer */
    Context* ctxt;

    /* Specific values for the cubemap */
    GLfloat cubeMapSize;
    const char* szCubeFaces[6];
    GLenum cube[6];

    /* Variables needed to Load Content */
    GLbyte *pBytes;
    GLint iWidth, iHeight, iComponents;
    GLenum eFormat;
    GLint locMVPSkyBox, locCubeMap;

};

#endif
