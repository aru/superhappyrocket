#ifndef SHRPIXELSHADER_H
#define SHRPIXELSHADER_H

#include "ShrGraphicsLIB.h"
#include "ShrShader.h"

namespace shr
{

class SHR_GRAPHICS_ITEM PixelShader : public Shader
{
    SHR_DECLARE_RTTI;
    SHR_DECLARE_NAMES;
    SHR_DECLARE_STREAM(PixelShader);

public:
    // Construction and destruction.  See comments in ShrShader.h about
    // constructing shader programs.
    PixelShader (const std::string& programName, int numInputs,
        int numOutputs, int numConstants, int numSamplers, bool profileOwner);

    virtual ~PixelShader ();

    // Pixel shader profile information.
    enum SHR_GRAPHICS_ITEM Profile
    {
        PP_NONE,
        PP_PS_1_1,
        PP_PS_2_0,
        PP_PS_3_0,
        PP_ARBFP1
    };

    static void SetProfile (Profile profile);
    static Profile GetProfile ();

protected:
    static Profile msProfile;
};

SHR_REGISTER_STREAM(PixelShader);
typedef Pointer0<PixelShader> PixelShaderPtr;

}

#endif
