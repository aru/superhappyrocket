//----------------------------------------------------------------------------
inline void VisualPass::SetVertexShader (VertexShader* vshader)
{
    mVShader = vshader;
}
//----------------------------------------------------------------------------
inline void VisualPass::SetPixelShader (PixelShader* pshader)
{
    mPShader = pshader;
}
//----------------------------------------------------------------------------
inline void VisualPass::SetAlphaState (AlphaState* alphaState)
{
    mAlphaState = alphaState;
}
//----------------------------------------------------------------------------
inline void VisualPass::SetCullState (CullState* cullState)
{
    mCullState = cullState;
}
//----------------------------------------------------------------------------
inline void VisualPass::SetDepthState (DepthState* depthState)
{
    mDepthState = depthState;
}
//----------------------------------------------------------------------------
inline void VisualPass::SetOffsetState (OffsetState* offsetState)
{
    mOffsetState = offsetState;
}
//----------------------------------------------------------------------------
inline void VisualPass::SetStencilState (StencilState* stencilState)
{
    mStencilState = stencilState;
}
//----------------------------------------------------------------------------
inline void VisualPass::SetWireState (WireState* wireState)
{
    mWireState = wireState;
}
//----------------------------------------------------------------------------
inline VertexShader* VisualPass::GetVertexShader () const
{
    return mVShader;
}
//----------------------------------------------------------------------------
inline PixelShader* VisualPass::GetPixelShader () const
{
    return mPShader;
}
//----------------------------------------------------------------------------
inline AlphaState* VisualPass::GetAlphaState () const
{
    return mAlphaState;
}
//----------------------------------------------------------------------------
inline CullState* VisualPass::GetCullState () const
{
    return mCullState;
}
//----------------------------------------------------------------------------
inline DepthState* VisualPass::GetDepthState () const
{
    return mDepthState;
}
//----------------------------------------------------------------------------
inline OffsetState* VisualPass::GetOffsetState () const
{
    return mOffsetState;
}
//----------------------------------------------------------------------------
inline StencilState* VisualPass::GetStencilState () const
{
    return mStencilState;
}
//----------------------------------------------------------------------------
inline WireState* VisualPass::GetWireState () const
{
    return mWireState;
}
//----------------------------------------------------------------------------
