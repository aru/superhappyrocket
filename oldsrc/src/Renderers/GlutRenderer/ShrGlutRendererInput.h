// Geometric Tools, LLC
// Copyright (c) 1998-2012
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 5.6.2 (2012/07/31)

#ifndef SHRGLUTRENDERERINPUT_H
#define SHRGLUTRENDERERINPUT_H

#include "ShrOpenGLRendererLIB.h"

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#ifdef WIN32
// The glut.h has unreference local functions glutInit_ATEXIT_HACK,
// glutCreateWindow_ATEXIT_HACK, and glutCreateMenu_ATEXIT_HACK.
// Disable the warnings about these.
#pragma warning(disable : 4505)
#endif
#include "ShrWglExtensions.h"
#include <GL/glut.h>
#endif

namespace shr
{

class RendererInput
{
public:
    int mWindowID;
    bool mDisableVerticalSync;
};

}

#endif