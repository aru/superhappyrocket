#ifndef SHRFLOAT4_H
#define SHRFLOAT4_H

#include "ShrMathematicsLIB.h"
#include "ShrTuple.h"

namespace shr
{

class Float4 : public Tuple<4,float>
{
public:
    // Construction and destruction.
    inline Float4 ();   // uninitialized
    inline ~Float4 ();  // hides ~Tuple<4,float>
    inline Float4 (float f0, float f1, float f2, float f3);
    inline Float4 (const Float4& tuple);

    // Assignment.
    inline Float4& operator= (const Float4& tuple);
};

#include "ShrFloat4.inl"

}

#endif
