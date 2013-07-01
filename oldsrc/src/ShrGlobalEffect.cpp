#include "ShrGraphicsPCH.h"
#include "ShrGlobalEffect.h"
using namespace shr;

SHR_IMPLEMENT_RTTI(shr, Object, GlobalEffect);
SHR_IMPLEMENT_STREAM(GlobalEffect);
SHR_IMPLEMENT_ABSTRACT_FACTORY(GlobalEffect);
SHR_IMPLEMENT_DEFAULT_NAMES(Object, GlobalEffect);
SHR_IMPLEMENT_DEFAULT_STREAM(Object, GlobalEffect);

//----------------------------------------------------------------------------
GlobalEffect::GlobalEffect ()
{
}
//----------------------------------------------------------------------------
GlobalEffect::~GlobalEffect ()
{
}
//----------------------------------------------------------------------------
