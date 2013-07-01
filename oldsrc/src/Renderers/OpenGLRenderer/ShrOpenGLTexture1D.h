// Geometric Tools, LLC
// Copyright (c) 1998-2012
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 5.0.1 (2011/07/09)

#ifndef SHROPENGLTEXTURE1D_H
#define SHROPENGLTEXTURE1D_H

#include "ShrOpenGLRendererLIB.h"
#include "ShrTexture1D.h"

namespace shr
{

class Renderer;

class PdrTexture1D
{
public:
    // Construction and destruction.
    PdrTexture1D (Renderer* renderer, const Texture1D* texture);
    ~PdrTexture1D ();

    // Texture operations.
    void Enable (Renderer* renderer, int textureUnit);
    void Disable (Renderer* renderer, int textureUnit);
    void* Lock (int level, Buffer::Locking mode);
    void Unlock (int level);

private:
    GLuint mTexture, mInternalFormat, mFormat, mType, mPreviousTexture;
    GLint mNumLevels;
    GLint mNumLevelBytes[Texture::MM_MAX_MIPMAP_LEVELS];
    GLint mDimension[Texture::MM_MAX_MIPMAP_LEVELS];
    GLuint mBuffer[Texture::MM_MAX_MIPMAP_LEVELS];
    void* mLockedMemory[Texture::MM_MAX_MIPMAP_LEVELS];
    bool mWriteLock[Texture::MM_MAX_MIPMAP_LEVELS];
};

}

#endif
