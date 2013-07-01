#ifndef SHRRTTI_H
#define SHRRTTI_H

#include "ShrCoreLIB.h"

namespace shr
{

class SHR_CORE_ITEM Rtti
{
public:
    // Construction and destruction.  The name must be unique among all
    // objects in the system.  In the Shr namespace, a class Foo should use
    // "Shr.Foo".  If an application has another namespace, SomeName, then
    // the name should be "SomeName.Foo".
    Rtti (const char* name, const Rtti* baseType);
    ~Rtti ();

    inline const char* GetName () const;
    inline bool IsExactly (const Rtti& type) const;
    bool IsDerived (const Rtti& type) const;

private:
    const char* mName;
    const Rtti* mBaseType;
};

#include "ShrRtti.inl"

}

//----------------------------------------------------------------------------
#define SHR_DECLARE_RTTI \
public: \
    static const Rtti TYPE; \
    \
    virtual const Rtti& GetRttiType () const \
    { \
        return TYPE; \
    }
//----------------------------------------------------------------------------
#define SHR_IMPLEMENT_RTTI(nsname, baseclassname, classname) \
    const Rtti classname::TYPE(#nsname"."#classname, &baseclassname::TYPE)
//----------------------------------------------------------------------------

#endif
