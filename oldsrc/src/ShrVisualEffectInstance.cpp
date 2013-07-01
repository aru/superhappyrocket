#include "ShrGraphicsPCH.h"
#include "ShrVisualEffectInstance.h"
using namespace shr;

SHR_IMPLEMENT_RTTI(shr, Object, VisualEffectInstance);
SHR_IMPLEMENT_STREAM(VisualEffectInstance);
SHR_IMPLEMENT_FACTORY(VisualEffectInstance);

//----------------------------------------------------------------------------
VisualEffectInstance::VisualEffectInstance (const VisualEffect* effect,
    int techniqueIndex)
    :
    mEffect((VisualEffect*)effect),  // conceptual constness
    mTechniqueIndex(techniqueIndex)
{
    assertion(effect != 0, "Effect must be specified.\n");
    assertion(
        0 <= techniqueIndex && techniqueIndex < effect->GetNumTechniques(),
        "Invalid technique index.\n");

    VisualTechnique* technique = mEffect->GetTechnique(mTechniqueIndex);
    mNumPasses = technique->GetNumPasses();
    mVertexParameters = new1<ShaderParametersPtr>(mNumPasses);
    mPixelParameters = new1<ShaderParametersPtr>(mNumPasses);
    int p;
    for (p = 0; p < mNumPasses; ++p)
    {
        VisualPass* pass = technique->GetPass(p);
        mVertexParameters[p] =
            new0 ShaderParameters(pass->GetVertexShader());
        mPixelParameters[p] =
            new0 ShaderParameters(pass->GetPixelShader());
    }
}
//----------------------------------------------------------------------------
VisualEffectInstance::~VisualEffectInstance ()
{
    delete1(mVertexParameters);
    delete1(mPixelParameters);
}
//----------------------------------------------------------------------------
const VisualPass* VisualEffectInstance::GetPass (int pass) const
{
    if (0 <= pass && pass < mNumPasses)
    {
        return mEffect->GetTechnique(mTechniqueIndex)->GetPass(pass);
    }

    assertion(false, "Invalid pass index.\n");
    return 0;
}
//----------------------------------------------------------------------------
ShaderParameters* VisualEffectInstance::GetVertexParameters (int pass) const
{
    if (0 <= pass && pass < mNumPasses)
    {
        return mVertexParameters[pass];
    }

    assertion(false, "Invalid pass index.\n");
    return 0;
}
//----------------------------------------------------------------------------
ShaderParameters* VisualEffectInstance::GetPixelParameters (int pass) const
{
    if (0 <= pass && pass < mNumPasses)
    {
        return mPixelParameters[pass];
    }

    assertion(false, "Invalid pass index.\n");
    return 0;
}
//----------------------------------------------------------------------------
int VisualEffectInstance::SetVertexConstant (int pass,
    const std::string& name, ShaderFloat* sfloat)
{
    if (0 <= pass && pass < mNumPasses)
    {
        return mVertexParameters[pass]->SetConstant(name, sfloat);
    }

    assertion(false, "Invalid pass index.\n");
    return -1;
}
//----------------------------------------------------------------------------
int VisualEffectInstance::SetPixelConstant (int pass, const std::string& name,
    ShaderFloat* sfloat)
{
    if (0 <= pass && pass < mNumPasses)
    {
        return mPixelParameters[pass]->SetConstant(name, sfloat);
    }

    assertion(false, "Invalid pass index.\n");
    return -1;
}
//----------------------------------------------------------------------------
int VisualEffectInstance::SetVertexTexture (int pass, const std::string& name,
    Texture* texture)
{
    if (0 <= pass && pass < mNumPasses)
    {
        return mVertexParameters[pass]->SetTexture(name, texture);
    }

    assertion(false, "Invalid pass index.\n");
    return -1;
}
//----------------------------------------------------------------------------
int VisualEffectInstance::SetPixelTexture (int pass, const std::string& name,
    Texture* texture)
{
    if (0 <= pass && pass < mNumPasses)
    {
        return mPixelParameters[pass]->SetTexture(name, texture);
    }

    assertion(false, "Invalid pass index.\n");
    return -1;
}
//----------------------------------------------------------------------------
void VisualEffectInstance::SetVertexConstant (int pass, int handle,
    ShaderFloat* sfloat)
{
    if (0 <= pass && pass < mNumPasses)
    {
        return mVertexParameters[pass]->SetConstant(handle, sfloat);
    }

    assertion(false, "Invalid pass index.\n");
}
//----------------------------------------------------------------------------
void VisualEffectInstance::SetPixelConstant (int pass, int handle,
    ShaderFloat* sfloat)
{
    if (0 <= pass && pass < mNumPasses)
    {
        return mPixelParameters[pass]->SetConstant(handle, sfloat);
    }

    assertion(false, "Invalid pass index.\n");
}
//----------------------------------------------------------------------------
void VisualEffectInstance::SetVertexTexture (int pass, int handle,
    Texture* texture)
{
    if (0 <= pass && pass < mNumPasses)
    {
        return mVertexParameters[pass]->SetTexture(handle, texture);
    }

    assertion(false, "Invalid pass index.\n");
}
//----------------------------------------------------------------------------
void VisualEffectInstance::SetPixelTexture (int pass, int handle,
    Texture* texture)
{
    if (0 <= pass && pass < mNumPasses)
    {
        return mPixelParameters[pass]->SetTexture(handle, texture);
    }

    assertion(false, "Invalid pass index.\n");
}
//----------------------------------------------------------------------------
ShaderFloat* VisualEffectInstance::GetVertexConstant (int pass,
    const std::string& name) const
{
    if (0 <= pass && pass < mNumPasses)
    {
        return mVertexParameters[pass]->GetConstant(name);
    }

    assertion(false, "Invalid pass index.\n");
    return 0;
}
//----------------------------------------------------------------------------
ShaderFloat* VisualEffectInstance::GetPixelConstant (int pass,
    const std::string& name) const
{
    if (0 <= pass && pass < mNumPasses)
    {
        return mPixelParameters[pass]->GetConstant(name);
    }

    assertion(false, "Invalid pass index.\n");
    return 0;
}
//----------------------------------------------------------------------------
Texture* VisualEffectInstance::GetVertexTexture (int pass,
    const std::string& name) const
{
    if (0 <= pass && pass < mNumPasses)
    {
        return mVertexParameters[pass]->GetTexture(name);
    }

    assertion(false, "Invalid pass index.\n");
    return 0;
}
//----------------------------------------------------------------------------
Texture* VisualEffectInstance::GetPixelTexture (int pass,
    const std::string& name) const
{
    if (0 <= pass && pass < mNumPasses)
    {
        return mPixelParameters[pass]->GetTexture(name);
    }

    assertion(false, "Invalid pass index.\n");
    return 0;
}
//----------------------------------------------------------------------------
ShaderFloat* VisualEffectInstance::GetVertexConstant (int pass, int handle)
    const
{
    if (0 <= pass && pass < mNumPasses)
    {
        return mVertexParameters[pass]->GetConstant(handle);
    }

    assertion(false, "Invalid pass index.\n");
    return 0;
}
//----------------------------------------------------------------------------
ShaderFloat* VisualEffectInstance::GetPixelConstant (int pass, int handle)
    const
{
    if (0 <= pass && pass < mNumPasses)
    {
        return mPixelParameters[pass]->GetConstant(handle);
    }

    assertion(false, "Invalid pass index.\n");
    return 0;
}
//----------------------------------------------------------------------------
Texture* VisualEffectInstance::GetVertexTexture (int pass, int handle) const
{
    if (0 <= pass && pass < mNumPasses)
    {
        return mVertexParameters[pass]->GetTexture(handle);
    }

    assertion(false, "Invalid pass index.\n");
    return 0;
}
//----------------------------------------------------------------------------
Texture* VisualEffectInstance::GetPixelTexture (int pass, int handle) const
{
    if (0 <= pass && pass < mNumPasses)
    {
        return mPixelParameters[pass]->GetTexture(handle);
    }

    assertion(false, "Invalid pass index.\n");
    return 0;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Name support.
//----------------------------------------------------------------------------
Object* VisualEffectInstance::GetObjectByName (const std::string& name)
{
    Object* found = Object::GetObjectByName(name);
    if (found)
    {
        return found;
    }

    SHR_GET_OBJECT_BY_NAME(mEffect, name, found);
    for (int pass = 0; pass < mNumPasses; ++pass)
    {
        SHR_GET_OBJECT_BY_NAME(mVertexParameters[pass], name, found);
        SHR_GET_OBJECT_BY_NAME(mPixelParameters[pass], name, found);
    }

    return 0;
}
//----------------------------------------------------------------------------
void VisualEffectInstance::GetAllObjectsByName (const std::string& name,
    std::vector<Object*>& objects)
{
    Object::GetAllObjectsByName(name, objects);

    SHR_GET_ALL_OBJECTS_BY_NAME(mEffect, name, objects);
    for (int pass = 0; pass < mNumPasses; ++pass)
    {
        SHR_GET_ALL_OBJECTS_BY_NAME(mVertexParameters[pass], name, objects);
        SHR_GET_ALL_OBJECTS_BY_NAME(mPixelParameters[pass], name, objects);
    }
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Streaming support.
//----------------------------------------------------------------------------
VisualEffectInstance::VisualEffectInstance (LoadConstructor value)
    :
    Object(value),
    mTechniqueIndex(0),
    mNumPasses(0),
    mVertexParameters(0),
    mPixelParameters(0)
{
}
//----------------------------------------------------------------------------
void VisualEffectInstance::Load (InStream& source)
{
    SHR_BEGIN_DEBUG_STREAM_LOAD(source);

    Object::Load(source);

    source.Read(mTechniqueIndex);
    source.ReadPointer(mEffect);
    source.ReadPointerRR(mNumPasses, mVertexParameters);
    source.ReadPointerVR(mNumPasses, mPixelParameters);

    SHR_END_DEBUG_STREAM_LOAD(VisualEffectInstance, source);
}
//----------------------------------------------------------------------------
void VisualEffectInstance::Link (InStream& source)
{
    Object::Link(source);

    source.ResolveLink(mEffect);
    source.ResolveLink(mNumPasses, mVertexParameters);
    source.ResolveLink(mNumPasses, mPixelParameters);
}
//----------------------------------------------------------------------------
void VisualEffectInstance::PostLink ()
{
    Object::PostLink();
}
//----------------------------------------------------------------------------
bool VisualEffectInstance::Register (OutStream& target) const
{
    if (Object::Register(target))
    {
        target.Register(mEffect);
        target.Register(mNumPasses, mVertexParameters);
        target.Register(mNumPasses, mPixelParameters);
        return true;
    }
    return false;
}
//----------------------------------------------------------------------------
void VisualEffectInstance::Save (OutStream& target) const
{
    SHR_BEGIN_DEBUG_STREAM_SAVE(target);

    Object::Save(target);

    target.Write(mTechniqueIndex);
    target.WritePointer(mEffect);
    target.WritePointerW(mNumPasses, mVertexParameters);
    target.WritePointerN(mNumPasses, mPixelParameters);

    SHR_END_DEBUG_STREAM_SAVE(VisualEffectInstance, target);
}
//----------------------------------------------------------------------------
int VisualEffectInstance::GetStreamingSize () const
{
    int size = Object::GetStreamingSize();
    size += sizeof(mTechniqueIndex);
    size += SHR_POINTERSIZE(mEffect);
    size += sizeof(mNumPasses);
    size += mNumPasses*SHR_POINTERSIZE(mVertexParameters[0]);
    size += mNumPasses*SHR_POINTERSIZE(mPixelParameters[0]);
    return size;
}
//----------------------------------------------------------------------------
