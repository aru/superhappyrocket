#include "ShrMathematicsPCH.h"
#include "ShrMatrix4.h"

namespace shr
{
template<> const Matrix4<float> Matrix4<float>::ZERO(true);
template<> const Matrix4<float> Matrix4<float>::IDENTITY(false);

template<> const Matrix4<double> Matrix4<double>::ZERO(true);
template<> const Matrix4<double> Matrix4<double>::IDENTITY(false);
}