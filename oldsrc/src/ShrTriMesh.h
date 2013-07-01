#ifndef SHRTRIMESH_H
#define SHRTRIMESH_H

#include "ShrGraphicsLIB.h"
#include "ShrTriangles.h"

namespace shr
{

class SHR_GRAPHICS_ITEM TriMesh : public Triangles
{
    SHR_DECLARE_RTTI;
    SHR_DECLARE_NAMES;
    SHR_DECLARE_STREAM(TriMesh);

protected:
    // Default construction for derived classes.
    TriMesh ();
public:
    // Construction and destruction.
    TriMesh (VertexFormat* vformat, VertexBuffer* vbuffer,
        IndexBuffer* ibuffer);

    virtual ~TriMesh ();

    // Interpretation of the index buffer data.
    virtual int GetNumTriangles () const;
    virtual bool GetTriangle (int i, int& v0, int& v1, int& v2) const;
};

SHR_REGISTER_STREAM(TriMesh);
typedef Pointer0<TriMesh> TriMeshPtr;

}

#endif
