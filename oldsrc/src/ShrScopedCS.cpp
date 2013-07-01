#include "ShrCorePCH.h"
#include "ShrScopedCS.h"
using namespace shr;

//----------------------------------------------------------------------------
ScopedCS::ScopedCS (Mutex* mutex)
    :
    mMutex(mutex)
{
    mMutex->Enter();
}
//----------------------------------------------------------------------------
ScopedCS::~ScopedCS ()
{
    mMutex->Leave();
}
//----------------------------------------------------------------------------
