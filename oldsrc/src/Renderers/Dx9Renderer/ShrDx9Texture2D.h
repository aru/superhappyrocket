// Geometric Tools, LLC
// Copyright (c) 1998-2012
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 5.0.0 (2010/01/01)

#ifndef SHRDX9TEXTURE2D_H
#define SHRDX9TEXTURE2D_H

#include "ShrDx9RendererLIB.h"
#include "ShrTexture2D.h"
#include "ShrMemory.h"

namespace shr
{

class Renderer;

class PdrTexture2D
{
public:
    // Construction and destruction.
    PdrTexture2D (Renderer* renderer, const Texture2D* texture);
    ~PdrTexture2D ();

    // Texture operations.
    void Enable (Renderer* renderer, int textureUnit);
    void Disable (Renderer* renderer, int textureUnit);
    void* Lock (int level, Buffer::Locking mode);
    void Unlock (int level);

private:
    // Constructor for creating the color/depth textures for a render target.
    friend class Memory;
    friend class PdrRenderTarget;
    PdrTexture2D (Renderer* renderer, bool isColortexture,
        const Texture2D* texture, bool autoGenMipMap);

    IDirect3DTexture9* mTexture;
};

}

#endif
