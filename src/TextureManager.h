/**
 * TextureManager.h
 *
 * Responsible for loading and initializing the 2D textures.
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

#ifndef SHR_TEXTUREMANAGER
#define SHR_TEXTUREMANAGER

#include <string>

#include "Context.h"
#include "Texture2D.h"

class TextureManager
{
public:
    TextureManager( Context* ctx );
    ~TextureManager();

    /* Standard engine methods */
    const int Initialize();
    const int LoadContent();
    const int UnloadContent();

    /* Helper Methods */
    const int bindTexture( int text );
    const bool LoadTGATexture(const char *szFileName, GLenum minFilter, GLenum magFilter, GLenum wrapMode);
    const bool LoadTGATexture(Texture2D* text);

    /* Member specific methods */
    const int addTexture( string file );
    const int addTexture( char* file );
    const int addTexture( Texture2D* text );

    /* Member variables */
    Context* ctxt;
    GLuint *textures;
    vector<char*> textureFiles;
    vector<Texture2D*> texts;
    int numTextures;

    GLbyte *pBytes;
};

#endif
