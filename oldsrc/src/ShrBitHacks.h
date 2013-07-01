// Bit hacks are available at
//     http://graphics.stanford.edu/~seander/bithacks.html

#ifndef SHRBITHACKS_H
#define SHRBITHACKS_H

#include "ShrMathematicsLIB.h"

namespace shr
{

SHR_MATHEMATICS_ITEM bool IsPowerOfTwo (unsigned int value);
SHR_MATHEMATICS_ITEM bool IsPowerOfTwo (int value);

SHR_MATHEMATICS_ITEM unsigned int Log2OfPowerOfTwo (unsigned int powerOfTwo);
SHR_MATHEMATICS_ITEM int Log2OfPowerOfTwo (int powerOfTwo);

// Fast conversion from a IEEE 32-bit floating point number F in [0,1] to a
// a 32-bit integer I in [0,2^P-1].  The input 'value' is F, the input
// 'power' is P, and the return value of the function is I.
inline int ScaledFloatToInt (float value, int power);

#include "ShrBitHacks.inl"

}

#endif