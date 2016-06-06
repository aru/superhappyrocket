# For Assimp we will try to download the current build at github
# this is a bit risky, because the library may not be in a stable state
# however the current version of Assimp(3.2) in their website isn't working
# either without modifications to it, while it is really better to just
# install the libraries via a package manager, for Windows we don't have that.
# So we will be getting the source through git, there are 2 ways to do this:
#   1. get them via git
#   2. get them via normal download
# Number 1 is easily updateable and is a solution that we should explore,
# but for now, we will just do Number 2, as it is what we do for the rest
# of the libraries, if we were to do Number 1, we should also do this for
# the rest of the libraries, CMake has HG support, which SDL uses as of today.

include(ExternalProject)

set(ASSIMP_FOUND FALSE)

if(WIN32)
# Get SDL2 dev package
  ExternalProject_Add(
    assimp
    #GIT_REPOSITORY git@github.com:assimp/assimp.git
    #TIMEOUT 10
    PREFIX ${DEPENDENCIES_ROOT}
    URL https://github.com/assimp/assimp/archive/master.zip
    DOWNLOAD_DIR ${DOWNLOAD_DIR}
    #CONFIGURE_COMMAND ""
    #BUILD_COMMAND ""
    #INSTALL_COMMAND ""
    INSTALL_DIR ${DEPENDENCIES_ROOT}/src/assimp-install
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=<INSTALL_DIR> -DASSIMP_BUILD_ASSIMP_TOOLS=NO
    )
  set(ASSIMP_INCLUDE_DIR ${DEPENDENCIES_ROOT}/src/assimp-install/include/)
  #if(CMAKE_SIZEOF_VOID_P EQUAL 8)
  #  link_directories(${DEPENDENCIES_ROOT}/lib/x64/)
  #else(CMAKE_SIZEOF_VOID_P EQUAL 8)
  set(ASSIMP_LIBRARIES ${ASSIMP_LIBRARIES} ${DEPENDENCIES_ROOT}/src/assimp-install/lib/assimp-vc140-mt.lib)
  set(ASSIMP_LIBRARY ${ASSIMP_LIBRARY})
  set(ASSIMP_FOUND TRUE)
  #set(ASSIMP_LIBRARIES ${ASSIMP_LIBRARIES} ${DEPENDENCIES_ROOT}/lib/x86/SDL2main.lib)
  #endif(CMAKE_SIZEOF_VOID_P EQUAL 8)
else(WIN32)
  ExternalProject_Add(
    assimp
    #GIT_REPOSITORY git@github.com:assimp/assimp.git
    #TIMEOUT 10
    PREFIX ${DEPENDENCIES_ROOT}
    URL https://github.com/assimp/assimp/archive/master.zip
    DOWNLOAD_DIR ${DOWNLOAD_DIR}
    INSTALL_DIR ${DEPENDENCIES_ROOT}/src/assimp-install
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=<INSTALL_DIR> -DASSIMP_BUILD_ASSIMP_TOOLS=NO
    #CONFIGURE_COMMAND <SOURCE_DIR>/configure --prefix=${DEPENDENCIES_ROOT}
    #BUILD_COMMAND ""
    #INSTALL_COMMAND
    )
  # Experimental
  set(ASSIMP_INCLUDE_DIR ${DEPENDENCIES_ROOT}/src/assimp-install/include/)
  if(APPLE)
    set(ASSIMP_LIBRARIES ${ASSIMP_LIBRARIES} ${DEPENDENCIES_ROOT}/src/assimp-install/lib/libassimp.dylib)
  else(APPLE)
    set(ASSIMP_LIBRARIES ${ASSIMP_LIBRARIES} ${DEPENDENCIES_ROOT}/src/assimp-install/lib/libassimp.so)
  endif(APPLE)
  set(ASSIMP_LIBRARY ${ASSIMP_LIBRARY})
  set(ASSIMP_FOUND TRUE)
endif(WIN32)
