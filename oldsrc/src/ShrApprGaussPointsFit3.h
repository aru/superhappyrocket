#ifndef SHRAPPRGAUSSPOINTSFIT3_H
#define SHRAPPRGAUSSPOINTSFIT3_H

#include "ShrMathematicsLIB.h"
#include "ShrBox3.h"

namespace shr
{

// Fit points with a Gaussian distribution.  The center is the mean of the
// points, the axes are the eigenvectors of the covariance matrix, and the
// extents are the eigenvalues of the covariance matrix and are returned in
// increasing order.  The quantites are stored in a Box3<Real> just to have a
// single container.
template <typename Real> SHR_MATHEMATICS_ITEM
Box3<Real> GaussPointsFit3 (int numPoints, const Vector3<Real>* points);

}

#endif