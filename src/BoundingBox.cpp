#include "BoundingBox.h"

BoundingBox::BoundingBox( float c0, float c1, float c2,
                          float r0, float r1, float r2 )
{
    c[0] = c0;
    c[1] = c1;
    c[2] = c2;

    r[0] = r0;
    r[1] = r1;
    r[2] = r2;
}

BoundingBox::~BoundingBox()
{
}

const bool BoundingBox::intersectsWith( const BoundingBox& box )
{
    int t;
    t = r[0] + box.r[0]; if( (unsigned int)(c[0] - box.c[0]+t) > t+t ) return false;
    t = r[1] + box.r[1]; if( (unsigned int)(c[1] - box.c[1]+t) > t+t ) return false;
    t = r[2] + box.r[2]; if( (unsigned int)(c[2] - box.c[2]+t) > t+t ) return false;
    return true;
}
