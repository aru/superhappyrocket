#ifndef MATRIX3_H
#define MATRIX3_H

#include "Table.h"
#include "Vector.h"

class Matrix3 : public Table<3,3,float>
{
	// If makeZero is true we create the zero matrix, else
	// we make the identity matrix
	Matrix3 (bool makeZero = true);

	// Copy constructor
	Matrix3 (const Matrix3& mat );

	// Direct input
	Matrix3 (float m00, float m01, float m02,
			float m10, float m11, float m12,
			float m20, float m21, float m22 );

	// Create a matrix from an array of numbers.  The input array is
    // interpreted based on the bool input as
    //   true:  entry[0..8]={m00,m01,m02,m10,m11,m12,m20,m21,m22} [row major]
    //   false: entry[0..8]={m00,m10,m20,m01,m11,m21,m02,m12,m22} [col major]
    Matrix3 (const float entry[9], bool rowMajor);

	// Create matrices based on vector input.  The bool is interpreted as
    //   true: vectors are columns of the matrix
    //   false: vectors are rows of the matrix
    Matrix3 (const Vector<float>& u, const Vector<float>& v,
        const Vector<float>& w, bool columns);
    Matrix3 (const Vector<float>* v, bool columns);

	// Create a diagonal matrix, m01 = m10 = m02 = m20 = m12 = m21 = 0.
    Matrix3 (float m00, float m11, float m22);

	// Create rotation matrices (positive angle -> counterclockwise).  The
    // angle must be in radians, not degrees.
    Matrix3 (const Vector<float>& axis, Real angle);

	~Matrix3 ();
};

#endif