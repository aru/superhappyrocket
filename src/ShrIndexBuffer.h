#ifndef SHRINDEXBUFFER_H
#define SHRINDEXBUFFER_H

#include "ShrGraphicsLIB.h"
#include "ShrBuffer.h"

namespace shr
{

class SHR_GRAPHICS_ITEM IndexBuffer : public Buffer
{
    SHR_DECLARE_RTTI;
    SHR_DECLARE_NAMES;
    SHR_DECLARE_STREAM(IndexBuffer);

public:
    // Construction and destruction.
    IndexBuffer (int numIndices, int indexSize, Usage usage = BU_STATIC);
    virtual ~IndexBuffer ();

    // Access the buffer data.
    inline char* GetData () const;

    // The offset into the indices is used by the renderer for drawing.  The
    // ability to set this is useful when multiple geometric primitives share
    // an index buffer, each primitive using a continguous set of indices.  In
    // this case, SetNumElements and SetOffset will be called dynamically by
    // the application for each such geometric primitive.
    inline void SetOffset (int offset);
    inline int GetOffset () const;

protected:
    int mOffset;
};

SHR_REGISTER_STREAM(IndexBuffer);
typedef Pointer0<IndexBuffer> IndexBufferPtr;
#include "ShrIndexBuffer.inl"

}

#endif