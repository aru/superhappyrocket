#ifndef ENDIAN_H
#define ENDIAN_H

#include "CoreLIB.h"

class Endian
{
public:
    // Test whether the byte order of the machine is big endian.
    static bool IsBig ();

    // Test whether the byte order of the machine is little endian.
    static bool IsLittle ();

    // Swap the byte order.  The functions with itemSize input are designed
    // to be used with template classes, where the item size depends on the
    // template parameter.
    static void Swap2 (void* datum);
    static void Swap2 (int numItems, void* data);
    static void Swap4 (void* datum);
    static void Swap4 (int numItems, void* data);
    static void Swap8 (void* datum);
    static void Swap8 (int numItems, void* data);
    static void Swap (size_t itemSize, void* datum);
    static void Swap (size_t itemSize, int numItems, void* data);

private:
    static bool msIsLittle;
};

#endif
