#include "ShrGraphicsPCH.h"
#include "ShrShaderFloat.h"
using namespace shr;

SHR_IMPLEMENT_RTTI(shr, Object, ShaderFloat);
SHR_IMPLEMENT_STREAM(ShaderFloat);
SHR_IMPLEMENT_FACTORY(ShaderFloat);
SHR_IMPLEMENT_DEFAULT_NAMES(Object, ShaderFloat);

//----------------------------------------------------------------------------
ShaderFloat::ShaderFloat ()
    :
    mNumElements(0),
    mData(0),
    mAllowUpdater(false)
{
}
//----------------------------------------------------------------------------
ShaderFloat::ShaderFloat (int numRegisters)
    :
    mAllowUpdater(false)
{
    SetNumRegisters(numRegisters);
}
//----------------------------------------------------------------------------
ShaderFloat::~ShaderFloat ()
{
    delete1(mData);
}
//----------------------------------------------------------------------------
void ShaderFloat::SetNumRegisters (int numRegisters)
{
    assertion(numRegisters > 0, "Number of registers must be positive\n");
    mNumElements = 4*numRegisters;
    mData = new1<float>(mNumElements);
}
//----------------------------------------------------------------------------
void ShaderFloat::SetRegister (int i, const float* data)
{
    assertion(0 <= i && i < mNumElements/4, "Invalid register\n");
    float* target = mData + 4*i;
    *target++ = *data++;
    *target++ = *data++;
    *target++ = *data++;
    *target   = *data;
}
//----------------------------------------------------------------------------
void ShaderFloat::SetRegisters (const float* data)
{
    float* target = mData;
    for (int i = 0; i < mNumElements; ++i)
    {
        *target++ = *data++;
    }
}
//----------------------------------------------------------------------------
void ShaderFloat::GetRegister (int i, float* data)
{
    assertion(0 <= i && i < mNumElements/4, "Invalid register\n");
    float* source = mData + 4*i;
    *data++ = *source++;
    *data++ = *source++;
    *data++ = *source++;
    *data   = *source;
}
//----------------------------------------------------------------------------
void ShaderFloat::GetRegisters (float* data)
{
    float* source = mData;
    for (int i = 0; i < mNumElements; ++i)
    {
        *data++ = *source++;
    }
}
//----------------------------------------------------------------------------
ShaderFloat& ShaderFloat::operator= (const float* data)
{
    float* target = mData;
    for (int i = 0; i < mNumElements; ++i)
    {
        *target++ = *data++;
    }
    return *this;
}
//----------------------------------------------------------------------------
void ShaderFloat::Update (const Visual*, const Camera*)
{
    // Stub for derived classes.
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Streaming support.
//----------------------------------------------------------------------------
ShaderFloat::ShaderFloat (LoadConstructor value)
    :
    Object(value),
    mNumElements(0),
    mData(0),
    mAllowUpdater(false)
{
}
//----------------------------------------------------------------------------
void ShaderFloat::Load (InStream& source)
{
    SHR_BEGIN_DEBUG_STREAM_LOAD(source);

    Object::Load(source);

    source.ReadRR(mNumElements, mData);
    source.ReadBool(mAllowUpdater);

    SHR_END_DEBUG_STREAM_LOAD(ShaderFloat, source);
}
//----------------------------------------------------------------------------
void ShaderFloat::Link (InStream& source)
{
    Object::Link(source);
}
//----------------------------------------------------------------------------
void ShaderFloat::PostLink ()
{
    Object::PostLink();
}
//----------------------------------------------------------------------------
bool ShaderFloat::Register (OutStream& target) const
{
    return Object::Register(target);
}
//----------------------------------------------------------------------------
void ShaderFloat::Save (OutStream& target) const
{
    SHR_BEGIN_DEBUG_STREAM_SAVE(target);

    Object::Save(target);

    target.WriteW(mNumElements, mData);
    target.WriteBool(mAllowUpdater);

    SHR_END_DEBUG_STREAM_SAVE(ShaderFloat, target);
}
//----------------------------------------------------------------------------
int ShaderFloat::GetStreamingSize () const
{
    int size = Object::GetStreamingSize();
    size += sizeof(mNumElements);
    size += mNumElements*sizeof(mData[0]);
    size += SHR_BOOLSIZE(mAllowUpdater);
    return size;
}
//----------------------------------------------------------------------------
