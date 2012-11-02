#ifndef HPOINT_H
#define HPOINT_H

#include "CoreLIB.h"

class HPoint
{
public:
    // Construction and destruction.  HPoint represents a homogeneous point
    // of the form (x,y,z,w).  Affine points are characterized by w = 1
    // (see class APoint) and affine vectors are characterized by w = 0
    // (see class AVector).
    HPoint ();  // uninitialized
    HPoint (const HPoint& pnt);
    HPoint (float x, float y, float z, float w);
    ~HPoint ();

    // Coordinate access.
    inline operator const float* () const;
    inline operator float* ();
    inline const float& operator[] (int i) const;
    inline float& operator[] (int i);
    inline float X () const;
    inline float& X ();
    inline float Y () const;
    inline float& Y ();
    inline float Z () const;
    inline float& Z ();
    inline float W () const;
    inline float& W ();

    // Assignment.
    HPoint& operator= (const HPoint& pnt);

    // Comparison (for use by STL containers).
    bool operator== (const HPoint& pnt) const;
    bool operator!= (const HPoint& pnt) const;
    bool operator<  (const HPoint& pnt) const;
    bool operator<= (const HPoint& pnt) const;
    bool operator>  (const HPoint& pnt) const;
    bool operator>= (const HPoint& pnt) const;

protected:
    float mTuple[4];
};

#include "HPoint.inl"

#endif