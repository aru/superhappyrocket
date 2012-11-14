#ifndef SHRDEPTHSTATE_H
#define SHRDEPTHSTATE_H

#include "ShrGraphicsLIB.h"
#include "ShrObject.h"

namespace shr
{

class SHR_GRAPHICS_ITEM DepthState : public Object
{
    SHR_DECLARE_RTTI;
    SHR_DECLARE_NAMES;
    SHR_DECLARE_STREAM(DepthState);

public:
    // Construction and destruction.
    DepthState ();
    virtual ~DepthState ();

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

    bool Enabled;         // default: true
    bool Writable;        // default: true
    CompareMode Compare;  // default: CM_LEQUAL
};

SHR_REGISTER_STREAM(DepthState);
typedef Pointer0<DepthState> DepthStatePtr;

}

#endif
