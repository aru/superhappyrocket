// Geometric Tools, LLC
// Copyright (c) 1998-2012
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 5.0.0 (2010/01/01)

#ifndef SHROPENGLVERTEXSHADER_H
#define SHROPENGLVERTEXSHADER_H

#include "ShrOpenGLRendererLIB.h"
#include "ShrOpenGLShader.h"
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
    GLuint mShader;
};

}

#endif
