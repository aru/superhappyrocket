#ifndef SHRPOLYPOINT_H
#define SHRPOLYPOINT_H

#include "ShrGraphicsLIB.h"
#include "ShrVisual.h"

namespace shr
{

class SHR_GRAPHICS_ITEM Polypoint : public Visual
{
    SHR_DECLARE_RTTI;
    SHR_DECLARE_NAMES;
    SHR_DECLARE_STREAM(Polypoint);

public:
    // Construction and destruction.
    Polypoint (VertexFormat* vformat, VertexBuffer* vbuffer);
    virtual ~Polypoint ();

    // Member access.  Allow the application to specify fewer than the maximum
    // number of point to draw.
    int GetMaxNumPoints () const;
    void SetNumPoints (int numPoints);
    inline int GetNumPoints () const;

protected:
    // The number of points currently active.
    int mNumPoints;
};

SHR_REGISTER_STREAM(Polypoint);
typedef Pointer0<Polypoint> PolypointPtr;
#include "ShrPolypoint.inl"

}

#endif
