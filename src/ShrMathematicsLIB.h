#ifndef SHRMATHEMATICSLIB_H
#define SHRMATHEMATICSLIB_H

#include "ShrCoreLIB.h"

// Begin Microsoft Windows DLL support.
#if defined(SHR_MATHEMATICS_DLL_EXPORT)
    // For the DLL library.
    #define SHR_MATHEMATICS_ITEM __declspec(dllexport)
#elif defined(SHR_MATHEMATICS_DLL_IMPORT)
    // For a client of the DLL library.
    #define SHR_MATHEMATICS_ITEM __declspec(dllimport)
#else
    // For the static library and for Apple/Linux.
    #define SHR_MATHEMATICS_ITEM
#endif
// End Microsoft Windows DLL support.

// Enable this define if you want the Rational class to assert when the
// constructor is passed a floating-point infinity or NaN.
//#define SHR_ASSERT_ON_RATIONAL_CONVERT_NAN

// Enable this define if you want Vector2<Real>::GetBarycentrics to assert
// when the input triangle is degenerate.
//#define SHR_ASSERT_ON_BARYCENTRIC2_DEGENERATE

// Enable this define if you want Vector3<Real>::GetBarycentrics to assert
// when the input tetrahedron is degenerate.
//#define SHR_ASSERT_ON_BARYCENTRIC3_DEGENERATE

// Enable this define if you want index range checking in GVector<Real>.
#define SHR_ASSERT_GVECTOR_OUT_OF_RANGE

// Enable this define if you want index range checking in GMatrix<Real>.
#define SHR_ASSERT_GMATRIX_OUT_OF_RANGE

#endif