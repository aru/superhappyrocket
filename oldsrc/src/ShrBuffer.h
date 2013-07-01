#ifndef SHRBUFFER_H
#define SHRBUFFER_H

#include "ShrGraphicsLIB.h"
#include "ShrObject.h"

namespace shr
{

class SHR_GRAPHICS_ITEM Buffer : public Object
{
    SHR_DECLARE_RTTI;
    SHR_DECLARE_NAMES;
    SHR_DECLARE_STREAM(Buffer);

public:
    // Usage flags for vertex buffers, index buffers, and textures.
    enum SHR_GRAPHICS_ITEM Usage
    {
        BU_STATIC,
        BU_DYNAMIC,
        BU_RENDERTARGET,
        BU_DEPTHSTENCIL,
        BU_TEXTURE,
        BU_QUANTITY
    };

    // Locking modes for accessing video memory for a buffer or texture.
    enum SHR_GRAPHICS_ITEM Locking
    {
        BL_READ_ONLY,
        BL_WRITE_ONLY,
        BL_READ_WRITE,
        BL_QUANTITY
    };

protected:
    // Abstract base class.  Construction and destruction.
    Buffer ();
    Buffer (int numElements, int elementSize, Usage usage);
public:
    virtual ~Buffer ();

    // Member access.
    inline int GetNumElements () const;
    inline int GetElementSize () const;
    inline Usage GetUsage () const;

    // An application might want to vary the active number of indices.  Use
    // this function to do so.  It does not change the data storage, only the
    // Buffer::mNumElements member.  The caller is responsible for saving the
    // original number of indices and resetting this when finished with the
    // index buffer.  The caller also should not pass in a number of indices
    // that is larger than the original number of indices.
    inline void SetNumElements (int numElements);

    // Manage a copy of the buffer in system memory.  Queries of the system
    // memory occur in IndexBuffer and VertexBuffer.  The GetData() accessor
    // should be for read-only data.  Do not typecast as "char*" and write,
    // otherwise the renderers will not know the data has been modified.
    inline int GetNumBytes () const;
    inline const char* GetData () const;

protected:
    int mNumElements;
    int mElementSize;
    Usage mUsage;
    int mNumBytes;
    char* mData;
};

SHR_REGISTER_STREAM(Buffer);
typedef Pointer0<Buffer> BufferPtr;
#include "ShrBuffer.inl"

}

#endif
