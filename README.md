# Super Happy Rocket
A very simple 3D runner made in C++ with SDL and OpenGL, made for our learning
purposes.
The current build status is:

Linux: [![travis-build-status](https://travis-ci.org/aru/superhappyrocket.svg "travis-build-status")](https://travis-ci.org/aru/superhappyrocket)   Windows: [![appveyor-build-status](https://ci.appveyor.com/api/projects/status/ca2a2qkvwaufp40y?svg=true "appveyor-build-status")](https://ci.appveyor.com/project/aru/superhappyrocket)


## Cross-platform

Everything works in:
- Windows
- Linux
- OS X


## Dependencies

- Assimp
- SDL2
- SDL2_mixer
- SDL2_image
- SDL2_ttf

## Installing

SuperHappyRocket uses CMake as part of its build process:

1. Download and install CMake (https://cmake.org/)
2. Create a new folder where you cloned this repository (i.e. build/)
3. Change into this new folder (i.e. cd build)
4. Run CMake and point to the root directory (i.e. cmake ..)


## Installing on Windows

1. Download and install CMake (https://cmake.org/)
2. Create a new folder where you cloned this repository (i.e. windows-build/)
3. Open CMake-gui and select the path where the source code is (where the repository was cloned)
4. Select the folder you just created in step 2 as the path where the binaries will be built![cmake-gui](https://github.com/popoca/markdown-images/blob/master/cmake1.png?raw=true "cmake-gui")
5. Press the Configure button and select the generator to be used (your version of Visual Studio, i.e. Visual Studio 14 2015) then press finish

 ![cmake-generator](https://github.com/popoca/markdown-images/blob/master/cmake3.png?raw=true "cmake-generator")
6. After the configuring is done, press the Generate button![cmake-gui](https://github.com/popoca/markdown-images/blob/master/cmake2.png?raw=true "cmake-gui")
7. Open the project on Visual Studio (it can be found on the folder where the binaries were created)
8. Build the project

 ![build-project](https://github.com/popoca/markdown-images/blob/master/vs2.png?raw=true "build-project")
9. Set SuperHappyRocket as the StartUp Project

 ![startup-project](https://github.com/popoca/markdown-images/blob/master/vs1.png?raw=true "startup-project")
10. Run the program
