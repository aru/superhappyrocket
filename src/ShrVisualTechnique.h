#ifndef SHRVISUALTECHNIQUE_H
#define SHRVISUALTECHNIQUE_H

#include "ShrGraphicsLIB.h"
#include "ShrVisualPass.h"

namespace shr
{

class SHR_GRAPHICS_ITEM VisualTechnique : public Object
{
    SHR_DECLARE_RTTI;
    SHR_DECLARE_NAMES;
    SHR_DECLARE_STREAM(VisualTechnique);

public:
    // Construction and destruction.
    VisualTechnique ();
    virtual ~VisualTechnique ();

    // Support for deferred creation.  The function appends the new pass to
    // the end of the array.
    void InsertPass (VisualPass* pass);

    // Member access.
    inline int GetNumPasses () const;
    VisualPass* GetPass (int passIndex) const;

    // Access to components of the pass.
    VertexShader* GetVertexShader (int passIndex) const;
    PixelShader* GetPixelShader (int passIndex) const;
    AlphaState* GetAlphaState (int passIndex) const;
    CullState* GetCullState (int passIndex) const;
    DepthState* GetDepthState (int passIndex) const;
    OffsetState* GetOffsetState (int passIndex) const;
    StencilState* GetStencilState (int passIndex) const;
    WireState* GetWireState (int passIndex) const;

protected:
    std::vector<VisualPassPtr> mPasses;
};

SHR_REGISTER_STREAM(VisualTechnique);
typedef Pointer0<VisualTechnique> VisualTechniquePtr;
#include "ShrVisualTechnique.inl"

}

#endif