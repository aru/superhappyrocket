#ifndef SHRTHREAD_H
#define SHRTHREAD_H

#include "ShrCoreLIB.h"
#include "ShrThreadType.h"

namespace shr
{

class SHR_CORE_ITEM Thread
{
public:
    // Construction and destruction.
    Thread (void* function, void* userData, unsigned int processorNumber = 0,
        unsigned int stackSize = 0);

    ~Thread ();

    // Start and stop the thread.
    void Resume ();
    void Suspend ();

private:
    ThreadType mThread;
    unsigned int mThreadID;
    void* mFunction;
    void* mUserData;
    unsigned int mProcessorNumber;
    unsigned int mStackSize;
};

}

#endif
