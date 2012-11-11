// Geometric Tools, LLC
// Copyright (c) 1998-2012
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 5.0.0 (2010/01/01)

#ifndef SHR_APPLICATION_H
#define SHR_APPLICATION_H

#include "ShrCore.h"
#include "ShrMathematics.h"
//#include "ShrImagics.h"
//#include "ShrPhysics.h"
//#include "ShrGraphics.h"
//#include "ShrRenderers.h"
#include "ShrCommand.h"

namespace shr
{

class Application
{
protected:
    // Abstract base class.
    Application ();
public:
    virtual ~Application ();

    // The unique application object.
    static Application* TheApplication;

    // The unique command-line arguments object.
    static Command* TheCommand;

    // The installation directory of Super Happy Rocket.
    static std::string Path;

    // The path to the application project directory.
    static std::string ThePath;

    // Derived classes must set this function pointer.  The int parameter is
    // the number of command line arguments.  The char** parameter is the
    // array of argument strings.
    typedef int (*EntryPoint)(int, char**);
    static EntryPoint Run;
};

}

#endif
