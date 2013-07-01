#ifndef MUTEXTYPE_H
#define MUTEXTYPE_H

#include "CoreLIB.h"

#if defined(WIN32)
//----------------------------------------------------------------------------
// Mutex type for Microsoft Windows.  It is technically a HANDLE, but
// including <windows.h> here exposes Microsoft Windows symbols in the
// application layer.  To avoid this, void* is used and typecasts are
// applied in Mutex.cpp.
//----------------------------------------------------------------------------

typedef void* MutexType;

//----------------------------------------------------------------------------
#elif defined(__LINUX__) || defined(__APPLE__)
//----------------------------------------------------------------------------
// Mutex type for Linux/Apple.  The file pthread.h exposes only native data
// types, so including it here does not suck in lots of extra stuff.
//----------------------------------------------------------------------------
#include <pthread.h>
    typedef struct
    {
        pthread_mutexattr_t Attribute;
        pthread_mutex_t Mutex;
    }
    MutexType;
#else
//----------------------------------------------------------------------------
// TODO: Mutex types for other platforms.
//----------------------------------------------------------------------------
#error Other platforms not yet implemented.
#endif

#endif
