#include "ShrCorePCH.h"
#include "ShrThread.h"
#include "ShrAssert.h"
using namespace shr;

#if defined(WIN32)
//----------------------------------------------------------------------------
#include <windows.h>
//----------------------------------------------------------------------------
Thread::Thread (void* function, void* userData, unsigned int processorNumber,
    unsigned int stackSize)
    :
    mFunction(function),
    mUserData(userData),
    mProcessorNumber(processorNumber),
    mStackSize(stackSize)
{
    mThread = CreateThread(NULL, (SIZE_T)stackSize,
        (LPTHREAD_START_ROUTINE)function, (LPVOID)userData, CREATE_SUSPENDED,
        (LPDWORD)&mThreadID);
}
//----------------------------------------------------------------------------
Thread::~Thread ()
{
    // TODO:  Write the threading system to allow graceful termination of
    // each thread.  The destructor is not the place to terminate.  In C++,
    // the thread function should exit (in C, ExitThread is the function to
    // call).  When it is time to exit, you can give the thread information
    // to do so (via the userData). 
}
//----------------------------------------------------------------------------
void Thread::Resume ()
{
    DWORD result = ResumeThread((HANDLE)mThread);
    assertion(result != (DWORD)-1, "Failed to resume thread\n");
    SHR_UNUSED(result);
}
//----------------------------------------------------------------------------
void Thread::Suspend ()
{
    DWORD result = SuspendThread((HANDLE)mThread);
    assertion(result != (DWORD)-1, "Failed to suspend thread\n");
    SHR_UNUSED(result);
}
//----------------------------------------------------------------------------
#elif defined(__LINUX__) || defined(__APPLE__)
//----------------------------------------------------------------------------
Thread::Thread (void* function, void* userData, unsigned int processorNumber,
    unsigned int stackSize)
    :
    mFunction(function),
    mUserData(userData),
    mProcessorNumber(processorNumber),
    mStackSize(stackSize)
{
    // TODO.
}
//----------------------------------------------------------------------------
Thread::~Thread ()
{
    // TODO. 
}
//----------------------------------------------------------------------------
void Thread::Resume ()
{
    // TODO.
}
//----------------------------------------------------------------------------
void Thread::Suspend ()
{
    // TODO.
}
//----------------------------------------------------------------------------
#else
#error Other platforms not yet implemented.
#endif
//----------------------------------------------------------------------------
