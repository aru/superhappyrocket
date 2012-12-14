#include "ShrGraphicsPCH.h"
#include "ShrPolysegment.h"
using namespace shr;

SHR_IMPLEMENT_RTTI(shr, Visual, Polysegment);
SHR_IMPLEMENT_STREAM(Polysegment);
SHR_IMPLEMENT_FACTORY(Polysegment);
SHR_IMPLEMENT_DEFAULT_NAMES(Visual, Polysegment);

//----------------------------------------------------------------------------
Polysegment::Polysegment (VertexFormat* vformat, VertexBuffer* vbuffer,
    bool contiguous)
    :
    Visual(contiguous ? PT_POLYSEGMENTS_CONTIGUOUS : PT_POLYSEGMENTS_DISJOINT,
        vformat, vbuffer, 0),
    mContiguous(contiguous)
{
    int numVertices = mVBuffer->GetNumElements();
    assertion(numVertices >= 2,
        "Polysegments must have at least two points.\n");

    if (mContiguous)
    {
        mNumSegments = numVertices - 1;
    }
    else
    {
        assertion((numVertices & 1) == 0,
            "Disconnected segments require an even number of vertices.\n");

        mNumSegments = numVertices/2;
    }
}
//----------------------------------------------------------------------------
Polysegment::~Polysegment ()
{
}
//----------------------------------------------------------------------------
int Polysegment::GetMaxNumSegments () const
{
    int numVertices = mVBuffer->GetNumElements();
    return mContiguous ? numVertices - 1 : numVertices/2;
}
//----------------------------------------------------------------------------
void Polysegment::SetNumSegments (int numSegments)
{
    int numVertices = mVBuffer->GetNumElements();
    if (mContiguous)
    {
        int numVerticesM1 = numVertices - 1;
        if (0 <= numSegments && numSegments <= numVerticesM1)
        {
            mNumSegments = numSegments;
        }
        else
        {
            mNumSegments = numVerticesM1;
        }
    }
    else
    {
        int numVerticesD2 = numVertices/2;
        if (0 <= numSegments && numSegments <= numVerticesD2)
        {
            mNumSegments = numSegments;
        }
        else
        {
            mNumSegments = numVerticesD2;
        }
    }
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Streaming support.
//----------------------------------------------------------------------------
Polysegment::Polysegment (LoadConstructor value)
    :
    Visual(value),
    mNumSegments(0),
    mContiguous(false)
{
}
//----------------------------------------------------------------------------
void Polysegment::Load (InStream& source)
{
    SHR_BEGIN_DEBUG_STREAM_LOAD(source);

    Visual::Load(source);

    source.Read(mNumSegments);
    source.ReadBool(mContiguous);

    SHR_END_DEBUG_STREAM_LOAD(Polysegment, source);
}
//----------------------------------------------------------------------------
void Polysegment::Link (InStream& source)
{
    Visual::Link(source);
}
//----------------------------------------------------------------------------
void Polysegment::PostLink ()
{
    Visual::PostLink();
}
//----------------------------------------------------------------------------
bool Polysegment::Register (OutStream& target) const
{
    return Visual::Register(target);
}
//----------------------------------------------------------------------------
void Polysegment::Save (OutStream& target) const
{
    SHR_BEGIN_DEBUG_STREAM_SAVE(target);

    Visual::Save(target);

    target.Write(mNumSegments);
    target.WriteBool(mContiguous);

    SHR_END_DEBUG_STREAM_SAVE(Polysegment, target);
}
//----------------------------------------------------------------------------
int Polysegment::GetStreamingSize () const
{
    int size = Visual::GetStreamingSize();
    size += sizeof(mNumSegments);
    size += SHR_BOOLSIZE(mContiguous);
    return size;
}
//----------------------------------------------------------------------------
