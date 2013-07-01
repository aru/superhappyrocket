#ifndef MUTEX_H
#define MUTEX_H

#include "CoreLIB.h"
#include "MutexType.h"

class Mutex
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

#endif
