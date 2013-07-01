#include "ShrGraphicsPCH.h"
#include "ShrVisibleSet.h"
using namespace shr;

//----------------------------------------------------------------------------
VisibleSet::VisibleSet ()
    :
    mNumVisible(0)
{
}
//----------------------------------------------------------------------------
VisibleSet::~VisibleSet ()
{
}
//----------------------------------------------------------------------------
void VisibleSet::Insert (Spatial* visible)
{
    int size = (int)mVisible.size();
    if (mNumVisible < size)
    {
        mVisible[mNumVisible] = visible;
    }
    else
    {
        mVisible.push_back(visible);
    }
    ++mNumVisible;
}
//----------------------------------------------------------------------------
