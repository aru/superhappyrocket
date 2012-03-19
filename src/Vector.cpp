#include "Vector.h"

Vector::Vector()
{
}

Vector::Vector( float x, float y, float z )
{
	mTuple[0] = x;
	mTuple[1] = y;
	mTuple[2] = z;
}
Vector& Vector::operator=(const Vector& vec) 
{
	mTuple[0] = vec.mTuple[0];
	mTuple[1] = vec.mTuple[1];
	mTuple[2] = vec.mTuple[2];
	return *this;
}

Vector& Vector::operator=(const float* tuple)
{
	mTuple[0] = tuple[0];
	mTuple[1] = tuple[1];
	mTuple[2] = tuple[2];
	return *this;
}

Vector::~Vector()
{
}

// Special vectors
const Vector Vector::ZERO(0.0f, 0.0f, 0.0f);
const Vector Vector::UNIT_X(1.0f, 0.0f, 0.0f);
const Vector Vector::UNIT_Y(0.0f, 1.0f, 0.0f);
const Vector Vector::UNIT_Z(0.0f, 0.0f, 1.0f);
const Vector Vector::ONE(1.0f, 1.0f, 1.0f);