#include "ShrGraphicsPCH.h"
#include "ShrWireState.h"
using namespace shr;

SHR_IMPLEMENT_RTTI(shr, Object, WireState);
SHR_IMPLEMENT_STREAM(WireState);
SHR_IMPLEMENT_FACTORY(WireState);
SHR_IMPLEMENT_DEFAULT_NAMES(Object, WireState);

//----------------------------------------------------------------------------
WireState::WireState ()
    :
    Enabled(false)
{
}
//----------------------------------------------------------------------------
WireState::~WireState ()
{
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Streaming support.
//----------------------------------------------------------------------------
WireState::WireState (LoadConstructor value)
    :
    Object(value),
    Enabled(false)
{
}
//----------------------------------------------------------------------------
void WireState::Load (InStream& source)
{
    SHR_BEGIN_DEBUG_STREAM_LOAD(source);

    Object::Load(source);

    source.ReadBool(Enabled);

    SHR_END_DEBUG_STREAM_LOAD(WireState, source);
}
//----------------------------------------------------------------------------
void WireState::Link (InStream& source)
{
    Object::Link(source);
}
//----------------------------------------------------------------------------
void WireState::PostLink ()
{
    Object::PostLink();
}
//----------------------------------------------------------------------------
bool WireState::Register (OutStream& target) const
{
    return Object::Register(target);
}
//----------------------------------------------------------------------------
void WireState::Save (OutStream& target) const
{
    SHR_BEGIN_DEBUG_STREAM_SAVE(target);

    Object::Save(target);

    target.WriteBool(Enabled);

    SHR_END_DEBUG_STREAM_SAVE(WireState, target);
}
//----------------------------------------------------------------------------
int WireState::GetStreamingSize () const
{
    int size = Object::GetStreamingSize();
    size += SHR_BOOLSIZE(Enabled);
    return size;
}
//----------------------------------------------------------------------------