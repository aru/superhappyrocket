#ifndef SHRFLOAT2_H
#define SHRFLOAT2_H

#include "ShrMathematicsLIB.h"
#include "ShrTuple.h"

namespace shr
{

class Float2 : public Tuple<2,float>
{
public:
    // Construction and destruction.
    inline Float2 ();   // uninitialized
    inline ~Float2 ();  // hides ~Tuple<2,float>
    inline Float2 (float f0, float f1);
    inline Float2 (const Float2& tuple);

    // Assignment.
    inline Float2& operator= (const Float2& tuple);
};

#include "ShrFloat2.inl"

}

#endif
