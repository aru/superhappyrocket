#ifndef SHRTHREADTYPE_H
#define SHRTHREADTYPE_H

#include "ShrCoreLIB.h"

#if defined(WIN32)
//----------------------------------------------------------------------------
// Thread type for Microsoft Windows.  It is technically a HANDLE, but
// including <windows.h> here exposes Microsoft Windows symbols in the
// application layer.  To avoid this, void* is used and typecasts are
// applied in ShrThread.cpp.
//----------------------------------------------------------------------------
namespace shr
{
typedef void* ThreadType;
}
//----------------------------------------------------------------------------
#elif defined(__LINUX__) || defined(__APPLE__)
//----------------------------------------------------------------------------
// Thread type for Linux/Apple.  The file pthread.h exposes only native data
// types, so including it here does not suck in lots of extra stuff.
//----------------------------------------------------------------------------
#include <pthread.h>
namespace shr
{
typedef pthread_t ThreadType;
}
//----------------------------------------------------------------------------
#else
//----------------------------------------------------------------------------
// TODO: Thread types for other platforms.
//----------------------------------------------------------------------------
#error Other platforms not yet implemented.
#endif

#endif
