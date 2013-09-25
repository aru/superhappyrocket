#include "shr3DVector.h"

shr3DVector::shr3DVector()
	:x(0),y(0),z(0)
{
}

shr3DVector::shr3DVector( float x, float y, float z )
{
	this->x = x;
	this->y = y;
	this->z = z;
}

shr3DVector::shr3DVector( const shr3DVector& vector )
{
	this->x = vector.x;
	this->y = vector.y;
	this->z = vector.z;
}

shr3DVector& shr3DVector::operator=( const shr3DVector rhs )
{
	if( this != &rhs )
	{
		this->x = rhs.x;
		this->y = rhs.y;
		this->z = rhs.z;
	}
	return *this;
}

shr3DVector& shr3DVector::operator=( const shr3DVector* rhs )
{
	if( this != rhs )
	{
		this->x = rhs->x;
		this->y = rhs->y;
		this->z = rhs->z;
	}
	return *this;
}

bool shr3DVector::operator==( const shr3DVector rhs )
{
	const  float e = 0.00001f;

	if( ( fabs(this->x - rhs.x) < e ) &&
		( fabs(this->y - rhs.y) < e ) &&
		( fabs(this->z - rhs.z) < e ) )
		return true;
	else
		return false;
}

bool shr3DVector::operator!=( const shr3DVector rhs )
{
	return !(*this == rhs);
}

shr3DVector::~shr3DVector()
{
}