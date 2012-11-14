#include "ShrGraphicsPCH.h"
#include "ShrBuffer.h"
using namespace shr;

SHR_IMPLEMENT_RTTI(shr, Object, Buffer);
SHR_IMPLEMENT_STREAM(Buffer);
SHR_IMPLEMENT_ABSTRACT_FACTORY(Buffer);
SHR_IMPLEMENT_DEFAULT_NAMES(Object, Buffer);

//----------------------------------------------------------------------------
Buffer::Buffer ()
    :
    mNumElements(0),
    mElementSize(0),
    mUsage(Buffer::BU_QUANTITY),
    mNumBytes(0),
    mData(0)
{
}
//----------------------------------------------------------------------------
Buffer::Buffer (int numElements, int elementSize, Usage usage)
    :
    mNumElements(numElements),
    mElementSize(elementSize),
    mUsage(usage),
    mNumBytes(numElements*elementSize)
{
    assertion(mNumElements > 0, "Number of elements must be positive\n");
    assertion(mElementSize > 0, "Element size must be positive\n");

    mData = new1<char>(mNumBytes);
}
//----------------------------------------------------------------------------
Buffer::~Buffer ()
{
    delete1(mData);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Streaming support.
//----------------------------------------------------------------------------
Buffer::Buffer (LoadConstructor value)
    :
    Object(value),
    mNumElements(0),
    mElementSize(0),
    mUsage(Buffer::BU_QUANTITY),
    mNumBytes(0),
    mData(0)
{
}
//----------------------------------------------------------------------------
void Buffer::Load (InStream& source)
{
    SHR_BEGIN_DEBUG_STREAM_LOAD(source);

    Object::Load(source);

    source.Read(mNumElements);
    source.Read(mElementSize);
    source.ReadEnum(mUsage);
    source.ReadRR(mNumBytes, mData);

    SHR_END_DEBUG_STREAM_LOAD(Buffer, source);
}
//----------------------------------------------------------------------------
void Buffer::Link (InStream& source)
{
    Object::Link(source);
}
//----------------------------------------------------------------------------
void Buffer::PostLink ()
{
    Object::PostLink();
}
//----------------------------------------------------------------------------
bool Buffer::Register (OutStream& target) const
{
    return Object::Register(target);
}
//----------------------------------------------------------------------------
void Buffer::Save (OutStream& target) const
{
    SHR_BEGIN_DEBUG_STREAM_SAVE(target);

    Object::Save(target);

    target.Write(mNumElements);
    target.Write(mElementSize);
    target.WriteEnum(mUsage);
    target.WriteW(mNumBytes, mData);

    SHR_END_DEBUG_STREAM_SAVE(Buffer, target);
}
//----------------------------------------------------------------------------
int Buffer::GetStreamingSize () const
{
    int size = Object::GetStreamingSize();
    size += sizeof(mNumElements);
    size += sizeof(mElementSize);
    size += SHR_ENUMSIZE(mUsage);
    size += sizeof(mNumBytes);
    size += mNumBytes*sizeof(mData[0]);
    return size;
}
//----------------------------------------------------------------------------
