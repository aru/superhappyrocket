# Look for biicode and resolve future project dependencies
if( BIICODE )
  include("biicode.cmake")
  return()
endif()

# Normal cmake configuration follows
cmake_minimum_required( VERSION 2.8.4 )
project( SHR )

set(SHR_VERSION_MAJOR 1)
set(SHR_VERSION_MINOR 0)


