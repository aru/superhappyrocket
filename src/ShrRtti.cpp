#include "ShrCorePCH.h"
#include "ShrRtti.h"
using namespace shr;

//----------------------------------------------------------------------------
Rtti::Rtti (const char* name, const Rtti* baseType)
{
    mName = name;
    mBaseType = baseType;
}
//----------------------------------------------------------------------------
Rtti::~Rtti ()
{
}
//----------------------------------------------------------------------------
bool Rtti::IsDerived (const Rtti& type) const
{
    const Rtti* search = this;
    while (search)
    {
        if (search == &type)
        {
            return true;
        }
        search = search->mBaseType;
    }
    return false;
}
//----------------------------------------------------------------------------
