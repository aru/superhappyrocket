//----------------------------------------------------------------------------
inline int VisibleSet::GetNumVisible () const
{
    return mNumVisible;
}
//----------------------------------------------------------------------------
inline const std::vector<Spatial*>& VisibleSet::GetAllVisible () const
{
    return mVisible;
}
//----------------------------------------------------------------------------
inline Spatial* VisibleSet::GetVisible (int i) const
{
    assertion(0 <= i && i < mNumVisible, "Invalid index to GetVisible\n");
    return mVisible[i];
}
//----------------------------------------------------------------------------
inline void VisibleSet::Clear ()
{
    mNumVisible = 0;
}
//----------------------------------------------------------------------------
