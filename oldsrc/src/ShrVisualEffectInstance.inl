//----------------------------------------------------------------------------
inline const VisualEffect* VisualEffectInstance::GetEffect () const
{
    return mEffect;
}
//----------------------------------------------------------------------------
inline int VisualEffectInstance::GetTechniqueIndex () const
{
    return mTechniqueIndex;
}
//----------------------------------------------------------------------------
inline int VisualEffectInstance::GetNumPasses () const
{
    return mEffect->GetTechnique(mTechniqueIndex)->GetNumPasses();
}
//----------------------------------------------------------------------------
