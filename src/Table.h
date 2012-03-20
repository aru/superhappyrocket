#ifndef TABLE_H
#define TABLE_H

#include "Tuple.h"

template <int NUMROWS, int NUMCOLS, typename TYPE>
class Table
{
public:
	
	Table();
	Table( const Table& table );
	~Table();

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

	// Comparison.  The inequalities make the comparisons using memcmp, thus
    // treating the tuple as an array of unsigned bytes.
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

#endif