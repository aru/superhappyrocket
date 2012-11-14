// Geometric Tools, LLC
// Copyright (c) 1998-2012
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 5.0.0 (2010/01/01)

#ifndef SHROPENGLSHADER_H
#define SHROPENGLSHADER_H

#include "ShrOpenGLRendererLIB.h"
#include "ShrOpenGLRendererData.h"
#include "ShrShader.h"
#include "ShrShaderParameters.h"

namespace shr
{

class Renderer;

class PdrShader
{
public:
    // Construction and destruction.  The derived classes are
    // PdrVertexShader and PdrPixelShader.  Both classes hide the
    // base-class destructor.  This is not a problem because the
    // derived-class destructors are called explicitly when the shaders
    // are destroyed by Renderer.
    PdrShader ();
    ~PdrShader ();

protected:
    void SetSamplerState (Renderer* renderer, const Shader* shader,
        int profile, const ShaderParameters* parameters, int maxSamplers,
        RendererData::SamplerState* currentSS);

    void DisableTextures (Renderer* renderer, const Shader* shader,
        int profile, const ShaderParameters* parameters, int maxSamplers);
};

}

#endif
