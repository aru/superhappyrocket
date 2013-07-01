#ifndef SHRVECTOR4_H
#define SHRVECTOR4_H

#include "ShrMathematicsLIB.h"
#include "ShrTuple.h"
#include "ShrMath.h"

namespace shr
{

template <typename Real>
class Vector4 : public Tuple<4,Real>
{
public:
    // Construction.
    Vector4 ();  // uninitialized
    Vector4 (const Vector4& vec);
    Vector4 (const Tuple<4,Real>& tuple);
    Vector4 (Real x, Real y, Real z, Real w);

    // Assignment.
    Vector4& operator= (const Vector4& vec);
    Vector4& operator= (const Tuple<4,Real>& tuple);

    // Coordinate access.
    inline Real X () const;
    inline Real& X ();
    inline Real Y () const;
    inline Real& Y ();
    inline Real Z () const;
    inline Real& Z ();
    inline Real W () const;
    inline Real& W ();

    // Arithmetic operations.
    inline Vector4 operator+ (const Vector4& vec) const;
    inline Vector4 operator- (const Vector4& vec) const;
    inline Vector4 operator* (Real scalar) const;
    inline Vector4 operator/ (Real scalar) const;
    inline Vector4 operator- () const;

    // Arithmetic updates.
    inline Vector4& operator+= (const Vector4& vec);
    inline Vector4& operator-= (const Vector4& vec);
    inline Vector4& operator*= (Real scalar);
    inline Vector4& operator/= (Real scalar);

    // Vector operations.
    inline Real Length () const;
    inline Real SquaredLength () const;
    inline Real Dot (const Vector4& vec) const;
    inline Real Normalize (const Real epsilon = Math<Real>::ZERO_TOLERANCE);

    // Compute the axis-aligned bounding box of the points.
    static void ComputeExtremes (int numVectors, const Vector4* vectors,
        Vector4& vmin, Vector4& vmax);

    // Special vectors.
    SHR_MATHEMATICS_ITEM static const Vector4 ZERO;
    SHR_MATHEMATICS_ITEM static const Vector4 UNIT_X;  // (1,0,0,0)
    SHR_MATHEMATICS_ITEM static const Vector4 UNIT_Y;  // (0,1,0,0)
    SHR_MATHEMATICS_ITEM static const Vector4 UNIT_Z;  // (0,0,1,0)
    SHR_MATHEMATICS_ITEM static const Vector4 UNIT_W;  // (0,0,0,1)
    SHR_MATHEMATICS_ITEM static const Vector4 ONE;     // (1,1,1,1)

protected:
    using Tuple<4,Real>::mTuple;
};

// Arithmetic operations.
template <typename Real>
inline Vector4<Real> operator* (Real scalar, const Vector4<Real>& vec);

// debugging output
template <typename Real>
std::ostream& operator<< (std::ostream& outFile, const Vector4<Real>& vec);

#include "ShrVector4.inl"

typedef Vector4<float> Vector4f;
typedef Vector4<double> Vector4d;

}

#endif
