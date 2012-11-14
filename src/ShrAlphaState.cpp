#include "ShrGraphicsPCH.h"
#include "ShrAlphaState.h"
using namespace shr;

SHR_IMPLEMENT_RTTI(shr, Object, AlphaState);
SHR_IMPLEMENT_STREAM(AlphaState);
SHR_IMPLEMENT_FACTORY(AlphaState);
SHR_IMPLEMENT_DEFAULT_NAMES(Object, AlphaState);

//----------------------------------------------------------------------------
AlphaState::AlphaState ()
    :
    BlendEnabled(false),
    SrcBlend(SBM_SRC_ALPHA),
    DstBlend(DBM_ONE_MINUS_SRC_ALPHA),
    CompareEnabled(false),
    Compare(CM_ALWAYS),
    Reference(0.0f),
    ConstantColor(0.0f, 0.0f, 0.0f, 0.0f)
{
}
//----------------------------------------------------------------------------
AlphaState::~AlphaState ()
{
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Streaming support.
//----------------------------------------------------------------------------
AlphaState::AlphaState (LoadConstructor value)
    :
    Object(value),
    BlendEnabled(false),
    SrcBlend(SBM_ZERO),
    DstBlend(DBM_ZERO),
    CompareEnabled(false),
    Compare(CM_NEVER),
    Reference(0.0f),
    ConstantColor(0.0f, 0.0f, 0.0f, 0.0f)
{
}
//----------------------------------------------------------------------------
void AlphaState::Load (InStream& source)
{
    SHR_BEGIN_DEBUG_STREAM_LOAD(source);

    Object::Load(source);

    source.ReadBool(BlendEnabled);
    source.ReadEnum(SrcBlend);
    source.ReadEnum(DstBlend);
    source.ReadBool(CompareEnabled);
    source.ReadEnum(Compare);
    source.Read(Reference);
    source.ReadAggregate(ConstantColor);

    SHR_END_DEBUG_STREAM_LOAD(AlphaState, source);
}
//----------------------------------------------------------------------------
void AlphaState::Link (InStream& source)
{
    Object::Link(source);
}
//----------------------------------------------------------------------------
void AlphaState::PostLink ()
{
    Object::PostLink();
}
//----------------------------------------------------------------------------
bool AlphaState::Register (OutStream& target) const
{
    return Object::Register(target);
}
//----------------------------------------------------------------------------
void AlphaState::Save (OutStream& target) const
{
    SHR_BEGIN_DEBUG_STREAM_SAVE(target);

    Object::Save(target);

    target.WriteBool(BlendEnabled);
    target.WriteEnum(SrcBlend);
    target.WriteEnum(DstBlend);
    target.WriteBool(CompareEnabled);
    target.WriteEnum(Compare);
    target.Write(Reference);
    target.WriteAggregate(ConstantColor);

    SHR_END_DEBUG_STREAM_SAVE(AlphaState, target);
}
//----------------------------------------------------------------------------
int AlphaState::GetStreamingSize () const
{
    int size = Object::GetStreamingSize();
    size += SHR_BOOLSIZE(BlendEnabled);
    size += SHR_ENUMSIZE(SrcBlend);
    size += SHR_ENUMSIZE(DstBlend);
    size += SHR_BOOLSIZE(CompareEnabled);
    size += SHR_ENUMSIZE(Compare);
    size += sizeof(Reference);
    size += sizeof(ConstantColor);
    return size;
}
//----------------------------------------------------------------------------
