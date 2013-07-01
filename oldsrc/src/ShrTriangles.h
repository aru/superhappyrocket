#ifndef SHRTRIANGLES_H
#define SHRTRIANGLES_H

#include "ShrGraphicsLIB.h"
#include "ShrVisual.h"
#include "ShrFloat2.h"
#include "ShrAPoint.h"
#include "ShrVertexBufferAccessor.h"

namespace shr
{

class SHR_GRAPHICS_ITEM Triangles : public Visual
{
    SHR_DECLARE_RTTI;
    SHR_DECLARE_NAMES;
    SHR_DECLARE_STREAM(Triangles);

protected:
    // Abstract base class.  Construction and destruction.
    Triangles (PrimitiveType type = PT_TRIANGLES);
    Triangles (PrimitiveType type, VertexFormat* vformat,
        VertexBuffer* vbuffer, IndexBuffer* ibuffer);
public:
    virtual ~Triangles ();

    // These functions depend on the interpretation of the index buffer of
    // the triangle primitive.  The triangle <V0,V1,V2> is counterclockwise
    // order.  It is required that the vertex buffer have 3-tuple positions.
    virtual int GetNumTriangles () const = 0;
    virtual bool GetTriangle (int i, int& v0, int& v1, int& v2) const = 0;
    bool GetModelTriangle (int i, APoint* modelTriangle) const;
    bool GetWorldTriangle (int i, APoint* worldTriangle) const;

    // Support for bounding-tree-based collision detection.  The input index
    // 'v' must be contained in the index buffer.
    inline int GetNumVertices () const;
    inline const Transform& GetWorldTransform () const;
    Float3 GetPosition (int v) const;

    // Geometric updates.  See the comments in ShrVisual.h about the
    // input parameter.
    virtual void UpdateModelSpace (UpdateType type);

private:
    // Support for the geometric update.
    void UpdateModelNormals (VertexBufferAccessor& vba);

    // Specialized updates for the tangent space.
    void UpdateModelTangentsUseGeometry (VertexBufferAccessor& vba);
    void UpdateModelTangentsUseTCoords (VertexBufferAccessor& vba);

    // This function is used by UpdateUseTCoord to compute a tangent vector at
    // position0.  The triangle has positions position0, position1, and
    // position2, listed in counterclockwise order.  The corresponding texture
    // coordinates are tcoord0, tcoord1, and tcoord2, and are those associated
    // with the texture coordinate 'channel' that was passed to
    // UpdateUseTCoord.
    static AVector ComputeTangent (
        const APoint& position0, const Float2& tcoord0,
        const APoint& position1, const Float2& tcoord1,
        const APoint& position2, const Float2& tcoord2);
};

SHR_REGISTER_STREAM(Triangles);
typedef Pointer0<Triangles> TrianglesPtr;
#include "ShrTriangles.inl"

}

#endif
