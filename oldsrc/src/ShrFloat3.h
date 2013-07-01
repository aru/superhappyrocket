#ifndef SHRFLOAT3_H
#define SHRFLOAT3_H

#include "ShrMathematicsLIB.h"
#include "ShrTuple.h"

namespace shr
{

class Float3 : public Tuple<3,float>
{
public:
    // Construction and destruction.
    inline Float3 ();   // uninitialized
    inline ~Float3 ();  // hides ~Tuple<3,float>
    inline Float3 (float f0, float f1, float f2);
    inline Float3 (const Float3& tuple);

    // Assignment.
    inline Float3& operator= (const Float3& tuple);
};

#include "ShrFloat3.inl"

}

#endif
