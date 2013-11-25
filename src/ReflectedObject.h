/**
 * ReflectedObject.h
 *
 * The ReflectedObject class is used to generate a reflected image of 
 * the object we load, in this case we create a reflection of the world 
 * to use in objects that have a reflection property. 
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

#ifndef SHR_REFLECTEDOBJECT
#define SHR_REFLECTEDOBJECT

#include "Context.h"
#include "SimpleObject.h"

class ReflectedObject : public SimpleObject
{
public:
	ReflectedObject( const char* upperTexture, GLint reflectedText );
	~ReflectedObject();

	/* Standard member methods */
	const int Initialize( Context* ctx );
	const int LoadContent();
	const int Draw( Camera* camera, GLShaderManager* shaderManager, TextureManager* textureManager, Light* light );
	const int UnloadContent();

	/* Standard member context pointer */
	Context* ctxt;

	/* Variables needed to Load Content */
	GLbyte	*pBytes;
    GLint	iWidth, iHeight, iComponents;
    GLenum	eFormat;
	GLint	locMVPReflect, locMVReflect, locNormalReflect, locInvertedCamera;
	GLint	locTarnishMap;

	/* Object that we will be reflecting */
	GLint	locCubeMap;
	GLuint  reflectedTexture;

};

#endif