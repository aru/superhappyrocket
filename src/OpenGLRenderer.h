/**
 * OpenGLRenderer.h
 *
 * This class is the core of our system, it manages all OpenGL rendering.
 * Loads, draws, updates and shuts down our rendering context.
 * Manages the ASSIMP library, textures, light and shader support.
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

#ifndef SHR_OPENGLRENDERER
#define SHR_OPENGLRENDERER

#define NO_SDL_GLEXT
#define DEBUG

#include <stdio.h>
#include <vector>
#include <string>

/* SHR include Files */
#include "Context.h"
#include "Camera.h"
#include "SimpleObject.h"

/* GLTools include files */
#include "GLTools.h"
#include "GLFrame.h"

/* SDL Imports */

/* Assimp Imports */

using namespace std;

class Renderer{
public:
    /* Constructors */
    Renderer( Context* ctx );
    Renderer();
    ~Renderer();

    /* Standard Engine Methods */
    const int Initialize();
    const int LoadContent();
    const int Update( float delta );
    const int Draw();
    const int UnloadContent();

    /* Class Specific Methods */
    const int ChangeSize( int nWidth, int nHeight );

    /* Member variables */
    Context* ctxt;

    /* Array of pointers to structures that will be rendered */

    /* Camera Support, as a pointer in case we have more than one camera later */
    Camera* camera;

    /* Shader support */
    GLShaderManager shaderManager;

    /* Drawable Objects Array */
    vector<SimpleObject*> actors;
    /* Light Sources Array, for now just one */
    Light* light;
    //vector<SimpleObject*> lights;

    /* ARB_debug_output support */
    static void APIENTRY myErrorCallback( GLenum _source,
                                          GLenum _type, GLuint _id, GLenum _severity,
                                          GLsizei _length, const char* _message,
                                          void* _userParam );
    static GLuint unusedIds;
};

/* Useful Renderer Only Macros */

#endif
