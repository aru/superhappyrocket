#ifndef SHRBOX3_H
#define SHRBOX3_H

#include "ShrMathematicsLIB.h"
#include "ShrVector3.h"

namespace shr
{

template <typename Real>
class Box3
{
public:
    // A box has center C, axis directions U[0], U[1], and U[2] (mutually
    // perpendicular unit-length vectors), and extents e[0], e[1], and e[2]
    // (all nonnegative numbers).  A point X = C+y[0]*U[0]+y[1]*U[1]+y[2]*U[2]
    // is inside or on the box whenever |y[i]| <= e[i] for all i.

    // Construction and destruction.
    Box3 ();  // uninitialized
    ~Box3 ();

    Box3 (const Vector3<Real>& center, const Vector3<Real> axis[3],
        const Real extent[3]);

    Box3 (const Vector3<Real>& center, const Vector3<Real>& axis0,
        const Vector3<Real>& axis1, const Vector3<Real>& axis2,
        const Real extent0, const Real extent1, const Real extent2);

    void ComputeVertices (Vector3<Real> vertex[8]) const;

    Vector3<Real> Center;
    Vector3<Real> Axis[3];
    Real Extent[3];
};

#include "ShrBox3.inl"

typedef Box3<float> Box3f;
typedef Box3<double> Box3d;

}

#endif
