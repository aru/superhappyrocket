#ifndef SHRSHADERFLOAT_H
#define SHRSHADERFLOAT_H

#include "ShrGraphicsLIB.h"
#include "ShrObject.h"

namespace shr
{

class Camera;
class Visual;

class SHR_GRAPHICS_ITEM ShaderFloat : public Object
{
    SHR_DECLARE_RTTI;
    SHR_DECLARE_NAMES;
    SHR_DECLARE_STREAM(ShaderFloat);

public:
    // Construction and destruction.  The number of registers must be
    // positive.  Each register represents four floating-point values.
    ShaderFloat ();
    ShaderFloat (int numRegisters);
    virtual ~ShaderFloat ();

    // For deferred construction.
    void SetNumRegisters (int numRegisters);

    // Member access.
    inline int GetNumRegisters () const;
    inline const float* GetData () const;
    inline float* GetData ();

    // Access to data by registers.  SetRegister copies four floats from
    // 'data' into register i.  SetRegisters copies mNumElements floats
    // from 'data' into all the registers.  Similar float-sizes are copied
    // by the Get* functions.
    void SetRegister (int i, const float* data);
    void SetRegisters (const float* data);
    void GetRegister (int i, float* data);
    void GetRegisters (float* data);

    // The same as SetRegisters.  This is useful when the source data is
    // an object that defines an implict conversion to 'const float*'.
    ShaderFloat& operator= (const float* data);

    // Access to data by index.
    inline float operator[] (int i) const;
    inline float& operator[] (int i);

    // This function allows for dynamic updates of the shader constants
    // in the VisualEffectInput::Enable function that the renderer calls.
    // Thus, the transfer of the data to the shader programs occurs as
    // late as possible in the rendering pass.  This is useful for global
    // effects that modify camera settings during their drawing calls.
    inline void EnableUpdater ();
    inline void DisableUpdater ();
    inline bool AllowUpdater () const;
    virtual void Update (const Visual* visual, const Camera* camera);

protected:
    int mNumElements;
    float* mData;
    bool mAllowUpdater;
};

SHR_REGISTER_STREAM(ShaderFloat);
typedef Pointer0<ShaderFloat> ShaderFloatPtr;
#include "ShrShaderFloat.inl"

}

#endif
