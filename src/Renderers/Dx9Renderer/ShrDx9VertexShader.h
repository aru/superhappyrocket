// Geometric Tools, LLC
// Copyright (c) 1998-2012
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 5.0.0 (2010/01/01)

#ifndef SHRDX9VERTEXSHADER_H
#define SHRDX9VERTEXSHADER_H

#include "ShrDx9RendererLIB.h"
#include "ShrDx9Shader.h"
#include "ShrVertexShader.h"

namespace shr
{

class Renderer;

class PdrVertexShader : public PdrShader
{
public:
    // Construction and destruction
    PdrVertexShader (Renderer* renderer, const VertexShader* vshader);
    ~PdrVertexShader ();

    // Vertex shader operations.
    void Enable (Renderer* renderer, const VertexShader* vshader,
        const ShaderParameters* parameters);
    void Disable (Renderer* renderer, const VertexShader* vshader,
        const ShaderParameters* parameters);

private:
    IDirect3DVertexShader9* mShader;
};

}

#endif
