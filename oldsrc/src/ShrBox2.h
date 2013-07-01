#ifndef SHRBOX2_H
#define SHRBOX2_H

#include "ShrMathematicsLIB.h"
#include "ShrVector2.h"

namespace shr
{

template <typename Real>
class Box2
{
public:
    // A box has center C, axis directions U[0] and U[1] (perpendicular and
    // unit-length vectors), and extents e[0] and e[1] (nonnegative numbers).
    // A/ point X = C+y[0]*U[0]+y[1]*U[1] is inside or on the box whenever
    // |y[i]| <= e[i] for all i.

    // Construction and destruction.
    Box2 ();  // uninitialized
    ~Box2 ();

    Box2 (const Vector2<Real>& center, const Vector2<Real> axis[2],
        const Real extent[2]);

    Box2 (const Vector2<Real>& center, const Vector2<Real>& axis0,
        const Vector2<Real>& axis1, const Real extent0, const Real extent1);

    void ComputeVertices (Vector2<Real> vertex[4]) const;

    Vector2<Real> Center;
    Vector2<Real> Axis[2];
    Real Extent[2];
};

#include "ShrBox2.inl"

typedef Box2<float> Box2f;
typedef Box2<double> Box2d;

}

#endif