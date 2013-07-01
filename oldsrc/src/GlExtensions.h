#ifndef GL_EXTENSIONS_H
#define GL_EXTENSIONS_H

#ifdef WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
// for now this thing is windoze only
#include <glew.h>
#include <wglew.h>
#endif
#if defined(__APPLE__) && defined(__MACH__)
#include <OpenGL/gl.h>	// Header File For The OpenGL32 Library
#include <OpenGL/glu.h>	// Header File For The GLu32 Library
#include "SDL_mixer/SDL_mixer.h" //SDL_mixer
#else
// this is good:
// #include <GL/GL.h>	// Header File For The OpenGL32 Library
// #include <GL/glu.h>	// Header File For The GLu32 Library --> included in glew.h
#endif
#if defined(__linux)
#include "SDL_mixer.h"
#endif
#if defined(WIN32)
#include "SDL_mixer.h" //SDL_mixer
#endif
// more to come
#include "SDL.h"
#endif