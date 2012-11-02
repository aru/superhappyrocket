#ifndef STREAM_H
#define STREAM_H

#include "CoreLIB.h"
#include "BufferIO.h"
#include "InitTerm.h"
#include "SmartPointer.h"

class Stream
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

//----------------------------------------------------------------------------
#define DECLARE_STREAM(classname) \
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
#define IMPLEMENT_STREAM(classname) \
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
#define IMPLEMENT_DEFAULT_STREAM(baseclassname, classname) \
classname::classname (LoadConstructor value) \
    : \
    baseclassname(value) \
{ \
} \
\
void classname::Load (InStream& source) \
{ \
    BEGIN_DEBUG_STREAM_LOAD(source); \
    baseclassname::Load(source); \
    END_DEBUG_STREAM_LOAD(baseclassname, source); \
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
    BEGIN_DEBUG_STREAM_SAVE(target); \
    baseclassname::Save(target); \
    END_DEBUG_STREAM_SAVE(baseclassname, target); \
} \
\
int classname::GetStreamingSize () const \
{ \
    return baseclassname::GetStreamingSize(); \
}
//----------------------------------------------------------------------------
#define IMPLEMENT_ABSTRACT_FACTORY(classname) \
Object* classname::Factory (InStream&) \
{ \
    assert(false, "Abstract classes have no factory.\n"); \
    return 0; \
}
//----------------------------------------------------------------------------
#define IMPLEMENT_FACTORY(classname) \
Object* classname::Factory (InStream& source) \
{ \
    classname* object = new0 classname(LC_LOADER); \
    object->Load(source); \
    return object; \
}
//----------------------------------------------------------------------------
#define REGISTER_STREAM(classname) \
static bool gsStreamRegistered_##classname = classname::RegisterFactory()
//----------------------------------------------------------------------------
#ifdef USE_ASSERT
#define BEGIN_DEBUG_STREAM_LOAD(source) \
    int beginLoad_ = source.GetBytesRead()
#else
#define BEGIN_DEBUG_STREAM_LOAD(source)
#endif
//----------------------------------------------------------------------------
#ifdef USE_ASSERT
#define END_DEBUG_STREAM_LOAD(classname,source) \
    int endLoad_ = source.GetBytesRead(); \
    int usedLoad_ = endLoad_ - beginLoad_ + \
        Stream::GetStreamingSize(GetRttiType().GetName()); \
    int usedReported_ = classname::GetStreamingSize(); \
    assert(usedLoad_ == usedReported_, \
        "Mismatched bytes during Load: loaded = %d, required = %d\n", \
        usedLoad_, usedReported_)
#else
#define END_DEBUG_STREAM_LOAD(classname,source)
#endif
//----------------------------------------------------------------------------
#ifdef USE_ASSERT
#define BEGIN_DEBUG_STREAM_SAVE(target) \
    int beginSave_ = target.GetBytesWritten()
#else
#define BEGIN_DEBUG_STREAM_SAVE(target)
#endif
//----------------------------------------------------------------------------
/* assert == "Mismatched bytes during Save: saved = %d, required = %d\n", usedSave_, usedReported_) */
#ifdef USE_ASSERT
#define END_DEBUG_STREAM_SAVE(classname,target) \
    int endSave_ = target.GetBytesWritten(); \
    int usedSave_ = endSave_ - beginSave_; \
    int usedReported_ = classname::GetStreamingSize(); \
    assert(usedSave_ == usedReported_ )\
#else
#define END_DEBUG_STREAM_SAVE(classname,target)
#endif
//----------------------------------------------------------------------------
// The POINTERSIZE macro is used by the streaming system.  A unique ID is
// an unsigned int written to 4 bytes on disk.
#define POINTERSIZE(value) 4
//----------------------------------------------------------------------------
// The BOOLSIZE macro is used by the streaming system.  A bool is written
// to 4 bytes on disk.
#define BOOLSIZE(value) 4
//----------------------------------------------------------------------------
// The ENUMSIZE macro is used by the streaming system.  An enum is written
// to 4 bytes on disk.
#define ENUMSIZE(value) 4
//----------------------------------------------------------------------------
#define STRINGSIZE(value) Stream::GetStreamingSize(value)
//----------------------------------------------------------------------------

#endif
