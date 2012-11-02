#ifndef ASSERT_H
#define ASSERT_H

#include "CoreLIB.h"

#ifdef USE_ASSERT
//----------------------------------------------------------------------------
// Use asserts with file/line tracking.
//----------------------------------------------------------------------------

class CORE_ITEM Assert
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

#ifdef USE_ASSERT_WRITE_TO_MESSAGE_BOX
    static const char* msMessageBoxTitle;
#endif
};

#define assertion(condition, format, ...) \
    Assert(condition, __FILE__, __LINE__, format, __VA_ARGS__)
//----------------------------------------------------------------------------
#else
//----------------------------------------------------------------------------
// Use standard asserts.
//----------------------------------------------------------------------------
#define assertion(condition, format, ...) assert(condition)
//----------------------------------------------------------------------------
#endif

#endif
