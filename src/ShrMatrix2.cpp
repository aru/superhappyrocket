#include "ShrMathematicsPCH.h"
#include "ShrMatrix2.h"

namespace shr
{
template<> const Matrix2<float> Matrix2<float>::ZERO(true);
template<> const Matrix2<float> Matrix2<float>::IDENTITY(false);

template<> const Matrix2<double> Matrix2<double>::ZERO(true);
template<> const Matrix2<double> Matrix2<double>::IDENTITY(false);
}
