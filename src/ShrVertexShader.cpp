#include "ShrGraphicsPCH.h"
#include "ShrVertexShader.h"
#include "ShrRenderer.h"
using namespace shr;

SHR_IMPLEMENT_RTTI(shr, Shader, VertexShader);
SHR_IMPLEMENT_STREAM(VertexShader);
SHR_IMPLEMENT_FACTORY(VertexShader);
SHR_IMPLEMENT_DEFAULT_NAMES(Shader, VertexShader);
SHR_IMPLEMENT_DEFAULT_STREAM(Shader, VertexShader);

VertexShader::Profile VertexShader::msProfile = VertexShader::VP_NONE;

//----------------------------------------------------------------------------
VertexShader::VertexShader (const std::string& programName, int numInputs,
    int numOutputs, int numConstants, int numSamplers, bool profileOwner)
    :
    Shader(programName, numInputs, numOutputs, numConstants, numSamplers,
        profileOwner)
{
}
//----------------------------------------------------------------------------
VertexShader::~VertexShader ()
{
    Renderer::UnbindAll(this);
}
//----------------------------------------------------------------------------
void VertexShader::SetProfile (Profile profile)
{
    msProfile = profile;
}
//----------------------------------------------------------------------------
VertexShader::Profile VertexShader::GetProfile ()
{
    return msProfile;
}
//----------------------------------------------------------------------------
