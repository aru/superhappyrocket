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

#ifndef SHR_TEXTURE
#define SHR_TEXTURE

#include <string>

#include "Context.h"

class Texture2D;
#include "Texture2D.h"

class TextureManager
{
public:
	TextureManager();
	TextureManager( Context* context );
	~TextureManager();
	int addTexture(char* file);
	int addTexture(Texture2D* text);
	void changeTexture();
	void bindTexture( int text );
	void Init();
	void Init2();
	bool LoadTGATexture(const char *szFileName, GLenum minFilter, GLenum magFilter, GLenum wrapMode);
	bool LoadTGATexture(Texture2D* text);

	Context* ctxt;
	GLuint *textures;
	vector<char*> textureFiles;
	vector<Texture2D*> texts;
	int numTextures;

	GLbyte *pBytes;

};

#endif