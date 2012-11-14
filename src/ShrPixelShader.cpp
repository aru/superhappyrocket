#include "ShrGraphicsPCH.h"
#include "ShrPixelShader.h"
#include "ShrRenderer.h"
using namespace shr;

SHR_IMPLEMENT_RTTI(shr, Shader, PixelShader);
SHR_IMPLEMENT_STREAM(PixelShader);
SHR_IMPLEMENT_FACTORY(PixelShader);
SHR_IMPLEMENT_DEFAULT_NAMES(Shader, PixelShader);
SHR_IMPLEMENT_DEFAULT_STREAM(Shader, PixelShader);

PixelShader::Profile PixelShader::msProfile = PixelShader::PP_NONE;

//----------------------------------------------------------------------------
PixelShader::PixelShader (const std::string& programName, int numInputs,
    int numOutputs, int numConstants, int numSamplers, bool profileOwner)
    :
    Shader(programName, numInputs, numOutputs, numConstants, numSamplers,
        profileOwner)
{
}
//----------------------------------------------------------------------------
PixelShader::~PixelShader ()
{
    Renderer::UnbindAll(this);
}
//----------------------------------------------------------------------------
void PixelShader::SetProfile (Profile profile)
{
    msProfile = profile;
}
//----------------------------------------------------------------------------
PixelShader::Profile PixelShader::GetProfile ()
{
    return msProfile;
}
//----------------------------------------------------------------------------