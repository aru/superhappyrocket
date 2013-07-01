// Geometric Tools, LLC
// Copyright (c) 1998-2012
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 5.0.0 (2010/01/01)

#ifndef SHRAGLRENDERERINPUT_H
#define SHRAGLRENDERERINPUT_H

#include "ShrOpenGLRendererLIB.h"
#include <AGL/agl.h>
#include <Carbon/Carbon.h>
#include <DrawSprocket/DrawSprocket.h>

namespace shr
{

class RendererInput
{
public:
    AGLDevice mDevice;
    WindowRef mWindow;
};

}

#endif
