#ifndef SHRSCOPEDCS_H
#define SHRSCOPEDCS_H

#include "ShrCoreLIB.h"
#include "ShrMutex.h"

namespace shr
{

// Scoped critial section:  This provides for a mutex that is entered at the
// beginning of a scope.  The mutex leaves when the ScopedCS object is
// automatically destroyed when leaving the scope, due to the usual C++
// semantics of calling destructors when exiting a scope.

class SHR_CORE_ITEM ScopedCS
{
public:
    // Construction and destruction.
    ScopedCS (Mutex* mutex);
    ~ScopedCS ();

private:
    Mutex* mMutex;
};

}

#endif
