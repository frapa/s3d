# S3D

S3D is a small and lightweight C++ library for 3D graphics with OpenGL.
Since OpenGl 3.0, the fixed pipeline and the direct rendering mode has been
removed, improving performances and cleaning the api, but also increasing the
learning curve and making programs longer. S3D tries to solve these problems
offering the following features (through a small set of classes, in a C++
fashion):

 * __Shaders__: S3D helps you loading, compiling, linking and running
   shaders.
 * __Matrix Math__: since all matrix math has been removed from OpenGL,
   S3D provides a simple Matrix class with transformations (translate,
   scale, rotate) built-in. There is also a function to replace
   gluPerspective for the calculation of the projection matrix.
 * __Indexed Arrays__: you just need to define the vertices and indices
   for your geometry and S3D will take care to upload the data to the
   graphic card and to draw it for you.
 * __Easy to use__: S3D will say out of your way and help you just
   get the work done. There is no need of complicated libraries.
 * __Small__: Just 18.5 KB for the source archive!

## Limitations

S3D does not claim, nor is intended, to be:

 * A huge and complex 3D engine.
 * A complete library for you 3D app. It is a rather low-level
   library that ease the most common, verbose and boring tasks
   with OpenGL. There is no mesh loader, you have to build everithing
   manually from triangles
 * A scene graph library.

## Development

The library is very young, I worked on it for just a few days, and is by no
means complete. The first semi-stable release will come in some time.
However the very basic functions are already working.

If you find bugs, I will be very welcome if you can send me an e-mail
(francescopasa<at>gmail<dot>com).

## Building

I'm not an expert in using Cmake, but i've found it to be a nice build system.
For now there is no option for installing the library, you can just build
it (and then you can place the files manually where you need them).

Decompress the archive, then with the command line enter the root directory
and type:

    cmake .

Once done type:

    make

In the build directory you will find a shared library named libs3d (the extension
is .so on Linux and .ddl on Windows) and a static library, also called libs3d
(with extension .a on Linux and .lib on windows).

There is also a small test program called test (tons of imagination) in the
examples folder. To run it, type, from the root directory (otherwise it will
fail loading the shaders):

	./examples/test

The build system should be cross-platform but everything has been tested only
on my linux machine.

## Contact

If you wish to contact me for any reason, write me at francescopasa<at>gmail<dot>com.
I will be very pleased o answer you.
