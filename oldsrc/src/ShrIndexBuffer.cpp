#include "ShrGraphicsPCH.h"
#include "ShrIndexBuffer.h"
#include "ShrRenderer.h"
using namespace shr;

SHR_IMPLEMENT_RTTI(shr, Buffer, IndexBuffer);
SHR_IMPLEMENT_STREAM(IndexBuffer);
SHR_IMPLEMENT_FACTORY(IndexBuffer);
SHR_IMPLEMENT_DEFAULT_NAMES(Buffer, IndexBuffer);

//----------------------------------------------------------------------------
IndexBuffer::IndexBuffer (int numIndices, int indexSize, Usage usage)
    :
    Buffer(numIndices, indexSize, usage),
    mOffset(0)
{
}
//----------------------------------------------------------------------------
IndexBuffer::~IndexBuffer ()
{
    Renderer::UnbindAll(this);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Streaming support.
//----------------------------------------------------------------------------
IndexBuffer::IndexBuffer (LoadConstructor value)
    :
    Buffer(value),
    mOffset(0)
{
}
//----------------------------------------------------------------------------
void IndexBuffer::Load (InStream& source)
{
    SHR_BEGIN_DEBUG_STREAM_LOAD(source);

    Buffer::Load(source);

    source.Read(mOffset);

    SHR_END_DEBUG_STREAM_LOAD(IndexBuffer, source);
}
//----------------------------------------------------------------------------
void IndexBuffer::Link (InStream& source)
{
    Buffer::Link(source);
}
//----------------------------------------------------------------------------
void IndexBuffer::PostLink ()
{
    Buffer::PostLink();
}
//----------------------------------------------------------------------------
bool IndexBuffer::Register (OutStream& target) const
{
    return Buffer::Register(target);
}
//----------------------------------------------------------------------------
void IndexBuffer::Save (OutStream& target) const
{
    SHR_BEGIN_DEBUG_STREAM_SAVE(target);

    Buffer::Save(target);

    target.Write(mOffset);

    SHR_END_DEBUG_STREAM_SAVE(IndexBuffer, target);
}
//----------------------------------------------------------------------------
int IndexBuffer::GetStreamingSize () const
{
    int size = Buffer::GetStreamingSize();
    size += sizeof(mOffset);
    return size;
}
//----------------------------------------------------------------------------
