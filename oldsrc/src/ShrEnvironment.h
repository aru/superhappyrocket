#ifndef SHRENVIRONMENT_H
#define SHRENVIRONMENT_H

#include "ShrCoreLIB.h"
#include "ShrInitTerm.h"

namespace shr
{

class SHR_CORE_ITEM Environment
{
    SHR_DECLARE_INITIALIZE;
    SHR_DECLARE_TERMINATE;

public:
    // Get the string corresponding to an environment variable.
    static std::string GetVariable (const std::string& varName);

    // Support for paths to locate files.  For platform independence, use
    // "/" for the path separator.  Please terminate the input 'directory'
    // values with "/".  The Insert/Remove functions return 'true' iff the
    // operation was successful.
    static int GetNumDirectories ();
    static std::string GetDirectory (int i);
    static bool InsertDirectory (const std::string& directory);
    static bool RemoveDirectory (const std::string& directory);
    static void RemoveAllDirectories ();

    // The GetPath* function searches the list of directories and returns the
    // fully decorated file name, assuming it satisfies the required
    // conditions, or returns "" if conditions are not met.  GetPathR succeeds
    // when the file can be opened for reading.  GetPathW succeeds when the
    // file can be opened for writing.  GetPathRW succedds when the file can
    // be opened for reading and/or writing.
    static std::string GetPath (const std::string& fileName, int mode);
    static std::string GetPathR (const std::string& fileName);
    static std::string GetPathW (const std::string& fileName);
    static std::string GetPathRW (const std::string& fileName);

private:
    static std::string GetPath (const std::string& filename,
        const char* attributes);

    // The list of directories for GetPath to search.  The list is
    // allocated during InitTerm::ExecuteInitializers.  As with other
    // classes in Wild Magic, no dynamic allocation occurs pre-main to
    // assist in tracking memory problems.
    static std::vector<std::string>* msDirectories;
};

SHR_REGISTER_INITIALIZE(Environment);
SHR_REGISTER_TERMINATE(Environment);

}

#endif
