#ifndef TUPLE_H
#define TUPLE_H

#include "CoreLIB.h"

template <int DIMENSION, typename TYPE>
class Tuple
{
public:
	Tuple();
	Tuple( const Tuple& tuple );
	~Tuple();

	// Coordinate access
	inline operator const TYPE* () const;
    inline operator TYPE* ();
    inline const TYPE& operator[] (int i) const;
    inline TYPE& operator[] (int i);

	// Assignment.
    Tuple& operator= (const Tuple& tuple);

	// Comparison.  The inequalities make the comparisons using memcmp, thus
    // treating the tuple as an array of unsigned bytes.
    bool operator== (const Tuple& tuple) const;
    bool operator!= (const Tuple& tuple) const;
    bool operator<  (const Tuple& tuple) const;
    bool operator<= (const Tuple& tuple) const;
    bool operator>  (const Tuple& tuple) const;
    bool operator>= (const Tuple& tuple) const;

protected:
    TYPE mTuple[DIMENSION];
};

#include "Tuple.inl"

#endif