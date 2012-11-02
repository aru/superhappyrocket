#ifndef CORELIB_H
#define CORELIB_H

//----------------------------------------------------------------------------
// Microsoft Windows platform
//----------------------------------------------------------------------------
#if defined(_WIN32) || defined(WIN32)

#ifndef _WIN32
#define _WIN32
#endif

#ifndef WIN32
#define WIN32
#endif

// Windows is little endian, I think lol
#define LITTLE_ENDIAN

#if defined(_MSC_VER)
// MSVC6 is version 12.00, MSVC7.0 is version 13.00, MSVC7.1 is version 13.10,
// MSVC8.0 is version 14.00, and MSVC9.0 is version 15.00.  Currently, only
// version 9.0 or later are supported.
#if _MSC_VER < 1400
#error MSVC 8.0 or later is required
#elif _MSC_VER < 1500
#define USING_VC80
#else
#define USING_VC90
#endif

// Disable the Microsoft warnings about not using the secure functions.
#pragma warning(disable : 4996)

// Support for standard integer types.  This is only a small part of what
// stdint.h provides on Unix platforms. Needed for better portability.
//#include <climits>
//
//typedef __int8              int8_t;
//typedef __int16             int16_t;
//typedef __int32             int32_t;
//typedef __int64             int64_t;
//typedef unsigned __int8     uint8_t;
//typedef unsigned __int16    uint16_t;
//typedef unsigned __int32    uint32_t;
//typedef unsigned __int64    uint64_t;
//
//#define INT8_MIN            _I8_MIN
//#define INT8_MAX            _I8_MAX
//#define INT16_MIN           _I16_MIN
//#define INT16_MAX           _I16_MAX
//#define INT32_MIN           _I32_MIN
//#define INT32_MAX           _I32_MAX
//#define INT64_MIN           _I64_MIN
//#define INT64_MAX           _I64_MAX
//#define UINT8_MAX           _UI8_MAX
//#define UINT16_MAX          _UI16_MAX
//#define UINT32_MAX          _UI32_MAX
//#define UINT64_MAX          _UI64_MAX
#endif

// Common standard library headers.
#include <cassert>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <fstream>

// Common STL headers.
#include <algorithm>
#include <deque>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

// User-defined keywords for syntax highlighting of special class sections.
#define public_internal public
#define protected_internal protected
#define private_internal private

// Avoid warnings about unused variables.  This is designed for variables
// that are exposed in debug configurations but are hidden in release
// configurations.
#define UNUSED(variable) (void)variable

// Begin Microsoft Windows DLL support.
#if defined(CORE_DLL_EXPORT)
    // For the DLL library.
    #define CORE_ITEM __declspec(dllexport)
#elif defined(CORE_DLL_IMPORT)
    // For a client of the DLL library.
    #define CORE_ITEM __declspec(dllimport)
#else
    // For the static library and for Apple/Linux.
    #define CORE_ITEM
#endif

// Macros to enable or disable various Assert subsystems.  TODO:  Currently,
// the extended assert system is implemented only for Microsoft Visual Studio.
#ifdef _DEBUG
    #if defined(WIN32) && defined(_MSC_VER)
        #define USE_ASSERT
        #ifdef USE_ASSERT
            #define USE_ASSERT_WRITE_TO_OUTPUT_WINDOW
            #define USE_ASSERT_WRITE_TO_MESSAGE_BOX
        #endif
    #endif
    //#define USE_ASSERT_LOG_TO_FILE
#endif

// Macros for memory management.  To report memory leaks and related
// file-line information, you must enable USE_MEMORY.  This in
// turn requires Memory::Initialize and Memory::Terminate to be called
// in your application.  This is handled automatically if you use the
// Wild Magic application layer.  If you do not, see the 'main' function
// in the file
//   WildMagic5/LibApplication/Application.cpp
// for an example.  Also read the general documentation about start-up
// and shut-down
//   WildMagic5/Documentation/InitTerm.pdf
//
#define USE_MEMORY2
#ifdef USE_MEMORY
    // Enable an assertion when a allocation occurs before
    // Memory::Initialize was called or when a deallocation occurs after
    // Memory::Terminate was called.
    #define USE_MEMORY_ASSERT_ON_PREINIT_POSTTERM_OPERATIONS

    // When USE_MEMORY is enabled, the Memory functions delete0,
    // delete1, delete2, and delete3 will fail when the incoming pointer
    // was not allocated by the Wild Magic memory manager.  Enabling the
    // following flag tells Wild Magic's memory manager to attempt
    // 'delete' or 'delete[]' under the assumption that the memory was
    // allocated by 'new' or 'new[]'.
    #define USE_MEMORY_ALLOW_DELETE_ON_FAILED_MAP_LOOKUP
#endif

#endif

#endif