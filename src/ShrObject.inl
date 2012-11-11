//----------------------------------------------------------------------------
// Static and dynamic typecasting.
//----------------------------------------------------------------------------
template <class T>
T* StaticCast (Object* object)
{
    return (T*)object;
}
//----------------------------------------------------------------------------
template <class T>
const T* StaticCast (const Object* object)
{
    return (const T*)object;
}
//----------------------------------------------------------------------------
template <class T>
T* DynamicCast (Object* object)
{
    return object && object->IsDerived(T::TYPE) ? (T*)object : 0;
}
//----------------------------------------------------------------------------
template <class T>
const T* DynamicCast (const Object* object)
{
    return object && object->IsDerived(T::TYPE) ? (const T*)object : 0;
}
//----------------------------------------------------------------------------