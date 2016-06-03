include(ExternalProject)

set(SDL2_FOUND "NO")

# For win32 is better to download just the binaries.
if (WIN32)
  # Get SDL2 dev package
  ExternalProject_Add(
    sdl2
    PREFIX ${DEPENDENCIES_ROOT}
    DOWNLOAD_DIR ${DOWNLOAD_DIR}
    URL https://libsdl.org/release/SDL2-devel-2.0.4-VC.zip
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
    INSTALL_COMMAND ""
      #COMMAND ${CMAKE_COMMAND} -E copy_directory ${DEPENDENCIES_ROOT}/src/sdl2/lib ${DEPENDENCIES_ROOT}/lib
      #COMMAND ${CMAKE_COMMAND} -E copy_directory ${DEPENDENCIES_ROOT}/src/sdl2/include ${DEPENDENCIES_ROOT}/include/sdl2
      # these things require admin privileges so bail out for now
      #COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/Debug
      #COMMAND ${CMAKE_COMMAND} -E copy ${DEPENDENCIES_ROOT}/lib/x86/SDL2.dll ${CMAKE_BINARY_DIR/Debug/}
      )
    set(SDL2_INCLUDE_DIR ${DEPENDENCIES_ROOT}/src/sdl2/include)
    #set(SDL2_INCLUDE_DIR ${DEPENDENCIES_ROOT}/include/SDL2)
    #if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    #  link_directories(${DEPENDENCIES_ROOT}/lib/x64/)
    #else(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(SDL2_LIBRARY_DIR ${DEPENDENCIES_ROOT}/src/sdl2/lib)
    set(SDL2_LIBRARY ${SDL2_LIBRARY} ${DEPENDENCIES_ROOT}/src/sdl2/lib/x86/SDL2.lib)
    set(SDL2_LIBRARY ${SDL2_LIBRARY} ${DEPENDENCIES_ROOT}/src/sdl2/lib/x86/SDL2main.lib)
    #set(SDL2_LIBRARY ${SDL2_LIBRARY} ${DEPENDENCIES_ROOT}/lib/x86/SDL2.lib)
    #set(SDL2_LIBRARY ${SDL2_LIBRARY} ${DEPENDENCIES_ROOT}/lib/x86/SDL2main.lib)
    #endif(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(SDL2_FOUND "YES")
else() # Now, if using anything else, get the sources. (TODO Poor MacOSX guys have nothing yet. :)
  # Build SDL2
  ExternalProject_Add(
    sdl2
    PREFIX ${DEPENDENCIES_ROOT}
    DOWNLOAD_DIR ${DOWNLOAD_DIR}
    URL https://libsdl.org/release/SDL2-2.0.4.tar.gz
    CONFIGURE_COMMAND <SOURCE_DIR>/configure --prefix=${DEPENDENCIES_ROOT}
    )
  # experimental
  set(SDL2_INCLUDE_DIR ${DEPENDENCIES_ROOT}/src/sdl2/include)
  set(SDL2_FOUND "YES")

  set(SDL2_LIBRARY_DIR ${DEPENDENCIES_ROOT}/lib)
  set(SDL2_LIBRARY ${SDL2_LIBRARY} ${SDL2_LIBRARY_DIR}/libSDL2.so)
  set(SDL2_LIBRARY ${SDL2_LIBRARY} ${SDL2_LIBRARY_DIR}/libSDL2main.a)
endif()

# find_path( SDL2_INCLUDE_DIR SDL.H
#   PATH_SUFFIXES include/SDL2 include SDL2
#   PATHS
#   ${DEPENDENCIES_ROOT}/include/SDL2
#   NO_DEFAULT_PATH
#   )
