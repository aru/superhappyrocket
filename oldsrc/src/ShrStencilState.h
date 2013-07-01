#ifndef SHRSTENCILSTATE_H
#define SHRSTENCILSTATE_H

#include "ShrGraphicsLIB.h"
#include "ShrObject.h"

namespace shr
{

class SHR_GRAPHICS_ITEM StencilState : public Object
{
    SHR_DECLARE_RTTI;
    SHR_DECLARE_NAMES;
    SHR_DECLARE_STREAM(StencilState);

public:
    // Construction and destruction.
    StencilState ();
    virtual ~StencilState ();

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

    enum SHR_GRAPHICS_ITEM OperationType
    {
        OT_KEEP,
        OT_ZERO,
        OT_REPLACE,
        OT_INCREMENT,
        OT_DECREMENT,
        OT_INVERT,
        OT_QUANTITY
    };

    bool Enabled;            // default: false
    CompareMode Compare;     // default: CM_NEVER
    unsigned int Reference;  // default: 0
    unsigned int Mask;       // default: UINT_MAX (0xFFFFFFFF)
    unsigned int WriteMask;  // default: UINT_MAX (0xFFFFFFFF)
    OperationType OnFail;    // default: OT_KEEP
    OperationType OnZFail;   // default: OT_KEEP
    OperationType OnZPass;   // default: OT_KEEP
};

SHR_REGISTER_STREAM(StencilState);
typedef Pointer0<StencilState> StencilStatePtr;

}

#endif
