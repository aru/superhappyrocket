#ifndef SHRCONTBOX3_H
#define SHRCONTBOX3_H

#include "ShrMathematicsLIB.h"
#include "ShrBox3.h"

namespace shr
{

// Compute the smallest axis-aligned bounding box of the points.
template <typename Real> SHR_MATHEMATICS_ITEM
Box3<Real> ContAlignedBox (int numPoints, const Vector3<Real>* points);

// Compute an oriented bounding box of the points.  The box center is the
// average of the points.  The box axes are the eigenvectors of the covariance
// matrix.
template <typename Real> SHR_MATHEMATICS_ITEM
Box3<Real> ContOrientedBox (int numPoints, const Vector3<Real>* points);

// Test for containment.  Let X = C + y0*U0 + y1*U1 + y2*U2 where C is the
// box center and U0, U1, U2 are the orthonormal axes of the box.  X is in
// the box if |y_i| <= E_i for all i where E_i are the extents of the box.
template <typename Real> SHR_MATHEMATICS_ITEM
bool InBox (const Vector3<Real>& point, const Box3<Real>& box);

// Construct an oriented box that contains two other oriented boxes.  The
// result is not guaranteed to be the minimum volume box containing the
// input boxes.
template <typename Real> SHR_MATHEMATICS_ITEM
Box3<Real> MergeBoxes (const Box3<Real>& box0, const Box3<Real>& box1);

}

#endif