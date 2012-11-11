#ifndef SHRAPPRGAUSSPOINTSFIT2_H
#define SHRAPPRGAUSSPOINTSFIT2_H

#include "ShrMathematicsLIB.h"
#include "ShrBox2.h"

namespace shr
{

// Fit points with a Gaussian distribution.  The center is the mean of the
// points, the axes are the eigenvectors of the covariance matrix, and the
// extents are the eigenvalues of the covariance matrix and are returned in
// increasing order.  The quantites are stored in a Box2<Real> just to have a
// single container.
template <typename Real> SHR_MATHEMATICS_ITEM
Box2<Real> GaussPointsFit2 (int numPoints, const Vector2<Real>* points);

}

#endif
