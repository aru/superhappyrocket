//----------------------------------------------------------------------------
inline Float3::Float3 ()
{
}
//----------------------------------------------------------------------------
inline Float3::~Float3 ()
{
}
//----------------------------------------------------------------------------
inline Float3::Float3 (float f0, float f1, float f2)
{
    mTuple[0] = f0;
    mTuple[1] = f1;
    mTuple[2] = f2;
}
//----------------------------------------------------------------------------
inline Float3::Float3 (const Float3& tuple)
{
    mTuple[0] = tuple.mTuple[0];
    mTuple[1] = tuple.mTuple[1];
    mTuple[2] = tuple.mTuple[2];
}
//----------------------------------------------------------------------------
inline Float3& Float3::operator= (const Float3& tuple)
{
    mTuple[0] = tuple.mTuple[0];
    mTuple[1] = tuple.mTuple[1];
    mTuple[2] = tuple.mTuple[2];
    return *this;
}
//----------------------------------------------------------------------------