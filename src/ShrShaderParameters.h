#ifndef SHRSHADERPARAMETERS_H
#define SHRSHADERPARAMETERS_H

#include "ShrGraphicsLIB.h"
#include "ShrShader.h"
#include "ShrShaderFloat.h"
#include "ShrTexture.h"

namespace shr
{

class SHR_GRAPHICS_ITEM ShaderParameters : public Object
{
    SHR_DECLARE_RTTI;
    SHR_DECLARE_NAMES;
    SHR_DECLARE_STREAM(ShaderParameters);

public:
    // Construction and destruction.
    ShaderParameters (Shader* shader);
    virtual ~ShaderParameters ();

    // Member access.
    inline int GetNumConstants () const;
    inline int GetNumTextures () const;
    inline ShaderFloatPtr* GetConstants () const;
    inline TexturePtr* GetTextures () const;

    // These functions set the constants/textures.  If successful, the return
    // value is nonnegative and is the index into the appropriate array.  This
    // index may passed to the Set* functions that have the paremeter
    // 'handle'.  The mechanism allows you to set directly by index and avoid
    // the name comparisons that occur with the Set* functions that have the
    // parameter 'const std::string& name'.
    int SetConstant (const std::string& name, ShaderFloat* sfloat);
    int SetTexture (const std::string& name, Texture* texture);

    // The 'handle' is the return value of the Set* functions above.
    void SetConstant (int handle, ShaderFloat* sfloat);
    void SetTexture (int handle, Texture* texture);

    // Member access.
    ShaderFloat* GetConstant (const std::string& name) const;
    Texture* GetTexture (const std::string& name) const;

    // The 'handle' is the return value of the Set* functions above.
    ShaderFloat* GetConstant (int handle) const;
    Texture* GetTexture (int handle) const;

    // Update shader constants during a drawing call.
    void UpdateConstants (const Visual* visual, const Camera* camera);

protected:
    ShaderPtr mShader;
    int mNumConstants;
    ShaderFloatPtr* mConstants;
    int mNumTextures;
    TexturePtr* mTextures;
};

SHR_REGISTER_STREAM(ShaderParameters);
typedef Pointer0<ShaderParameters> ShaderParametersPtr;
#include "ShrShaderParameters.inl"

}

#endif
