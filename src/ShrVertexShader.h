#ifndef SHRVERTEXSHADER_H
#define SHRVERTEXSHADER_H

#include "ShrGraphicsLIB.h"
#include "ShrShader.h"

namespace shr
{

class SHR_GRAPHICS_ITEM VertexShader : public Shader
{
    SHR_DECLARE_RTTI;
    SHR_DECLARE_NAMES;
    SHR_DECLARE_STREAM(VertexShader);

public:
    // Construction and destruction.  See comments in ShrShader.h about
    // constructing shader programs.
    VertexShader (const std::string& programName, int numInputs,
        int numOutputs, int numConstants, int numSamplers, bool profileOwner);

    virtual ~VertexShader ();

    // Vertex shader profile information.
    enum SHR_GRAPHICS_ITEM Profile
    {
        VP_NONE,
        VP_VS_1_1,
        VP_VS_2_0,
        VP_VS_3_0,
        VP_ARBVP1
    };

    static void SetProfile (Profile profile);
    static Profile GetProfile ();

protected:
    static Profile msProfile;
};

SHR_REGISTER_STREAM(VertexShader);
typedef Pointer0<VertexShader> VertexShaderPtr;

}

#endif
