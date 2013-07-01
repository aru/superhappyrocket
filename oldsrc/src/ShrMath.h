#ifndef SHRMATH_H
#define SHRMATH_H

#include "ShrMathematicsLIB.h"
#include "ShrAssert.h"
#include <cfloat>
#include <cmath>
#include <cstdlib>


namespace shr
{

template <typename Real>
class Math
{
public:
    // Wrappers to hide implementations of functions.  The ACos and ASin
    // functions clamp the input argument to [-1,1] to avoid NaN issues
    // when the input is slightly larger than 1 or slightly smaller than -1.
    // Other functions have the potential for using a fast and approximate
    // algorithm rather than calling the standard math library functions.
    static Real ACos (Real value);
    static Real ASin (Real value);
    static Real ATan (Real value);
    static Real ATan2 (Real y, Real x);
    static Real Ceil (Real value);
    static Real Cos (Real value);
    static Real Exp (Real value);
    static Real FAbs (Real value);
    static Real Floor (Real value);
    static Real FMod (Real x, Real y);
    static Real InvSqrt (Real value);
    static Real Log (Real value);
    static Real Log2 (Real value);
    static Real Log10 (Real value);
    static Real Pow (Real base, Real exponent);
    static Real Sin (Real value);
    static Real Sqr (Real value);
    static Real Sqrt (Real value);
    static Real Tan (Real value);

	// Return -1 if the input is negative, 0 if the input is zero, and +1
    // if the input is positive.
    static int Sign (int value);
    static Real Sign (Real value);


    // Common constants.
    SHR_MATHEMATICS_ITEM static const Real EPSILON;
    SHR_MATHEMATICS_ITEM static const Real ZERO_TOLERANCE;
    SHR_MATHEMATICS_ITEM static const Real MAX_REAL;
    SHR_MATHEMATICS_ITEM static const Real PI;
    SHR_MATHEMATICS_ITEM static const Real TWO_PI;
    SHR_MATHEMATICS_ITEM static const Real HALF_PI;
    SHR_MATHEMATICS_ITEM static const Real INV_PI;
    SHR_MATHEMATICS_ITEM static const Real INV_TWO_PI;
    SHR_MATHEMATICS_ITEM static const Real DEG_TO_RAD;
    SHR_MATHEMATICS_ITEM static const Real RAD_TO_DEG;
    SHR_MATHEMATICS_ITEM static const Real LN_2;
    SHR_MATHEMATICS_ITEM static const Real LN_10;
    SHR_MATHEMATICS_ITEM static const Real INV_LN_2;
    SHR_MATHEMATICS_ITEM static const Real INV_LN_10;
    SHR_MATHEMATICS_ITEM static const Real SQRT_2;
    SHR_MATHEMATICS_ITEM static const Real INV_SQRT_2;
    SHR_MATHEMATICS_ITEM static const Real SQRT_3;
    SHR_MATHEMATICS_ITEM static const Real INV_SQRT_3;
};

#include "ShrMath.inl"

typedef Math<float> Mathf;
typedef Math<double> Mathd;

}

#endif
