/**
 * Texture2D.h
 *
 * Structure containing the data of a 2D texture.
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

#ifndef SHR_TEXTURE2D
#define SHR_TEXTURE2D

#include "Context.h"
#include <string>

class Texture2D
{
public:
    Texture2D();
    Texture2D(const Texture2D &txt);
    Texture2D(const char* f, GLenum min, GLenum mag, GLenum wrap);
    Texture2D(string* str, GLenum min, GLenum mag, GLenum wrap);
    Texture2D(string str, GLenum min, GLenum mag, GLenum wrap);
    ~Texture2D();

    const char*         file;
    string              textureString;
    unsigned int	textureFile;
    GLenum		minFilter;
    GLenum		magFilter;
    GLenum		wrapMode;
};

#endif
