#ifndef SHRVISUALPASS_H
#define SHRVISUALPASS_H

#include "ShrGraphicsLIB.h"
#include "ShrVertexShader.h"
#include "ShrPixelShader.h"
#include "ShrAlphaState.h"
#include "ShrCullState.h"
#include "ShrDepthState.h"
#include "ShrOffsetState.h"
#include "ShrStencilState.h"
#include "ShrWireState.h"

namespace shr
{

class SHR_GRAPHICS_ITEM VisualPass : public Object
{
    SHR_DECLARE_RTTI;
    SHR_DECLARE_NAMES;
    SHR_DECLARE_STREAM(VisualPass);

public:
    // Construction and destruction.
    VisualPass ();
    virtual ~VisualPass ();

    // Support for deferred construction.
    inline void SetVertexShader (VertexShader* vshader);
    inline void SetPixelShader (PixelShader* pshader);
    inline void SetAlphaState (AlphaState* alphaState);
    inline void SetCullState (CullState* cullState);
    inline void SetDepthState (DepthState* depthState);
    inline void SetOffsetState (OffsetState* offsetState);
    inline void SetStencilState (StencilState* stencilState);
    inline void SetWireState (WireState* wireState);

    // Member access.
    inline VertexShader* GetVertexShader () const;
    inline PixelShader* GetPixelShader () const;
    inline AlphaState* GetAlphaState () const;
    inline CullState* GetCullState () const;
    inline DepthState* GetDepthState () const;
    inline OffsetState* GetOffsetState () const;
    inline StencilState* GetStencilState () const;
    inline WireState* GetWireState () const;

protected:
    VertexShaderPtr mVShader;
    PixelShaderPtr mPShader;
    AlphaStatePtr mAlphaState;
    CullStatePtr mCullState;
    DepthStatePtr mDepthState;
    OffsetStatePtr mOffsetState;
    StencilStatePtr mStencilState;
    WireStatePtr mWireState;
};

SHR_REGISTER_STREAM(VisualPass);
typedef Pointer0<VisualPass> VisualPassPtr;
#include "ShrVisualPass.inl"

}

#endif
