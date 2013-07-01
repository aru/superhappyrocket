
#include "ShrMathematicsPCH.h"
#include "ShrMatrix3.h"

namespace shr
{
template<> const Matrix3<float> Matrix3<float>::ZERO(true);
template<> const Matrix3<float> Matrix3<float>::IDENTITY(false);

template<> const Matrix3<double> Matrix3<double>::ZERO(true);
template<> const Matrix3<double> Matrix3<double>::IDENTITY(false);
}
