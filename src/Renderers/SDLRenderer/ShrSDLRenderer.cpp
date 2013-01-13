#include "ShrGraphicsPCH.h"
#include "ShrRenderer.h"
#include "ShrSDLRendererData.h"
#include "ShrSDLRendererInput.h"
using namespace shr;

//----------------------------------------------------------------------------
Renderer::Renderer (RendererInput& input, int width, int height,
    Texture::Format colorFormat, Texture::Format depthStencilFormat,
    int numMultisamples)
{
    Initialize(width, height, colorFormat, depthStencilFormat,
        numMultisamples);

    SDLRendererData* data = new0 SDLRendererData();
	SDL_VERSION(&data.version); //Set SDL version
	if(SDL_GetWMInfo(&data) <= 0) {
		printf("%s : %d\n", SDL_GetError(), data.window);
	}
    mData = data;
    data->SysInfo = input.SysInfo;

    // Load the function pointers for the OpenGL extensions.  This only
    // needs to occur once.  If you want a file to be created that stores
    // the OpenGL driver information, change the input filename to a
    // valid string; for example, "OpenGLDriverInfo.txt".
    //const char* infoFile = "OpenGLDriverInfo.txt";
    const char* infoFile = 0;

	// Call glew in here
	// glew_init();

    // Select the shader profiles.
    VertexShader::SetProfile(VertexShader::VP_ARBVP1);
    PixelShader::SetProfile(PixelShader::PP_ARBFP1);

    // Query the device for its capabilities.  TODO:  The number of images
    // turns out to be larger than what Shader Model 3 supports.  Why is this?
    data->mMaxVShaderImages = 0;
    data->mMaxPShaderImages = 0;
    data->mMaxCombinedImages = 0;
    glGetIntegerv(GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS,
        &data->mMaxVShaderImages);
    glGetIntegerv(GL_MAX_TEXTURE_IMAGE_UNITS,
        &data->mMaxPShaderImages);
    glGetIntegerv(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS,
        &data->mMaxCombinedImages);

    // Set the default render states.
    data->mCurrentRS.Initialize(mDefaultAlphaState, mDefaultCullState,
        mDefaultDepthState, mDefaultOffsetState, mDefaultStencilState,
        mDefaultWireState);
}
//----------------------------------------------------------------------------
Renderer::~Renderer ()
{
    delete0(mData);
    Terminate();
}
//----------------------------------------------------------------------------
void Renderer::DisplayColorBuffer ()
{
	// In here I should check that windowIds match but for now, no...
	//SDL_SysWMinfo SysInfo;
	//SDL_VERSION(&SysInfo.version); //Set SDL version
	//if(SDL_GetWMInfo(&SysInfo) <= 0) {
	//	printf("%s : %d\n", SDL_GetError(), SysInfo.window);
	//}

 //   SDLRendererData* data = (SDLRendererData*)mData;
 //   if (SDL_GetWMInfo(&data) == data)
 //   {
 //       SDL_GL_SwapBuffers();
 //   }
	SDL_GL_SwapBuffers();
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// For function extension support on Mac OS X.
//----------------------------------------------------------------------------
#ifdef __APPLE__
#include <mach-o/dyld.h>
#include <cstdlib>
#include <cstring>

extern "C"
{
//----------------------------------------------------------------------------
void* GTGetFunctionPointer (const char* function)
{
    NSSymbol symbol;
    char* symbolName;

    // Prepend a '_' for the Unix C symbol mangling convention.
    symbolName = (char*)malloc(strlen((const char*)function) + 2);
    strcpy(symbolName + 1,(const char*)function);
    symbolName[0] = '_';

    symbol = 0;
    if (NSIsSymbolNameDefined(symbolName))
	{
        symbol = NSLookupAndBindSymbol(symbolName);
	}

    free(symbolName);
    return symbol ? NSAddressOfSymbol(symbol) : 0;
}
//----------------------------------------------------------------------------
}
#endif
//----------------------------------------------------------------------------
