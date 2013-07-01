#include "ShrGraphicsPCH.h"
#include "ShrDepthState.h"
using namespace shr;

SHR_IMPLEMENT_RTTI(shr, Object, DepthState);
SHR_IMPLEMENT_STREAM(DepthState);
SHR_IMPLEMENT_FACTORY(DepthState);
SHR_IMPLEMENT_DEFAULT_NAMES(Object, DepthState);

//----------------------------------------------------------------------------
DepthState::DepthState ()
    :
    Enabled(true),
    Writable(true),
    Compare(CM_LEQUAL)
{
}
//----------------------------------------------------------------------------
DepthState::~DepthState ()
{
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Streaming support.
//----------------------------------------------------------------------------
DepthState::DepthState (LoadConstructor value)
    :
    Object(value),
    Enabled(false),
    Writable(false),
    Compare(CM_NEVER)
{
}
//----------------------------------------------------------------------------
void DepthState::Load (InStream& source)
{
    SHR_BEGIN_DEBUG_STREAM_LOAD(source);

    Object::Load(source);

    source.ReadBool(Enabled);
    source.ReadBool(Writable);
    source.ReadEnum(Compare);

    SHR_END_DEBUG_STREAM_LOAD(DepthState, source);
}
//----------------------------------------------------------------------------
void DepthState::Link (InStream& source)
{
    Object::Link(source);
}
//----------------------------------------------------------------------------
void DepthState::PostLink ()
{
    Object::PostLink();
}
//----------------------------------------------------------------------------
bool DepthState::Register (OutStream& target) const
{
    return Object::Register(target);
}
//----------------------------------------------------------------------------
void DepthState::Save (OutStream& target) const
{
    SHR_BEGIN_DEBUG_STREAM_SAVE(target);

    Object::Save(target);

    target.WriteBool(Enabled);
    target.WriteBool(Writable);
    target.WriteEnum(Compare);

    SHR_END_DEBUG_STREAM_SAVE(DepthState, target);
}
//----------------------------------------------------------------------------
int DepthState::GetStreamingSize () const
{
    int size = Object::GetStreamingSize();
    size += SHR_BOOLSIZE(Enabled);
    size += SHR_BOOLSIZE(Writable);
    size += SHR_ENUMSIZE(Compare);
    return size;
}
//----------------------------------------------------------------------------
