#include "ShrCorePCH.h"
#include "ShrStream.h"
using namespace shr;

//----------------------------------------------------------------------------
Stream::Stream ()
{
}
//----------------------------------------------------------------------------
Stream::~Stream ()
{
}
//----------------------------------------------------------------------------
int Stream::GetStreamingSize (const std::string& input)
{
    // The string is written to disk, length first and characters second,
    // but with no terminating null character.  It is padded to a multiple of
    // four bytes.
    int length = (int)input.length();
    int padding = 0;
    if (length > 0)
    {
        padding = (length % 4);
        if (padding > 0)
        {
            padding = 4 - padding;
        }
    }
    return sizeof(int) + length*sizeof(char) + padding;
}
//----------------------------------------------------------------------------