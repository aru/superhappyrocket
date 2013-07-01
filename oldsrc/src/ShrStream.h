#ifndef SHRSTREAM_H
#define SHRSTREAM_H

#include "ShrCoreLIB.h"
#include "ShrBufferIO.h"
#include "ShrInitTerm.h"
#include "ShrSmartPointer.h"

namespace shr
{

class SHR_CORE_ITEM Stream
{
public:
    // This function returns the number of bytes required to store a string.
    // The string length is stored first, as an integer, followed by its
    // characters.  The string is padded with zeros so that the total storage
    // uses a multiple of four bytes.
    static int GetStreamingSize (const std::string& input);

protected:
    // Abstract base class.
    Stream ();
    virtual ~Stream ();
};

}

//----------------------------------------------------------------------------
#define SHR_DECLARE_STREAM(classname) \
public: \
    static bool RegisterFactory (); \
    static void InitializeFactory (); \
    static Object* Factory (InStream&); \
    virtual void Load (InStream&); \
    virtual void Link (InStream&); \
    virtual void PostLink (); \
    virtual bool Register (OutStream&) const; \
    virtual void Save (OutStream&) const; \
    virtual int GetStreamingSize () const; \
protected: \
    friend class Memory; \
    classname (LoadConstructor value); \
private: \
    static bool msStreamRegistered
//----------------------------------------------------------------------------
#define SHR_IMPLEMENT_STREAM(classname) \
bool classname::msStreamRegistered = false; \
\
bool classname::RegisterFactory () \
{ \
    if (!msStreamRegistered) \
    { \
        InitTerm::AddInitializer(classname::InitializeFactory); \
        msStreamRegistered = true; \
    } \
    return msStreamRegistered; \
} \
\
void classname::InitializeFactory () \
{ \
    if (!msFactories) \
    { \
        msFactories = new0 Object::FactoryMap(); \
    } \
    msFactories->insert(std::make_pair(TYPE.GetName(), Factory)); \
}
//----------------------------------------------------------------------------
#define SHR_IMPLEMENT_DEFAULT_STREAM(baseclassname, classname) \
classname::classname (LoadConstructor value) \
    : \
    baseclassname(value) \
{ \
} \
\
void classname::Load (InStream& source) \
{ \
    SHR_BEGIN_DEBUG_STREAM_LOAD(source); \
    baseclassname::Load(source); \
    SHR_END_DEBUG_STREAM_LOAD(baseclassname, source); \
} \
\
void classname::Link (InStream& source) \
{ \
    baseclassname::Link(source); \
} \
void classname::PostLink () \
{ \
    baseclassname::PostLink(); \
} \
\
bool classname::Register (OutStream& target) const \
{ \
    return baseclassname::Register(target); \
} \
\
void classname::Save (OutStream& target) const \
{ \
    SHR_BEGIN_DEBUG_STREAM_SAVE(target); \
    baseclassname::Save(target); \
    SHR_END_DEBUG_STREAM_SAVE(baseclassname, target); \
} \
\
int classname::GetStreamingSize () const \
{ \
    return baseclassname::GetStreamingSize(); \
}
//----------------------------------------------------------------------------
#define SHR_IMPLEMENT_ABSTRACT_FACTORY(classname) \
Object* classname::Factory (InStream&) \
{ \
    assertion(false, "Abstract classes have no factory.\n"); \
    return 0; \
}
//----------------------------------------------------------------------------
#define SHR_IMPLEMENT_FACTORY(classname) \
Object* classname::Factory (InStream& source) \
{ \
    classname* object = new0 classname(LC_LOADER); \
    object->Load(source); \
    return object; \
}
//----------------------------------------------------------------------------
#define SHR_REGISTER_STREAM(classname) \
static bool gsStreamRegistered_##classname = classname::RegisterFactory()
//----------------------------------------------------------------------------
#ifdef SHR_USE_ASSERT
#define SHR_BEGIN_DEBUG_STREAM_LOAD(source) \
    int beginLoad_ = source.GetBytesRead()
#else
#define SHR_BEGIN_DEBUG_STREAM_LOAD(source)
#endif
//----------------------------------------------------------------------------
#ifdef SHR_USE_ASSERT
#define SHR_END_DEBUG_STREAM_LOAD(classname,source) \
    int endLoad_ = source.GetBytesRead(); \
    int usedLoad_ = endLoad_ - beginLoad_ + \
        Stream::GetStreamingSize(GetRttiType().GetName()); \
    int usedReported_ = classname::GetStreamingSize(); \
    assertion(usedLoad_ == usedReported_, \
        "Mismatched bytes during Load: loaded = %d, required = %d\n", \
        usedLoad_, usedReported_)
#else
#define SHR_END_DEBUG_STREAM_LOAD(classname,source)
#endif
//----------------------------------------------------------------------------
#ifdef SHR_USE_ASSERT
#define SHR_BEGIN_DEBUG_STREAM_SAVE(target) \
    int beginSave_ = target.GetBytesWritten()
#else
#define SHR_BEGIN_DEBUG_STREAM_SAVE(target)
#endif
//----------------------------------------------------------------------------
#ifdef SHR_USE_ASSERT
#define SHR_END_DEBUG_STREAM_SAVE(classname,target) \
    int endSave_ = target.GetBytesWritten(); \
    int usedSave_ = endSave_ - beginSave_; \
    int usedReported_ = classname::GetStreamingSize(); \
    assertion(usedSave_ == usedReported_, \
        "Mismatched bytes during Save: saved = %d, required = %d\n", \
        usedSave_, usedReported_)
#else
#define SHR_END_DEBUG_STREAM_SAVE(classname,target)
#endif
//----------------------------------------------------------------------------
// The SHR_POINTERSIZE macro is used by the streaming system.  A unique ID is
// an unsigned int written to 4 bytes on disk.
#define SHR_POINTERSIZE(value) 4
//----------------------------------------------------------------------------
// The SHR_BOOLSIZE macro is used by the streaming system.  A bool is written
// to 4 bytes on disk.
#define SHR_BOOLSIZE(value) 4
//----------------------------------------------------------------------------
// The SHR_ENUMSIZE macro is used by the streaming system.  An enum is written
// to 4 bytes on disk.
#define SHR_ENUMSIZE(value) 4
//----------------------------------------------------------------------------
#define SHR_STRINGSIZE(value) Stream::GetStreamingSize(value)
//----------------------------------------------------------------------------

#endif
