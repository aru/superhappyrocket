#ifndef SHRGLOBALEFFECT_H
#define SHRGLOBALEFFECT_H

#include "ShrGraphicsLIB.h"
#include "ShrObject.h"
#include "ShrRenderer.h"
#include "ShrVisibleSet.h"

namespace shr
{

class SHR_GRAPHICS_ITEM GlobalEffect : public Object
{
    SHR_DECLARE_RTTI;
    SHR_DECLARE_NAMES;
    SHR_DECLARE_STREAM(GlobalEffect);

protected:
    // Abstract base class.  Construction and destruction.
    GlobalEffect ();
public:
    virtual ~GlobalEffect ();

    // This function is called in Renderer::Draw(visibleSet,globalEffect)
    // when the globalEffect is nonnull.
    virtual void Draw (Renderer* renderer, const VisibleSet& visibleSet) = 0;
};

SHR_REGISTER_STREAM(GlobalEffect);
typedef Pointer0<GlobalEffect> GlobalEffectPtr;

}

#endif