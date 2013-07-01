#ifndef SHRTABLE_H
#define SHRTABLE_H

#include "ShrTuple.h"

// The class TYPE is either native data or is class data that has the
// following member functions:
//   TYPE::TYPE ()
//   TYPE::TYPE (const TYPE&);
//   TYPE& TYPE::operator= (const TYPE&)

namespace shr
{

template <int NUMROWS, int NUMCOLS, typename TYPE>
class Table
{
public:
    // Construction and destruction.  The default constructor does not
    // initialize the array elements for native elements.  The array elements
    // are initialized for class data whenever TYPE initializes during its
    // default construction.
    Table ();
    Table (const Table& table);
    ~Table ();

    // Coordinate access.
    inline operator const TYPE* () const;
    inline operator TYPE* ();
    inline const TYPE* operator[] (int row) const;
    inline TYPE* operator[] (int row);
    inline const TYPE& operator() (int row, int col) const;
    inline TYPE& operator() (int row, int col);
    void SetRow (int row, const Tuple<NUMCOLS,TYPE>& tuple);
    Tuple<NUMCOLS,TYPE> GetRow (int row) const;
    void SetColumn (int col, const Tuple<NUMROWS,TYPE>& tuple);
    Tuple<NUMROWS,TYPE> GetColumn (int col) const;

    // Assignment.
    Table& operator= (const Table& table);

    // Comparison.
    bool operator== (const Table& table) const;
    bool operator!= (const Table& table) const;
    bool operator<  (const Table& table) const;
    bool operator<= (const Table& table) const;
    bool operator>  (const Table& table) const;
    bool operator>= (const Table& table) const;

protected:
    // The array is stored in row-major order.
    enum { NUMENTRIES = NUMROWS*NUMCOLS };
    TYPE mEntry[NUMENTRIES];
};

#include "ShrTable.inl"

}

#endif
