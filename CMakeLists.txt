# Minimum required CMake version is 3.5
cmake_minimum_required(VERSION 3.5)

# Prevent in-tree build, you should always build outside of the source tree
# it makes it easy to:
# clean up whatever mess you do in the build directory
# distribute the source directory
if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
  message(FATAL_ERROR "Prevented in-tree built. Please create a build directory outside of the SHR source code and call cmake from there")
endif()

# Project name
project(shr_engine)
# Set the current version of this engine
set(SHR_ENGINE_MAJOR_VERSION 1)
set(SHR_ENGINE_MINOR_VERSION 0)
set(SHR_VERSION "${SHR_ENGINE_MAJOR_VERSION}.${SHR_ENGINE_MINOR_VERSION}")

# Add all of our source files in here
set(SOURCE_PATH ./src)

set(AUDIO_FILES
  ${SOURCE_PATH}/AudioManager.cpp
  ${SOURCE_PATH}/AudioManager.h
  )

set(CONTEXT_FILES
  ${SOURCE_PATH}/Context.cpp
  ${SOURCE_PATH}/Context.h
  )

set(DATATYPES_FILES
  ${SOURCE_PATH}/CubeMap.cpp
  ${SOURCE_PATH}/CubeMap.h
  ${SOURCE_PATH}/Light.cpp
  ${SOURCE_PATH}/Light.h
  ${SOURCE_PATH}/ReflectedObject.cpp
  ${SOURCE_PATH}/ReflectedObject.h
  ${SOURCE_PATH}/SimpleObject.cpp
  ${SOURCE_PATH}/SimpleObject.h
  )

set(GAMEOBJECTS_FILES
  ${SOURCE_PATH}/Entity.cpp
  ${SOURCE_PATH}/Entity.h
  )

set(LEVELS_FILES
  ${SOURCE_PATH}/BaseLevel.cpp
  ${SOURCE_PATH}/BaseLevel.h
  ${SOURCE_PATH}/Level1.cpp
  ${SOURCE_PATH}/Level1.h
  )

set(SCENEMANAGEMENT_FILES
  ${SOURCE_PATH}/EntityManager.cpp
  ${SOURCE_PATH}/EntityManager.h
  ${SOURCE_PATH}/SceneManager.cpp
  ${SOURCE_PATH}/SceneManager.h
  )

set(INPUT_FILES
  ${SOURCE_PATH}/InputManager.cpp
  ${SOURCE_PATH}/InputManager.h
  )

set(PHYSICS_FILES
  ${SOURCE_PATH}/BoundingBox.cpp
  ${SOURCE_PATH}/BoundingBox.h
  )

set(RENDERER_FILES
  ${SOURCE_PATH}/OpenGLRenderer.cpp
  ${SOURCE_PATH}/OpenGLRenderer.h
  )

set(CAMERA_FILES
  ${SOURCE_PATH}/Camera.cpp
  ${SOURCE_PATH}/Camera.h
  )

set(TEXTURE_FILES
  ${SOURCE_PATH}/Texture2D.cpp
  ${SOURCE_PATH}/Texture2D.h
  ${SOURCE_PATH}/TextureManager.cpp
  ${SOURCE_PATH}/TextureManager.h
  )

set(SDLAPP_FILES
  ${SOURCE_PATH}/SDLApp.cpp
  ${SOURCE_PATH}/SDLApp.h
  )

set(UTILS_FILES
  ${SOURCE_PATH}/assimpMesh.cpp
  ${SOURCE_PATH}/assimpMesh.h
  ${SOURCE_PATH}/Timer.cpp
  ${SOURCE_PATH}/Timer.h
  )

add_executable(SuperHappyRocket
  ${AUDIO_FILES}
  ${CONTEXT_FILES}
  ${DATATYPES_FILES}
  ${GAMEOBJECTS_FILES}
  ${LEVELS_FILES}
  ${SCENEMANAGEMENT_FILES}
  ${INPUT_FILES}
  ${PHYSICS_FILES}
  ${RENDERER_FILES}
  ${CAMERA_FILES}
  ${TEXTURE_FILES}
  ${SDLAPP_FILES}
  ${UTILS_FILES}
  #glad/src/glad.c
  src/main.cpp
  )
source_group(Audio FILES ${AUDIO_FILES} )
source_group(Context FILES ${CONTEXT_FILES})
source_group(DataTypes FILES ${DATATYPES_FILES})
source_group(GameObjects FILES ${GAMEOBJECTS_FILES})
source_group(Levels FILES ${LEVELS_FILES})
source_group(SceneManagement FILES ${SCENEMANAGEMENT_FILES})
source_group(Input FILES ${INPUT_FILES})
source_group(Renderer FILES ${RENDERER_FILES})
source_group(Renderer\\Camera FILES ${CAMERA_FILES})
source_group(Renderer\\Textures FILES ${TEXTURE_FILES})
source_group(SDLApp FILES ${SDLAPP_FILES})
source_group(UtilsAndImporters FILES ${UTILS_FILES})
source_group(Physics FILES ${PHYSICS_FILES})

# find our additional FindPackage macros for CMake
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/CMakeModules)

# Set compiler flags for our project

### Currently these are gcc only ###
### TODO: Do MSVC specific flags ###
### TODO: Do Debug/Release specific flags ###

# global compilation flags
set_property( GLOBAL PROPERTY CXX_STANDARD 11 )

# Set debugging symbols on
if((CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX) AND NOT CMAKE_COMPILER_IS_MINGW)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
  # Make all warnings appear
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
  # Set the language and library standard, shouldn't be needed with above property
  # set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
  # The -march flag will instruct the compiler to produce specific code for the
  # system's CPU, with all its capabilities, features, instruction sets, quirks.
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=native")
endif()

### Find the libraries that we need for this project ###
add_subdirectory(GLTools)
# External Project allows CMake to create a custom target to drive download,
# update/patch, configure, build, install and test steps of an external
# project. We want to use this to build libraries we need.
include(ExternalProject)

# Get the external root path, this is where we will install downloaded libraries
get_filename_component(DEPENDENCIES_ROOT ${CMAKE_BINARY_DIR}/../dependencies ABSOLUTE)
message(STATUS "Using ${DEPENDENCIES_ROOT} to place downloaded packages")

# First look for SDL2
find_package(SDL2)
# If we can't find it, build the one we include in the dependencies folder
if(NOT SDL2_FOUND)
  message(STATUS "SDL2 not found, downloading and building it.")
  include(get-sdl2)
  #find_package(SDL2)
  add_dependencies(SuperHappyRocket sdl2)
  #add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/dependencies/SDL2-2.0.4)
  #set(SDL2_PATH ${CMAKE_CURRENT_SOURCE_DIR}/dependencies/SDL2-2.0.4)
else(NOT SDL2_FOUND)
  message(STATUS "SDL2 found in ${SDL2_INCLUDE_DIR} and ${SDL2_LIBRARY}")
endif(NOT SDL2_FOUND)

# Now look for SDL2 Mixer
find_package(SDL2_Mixer)
# If we can't find it, build the one we include in the dependencies folder
if(NOT SDL2_MIXER_FOUND)
  message(STATUS "SDL2_Mixer not found, downloading and building it.")
  include(get-sdl2-mixer)
  add_dependencies(SuperHappyRocket sdl2-mixer)
  #add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/dependencies/SDL2_mixer-2.0.1)
  #set(SDL2_PATH ${CMAKE_CURRENT_SOURCE_DIR}/dependencies/SDL2_mixer-2.0.1)
else(NOT SDL2_MIXER_FOUND)
  message(STATUS "SDL2_Mixer found in ${SDL2_MIXER_INCLUDE_DIRS} and ${SDL2_MIXER_LIBRARIES}")
endif(NOT SDL2_MIXER_FOUND)
# Look for SDL2_Image
#find_package(SDL2_Image)

# Now look for Assimp
find_package(ASSIMP)
# If we can't find it, build the one we include in the dependencies folder
if(NOT ASSIMP_FOUND)
  message(STATUS "ASSIMP not found, downloading and building it.")
  include(get-assimp)
  #ExternalProject_Get_Property(assimp INSTALL_DIR)
  add_dependencies(SuperHappyRocket assimp)
  #add_subdirectory(${DEPENDENCIES_ROOT}/src/assimp)
endif(NOT ASSIMP_FOUND)
#find_package(ASSIMP REQUIRED)

# No need to find OpenGL either, as glew already provides it.
# find_package(OpenGL REQUIRED)

# define the include files for our engine
SET(SHR_ENGINE_INCLUDES
  #glad/include #experimental
  ${SDL2_INCLUDE_DIR}
  ${SDL_MIXER_INCLUDE_DIRS}
  ${SDL2_MIXER_INCLUDE_DIRS}
  #${SDL2_SOURCE_DIR}/include
  ${ASSIMP_INCLUDE_DIR}
  /GLTools/include
  )

# define the library include files we need for our engine
# GLM is a header only library, we only need to include its .h file
SET(SHR_ENGINE_LIBS
  ${SDL2_LIBRARY}
  ${SDL_MIXER_LIBRARIES}
  ${SDL2_MIXER_LIBRARIES}
  ${ASSIMP_LIBRARIES}
  gltools
  )

target_include_directories(SuperHappyRocket PUBLIC ${SHR_ENGINE_INCLUDES})
target_link_libraries(SuperHappyRocket ${SHR_ENGINE_LIBS} )

# Windows requires us to move the dlls to the executable's folder
if(MSVC)
add_custom_command( TARGET SuperHappyRocket POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
  "${SDL2_LIBRARY_DIR}/x86/SDL2.dll"
  $<TARGET_FILE_DIR:SuperHappyRocket>)

add_custom_command( TARGET SuperHappyRocket POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
  "${SDL2_MIXER_LIBRARY_DIR}/x86/SDL2_mixer.dll"
  $<TARGET_FILE_DIR:SuperHappyRocket>)

add_custom_command( TARGET SuperHappyRocket POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
  "${ASSIMP_INCLUDE_DIR}/../bin/assimp-vc140-mt.dll"
  $<TARGET_FILE_DIR:SuperHappyRocket>)
endif(MSVC)

#include_directories(${SHR_ENGINE_INCLUDES})
# uncomment this once our engine is a library.
#add_library(shr_engine SHARED ${TARGET_SRC})
#target_link_libraries(shr_engine ${ENGINE_LIBS})


#target_link_libraries(SuperHappyRocket shr_engine)

# install our newly created libraries
#install (TARGETS shr_engine DESTINATION lib)
#install (FILES ${TARGET_INC} DESTINATION include/shr_engine)
#install (FILES ${TARGET_INC_COMPONENTS} DESTINATION include/shr_engine/components)
