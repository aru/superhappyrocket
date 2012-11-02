#include "Core.h"
#include "InitTerm.h"
#include "Assert.h"

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
        assert(false); /* Increase MAX_ELEMENTS and recompile LibCore */
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
        assert(false); /* Increase MAX_ELEMENTS and recompile LibCore */
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
