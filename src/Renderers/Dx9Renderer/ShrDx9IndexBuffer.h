// Geometric Tools, LLC
// Copyright (c) 1998-2012
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 5.0.0 (2010/01/01)

#ifndef SHRDX9INDEXBUFFER_H
#define SHRDX9INDEXBUFFER_H

#include "ShrDx9RendererLIB.h"
#include "ShrIndexBuffer.h"

namespace shr
{

class Renderer;

class PdrIndexBuffer
{
public:
    // Construction and destruction.
    PdrIndexBuffer (Renderer* renderer, const IndexBuffer* ibuffer);
    ~PdrIndexBuffer ();

    // Buffer operations.
    void Enable (Renderer* renderer);
    void Disable (Renderer* renderer);
    void* Lock (Buffer::Locking mode);
    void Unlock ();

private:
    IDirect3DIndexBuffer9* mBuffer;
};

}

#endif