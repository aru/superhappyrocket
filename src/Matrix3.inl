// Geometric Tools, LLC
// Copyright (c) 1998-2011
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 5.0.1 (2010/10/15)

//----------------------------------------------------------------------------
template <typename Real>
Matrix3<Real>::Matrix3 (bool makeZero)
{
    if (makeZero)
    {
        MakeZero();
    }
    else
    {
        MakeIdentity();
    }
}
//----------------------------------------------------------------------------
template <typename Real>
Matrix3<Real>::Matrix3 (const Matrix3& mat)
{
    mEntry[0] = mat.mEntry[0];
    mEntry[1] = mat.mEntry[1];
    mEntry[2] = mat.mEntry[2];
    mEntry[3] = mat.mEntry[3];
    mEntry[4] = mat.mEntry[4];
    mEntry[5] = mat.mEntry[5];
    mEntry[6] = mat.mEntry[6];
    mEntry[7] = mat.mEntry[7];
    mEntry[8] = mat.mEntry[8];
}
//----------------------------------------------------------------------------
template <typename Real>
Matrix3<Real>::Matrix3 (Real m00, Real m01, Real m02, Real m10, Real m11,
    Real m12, Real m20, Real m21, Real m22)
{
    mEntry[0] = m00;
    mEntry[1] = m01;
    mEntry[2] = m02;
    mEntry[3] = m10;
    mEntry[4] = m11;
    mEntry[5] = m12;
    mEntry[6] = m20;
    mEntry[7] = m21;
    mEntry[8] = m22;
}
//----------------------------------------------------------------------------
template <typename Real>
Matrix3<Real>::Matrix3 (const Real entry[9], bool rowMajor)
{
    if (rowMajor)
    {
        mEntry[0] = entry[0];
        mEntry[1] = entry[1];
        mEntry[2] = entry[2];
        mEntry[3] = entry[3];
        mEntry[4] = entry[4];
        mEntry[5] = entry[5];
        mEntry[6] = entry[6];
        mEntry[7] = entry[7];
        mEntry[8] = entry[8];
    }
    else
    {
        mEntry[0] = entry[0];
        mEntry[1] = entry[3];
        mEntry[2] = entry[6];
        mEntry[3] = entry[1];
        mEntry[4] = entry[4];
        mEntry[5] = entry[7];
        mEntry[6] = entry[2];
        mEntry[7] = entry[5];
        mEntry[8] = entry[8];
    }
}
//----------------------------------------------------------------------------
template <typename Real>
Matrix3<Real>::Matrix3 (const Vector3<Real>& u, const Vector3<Real>& v,
    const Vector3<Real>& w, bool columns)
{
    if (columns)
    {
        mEntry[0] = u[0];
        mEntry[1] = v[0];
        mEntry[2] = w[0];
        mEntry[3] = u[1];
        mEntry[4] = v[1];
        mEntry[5] = w[1];
        mEntry[6] = u[2];
        mEntry[7] = v[2];
        mEntry[8] = w[2];
    }
    else
    {
        mEntry[0] = u[0];
        mEntry[1] = u[1];
        mEntry[2] = u[2];
        mEntry[3] = v[0];
        mEntry[4] = v[1];
        mEntry[5] = v[2];
        mEntry[6] = w[0];
        mEntry[7] = w[1];
        mEntry[8] = w[2];
    }
}
//----------------------------------------------------------------------------
template <typename Real>
Matrix3<Real>::Matrix3 (const Vector3<Real>* v, bool columns)
{
    if (columns)
    {
        mEntry[0] = v[0][0];
        mEntry[1] = v[1][0];
        mEntry[2] = v[2][0];
        mEntry[3] = v[0][1];
        mEntry[4] = v[1][1];
        mEntry[5] = v[2][1];
        mEntry[6] = v[0][2];
        mEntry[7] = v[1][2];
        mEntry[8] = v[2][2];
    }
    else
    {
        mEntry[0] = v[0][0];
        mEntry[1] = v[0][1];
        mEntry[2] = v[0][2];
        mEntry[3] = v[1][0];
        mEntry[4] = v[1][1];
        mEntry[5] = v[1][2];
        mEntry[6] = v[2][0];
        mEntry[7] = v[2][1];
        mEntry[8] = v[2][2];
    }
}
//----------------------------------------------------------------------------
template <typename Real>
Matrix3<Real>::Matrix3 (Real m00, Real m11, Real m22)
{
    MakeDiagonal(m00, m11, m22);
}
//----------------------------------------------------------------------------
template <typename Real>
Matrix3<Real>::Matrix3 (const Vector3<Real>& axis, Real angle)
{
    MakeRotation(axis, angle);
}
//----------------------------------------------------------------------------
template <typename Real>
Matrix3<Real>& Matrix3<Real>::operator= (const Matrix3& mat)
{
    mEntry[0] = mat.mEntry[0];
    mEntry[1] = mat.mEntry[1];
    mEntry[2] = mat.mEntry[2];
    mEntry[3] = mat.mEntry[3];
    mEntry[4] = mat.mEntry[4];
    mEntry[5] = mat.mEntry[5];
    mEntry[6] = mat.mEntry[6];
    mEntry[7] = mat.mEntry[7];
    mEntry[8] = mat.mEntry[8];
    return *this;
}
//----------------------------------------------------------------------------
template <typename Real>
Matrix3<Real>& Matrix3<Real>::MakeZero ()
{
    mEntry[0] = (Real)0;
    mEntry[1] = (Real)0;
    mEntry[2] = (Real)0;
    mEntry[3] = (Real)0;
    mEntry[4] = (Real)0;
    mEntry[5] = (Real)0;
    mEntry[6] = (Real)0;
    mEntry[7] = (Real)0;
    mEntry[8] = (Real)0;
    return *this;
}
//----------------------------------------------------------------------------
template <typename Real>
Matrix3<Real>& Matrix3<Real>::MakeIdentity ()
{
    mEntry[0] = (Real)1;
    mEntry[1] = (Real)0;
    mEntry[2] = (Real)0;
    mEntry[3] = (Real)0;
    mEntry[4] = (Real)1;
    mEntry[5] = (Real)0;
    mEntry[6] = (Real)0;
    mEntry[7] = (Real)0;
    mEntry[8] = (Real)1;
    return *this;
}
//----------------------------------------------------------------------------
template <typename Real>
Matrix3<Real>& Matrix3<Real>::MakeDiagonal (Real m00, Real m11, Real m22)
{
    mEntry[0] = m00;
    mEntry[1] = (Real)0;
    mEntry[2] = (Real)0;
    mEntry[3] = (Real)0;
    mEntry[4] = m11;
    mEntry[5] = (Real)0;
    mEntry[6] = (Real)0;
    mEntry[7] = (Real)0;
    mEntry[8] = m22;
    return *this;
}
//----------------------------------------------------------------------------
template <typename Real>
Matrix3<Real>& Matrix3<Real>::MakeRotation (const Vector3<Real>& axis,
    Real angle)
{
    Real cs = Math<Real>::Cos(angle);
    Real sn = Math<Real>::Sin(angle);
    Real oneMinusCos = ((Real)1) - cs;
    Real x2 = axis[0]*axis[0];
    Real y2 = axis[1]*axis[1];
    Real z2 = axis[2]*axis[2];
    Real xym = axis[0]*axis[1]*oneMinusCos;
    Real xzm = axis[0]*axis[2]*oneMinusCos;
    Real yzm = axis[1]*axis[2]*oneMinusCos;
    Real xSin = axis[0]*sn;
    Real ySin = axis[1]*sn;
    Real zSin = axis[2]*sn;
    
    mEntry[0] = x2*oneMinusCos + cs;
    mEntry[1] = xym - zSin;
    mEntry[2] = xzm + ySin;
    mEntry[3] = xym + zSin;
    mEntry[4] = y2*oneMinusCos + cs;
    mEntry[5] = yzm - xSin;
    mEntry[6] = xzm - ySin;
    mEntry[7] = yzm + xSin;
    mEntry[8] = z2*oneMinusCos + cs;
    return *this;
}
//----------------------------------------------------------------------------
template <typename Real>
Matrix3<Real> Matrix3<Real>::operator+ (const Matrix3& mat) const
{
    return Matrix3<Real>
    (
        mEntry[0] + mat.mEntry[0],
        mEntry[1] + mat.mEntry[1],
        mEntry[2] + mat.mEntry[2],
        mEntry[3] + mat.mEntry[3],
        mEntry[4] + mat.mEntry[4],
        mEntry[5] + mat.mEntry[5],
        mEntry[6] + mat.mEntry[6],
        mEntry[7] + mat.mEntry[7],
        mEntry[8] + mat.mEntry[8]
    );
}
//----------------------------------------------------------------------------
template <typename Real>
Matrix3<Real> Matrix3<Real>::operator- (const Matrix3& mat) const
{
    return Matrix3<Real>
    (
        mEntry[0] - mat.mEntry[0],
        mEntry[1] - mat.mEntry[1],
        mEntry[2] - mat.mEntry[2],
        mEntry[3] - mat.mEntry[3],
        mEntry[4] - mat.mEntry[4],
        mEntry[5] - mat.mEntry[5],
        mEntry[6] - mat.mEntry[6],
        mEntry[7] - mat.mEntry[7],
        mEntry[8] - mat.mEntry[8]
    );
}
//----------------------------------------------------------------------------
template <typename Real>
Matrix3<Real> Matrix3<Real>::operator* (Real scalar) const
{
    return Matrix3<Real>
    (
        scalar*mEntry[0],
        scalar*mEntry[1],
        scalar*mEntry[2],
        scalar*mEntry[3],
        scalar*mEntry[4],
        scalar*mEntry[5],
        scalar*mEntry[6],
        scalar*mEntry[7],
        scalar*mEntry[8]
    );
}
//----------------------------------------------------------------------------
template <typename Real>
Matrix3<Real> Matrix3<Real>::operator/ (Real scalar) const
{
    if (scalar != (Real)0)
    {
        Real invScalar = ((Real)1)/scalar;
        return Matrix3<Real>
        (
            invScalar*mEntry[0],
            invScalar*mEntry[1],
            invScalar*mEntry[2],
            invScalar*mEntry[3],
            invScalar*mEntry[4],
            invScalar*mEntry[5],
            invScalar*mEntry[6],
            invScalar*mEntry[7],
            invScalar*mEntry[8]
        );
    }
    else
    {
        return Matrix3<Real>
        (
            Math<Real>::MAX_REAL,
            Math<Real>::MAX_REAL,
            Math<Real>::MAX_REAL,
            Math<Real>::MAX_REAL,
            Math<Real>::MAX_REAL,
            Math<Real>::MAX_REAL,
            Math<Real>::MAX_REAL,
            Math<Real>::MAX_REAL,
            Math<Real>::MAX_REAL
        );
    }
}
//----------------------------------------------------------------------------
template <typename Real>
Matrix3<Real> Matrix3<Real>::operator- () const
{
    return Matrix3<Real>
    (
        -mEntry[0],
        -mEntry[1],
        -mEntry[2],
        -mEntry[3],
        -mEntry[4],
        -mEntry[5],
        -mEntry[6],
        -mEntry[7],
        -mEntry[8]
    );
}
//----------------------------------------------------------------------------
template <typename Real>
Matrix3<Real>& Matrix3<Real>::operator+= (const Matrix3& mat)
{
    mEntry[0] += mat.mEntry[0];
    mEntry[1] += mat.mEntry[1];
    mEntry[2] += mat.mEntry[2];
    mEntry[3] += mat.mEntry[3];
    mEntry[4] += mat.mEntry[4];
    mEntry[5] += mat.mEntry[5];
    mEntry[6] += mat.mEntry[6];
    mEntry[7] += mat.mEntry[7];
    mEntry[8] += mat.mEntry[8];
    return *this;
}
//----------------------------------------------------------------------------
template <typename Real>
Matrix3<Real>& Matrix3<Real>::operator-= (const Matrix3& mat)
{
    mEntry[0] -= mat.mEntry[0];
    mEntry[1] -= mat.mEntry[1];
    mEntry[2] -= mat.mEntry[2];
    mEntry[3] -= mat.mEntry[3];
    mEntry[4] -= mat.mEntry[4];
    mEntry[5] -= mat.mEntry[5];
    mEntry[6] -= mat.mEntry[6];
    mEntry[7] -= mat.mEntry[7];
    mEntry[8] -= mat.mEntry[8];
    return *this;
}
//----------------------------------------------------------------------------
template <typename Real>
Matrix3<Real>& Matrix3<Real>::operator*= (Real scalar)
{
    mEntry[0] *= scalar;
    mEntry[1] *= scalar;
    mEntry[2] *= scalar;
    mEntry[3] *= scalar;
    mEntry[4] *= scalar;
    mEntry[5] *= scalar;
    mEntry[6] *= scalar;
    mEntry[7] *= scalar;
    mEntry[8] *= scalar;
    return *this;
}
//----------------------------------------------------------------------------
template <typename Real>
Matrix3<Real>& Matrix3<Real>::operator/= (Real scalar)
{
    if (scalar != (Real)0)
    {
        Real invScalar = ((Real)1)/scalar;
        mEntry[0] *= invScalar;
        mEntry[1] *= invScalar;
        mEntry[2] *= invScalar;
        mEntry[3] *= invScalar;
        mEntry[4] *= invScalar;
        mEntry[5] *= invScalar;
        mEntry[6] *= invScalar;
        mEntry[7] *= invScalar;
        mEntry[8] *= invScalar;
    }
    else
    {
        mEntry[0] = Math<Real>::MAX_REAL;
        mEntry[1] = Math<Real>::MAX_REAL;
        mEntry[2] = Math<Real>::MAX_REAL;
        mEntry[3] = Math<Real>::MAX_REAL;
        mEntry[4] = Math<Real>::MAX_REAL;
        mEntry[5] = Math<Real>::MAX_REAL;
        mEntry[6] = Math<Real>::MAX_REAL;
        mEntry[7] = Math<Real>::MAX_REAL;
        mEntry[8] = Math<Real>::MAX_REAL;
    }

    return *this;
}
//----------------------------------------------------------------------------
template <typename Real>
Vector3<Real> Matrix3<Real>::operator* (const Vector3<Real>& vec) const
{
    return Vector3<Real>
    (
        mEntry[0]*vec[0] + mEntry[1]*vec[1] + mEntry[2]*vec[2],
        mEntry[3]*vec[0] + mEntry[4]*vec[1] + mEntry[5]*vec[2],
        mEntry[6]*vec[0] + mEntry[7]*vec[1] + mEntry[8]*vec[2]
    );
}
//----------------------------------------------------------------------------
template <typename Real>
Real Matrix3<Real>::QForm (const Vector3<Real>& u, const Vector3<Real>& v)
    const
{
    return u.Dot((*this)*v);
}
//----------------------------------------------------------------------------
template <typename Real>
Matrix3<Real> Matrix3<Real>::Transpose () const
{
    return Matrix3<Real>
    (
        mEntry[0],
        mEntry[3],
        mEntry[6],
        mEntry[1],
        mEntry[4],
        mEntry[7],
        mEntry[2],
        mEntry[5],
        mEntry[8]
    );
}
//----------------------------------------------------------------------------
template <typename Real>
Matrix3<Real> Matrix3<Real>::operator* (const Matrix3& mat) const
{
    // A*B
    return Matrix3<Real>
    (
        mEntry[0]*mat.mEntry[0] +
        mEntry[1]*mat.mEntry[3] +
        mEntry[2]*mat.mEntry[6],

        mEntry[0]*mat.mEntry[1] +
        mEntry[1]*mat.mEntry[4] +
        mEntry[2]*mat.mEntry[7],

        mEntry[0]*mat.mEntry[2] +
        mEntry[1]*mat.mEntry[5] +
        mEntry[2]*mat.mEntry[8],

        mEntry[3]*mat.mEntry[0] +
        mEntry[4]*mat.mEntry[3] +
        mEntry[5]*mat.mEntry[6],

        mEntry[3]*mat.mEntry[1] +
        mEntry[4]*mat.mEntry[4] +
        mEntry[5]*mat.mEntry[7],

        mEntry[3]*mat.mEntry[2] +
        mEntry[4]*mat.mEntry[5] +
        mEntry[5]*mat.mEntry[8],

        mEntry[6]*mat.mEntry[0] +
        mEntry[7]*mat.mEntry[3] +
        mEntry[8]*mat.mEntry[6],

        mEntry[6]*mat.mEntry[1] +
        mEntry[7]*mat.mEntry[4] +
        mEntry[8]*mat.mEntry[7],

        mEntry[6]*mat.mEntry[2] +
        mEntry[7]*mat.mEntry[5] +
        mEntry[8]*mat.mEntry[8]
    );
}
//----------------------------------------------------------------------------
template <typename Real>
Matrix3<Real> Matrix3<Real>::TransposeTimes (const Matrix3& mat) const
{
    // A^T*B
    return Matrix3<Real>
    (
        mEntry[0]*mat.mEntry[0] +
        mEntry[3]*mat.mEntry[3] +
        mEntry[6]*mat.mEntry[6],

        mEntry[0]*mat.mEntry[1] +
        mEntry[3]*mat.mEntry[4] +
        mEntry[6]*mat.mEntry[7],

        mEntry[0]*mat.mEntry[2] +
        mEntry[3]*mat.mEntry[5] +
        mEntry[6]*mat.mEntry[8],

        mEntry[1]*mat.mEntry[0] +
        mEntry[4]*mat.mEntry[3] +
        mEntry[7]*mat.mEntry[6],

        mEntry[1]*mat.mEntry[1] +
        mEntry[4]*mat.mEntry[4] +
        mEntry[7]*mat.mEntry[7],

        mEntry[1]*mat.mEntry[2] +
        mEntry[4]*mat.mEntry[5] +
        mEntry[7]*mat.mEntry[8],

        mEntry[2]*mat.mEntry[0] +
        mEntry[5]*mat.mEntry[3] +
        mEntry[8]*mat.mEntry[6],

        mEntry[2]*mat.mEntry[1] +
        mEntry[5]*mat.mEntry[4] +
        mEntry[8]*mat.mEntry[7],

        mEntry[2]*mat.mEntry[2] +
        mEntry[5]*mat.mEntry[5] +
        mEntry[8]*mat.mEntry[8]
    );
}
//----------------------------------------------------------------------------
template <typename Real>
Matrix3<Real> Matrix3<Real>::TimesTranspose (const Matrix3& mat) const
{
    // A*B^T
    return Matrix3<Real>
    (
        mEntry[0]*mat.mEntry[0] +
        mEntry[1]*mat.mEntry[1] +
        mEntry[2]*mat.mEntry[2],

        mEntry[0]*mat.mEntry[3] +
        mEntry[1]*mat.mEntry[4] +
        mEntry[2]*mat.mEntry[5],

        mEntry[0]*mat.mEntry[6] +
        mEntry[1]*mat.mEntry[7] +
        mEntry[2]*mat.mEntry[8],

        mEntry[3]*mat.mEntry[0] +
        mEntry[4]*mat.mEntry[1] +
        mEntry[5]*mat.mEntry[2],

        mEntry[3]*mat.mEntry[3] +
        mEntry[4]*mat.mEntry[4] +
        mEntry[5]*mat.mEntry[5],

        mEntry[3]*mat.mEntry[6] +
        mEntry[4]*mat.mEntry[7] +
        mEntry[5]*mat.mEntry[8],

        mEntry[6]*mat.mEntry[0] +
        mEntry[7]*mat.mEntry[1] +
        mEntry[8]*mat.mEntry[2],

        mEntry[6]*mat.mEntry[3] +
        mEntry[7]*mat.mEntry[4] +
        mEntry[8]*mat.mEntry[5],

        mEntry[6]*mat.mEntry[6] +
        mEntry[7]*mat.mEntry[7] +
        mEntry[8]*mat.mEntry[8]
    );
}
//----------------------------------------------------------------------------
template <typename Real>
Matrix3<Real> Matrix3<Real>::TransposeTimesTranspose (const Matrix3& mat)
    const
{
    // A^T*B^T
    return Matrix3<Real>
    (
        mEntry[0]*mat.mEntry[0] +
        mEntry[3]*mat.mEntry[1] +
        mEntry[6]*mat.mEntry[2],

        mEntry[0]*mat.mEntry[3] +
        mEntry[3]*mat.mEntry[4] +
        mEntry[6]*mat.mEntry[5],

        mEntry[0]*mat.mEntry[6] +
        mEntry[3]*mat.mEntry[7] +
        mEntry[6]*mat.mEntry[8],

        mEntry[1]*mat.mEntry[0] +
        mEntry[4]*mat.mEntry[1] +
        mEntry[7]*mat.mEntry[2],

        mEntry[1]*mat.mEntry[3] +
        mEntry[4]*mat.mEntry[4] +
        mEntry[7]*mat.mEntry[5],

        mEntry[1]*mat.mEntry[6] +
        mEntry[4]*mat.mEntry[7] +
        mEntry[7]*mat.mEntry[8],

        mEntry[2]*mat.mEntry[0] +
        mEntry[5]*mat.mEntry[1] +
        mEntry[8]*mat.mEntry[2],

        mEntry[2]*mat.mEntry[3] +
        mEntry[5]*mat.mEntry[4] +
        mEntry[8]*mat.mEntry[5],

        mEntry[2]*mat.mEntry[6] +
        mEntry[5]*mat.mEntry[7] +
        mEntry[8]*mat.mEntry[8]
    );
}
//----------------------------------------------------------------------------
template <typename Real>
Matrix3<Real> Matrix3<Real>::TimesDiagonal (const Vector3<Real>& diag) const
{
    return Matrix3<Real>
    (
        mEntry[0]*diag[0],
        mEntry[1]*diag[1],
        mEntry[2]*diag[2],
        mEntry[3]*diag[0],
        mEntry[4]*diag[1],
        mEntry[5]*diag[2],
        mEntry[6]*diag[0],
        mEntry[7]*diag[1],
        mEntry[8]*diag[2]
    );
}
//----------------------------------------------------------------------------
template <typename Real>
Matrix3<Real> Matrix3<Real>::DiagonalTimes (const Vector3<Real>& diag) const
{
    return Matrix3<Real>
    (
        diag[0]*mEntry[0],
        diag[0]*mEntry[1],
        diag[0]*mEntry[2],
        diag[1]*mEntry[3],
        diag[1]*mEntry[4],
        diag[1]*mEntry[5],
        diag[2]*mEntry[6],
        diag[2]*mEntry[7],
        diag[2]*mEntry[8]
    );
}
//----------------------------------------------------------------------------
template <typename Real>
Matrix3<Real> Matrix3<Real>::Inverse (const Real epsilon) const
{
    // Invert a 3x3 using cofactors.  This is faster than using a generic
    // Gaussian elimination because of the loop overhead of such a method.

    Matrix3 inverse;

    // Compute the adjoint.
    inverse.mEntry[0] = mEntry[4]*mEntry[8] - mEntry[5]*mEntry[7];
    inverse.mEntry[1] = mEntry[2]*mEntry[7] - mEntry[1]*mEntry[8];
    inverse.mEntry[2] = mEntry[1]*mEntry[5] - mEntry[2]*mEntry[4];
    inverse.mEntry[3] = mEntry[5]*mEntry[6] - mEntry[3]*mEntry[8];
    inverse.mEntry[4] = mEntry[0]*mEntry[8] - mEntry[2]*mEntry[6];
    inverse.mEntry[5] = mEntry[2]*mEntry[3] - mEntry[0]*mEntry[5];
    inverse.mEntry[6] = mEntry[3]*mEntry[7] - mEntry[4]*mEntry[6];
    inverse.mEntry[7] = mEntry[1]*mEntry[6] - mEntry[0]*mEntry[7];
    inverse.mEntry[8] = mEntry[0]*mEntry[4] - mEntry[1]*mEntry[3];

    Real det = mEntry[0]*inverse.mEntry[0] + mEntry[1]*inverse.mEntry[3] +
        mEntry[2]*inverse.mEntry[6];

    if (Math<Real>::FAbs(det) > epsilon)
    {
        Real invDet = ((Real)1)/det;
        inverse.mEntry[0] *= invDet;
        inverse.mEntry[1] *= invDet;
        inverse.mEntry[2] *= invDet;
        inverse.mEntry[3] *= invDet;
        inverse.mEntry[4] *= invDet;
        inverse.mEntry[5] *= invDet;
        inverse.mEntry[6] *= invDet;
        inverse.mEntry[7] *= invDet;
        inverse.mEntry[8] *= invDet;
        return inverse;
    }

    return ZERO;
}
//----------------------------------------------------------------------------
template <typename Real>
Matrix3<Real> Matrix3<Real>::Adjoint () const
{
    return Matrix3<Real>
    (
        mEntry[4]*mEntry[8] - mEntry[5]*mEntry[7],
        mEntry[2]*mEntry[7] - mEntry[1]*mEntry[8],
        mEntry[1]*mEntry[5] - mEntry[2]*mEntry[4],
        mEntry[5]*mEntry[6] - mEntry[3]*mEntry[8],
        mEntry[0]*mEntry[8] - mEntry[2]*mEntry[6],
        mEntry[2]*mEntry[3] - mEntry[0]*mEntry[5],
        mEntry[3]*mEntry[7] - mEntry[4]*mEntry[6],
        mEntry[1]*mEntry[6] - mEntry[0]*mEntry[7],
        mEntry[0]*mEntry[4] - mEntry[1]*mEntry[3]
    );
}
//----------------------------------------------------------------------------
template <typename Real>
Real Matrix3<Real>::Determinant () const
{
    Real co00 = mEntry[4]*mEntry[8] - mEntry[5]*mEntry[7];
    Real co10 = mEntry[5]*mEntry[6] - mEntry[3]*mEntry[8];
    Real co20 = mEntry[3]*mEntry[7] - mEntry[4]*mEntry[6];
    Real det = mEntry[0]*co00 + mEntry[1]*co10 + mEntry[2]*co20;
    return det;
}
//----------------------------------------------------------------------------
template <typename Real>
inline Matrix3<Real> operator* (Real scalar, const Matrix3<Real>& mat)
{
    return mat*scalar;
}
//----------------------------------------------------------------------------
template <typename Real>
inline Vector3<Real> operator* (const Vector3<Real>& vec,
    const Matrix3<Real>& mat)
{
    return Vector3<Real>
    (
        vec[0]*mat[0][0] + vec[1]*mat[1][0] + vec[2]*mat[2][0],
        vec[0]*mat[0][1] + vec[1]*mat[1][1] + vec[2]*mat[2][1],
        vec[0]*mat[0][2] + vec[1]*mat[1][2] + vec[2]*mat[2][2]
    );
}
//----------------------------------------------------------------------------
