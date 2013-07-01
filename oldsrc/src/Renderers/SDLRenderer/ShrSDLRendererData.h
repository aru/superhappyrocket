#ifndef SHRSDLRENDERERDATA_H
#define SHRSDLRENDERERDATA_H

#include "Renderers/OpenGLRenderer/ShrOpenGLRendererLIB.h"
#include "Renderers/OpenGLRenderer/ShrOpenGLRendererData.h"
#include "ShrSDLExtensions.h"

namespace shr
{

class Renderer;

class SDLRendererData : public RendererData
{
public:
	SDL_version version; // SDL version
    SDL_SysWMinfo window; //Will hold our Window information
};

}

#endif
