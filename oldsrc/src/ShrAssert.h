#ifndef SHRASSERT_H
#define SHRASSERT_H

#include "ShrCoreLIB.h"

#ifdef SHR_USE_ASSERT
//----------------------------------------------------------------------------
// Use SHR asserts with file/line tracking.
//----------------------------------------------------------------------------
namespace shr
{

class SHR_CORE_ITEM Assert
{
public:
    // Construction and destruction.
    Assert (bool condition, const char* file, int line, const char* format,
        ...);

    ~Assert ();

private:
    enum { MAX_MESSAGE_BYTES = 1024 };
    static const char* msDebugPrompt;
    static const size_t msDebugPromptLength;
    static const char* msMessagePrefix;

#ifdef SHR_USE_ASSERT_WRITE_TO_MESSAGE_BOX
    static const char* msMessageBoxTitle;
#endif
};

}

#define assertion(condition, format, ...) \
    shr::Assert(condition, __FILE__, __LINE__, format, __VA_ARGS__)
//----------------------------------------------------------------------------
#else
//----------------------------------------------------------------------------
// Use standard asserts.
//----------------------------------------------------------------------------
#define assertion(condition, format, ...) assert(condition)
//----------------------------------------------------------------------------
#endif

#endif
