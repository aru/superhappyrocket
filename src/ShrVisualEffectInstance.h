#ifndef SHRVISUALEFFECTINSTANCE_H
#define SHRVISUALEFFECTINSTANCE_H

#include "ShrGraphicsLIB.h"
#include "ShrShaderParameters.h"
#include "ShrVisualEffect.h"

namespace shr
{

class SHR_GRAPHICS_ITEM VisualEffectInstance : public Object
{
    SHR_DECLARE_RTTI;
    SHR_DECLARE_NAMES;
    SHR_DECLARE_STREAM(VisualEffectInstance);

public:
    // Construction and destruction.
    VisualEffectInstance (const VisualEffect* effect, int techniqueIndex);
    virtual ~VisualEffectInstance ();

    // Member access.  These are mainly used by Renderer during drawing
    // of a geometric primitive.
    inline const VisualEffect* GetEffect () const;
    inline int GetTechniqueIndex () const;
    inline int GetNumPasses () const;
    const VisualPass* GetPass (int pass) const;
    ShaderParameters* GetVertexParameters (int pass) const;
    ShaderParameters* GetPixelParameters (int pass) const;

    // These functions set the constants/textures.  If successful, the return
    // value is nonnegative and is the index into the appropriate array.  This
    // index may passed to the Set* functions that have the paremeter
    // 'handle'.  The mechanism allows you to set directly by index and avoid
    // the name comparisons that occur with the Set* functions that have the
    // parameter 'const std::string& name'.
    int SetVertexConstant (int pass, const std::string& name,
        ShaderFloat* sfloat);

    int SetPixelConstant (int pass, const std::string& name,
        ShaderFloat* sfloat);

    int SetVertexTexture (int pass, const std::string& name,
        Texture* texture);

    int SetPixelTexture (int pass, const std::string& name,
        Texture* texture);

    // The 'handle' is the return value of the Set* functions above.
    void SetVertexConstant (int pass, int handle, ShaderFloat* sfloat);
    void SetPixelConstant (int pass, int handle, ShaderFloat* sfloat);
    void SetVertexTexture (int pass, int handle, Texture* texture);
    void SetPixelTexture (int pass, int handle, Texture* texture);

    // These functions get the constants/textures.
    ShaderFloat* GetVertexConstant (int pass, const std::string& name) const;
    ShaderFloat* GetPixelConstant (int pass, const std::string& name) const;
    Texture* GetVertexTexture (int pass, const std::string& name) const;
    Texture* GetPixelTexture (int pass, const std::string& name) const;

    // The 'handle' is the return value of the Set* functions above.
    ShaderFloat* GetVertexConstant (int pass, int handle) const;
    ShaderFloat* GetPixelConstant (int pass, int handle) const;
    Texture* GetVertexTexture (int pass, int handle) const;
    Texture* GetPixelTexture (int pass, int handle) const;

protected:
    VisualEffectPtr mEffect;
    int mTechniqueIndex;
    int mNumPasses;
    ShaderParametersPtr* mVertexParameters;
    ShaderParametersPtr* mPixelParameters;
};

SHR_REGISTER_STREAM(VisualEffectInstance);
typedef Pointer0<VisualEffectInstance> VisualEffectInstancePtr;
#include "ShrVisualEffectInstance.inl"

}

#endif