#ifndef FLOAT3_H
#define FLOAT3_H

#include "Tuple.h"

class Float3 : public Tuple<3,float>
{
public:
    // Construction and destruction.
    Float3 ();   // uninitialized
    ~Float3 ();  // hides ~Tuple<3,float>
    Float3 (float f0, float f1, float f2);
    Float3 (const Float3& tuple);

    // Assignment.
    Float3& operator= (const Float3& tuple);
};

#endif
