#include "ShrGraphicsPCH.h"
#include "ShrCullState.h"
using namespace shr;

SHR_IMPLEMENT_RTTI(shr, Object, CullState);
SHR_IMPLEMENT_STREAM(CullState);
SHR_IMPLEMENT_FACTORY(CullState);
SHR_IMPLEMENT_DEFAULT_NAMES(Object, CullState);

//----------------------------------------------------------------------------
CullState::CullState ()
    :
    Enabled(true),
    CCWOrder(true)
{
}
//----------------------------------------------------------------------------
CullState::~CullState ()
{
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Streaming support.
//----------------------------------------------------------------------------
CullState::CullState (LoadConstructor value)
    :
    Object(value),
    Enabled(false),
    CCWOrder(false)
{
}
//----------------------------------------------------------------------------
void CullState::Load (InStream& source)
{
    SHR_BEGIN_DEBUG_STREAM_LOAD(source);

    Object::Load(source);

    source.ReadBool(Enabled);
    source.ReadBool(CCWOrder);

    SHR_END_DEBUG_STREAM_LOAD(CullState, source);
}
//----------------------------------------------------------------------------
void CullState::Link (InStream& source)
{
    Object::Link(source);
}
//----------------------------------------------------------------------------
void CullState::PostLink ()
{
    Object::PostLink();
}
//----------------------------------------------------------------------------
bool CullState::Register (OutStream& target) const
{
    return Object::Register(target);
}
//----------------------------------------------------------------------------
void CullState::Save (OutStream& target) const
{
    SHR_BEGIN_DEBUG_STREAM_SAVE(target);

    Object::Save(target);

    target.WriteBool(Enabled);
    target.WriteBool(CCWOrder);

    SHR_END_DEBUG_STREAM_SAVE(CullState, target);
}
//----------------------------------------------------------------------------
int CullState::GetStreamingSize () const
{
    int size = Object::GetStreamingSize();
    size += SHR_BOOLSIZE(Enabled);
    size += SHR_BOOLSIZE(CCWOrder);
    return size;
}
//----------------------------------------------------------------------------
