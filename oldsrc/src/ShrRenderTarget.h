#ifndef SHRRENDERTARGET_H
#define SHRRENDERTARGET_H

#include "ShrGraphicsLIB.h"
#include "ShrTexture2D.h"

namespace shr
{

class SHR_GRAPHICS_ITEM RenderTarget : public Object
{
    SHR_DECLARE_RTTI;
    SHR_DECLARE_NAMES;
    SHR_DECLARE_STREAM(RenderTarget);

public:
    // Construction and destruction.  The number of supported targets
    // depends on the graphics hardware and drivers.  'numTargets' must
    // be at least 1.
    RenderTarget (int numTargets, Texture::Format tformat, int width,
        int height, bool hasMipmaps, bool hasDepthStencil);

    virtual ~RenderTarget ();

    // Member access.
    inline int GetNumTargets () const;
    inline Texture::Format GetFormat () const;
    inline int GetWidth () const;
    inline int GetHeight () const;
    inline Texture2D* GetColorTexture (int i) const;
    inline Texture2D* GetDepthStencilTexture () const;
    inline bool HasMipmaps () const;
    inline bool HasDepthStencil () const;

protected:
    int mNumTargets;
    Texture2DPtr* mColorTextures;
    Texture2DPtr mDepthStencilTexture;
    bool mHasMipmaps;
};

SHR_REGISTER_STREAM(RenderTarget);
typedef Pointer0<RenderTarget> RenderTargetPtr;
#include "ShrRenderTarget.inl"

}

#endif