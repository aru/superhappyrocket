#ifndef SHRCULLSTATE_H
#define SHRCULLSTATE_H

#include "ShrGraphicsLIB.h"
#include "ShrObject.h"

namespace shr
{

class SHR_GRAPHICS_ITEM CullState : public Object
{
    SHR_DECLARE_RTTI;
    SHR_DECLARE_NAMES;
    SHR_DECLARE_STREAM(CullState);

public:
    // Construction and destruction.
    CullState ();
    virtual ~CullState ();

    bool Enabled;   // default: true
    bool CCWOrder;  // default: true
};

SHR_REGISTER_STREAM(CullState);
typedef Pointer0<CullState> CullStatePtr;

}

#endif