// Geometric Tools, LLC
// Copyright (c) 1998-2012
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 5.0.0 (2010/01/01)

#ifndef SHROPENGLPIXELSHADER_H
#define SHROPENGLPIXELSHADER_H

#include "ShrOpenGLRendererLIB.h"
#include "ShrOpenGLShader.h"
#include "ShrPixelShader.h"

namespace shr
{

class Renderer;

class PdrPixelShader : public PdrShader
{
public:
    // Construction and destruction.
    PdrPixelShader (Renderer* renderer, const PixelShader* pshader);
    ~PdrPixelShader ();

    // Pixel shader operations.
    void Enable (Renderer* renderer, const PixelShader* pshader,
        const ShaderParameters* parameters);
    void Disable (Renderer* renderer, const PixelShader* pshader,
        const ShaderParameters* parameters);

private:
    GLuint mShader;
};

}

#endif
