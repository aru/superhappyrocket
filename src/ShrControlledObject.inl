//----------------------------------------------------------------------------
inline int ControlledObject::GetNumControllers () const
{
    return mNumControllers;
}
//----------------------------------------------------------------------------
inline Controller* ControlledObject::GetController (int i) const
{
    if (0 <= i && i < mNumControllers)
    {
        return mControllers[i];
    }

    assertion(false, "Invalid index in GetController.\n");
    return 0;
}
//----------------------------------------------------------------------------
