// Geometric Tools, LLC
// Copyright (c) 1998-2012
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 5.0.0 (2010/01/01)

#ifndef SHRDX9SHADER_H
#define SHRDX9SHADER_H

#include "ShrDx9RendererLIB.h"
#include "ShrDx9RendererData.h"
#include "ShrShader.h"
#include "ShrShaderParameters.h"

namespace shr
{

class Renderer;

class PdrShader
{
public:
    // Construction and destruction.  The derived classes are PdrVertexShader
    // and PdrPixelShader.  Both classes hide the base-class destructor.  This
    // is not a problem because the derived-class destructors are called
    // explicitly when the shaders are destroyed by Renderer.
    PdrShader ();
    ~PdrShader ();

protected:
    void SetSamplerState (Renderer* renderer, const Shader* shader,
        int profile, const ShaderParameters* parameters, int maxSamplers,
        DWORD base, RendererData::SamplerState* currentSS);

    void DisableTextures (Renderer* renderer, const Shader* shader,
        int profile, const ShaderParameters* parameters, int maxSamplers,
        DWORD base);
};

}

#endif
