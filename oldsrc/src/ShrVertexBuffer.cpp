#include "ShrGraphicsPCH.h"
#include "ShrVertexBuffer.h"
#include "ShrRenderer.h"
using namespace shr;

SHR_IMPLEMENT_RTTI(shr, Buffer, VertexBuffer);
SHR_IMPLEMENT_STREAM(VertexBuffer);
SHR_IMPLEMENT_FACTORY(VertexBuffer);
SHR_IMPLEMENT_DEFAULT_NAMES(Buffer, VertexBuffer);
SHR_IMPLEMENT_DEFAULT_STREAM(Buffer, VertexBuffer);

//----------------------------------------------------------------------------
VertexBuffer::VertexBuffer (int numVertices, int vertexSize, Usage usage)
    :
    Buffer(numVertices, vertexSize, usage)
{
}
//----------------------------------------------------------------------------
VertexBuffer::~VertexBuffer ()
{
    Renderer::UnbindAll(this);
}
//----------------------------------------------------------------------------
