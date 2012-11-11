#ifndef SHRMUTEX_H
#define SHRMUTEX_H

#include "ShrCoreLIB.h"
#include "ShrMutexType.h"

namespace shr
{

class SHR_CORE_ITEM Mutex
{
public:
    // Construction and destruction.
    Mutex ();
    ~Mutex ();

    // Markers for critical sections.
    void Enter ();
    void Leave ();

private:
    MutexType mMutex;
};

}

#endif
