#ifndef SHRSDLRENDERERDATA_H
#define SHRSDLRENDERERDATA_H

#include "ShrOpenGLRendererLIB.h"
#include "ShrOpenGLRendererData.h"
#include "ShrSDLExtensions.h"

namespace shr
{

class Renderer;

class SDLRendererData : public RendererData
{
public:
    SDL_SysWMinfo SysInfo; //Will hold our Window information
};

}

#endif
