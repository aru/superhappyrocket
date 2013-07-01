#include "ShrGraphicsPCH.h"
#include "ShrStencilState.h"
using namespace shr;

SHR_IMPLEMENT_RTTI(shr, Object, StencilState);
SHR_IMPLEMENT_STREAM(StencilState);
SHR_IMPLEMENT_FACTORY(StencilState);
SHR_IMPLEMENT_DEFAULT_NAMES(Object, StencilState);

//----------------------------------------------------------------------------
StencilState::StencilState ()
    :
    Enabled(false),
    Compare(CM_NEVER),
    Reference(0),
    Mask(UINT_MAX),
    WriteMask(UINT_MAX),
    OnFail(OT_KEEP),
    OnZFail(OT_KEEP),
    OnZPass(OT_KEEP)
{
}
//----------------------------------------------------------------------------
StencilState::~StencilState ()
{
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Streaming support.
//----------------------------------------------------------------------------
StencilState::StencilState (LoadConstructor value)
    :
    Object(value),
    Enabled(false),
    Compare(CM_NEVER),
    Reference(0),
    Mask(0),
    WriteMask(0),
    OnFail(OT_KEEP),
    OnZFail(OT_KEEP),
    OnZPass(OT_KEEP)
{
}
//----------------------------------------------------------------------------
void StencilState::Load (InStream& source)
{
    SHR_BEGIN_DEBUG_STREAM_LOAD(source);

    Object::Load(source);

    source.ReadBool(Enabled);
    source.ReadEnum(Compare);
    source.Read(Reference);
    source.Read(Mask);
    source.Read(WriteMask);
    source.ReadEnum(OnFail);
    source.ReadEnum(OnZFail);
    source.ReadEnum(OnZPass);

    SHR_END_DEBUG_STREAM_LOAD(StencilState, source);
}
//----------------------------------------------------------------------------
void StencilState::Link (InStream& source)
{
    Object::Link(source);
}
//----------------------------------------------------------------------------
void StencilState::PostLink ()
{
    Object::PostLink();
}
//----------------------------------------------------------------------------
bool StencilState::Register (OutStream& target) const
{
    return Object::Register(target);
}
//----------------------------------------------------------------------------
void StencilState::Save (OutStream& target) const
{
    SHR_BEGIN_DEBUG_STREAM_SAVE(target);

    Object::Save(target);

    target.WriteBool(Enabled);
    target.WriteEnum(Compare);
    target.Write(Reference);
    target.Write(Mask);
    target.Write(WriteMask);
    target.WriteEnum(OnFail);
    target.WriteEnum(OnZFail);
    target.WriteEnum(OnZPass);

    SHR_END_DEBUG_STREAM_SAVE(StencilState, target);
}
//----------------------------------------------------------------------------
int StencilState::GetStreamingSize () const
{
    int size = Object::GetStreamingSize();
    size += SHR_BOOLSIZE(Enabled);
    size += SHR_ENUMSIZE(Compare);
    size += sizeof(Reference);
    size += sizeof(Mask);
    size += sizeof(WriteMask);
    size += SHR_ENUMSIZE(OnFail);
    size += SHR_ENUMSIZE(OnZFail);
    size += SHR_ENUMSIZE(OnZPass);
    return size;
}
//----------------------------------------------------------------------------
