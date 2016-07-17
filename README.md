# opengl-demo-scene

## build and run
* mkdir build && cd build
* cmake ..
* make
* ./bin/demo

## Windows build tools requirements

To provide build and development under Windows there are several dependencies you require. We use CLion for development
so this describes how to support build under Windows system.

### CLion + Cygwin

1. To provide build under Windows system you will require to install cygwin. We suggest to create separate folder
for Cygwin under build tools root dir to provide easier configuration. For example my configuration:

    1. cygwin root dir: **D:\build_tools\cygwin**
    2. cygwin download dir: **D:\build_tools\cygwin_downloads**

### CLion + MinGW

1. Use latin charset user name. Your user folder should be like this: C:\Users\<some_latin_name>
2. Download SDL2 development version for MinGW (http://www.libsdl.org/download-2.0.php)
3. Copy contents from *-mingw32 folder (one of two) to your MinGW installation (don't forget to make minGW backup!)
4. Everything should be ok now.