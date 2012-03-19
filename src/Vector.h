#ifndef VECTOR_H
#define VECTOR_H

#include "GlExtensions.h"
#include "Core.h"
#include "CoreLIB.h"

class Vector
{
public: 
	// Constructor
	Vector();
	Vector(const Vector& vec);
    Vector(float x, float y, float z);

	// Destructor
	~Vector();

	/* Mathy operations go here:
     * that is all */

	// Assignment, both for deep copies and arrays
    Vector& operator= (const Vector& vec);
	Vector& operator= (const float* tup);

	// Arithmetic operations.
    inline Vector operator+ (const Vector& vec) const;
    inline Vector operator- (const Vector& vec) const;
    inline Vector operator* (float scalar) const;
    inline Vector operator/ (float scalar) const;
    inline Vector operator- () const;

    // Arithmetic updates.
    inline Vector& operator+= (const Vector& vec);
    inline Vector& operator-= (const Vector& vec);
    inline Vector& operator*= (float scalar);
    inline Vector& operator/= (float scalar);

    // Vector operations.
    inline float Length () const;
    inline float SquaredLength () const;
    inline float Dot (const Vector& vec) const;
    inline float Normalize ( const float epsilon = FLT_MIN );

	// Special vectors
	static const Vector ZERO;    // (0,0,0)
    static const Vector UNIT_X;  // (1,0,0)
    static const Vector UNIT_Y;  // (0,1,0)
    static const Vector UNIT_Z;  // (0,0,1)
    static const Vector ONE;     // (1,1,1)

	// Data
	float mTuple[3];
};

#include "Vector.inl"

#endif