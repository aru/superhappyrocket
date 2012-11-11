#include "ShrCorePCH.h"
#include "ShrInitTerm.h"
#include "ShrAssert.h"
using namespace shr;

int InitTerm::msNumInitializers = 0;
InitTerm::Initializer InitTerm::msInitializers[MAX_ELEMENTS];
int InitTerm::msNumTerminators = 0;
InitTerm::Terminator InitTerm::msTerminators[MAX_ELEMENTS];

//----------------------------------------------------------------------------
void InitTerm::AddInitializer (Initializer function)
{
    if (msNumInitializers < MAX_ELEMENTS)
    {
        msInitializers[msNumInitializers++] = function;
    }
    else
    {
        assertion(false, "Increase MAX_ELEMENTS and recompile LibCore\n");
    }
}
//----------------------------------------------------------------------------
void InitTerm::ExecuteInitializers ()
{
    for (int i = 0; i < msNumInitializers; ++i)
    {
        msInitializers[i]();
    }
}
//----------------------------------------------------------------------------
void InitTerm::AddTerminator (Terminator function)
{
    if (msNumTerminators < MAX_ELEMENTS)
    {
        msTerminators[msNumTerminators++] = function;
    }
    else
    {
        assertion(false, "Increase MAX_ELEMENTS and recompile LibCore\n");
    }
}
//----------------------------------------------------------------------------
void InitTerm::ExecuteTerminators ()
{
    for (int i = 0; i < msNumTerminators; ++i)
    {
        msTerminators[i]();
    }
}
//----------------------------------------------------------------------------
