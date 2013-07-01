#ifndef SHRWIRESTATE_H
#define SHRWIRESTATE_H

#include "ShrGraphicsLIB.h"
#include "ShrObject.h"

namespace shr
{

class SHR_GRAPHICS_ITEM WireState : public Object
{
    SHR_DECLARE_RTTI;
    SHR_DECLARE_NAMES;
    SHR_DECLARE_STREAM(WireState);

public:
    // Construction and destruction.
    WireState ();
    virtual ~WireState ();

    bool Enabled;  // default: false
};

SHR_REGISTER_STREAM(WireState);
typedef Pointer0<WireState> WireStatePtr;

}

#endif
