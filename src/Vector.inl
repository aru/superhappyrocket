// Arithmetic operations.
inline Vector Vector::operator+ (const Vector& vec) const
{
	return Vector
    (
        mTuple[0] + vec.mTuple[0],
        mTuple[1] + vec.mTuple[1],
        mTuple[2] + vec.mTuple[2]
    );
}
inline Vector Vector:: operator- (const Vector& vec) const
{
	return Vector
    (
        mTuple[0] - vec.mTuple[0],
        mTuple[1] - vec.mTuple[1],
        mTuple[2] - vec.mTuple[2]
    );
}
inline Vector Vector:: operator* (float scalar) const
{
	return Vector
    (
        scalar*mTuple[0],
        scalar*mTuple[1],
        scalar*mTuple[2]
    );
}
inline Vector Vector:: operator/ (float scalar) const
{
	Vector result;

    if (scalar != (float)0)
    {
        float invScalar = ((float)1)/scalar;
        result.mTuple[0] = invScalar*mTuple[0];
        result.mTuple[1] = invScalar*mTuple[1];
        result.mTuple[2] = invScalar*mTuple[2];
    }
    else
    {
		result.mTuple[0] = FLT_MAX;
        result.mTuple[1] = FLT_MAX;
		result.mTuple[2] = FLT_MAX;
		
    }

    return result;
}
inline Vector Vector:: operator- () const
{
	return Vector
    (
        -mTuple[0],
        -mTuple[1],
        -mTuple[2]
    );
}

// Arithmetic updates.
inline Vector& Vector:: operator+= (const Vector& vec)
{
	mTuple[0] += vec.mTuple[0];
    mTuple[1] += vec.mTuple[1];
    mTuple[2] += vec.mTuple[2];
    return *this;
}
inline Vector& Vector:: operator-= (const Vector& vec)
{
	mTuple[0] -= vec.mTuple[0];
    mTuple[1] -= vec.mTuple[1];
    mTuple[2] -= vec.mTuple[2];
    return *this;
}
inline Vector& Vector:: operator*= (float scalar)
{
	mTuple[0] *= scalar;
    mTuple[1] *= scalar;
    mTuple[2] *= scalar;
    return *this;
}
inline Vector& Vector:: operator/= (float scalar)
{
	if (scalar != (float)0)
    {
        float invScalar = ((float)1)/scalar;
        mTuple[0] *= invScalar;
        mTuple[1] *= invScalar;
        mTuple[2] *= invScalar;
    }
    else
    {
        mTuple[0] *= FLT_MAX;
        mTuple[1] *= FLT_MAX;
        mTuple[2] *= FLT_MAX;
    }

    return *this;
}

// Vector operations.
inline float Vector::Length () const
{
	return std::sqrtf
    (
        mTuple[0]*mTuple[0] +
        mTuple[1]*mTuple[1] +
        mTuple[2]*mTuple[2]
    );
}
inline float Vector::SquaredLength () const
{
	return
        mTuple[0]*mTuple[0] +
        mTuple[1]*mTuple[1] +
        mTuple[2]*mTuple[2];
}
inline float Vector::Dot (const Vector& vec) const
{
	return
        mTuple[0]*vec.mTuple[0] +
        mTuple[1]*vec.mTuple[1] +
        mTuple[2]*vec.mTuple[2];
}
inline float Vector::Normalize ( const float epsilon )
{
	float length = Length();

    if (length > epsilon)
    {
        float invLength = ((float)1)/length;
        mTuple[0] *= invLength;
        mTuple[1] *= invLength;
        mTuple[2] *= invLength;
    }
    else
    {
        length = (float)0;
        mTuple[0] = (float)0;
        mTuple[1] = (float)0;
        mTuple[2] = (float)0;
    }

    return length;
}