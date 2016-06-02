# Modified module to get sdl2_mixer
# based on the gear2D engine, modified to work on Windows without minGW
include(ExternalProject)

if (WIN32)
  # Get SDL2 Mixer dev package
  ExternalProject_Add(
    sdl2-mixer
    DEPENDS sdl2
    PREFIX ${DEPENDENCIES_ROOT}
    DOWNLOAD_DIR ${DOWNLOAD_DIR}
    URL https://www.libsdl.org/projects/SDL_mixer/release/SDL2_mixer-devel-2.0.1-VC.zip
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
    INSTALL_COMMAND ""
      #COMMAND ${CMAKE_COMMAND} -E copy_directory ${EXTERNAL_ROOT}/src/sdl2-mixer/lib ${EXTERNAL_ROOT}/lib
      #COMMAND ${CMAKE_COMMAND} -E copy_directory ${EXTERNAL_ROOT}/src/sdl2-mixer/include ${EXTERNAL_ROOT}/include/sdl2
      )
    set(SDL_MIXER_FOUND TRUE)
    set(SDLMIXER_FOUND ${SDL_MIXER_FOUND})

    set(SDL_MIXER_INCLUDE_DIRS ${DEPENDENCIES_ROOT}/src/sdl2-mixer/include/)
    set(SDLMIXER_INCLUDE_DIR ${SDL_MIXER_INCLUDE_DIRS})
    set(SDL2_MIXER_INCLUDE_DIRS ${SDLMIXER_INCLUDE_DIR})

    #set(SDL_MIXER_INCLUDE_DIRS ${DEPENDENCIES_ROOT}/include/sdl2)
    #if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    #  link_directories(${DEPENDENCIES_ROOT}/lib/x64/)
    #else(CMAKE_SIZEOF_VOID_P EQUAL 8)

    set(SDL_MIXER_LIBRARIES ${SDL_MIXER_LIBRARIES} ${DEPENDENCIES_ROOT}/src/sdl2-mixer/lib/x86/SDL2_mixer.lib)
    set(SDL2_MIXER_LIBRARY_DIR ${DEPENDENCIES_ROOT}/src/sdl2-mixer/lib)
    set(SDLMIXER_LIBRARY ${SDL_MIXER_LIBRARIES})
    set(SDL2_MIXER_LIBRARY ${SDLMIXER_LIBRARY})
    set(SDL2_MIXER_LIBRARIES ${SDL_MIXER_LIBRARY})

    #endif(CMAKE_SIZEOF_VOID_P EQUAL 8)
else()
  # Yay, we need mixer friends.

  ExternalProject_Add(
    ogg
    PREFIX ${EXTERNAL_ROOT}
    DOWNLOAD_DIR ${DOWNLOAD_DIR}
    URL http://downloads.xiph.org/releases/ogg/libogg-1.3.1.tar.gz
    CONFIGURE_COMMAND <SOURCE_DIR>/configure --prefix=${EXTERNAL_ROOT}
  )

  ExternalProject_Add(
    vorbis
    PREFIX ${EXTERNAL_ROOT}
    DOWNLOAD_DIR ${DOWNLOAD_DIR}
    URL http://downloads.xiph.org/releases/vorbis/libvorbis-1.3.4.tar.gz
    CONFIGURE_COMMAND <SOURCE_DIR>/configure --prefix=${EXTERNAL_ROOT}
    DEPENDS ogg
  )

  ExternalProject_Add(
    tremor
    PREFIX ${EXTERNAL_ROOT}
    DOWNLOAD_DIR ${DOWNLOAD_DIR}
    SVN_REPOSITORY http://svn.xiph.org/trunk/Tremor/
    CONFIGURE_COMMAND PKG_CONFIG_PATH=${EXTERNAL_ROOT}/lib/pkgconfig <SOURCE_DIR>/autogen.sh --prefix=${EXTERNAL_ROOT} --with-sysroot=${EXTERNAL_ROOT}
    UPDATE_COMMAND ""
    # patch commands are experimental
    PATCH_COMMAND patch -d<SOURCE_DIR> -N < ${CMAKE_SOURCE_DIR}/patches/tremor-no-ogg-error-message.patch
    DEPENDS ogg vorbis
  )

  ExternalProject_Add(
    flac
    PREFIX ${EXTERNAL_ROOT}
    DOWNLOAD_DIR ${DOWNLOAD_DIR}
    URL http://downloads.xiph.org/releases/flac/flac-1.2.1.tar.gz
    CONFIGURE_COMMAND <SOURCE_DIR>/configure --prefix=${EXTERNAL_ROOT} --disable-xmms-plugin --disable-oggtest --disable-doxygen-docs --disable-rpath
    BUILD_IN_SOURCE 1 # FLAC wants its api/ folder :(
    # patch commands are experimental
    PATCH_COMMAND patch -Np1 < ${CMAKE_SOURCE_DIR}/patches/flac-1.2.1.patch
    DEPENDS tremor
  )

  ExternalProject_Add(
    smpeg
    PREFIX ${EXTERNAL_ROOT}
    DOWNLOAD_DIR ${DOWNLOAD_DIR}
    URL https://libsdl.org/projects/SDL_mixer/release/SDL2_mixer-2.0.0.tar.gz # smpeg2 from trunk is messy.
    CONFIGURE_COMMAND <SOURCE_DIR>/external/smpeg2-2.0.0/configure --prefix=${EXTERNAL_ROOT}
    DEPENDS sdl2
  )


  # Build sdl2-mixer
  ExternalProject_Add(
    sdl2-mixer
    DEPENDS sdl2 flac smpeg tremor
    PREFIX ${EXTERNAL_ROOT}
    DOWNLOAD_DIR ${DOWNLOAD_DIR}
    URL https://libsdl.org/projects/SDL_mixer/release/SDL2_mixer-2.0.0.tar.gz
    CONFIGURE_COMMAND
      PKG_CONFIG_PATH=${EXTERNAL_ROOT}/lib/pkgconfig
      CFLAGS+=-I${EXTERNAL_ROOT}/include
      CFLAGS+=-I${EXTERNAL_ROOT}/include/tremor
      LDFLAGS=-L${EXTERNAL_ROOT}/lib
      <SOURCE_DIR>/configure
        --prefix=${EXTERNAL_ROOT}
        --with-smpeg-prefix=${EXTERNAL_ROOT}
        --enable-music-ogg-tremor
  )

endif()
