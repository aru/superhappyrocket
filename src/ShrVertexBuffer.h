#ifndef SHRVERTEXBUFFER_H
#define SHRVERTEXBUFFER_H

#include "ShrGraphicsLIB.h"
#include "ShrBuffer.h"

namespace shr
{

class SHR_GRAPHICS_ITEM VertexBuffer : public Buffer
{
    SHR_DECLARE_RTTI;
    SHR_DECLARE_NAMES;
    SHR_DECLARE_STREAM(VertexBuffer);

public:
    // Construction and destruction.
    VertexBuffer (int numVertices, int vertexSize, Usage usage = BU_STATIC);
    virtual ~VertexBuffer ();

    // Access the buffer data.
    inline char* GetData () const;
};

SHR_REGISTER_STREAM(VertexBuffer);
typedef Pointer0<VertexBuffer> VertexBufferPtr;
#include "ShrVertexBuffer.inl"

}

#endif
