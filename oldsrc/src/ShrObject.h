#ifndef SHROBJECT_H
#define SHROBJECT_H

#include "ShrCoreLIB.h"
#include "ShrNames.h"
#include "ShrRtti.h"
#include "ShrSmartPointer.h"
#include "ShrInStream.h"
#include "ShrOutStream.h"

namespace shr
{

// The root class of the object system.  It provides some basic services for
// an object-oriented library.  This class is abstract.

class SHR_CORE_ITEM Object
{
// Run-time type information.
public:
    virtual const Rtti& GetRttiType () const;
    bool IsExactly (const Rtti& type) const;
    bool IsDerived (const Rtti& type) const;
    bool IsExactlyTypeOf (const Object* object) const;
    bool IsDerivedTypeOf (const Object* object) const;
    static const Rtti TYPE;

// Names for objects.
public:
    void SetName (const std::string& name);
    const std::string& GetName () const;
    virtual Object* GetObjectByName (const std::string& name);
    virtual void GetAllObjectsByName (const std::string& name,
        std::vector<Object*>& objects);
private:
    std::string mName;

// Streaming.
public:
    typedef Object* (*FactoryFunction)(InStream& stream);
    typedef std::map<std::string, FactoryFunction> FactoryMap;
    static bool RegisterFactory ();
    static void InitializeFactory ();
    static void TerminateFactory ();
    static FactoryFunction Find (const std::string& name);
    static Object* Factory (InStream& source);
    virtual void Load (InStream& source);
    virtual void Link (InStream& source);
    virtual void PostLink ();
    virtual bool Register (OutStream& target) const;
    virtual void Save (OutStream& target) const;
    virtual int GetStreamingSize () const;
    //Object* Copy (const std::string& uniqueNameAppend) const;
protected:
    // Constructor used by the loading system.
    enum LoadConstructor { LC_LOADER };
    Object (LoadConstructor value);
    static FactoryMap* msFactories;
private:
    static bool msStreamRegistered;

// Abstract base class.  Construction and destruction.
protected:
    Object ();
public:
    virtual ~Object ();

    // TODO:  Allow copy constructors and assignment operators?
};

static bool gsStreamRegistered_Object = Object::RegisterFactory();
typedef Pointer0<Object> ObjectPtr;
#include "ShrObject.inl"

}

#endif
