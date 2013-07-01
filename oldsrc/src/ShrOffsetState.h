#ifndef SHROFFSETSTATE_H
#define SHROFFSETSTATE_H

#include "ShrGraphicsLIB.h"
#include "ShrObject.h"

namespace shr
{

class SHR_GRAPHICS_ITEM OffsetState : public Object
{
    SHR_DECLARE_RTTI;
    SHR_DECLARE_NAMES;
    SHR_DECLARE_STREAM(OffsetState);

public:
    // Construction and destruction.
    OffsetState ();
    virtual ~OffsetState ();

    // Set whether offset should be enabled for the various polygon drawing
    // modes (fill, line, point).
    bool FillEnabled;   // default: false
    bool LineEnabled;   // default: false
    bool PointEnabled;  // default: false

    // The offset is Scale*dZ + Bias*r where dZ is the change in depth
    // relative to the screen space area of the poly, and r is the smallest
    // resolvable depth difference.  Negative values move polygons closer to
    // the eye.
    float Scale;  // default: 0
    float Bias;   // default: 0
};

SHR_REGISTER_STREAM(OffsetState);
typedef Pointer0<OffsetState> OffsetStatePtr;

}

#endif