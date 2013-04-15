#ifndef SHRSDLRENDERERINPUT_H
#define SHRSDLRENDERERINPUT_H

#include "Renderers/OpenGLRenderer/ShrOpenGLRendererLIB.h"
#include "ShrSDLExtensions.h"

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#ifdef WIN32
// The glut.h has unreference local functions glutInit_ATEXIT_HACK,
// glutCreateWindow_ATEXIT_HACK, and glutCreateMenu_ATEXIT_HACK.
// Disable the warnings about these.
#pragma warning(disable : 4505)
#endif
//#include "ShrWglExtensions.h"
//#include <GL/glut.h>
#endif

namespace shr
{

class RendererInput
{
public:
    SDL_SysWMinfo SysInfo;
    bool mDisableVerticalSync;
};

}

#endif