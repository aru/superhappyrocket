#include "ShrGraphicsPCH.h"
#include "ShrPolypoint.h"
using namespace shr;

SHR_IMPLEMENT_RTTI(shr, Visual, Polypoint);
SHR_IMPLEMENT_STREAM(Polypoint);
SHR_IMPLEMENT_FACTORY(Polypoint);
SHR_IMPLEMENT_DEFAULT_NAMES(Visual, Polypoint);

//----------------------------------------------------------------------------
Polypoint::Polypoint (VertexFormat* vformat, VertexBuffer* vbuffer)
    :
    Visual(PT_POLYPOINT, vformat, vbuffer, 0)
{
    mNumPoints = mVBuffer->GetNumElements();
}
//----------------------------------------------------------------------------
Polypoint::~Polypoint ()
{
}
//----------------------------------------------------------------------------
int Polypoint::GetMaxNumPoints () const
{
    return mVBuffer->GetNumElements();
}
//----------------------------------------------------------------------------
void Polypoint::SetNumPoints (int numPoints)
{
    int numVertices = mVBuffer->GetNumElements();
    if (0 <= numPoints && numPoints <= numVertices)
    {
        mNumPoints = numPoints;
    }
    else
    {
        mNumPoints = numVertices;
    }
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Streaming support.
//----------------------------------------------------------------------------
Polypoint::Polypoint (LoadConstructor value)
    :
    Visual(value),
    mNumPoints(0)
{
}
//----------------------------------------------------------------------------
void Polypoint::Load (InStream& source)
{
    SHR_BEGIN_DEBUG_STREAM_LOAD(source);

    Visual::Load(source);

    source.Read(mNumPoints);

    SHR_END_DEBUG_STREAM_LOAD(Polypoint, source);
}
//----------------------------------------------------------------------------
void Polypoint::Link (InStream& source)
{
    Visual::Link(source);
}
//----------------------------------------------------------------------------
void Polypoint::PostLink ()
{
    Visual::PostLink();
}
//----------------------------------------------------------------------------
bool Polypoint::Register (OutStream& target) const
{
    return Visual::Register(target);
}
//----------------------------------------------------------------------------
void Polypoint::Save (OutStream& target) const
{
    SHR_BEGIN_DEBUG_STREAM_SAVE(target);

    Visual::Save(target);

    target.Write(mNumPoints);

    SHR_END_DEBUG_STREAM_SAVE(Polypoint, target);
}
//----------------------------------------------------------------------------
int Polypoint::GetStreamingSize () const
{
    int size = Visual::GetStreamingSize();
    size += sizeof(mNumPoints);
    return size;
}
//----------------------------------------------------------------------------
