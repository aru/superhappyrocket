#ifndef SHRALPHASTATE_H
#define SHRALPHASTATE_H

#include "ShrGraphicsLIB.h"
#include "ShrObject.h"
#include "ShrFloat4.h"

namespace shr
{

class SHR_GRAPHICS_ITEM AlphaState : public Object
{
    SHR_DECLARE_RTTI;
    SHR_DECLARE_NAMES;
    SHR_DECLARE_STREAM(AlphaState);

public:
    // Construction and destruction.
    AlphaState ();
    virtual ~AlphaState ();

    enum SHR_GRAPHICS_ITEM SrcBlendMode
    {
        SBM_ZERO,
        SBM_ONE,
        SBM_DST_COLOR,
        SBM_ONE_MINUS_DST_COLOR,
        SBM_SRC_ALPHA,
        SBM_ONE_MINUS_SRC_ALPHA,
        SBM_DST_ALPHA,
        SBM_ONE_MINUS_DST_ALPHA,
        SBM_SRC_ALPHA_SATURATE,
        SBM_CONSTANT_COLOR,
        SBM_ONE_MINUS_CONSTANT_COLOR,
        SBM_CONSTANT_ALPHA,
        SBM_ONE_MINUS_CONSTANT_ALPHA,
        SBM_QUANTITY
    };

    enum SHR_GRAPHICS_ITEM DstBlendMode
    {
        DBM_ZERO,
        DBM_ONE,
        DBM_SRC_COLOR,
        DBM_ONE_MINUS_SRC_COLOR,
        DBM_SRC_ALPHA,
        DBM_ONE_MINUS_SRC_ALPHA,
        DBM_DST_ALPHA,
        DBM_ONE_MINUS_DST_ALPHA,
        DBM_CONSTANT_COLOR,
        DBM_ONE_MINUS_CONSTANT_COLOR,
        DBM_CONSTANT_ALPHA,
        DBM_ONE_MINUS_CONSTANT_ALPHA,
        DBM_QUANTITY
    };

    enum SHR_GRAPHICS_ITEM CompareMode
    {
        CM_NEVER,
        CM_LESS,
        CM_EQUAL,
        CM_LEQUAL,
        CM_GREATER,
        CM_NOTEQUAL,
        CM_GEQUAL,
        CM_ALWAYS,
        CM_QUANTITY
    };

    bool BlendEnabled;      // default: false
    SrcBlendMode SrcBlend;  // default: SBM_SRC_ALPHA
    DstBlendMode DstBlend;  // default: DBM_ONE_MINUS_SRC_ALPHA
    bool CompareEnabled;    // default: false
    CompareMode Compare;    // default: CM_ALWAYS
    float Reference;        // default: 0, always in [0,1]
    Float4 ConstantColor;   // default: (0,0,0,0)
};

SHR_REGISTER_STREAM(AlphaState);
typedef Pointer0<AlphaState> AlphaStatePtr;

}

#endif
