#ifndef MATRIX3_H
#define MATRIX3_H

#include "Table.h"
#include "Vector3.h"

template <typename Real>
class Matrix3 : public Table<3,3,Real>
{
public:
	// If makeZero is true we create the zero matrix, else
	// we make the identity matrix
	Matrix3 (bool makeZero = true);

	// Copy constructor
	Matrix3 (const Matrix3& mat );

	// Direct input
	Matrix3 (Real m00, Real m01, Real m02,
			Real m10, Real m11, Real m12,
			Real m20, Real m21, Real m22 );

	// Create a matrix from an array of numbers.  The input array is
    // interpreted based on the bool input as
    //   true:  entry[0..8]={m00,m01,m02,m10,m11,m12,m20,m21,m22} [row major]
    //   false: entry[0..8]={m00,m10,m20,m01,m11,m21,m02,m12,m22} [col major]
    Matrix3 (const Real entry[9], bool rowMajor);

	// Create matrices based on vector input.  The bool is interpreted as
    //   true: vectors are columns of the matrix
    //   false: vectors are rows of the matrix
    Matrix3 (const Vector3<Real>& u, const Vector3<Real>& v,
        const Vector3<Real>& w, bool columns);
    Matrix3 (const Vector3<Real>* v, bool columns);

	// Create a diagonal matrix, m01 = m10 = m02 = m20 = m12 = m21 = 0.
    Matrix3 (Real m00, Real m11, Real m22);

	// Create rotation matrices (positive angle -> counterclockwise).  The
    // angle must be in radians, not degrees.
    Matrix3 (const Vector3<Real>& axis, Real angle);

	// Assignment.
    Matrix3& operator= (const Matrix3& mat);

	// Create various matrices.
    Matrix3& MakeZero ();
    Matrix3& MakeIdentity ();
    Matrix3& MakeDiagonal (Real m00, Real m11, Real m22);
    Matrix3& MakeRotation (const Vector3<Real>& axis, Real angle);

	// Arithmetic operations.
    Matrix3 operator+ (const Matrix3& mat) const;
    Matrix3 operator- (const Matrix3& mat) const;
    Matrix3 operator* (Real scalar) const;
    Matrix3 operator/ (Real scalar) const;
    Matrix3 operator- () const;

    // Arithmetic updates.
    Matrix3& operator+= (const Matrix3& mat);
    Matrix3& operator-= (const Matrix3& mat);
    Matrix3& operator*= (Real scalar);
    Matrix3& operator/= (Real scalar);

	//Insertion operator
	friend std::ostream& operator<<(std::ostream& os, const Matrix3& mat)
	{
		for (int i = 0; i < 3; i++)  
		{
			for (int j = 0; j < 3; j++)
			{
				os << mat(i,j) << " ";
			}
			os << std::endl;
		}
		os << std::endl;
		return os;
	}


    // M*vec
    Vector3<Real> operator* (const Vector3<Real>& vec) const;

    // u^T*M*v
    Real QForm (const Vector3<Real>& u, const Vector3<Real>& v) const;

    // M^T
    Matrix3 Transpose () const;

    // M*mat
    Matrix3 operator* (const Matrix3& mat) const;

    // M^T*mat
    Matrix3 TransposeTimes (const Matrix3& mat) const;

    // M*mat^T
    Matrix3 TimesTranspose (const Matrix3& mat) const;

    // M^T*mat^T
    Matrix3 TransposeTimesTranspose (const Matrix3& mat) const;

	// Other operations.
    Matrix3 TimesDiagonal (const Vector3<Real>& diag) const;  // M*D
    Matrix3 DiagonalTimes (const Vector3<Real>& diag) const;  // D*M
    Matrix3 Inverse (const Real epsilon = (Real)0) const;
    Matrix3 Adjoint () const;
    Real Determinant () const;

	// Special matrices.
    static const Matrix3 ZERO;
    static const Matrix3 IDENTITY;

protected:
    using Table<3,3,Real>::mEntry;
};

// c * M
template <typename Real>
inline Matrix3<Real> operator* (Real scalar, const Matrix3<Real>& mat);

// v^T * M
template <typename Real>
inline Vector3<Real> operator* (const Vector3<Real>& vec,
    const Matrix3<Real>& mat);

#include "Matrix3.inl"

typedef Matrix3<float> Matrix3f;
typedef Matrix3<double> Matrix3d;

template<> const Matrix3<float> Matrix3<float>::ZERO(true);
template<> const Matrix3<float> Matrix3<float>::IDENTITY(false);

template<> const Matrix3<double> Matrix3<double>::ZERO(true);
template<> const Matrix3<double> Matrix3<double>::IDENTITY(false);

#endif