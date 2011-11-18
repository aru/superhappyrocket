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
#define WM5_USING_VC80
#else
#define WM5_USING_VC90
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

#endif

#endif