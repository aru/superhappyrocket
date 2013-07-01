#include "ShrGraphicsPCH.h"
#include "ShrOffsetState.h"
using namespace shr;

SHR_IMPLEMENT_RTTI(shr, Object, OffsetState);
SHR_IMPLEMENT_STREAM(OffsetState);
SHR_IMPLEMENT_FACTORY(OffsetState);
SHR_IMPLEMENT_DEFAULT_NAMES(Object, OffsetState);

//----------------------------------------------------------------------------
OffsetState::OffsetState ()
    :
    FillEnabled(false),
    LineEnabled(false),
    PointEnabled(false),
    Scale(0.0f),
    Bias(0.0f)
{
}
//----------------------------------------------------------------------------
OffsetState::~OffsetState ()
{
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Streaming support.
//----------------------------------------------------------------------------
OffsetState::OffsetState (LoadConstructor value)
    :
    Object(value),
    FillEnabled(false),
    LineEnabled(false),
    PointEnabled(false),
    Scale(0.0f),
    Bias(0.0f)
{
}
//----------------------------------------------------------------------------
void OffsetState::Load (InStream& source)
{
    SHR_BEGIN_DEBUG_STREAM_LOAD(source);

    Object::Load(source);

    source.ReadBool(FillEnabled);
    source.ReadBool(LineEnabled);
    source.ReadBool(PointEnabled);
    source.Read(Scale);
    source.Read(Bias);

    SHR_END_DEBUG_STREAM_LOAD(OffsetState, source);
}
//----------------------------------------------------------------------------
void OffsetState::Link (InStream& source)
{
    Object::Link(source);
}
//----------------------------------------------------------------------------
void OffsetState::PostLink ()
{
    Object::PostLink();
}
//----------------------------------------------------------------------------
bool OffsetState::Register (OutStream& target) const
{
    return Object::Register(target);
}
//----------------------------------------------------------------------------
void OffsetState::Save (OutStream& target) const
{
    SHR_BEGIN_DEBUG_STREAM_SAVE(target);

    Object::Save(target);

    target.WriteBool(FillEnabled);
    target.WriteBool(LineEnabled);
    target.WriteBool(PointEnabled);
    target.Write(Scale);
    target.Write(Bias);

    SHR_END_DEBUG_STREAM_SAVE(OffsetState, target);
}
//----------------------------------------------------------------------------
int OffsetState::GetStreamingSize () const
{
    int size = Object::GetStreamingSize();
    size += SHR_BOOLSIZE(FillEnabled);
    size += SHR_BOOLSIZE(LineEnabled);
    size += SHR_BOOLSIZE(PointEnabled);
    size += sizeof(Scale);
    size += sizeof(Bias);
    return size;
}
//----------------------------------------------------------------------------
