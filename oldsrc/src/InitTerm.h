#ifndef INITTERM_H
#define INITTERM_H

#include "CoreLIB.h"

class InitTerm
{
public:
    typedef void (*Initializer)(void);
    static void AddInitializer (Initializer function);
    static void ExecuteInitializers ();

    typedef void (*Terminator)(void);
    static void AddTerminator (Terminator function);
    static void ExecuteTerminators ();

private:
    // This number must be large enough to support your application.  If your
    // application triggers an assert about exceeding this, change this number
    // and recompile.  The goal is to avoid dynamic allocation during premain
    // and postmain execution, thus making it easier to manage and track
    // memory usage.
    enum
    {
        MAX_ELEMENTS = 512
    };

    static int msNumInitializers;
    static Initializer msInitializers[MAX_ELEMENTS];

    static int msNumTerminators;
    static Terminator msTerminators[MAX_ELEMENTS];
};

//----------------------------------------------------------------------------
#define DECLARE_INITIALIZE \
public: \
    static bool RegisterInitialize (); \
    static void Initialize (); \
private: \
    static bool msInitializeRegistered
//----------------------------------------------------------------------------
#define IMPLEMENT_INITIALIZE(classname) \
bool classname::msInitializeRegistered = false; \
bool classname::RegisterInitialize () \
{ \
    if (!msInitializeRegistered) \
    { \
        InitTerm::AddInitializer(classname::Initialize); \
        msInitializeRegistered = true; \
    } \
    return msInitializeRegistered; \
}
//----------------------------------------------------------------------------
#define REGISTER_INITIALIZE(classname) \
static bool gsInitializeRegistered_##classname = \
    classname::RegisterInitialize ()
//----------------------------------------------------------------------------
#define DECLARE_TERMINATE \
public: \
    static bool RegisterTerminate (); \
    static void Terminate (); \
private: \
    static bool msTerminateRegistered
//----------------------------------------------------------------------------
#define IMPLEMENT_TERMINATE(classname) \
bool classname::msTerminateRegistered = false; \
bool classname::RegisterTerminate () \
{ \
    if (!msTerminateRegistered) \
    { \
        InitTerm::AddTerminator(classname::Terminate); \
        msTerminateRegistered = true; \
    } \
    return msTerminateRegistered; \
}
//----------------------------------------------------------------------------
#define REGISTER_TERMINATE(classname) \
static bool gsTerminateRegistered_##classname = \
    classname::RegisterTerminate ()
//----------------------------------------------------------------------------

#endif
