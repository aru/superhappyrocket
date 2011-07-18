#ifdef WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#endif
#if defined(__APPLE__) && defined(__MACH__)
#include <OpenGL/gl.h>	// Header File For The OpenGL32 Library
#include <OpenGL/glu.h>	// Header File For The GLu32 Library
#else
#include <GL/gl.h>	// Header File For The OpenGL32 Library
#include <GL/glu.h>	// Header File For The GLu32 Library
#endif

#include "Renderer.h"

//----------------------------------------------------------------------------
// Viewport management.
//----------------------------------------------------------------------------
void Renderer::SetViewport (int xPosition, int yPosition, int width,
    int height)
{
    glViewport(xPosition, yPosition, width, height);
}
//----------------------------------------------------------------------------
void Renderer::GetViewport (int& xPosition, int& yPosition,
    int& width, int& height) const
{
	//int param[4]; Invalid conversion error on g++ MacOSX
    GLint param[4];
    glGetIntegerv(GL_VIEWPORT, param);

    xPosition = param[0];
    yPosition = param[1];
    width = param[2];
    height = param[3];
}
//----------------------------------------------------------------------------
void Renderer::SetDepthRange (float zMin, float zMax)
{
    glDepthRange((GLclampd)zMin, (GLclampd)zMax);
}
//----------------------------------------------------------------------------
void Renderer::GetDepthRange (float& zMin, float& zMax) const
{
    GLclampd param[2];
    glGetDoublev(GL_DEPTH_RANGE, param);

    zMin = (float)param[0];
    zMax = (float)param[1];
}
//----------------------------------------------------------------------------
void Renderer::Resize (int width, int height)
{
    mWidth = width;
    mHeight = height;

    //int param[4]; Invalid conversion error on g++ MacOSX
	GLint param[4];
    glGetIntegerv(GL_VIEWPORT, param);
    glViewport(param[0], param[1], width, height);
}
//----------------------------------------------------------------------------