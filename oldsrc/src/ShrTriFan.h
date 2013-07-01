#ifndef SHRTRIFAN_H
#define SHRTRIFAN_H

#include "ShrGraphicsLIB.h"
#include "ShrTriangles.h"

namespace shr
{

class SHR_GRAPHICS_ITEM TriFan : public Triangles
{
    SHR_DECLARE_RTTI;
    SHR_DECLARE_NAMES;
    SHR_DECLARE_STREAM(TriFan);

public:
    // Construction and destruction.
    TriFan (VertexFormat* vformat, VertexBuffer* vbuffer, int indexSize);
    TriFan (VertexFormat* vformat, VertexBuffer* vbuffer,
        IndexBuffer* ibuffer);

    virtual ~TriFan ();

    // Interpretation of the index buffer data.
    virtual int GetNumTriangles () const;
    virtual bool GetTriangle (int i, int& v0, int& v1, int& v2) const;
};

SHR_REGISTER_STREAM(TriFan);
typedef Pointer0<TriFan> TriFanPtr;

}

#endif
