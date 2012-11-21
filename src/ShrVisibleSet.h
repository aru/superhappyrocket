#ifndef SHRVISIBLESET_H
#define SHRVISIBLESET_H

#include "ShrGraphicsLIB.h"
#include "ShrAssert.h"

namespace shr
{

class Spatial;

class SHR_GRAPHICS_ITEM VisibleSet
{
public:
    // Construction and destruction.
    VisibleSet ();
    ~VisibleSet ();

    // Access to the elements of the visible set.
    inline int GetNumVisible () const;
    inline const std::vector<Spatial*>& GetAllVisible () const;
    inline Spatial* GetVisible (int i) const;

    // Insert a visible object into the set.
    void Insert (Spatial* visible);

    // Set the number of elements to zero.
    inline void Clear ();

private:
    int mNumVisible;
    std::vector<Spatial*> mVisible;
};

#include "ShrVisibleSet.inl"

}

#endif
