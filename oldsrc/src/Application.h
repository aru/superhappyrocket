#ifndef APPLICATION_H
#define APPLICATION_H

#include "Core.h"
#include "Command.h"

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

    // The installation directory of Wild Magic 5.
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
