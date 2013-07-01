#include "Core.h"
#include "Mutex.h"
/* #include "Assert.h" */

#if defined(WIN32)

// The system mutex is very slow and are not needed for the single-process
// applications of Wild Magic.  Critical sections are faster.  In case you
// relied on the system mutex, you can comment out this define to get the
// old behavior
#define USE_CRITICAL_SECTIONS

//----------------------------------------------------------------------------
#ifdef USING_VC80
// See the comments at
// http://msdn.microsoft.com/en-us/library/ms683476(VS.85).aspx
// about why these #defines expose InitializeCriticalSectionAndSpinCount.
#define WIN32_LEAN_AND_MEAN
#define _WIN32_WINNT 0x0500
#endif
#include <windows.h>
//----------------------------------------------------------------------------
Mutex::Mutex ()
{
#ifdef USE_CRITICAL_SECTIONS
    // The MSVS2010 documentation mentioned that the heap manager spin lock
    // was set to approximately 4000.  Let's see how 4096 does.
    mMutex = new CRITICAL_SECTION;
    BOOL success = InitializeCriticalSectionAndSpinCount(
        (CRITICAL_SECTION*)mMutex, 4096);
    assert(success == TRUE); /* Failed to initialize critical section*/
    UNUSED(success);
#else
    mMutex = CreateMutex(NULL, FALSE, NULL);
    assert(mMutex != 0); /* Failed to create mutex */
#endif
}
//----------------------------------------------------------------------------
Mutex::~Mutex ()
{
#ifdef USE_CRITICAL_SECTIONS
    DeleteCriticalSection((CRITICAL_SECTION*)mMutex);
    delete mMutex;
#else
    BOOL closed = CloseHandle((HANDLE)mMutex);
    assert(closed == TRUE); /* Failed to destroy mutex */
    UNUSED(closed);
#endif
}
//----------------------------------------------------------------------------
void Mutex::Enter ()
{
#ifdef USE_CRITICAL_SECTIONS
    EnterCriticalSection((CRITICAL_SECTION*)mMutex);
#else
    DWORD result = WaitForSingleObject((HANDLE)mMutex, INFINITE);
    UNUSED(result);
    // result:
    //   WAIT_ABANDONED (0x00000080)
    //   WAIT_OBJECT_0  (0x00000000), signaled
    //   WAIT_TIMEOUT   (0x00000102), [not possible with INFINITE]
    //   WAIT_FAILED    (0xFFFFFFFF), not signaled
#endif
}
//----------------------------------------------------------------------------
void Mutex::Leave ()
{
#ifdef USE_CRITICAL_SECTIONS
    LeaveCriticalSection((CRITICAL_SECTION*)mMutex);
#else
    BOOL released = ReleaseMutex((HANDLE)mMutex);
    UNUSED(released);
#endif
}
//----------------------------------------------------------------------------
#elif defined(__LINUX__) || defined(__APPLE__)
//----------------------------------------------------------------------------
Mutex::Mutex ()
{
    int result;
    UNUSED(result);
    
    result = pthread_mutexattr_init(&mMutex.Attribute);
    // successful = 0
    // errors = ENOMEM

    result = pthread_mutexattr_settype(&mMutex.Attribute,
         PTHREAD_MUTEX_RECURSIVE);
    // successful = 0
    
    result = pthread_mutex_init(&mMutex.Mutex, &mMutex.Attribute);
    // successful = 0
    // errors = EAGAIN, ENOMEM, EPERM, EBUSY, EINVAL
}
//----------------------------------------------------------------------------
Mutex::~Mutex ()
{
    int result;
    UNUSED(result);

    result = pthread_mutex_destroy(&mMutex.Mutex);
    // successful = 0
    // errors = EINVAL

    result = pthread_mutexattr_destroy(&mMutex.Attribute);
    // successful = 0
    // errors = EBUSY, EINVAL
}
//----------------------------------------------------------------------------
void Mutex::Enter ()
{
    int result = pthread_mutex_lock(&mMutex.Mutex);
    UNUSED(result);
    // successful = 0
    // errors = EINVAL, EDEADLK
}
//----------------------------------------------------------------------------
void Mutex::Leave ()
{
    int result = pthread_mutex_unlock(&mMutex.Mutex);
    UNUSED(result);
    // successful = 0
    // errors = EINVAL, EPERM
}
//----------------------------------------------------------------------------
#else
#error Other platforms not yet implemented.
#endif
//----------------------------------------------------------------------------
