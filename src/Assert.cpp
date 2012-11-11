#include "CorePCH.h"
#include "Assert.h"

#ifdef USE_ASSERT

#ifdef USE_ASSERT_WRITE_TO_OUTPUT_WINDOW
#include <windows.h>
#endif

#ifdef USE_ASSERT_WRITE_TO_MESSAGE_BOX
#include <intrin.h>
#endif

using namespace shr;

const char* Assert::msDebugPrompt = "Do you want to debug?";
const size_t Assert::msDebugPromptLength = strlen(Assert::msDebugPrompt);
const char* Assert::msMessagePrefix = "\nAssert failed at %s(%d):\n";

#ifdef USE_ASSERT_WRITE_TO_MESSAGE_BOX
const char* Assert::msMessageBoxTitle = "Assert Failed";
#endif

//----------------------------------------------------------------------------
Assert::Assert (bool condition, const char* file, int line,
    const char* format, ...)
{
    if (condition)
    {
        // The assertion is satisfied.
        return;
    }

    // The message prefix.
    char message[MAX_MESSAGE_BYTES];
    const size_t maxPrefixBytes = MAX_MESSAGE_BYTES - msDebugPromptLength - 1;
    _snprintf(message, maxPrefixBytes, msMessagePrefix, file, line);

    // Append user-specified arguments.
    va_list arguments;
    va_start(arguments, format);
    size_t length = strlen(message);
    _vsnprintf(message + length, maxPrefixBytes - length, format, arguments);
    va_end(arguments);

#ifdef USE_ASSERT_LOG_TO_FILE
    // Write the message to the log file.
    FILE* logFile = fopen(msLogFileName, "at");
    if (logFile)
    {
        fprintf(logFile, message);
    }
    fclose(logFile);
#endif

#ifdef USE_ASSERT_WRITE_TO_OUTPUT_WINDOW
    // Write the message to the output debug window.
    OutputDebugString(message);
#endif

#ifdef USE_ASSERT_WRITE_TO_MESSAGE_BOX
    // Give the user a chance to break-and-debug, to continue, or to
    // terminate execution.
    strcat(message, msDebugPrompt);
    int selection = ::MessageBox(0, message, msMessageBoxTitle,
        MB_ICONERROR | MB_YESNOCANCEL | MB_APPLMODAL | MB_TOPMOST);

    switch (selection)
    {
    case IDYES:
        // Break and debug.
        __debugbreak();
        break;
    case IDNO:
        // Continue execution.
        break;
    case IDCANCEL:
    default:
        // Terminate execution.
        exit(0);
        break;
    }
#endif
}
//----------------------------------------------------------------------------
Assert::~Assert ()
{
}
//----------------------------------------------------------------------------

#endif
