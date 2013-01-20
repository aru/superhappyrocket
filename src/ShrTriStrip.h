#ifndef SHRTRISTRIP_H
#define SHRTRISTRIP_H

#include "ShrGraphicsLIB.h"
#include "ShrTriangles.h"

namespace shr
{

class SHR_GRAPHICS_ITEM TriStrip : public Triangles
{
    SHR_DECLARE_RTTI;
    SHR_DECLARE_NAMES;
    SHR_DECLARE_STREAM(TriStrip);

public:
    // Construction and destruction.
    TriStrip (VertexFormat* vformat, VertexBuffer* vbuffer, int indexSize);
    TriStrip (VertexFormat* vformat, VertexBuffer* vbuffer,
        IndexBuffer* ibuffer);

    virtual ~TriStrip ();

    // Interpretation of the index buffer data.
    virtual int GetNumTriangles () const;
    virtual bool GetTriangle (int i, int& v0, int& v1, int& v2) const;
};

SHR_REGISTER_STREAM(TriStrip);
typedef Pointer0<TriStrip> TriStripPtr;

}

#endif
