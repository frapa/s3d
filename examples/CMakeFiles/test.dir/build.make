# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/francesco/Programming/C++/libraries/s3d

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/francesco/Programming/C++/libraries/s3d

# Include any dependencies generated for this target.
include examples/CMakeFiles/test.dir/depend.make

# Include the progress variables for this target.
include examples/CMakeFiles/test.dir/progress.make

# Include the compile flags for this target's objects.
include examples/CMakeFiles/test.dir/flags.make

examples/CMakeFiles/test.dir/test.cpp.o: examples/CMakeFiles/test.dir/flags.make
examples/CMakeFiles/test.dir/test.cpp.o: examples/test.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/francesco/Programming/C++/libraries/s3d/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object examples/CMakeFiles/test.dir/test.cpp.o"
	cd /home/francesco/Programming/C++/libraries/s3d/examples && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/test.dir/test.cpp.o -c /home/francesco/Programming/C++/libraries/s3d/examples/test.cpp

examples/CMakeFiles/test.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/test.cpp.i"
	cd /home/francesco/Programming/C++/libraries/s3d/examples && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/francesco/Programming/C++/libraries/s3d/examples/test.cpp > CMakeFiles/test.dir/test.cpp.i

examples/CMakeFiles/test.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/test.cpp.s"
	cd /home/francesco/Programming/C++/libraries/s3d/examples && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/francesco/Programming/C++/libraries/s3d/examples/test.cpp -o CMakeFiles/test.dir/test.cpp.s

examples/CMakeFiles/test.dir/test.cpp.o.requires:
.PHONY : examples/CMakeFiles/test.dir/test.cpp.o.requires

examples/CMakeFiles/test.dir/test.cpp.o.provides: examples/CMakeFiles/test.dir/test.cpp.o.requires
	$(MAKE) -f examples/CMakeFiles/test.dir/build.make examples/CMakeFiles/test.dir/test.cpp.o.provides.build
.PHONY : examples/CMakeFiles/test.dir/test.cpp.o.provides

examples/CMakeFiles/test.dir/test.cpp.o.provides.build: examples/CMakeFiles/test.dir/test.cpp.o

# Object files for target test
test_OBJECTS = \
"CMakeFiles/test.dir/test.cpp.o"

# External object files for target test
test_EXTERNAL_OBJECTS =

examples/test: examples/CMakeFiles/test.dir/test.cpp.o
examples/test: examples/CMakeFiles/test.dir/build.make
examples/test: build/libs3d.so
examples/test: examples/CMakeFiles/test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable test"
	cd /home/francesco/Programming/C++/libraries/s3d/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/CMakeFiles/test.dir/build: examples/test
.PHONY : examples/CMakeFiles/test.dir/build

examples/CMakeFiles/test.dir/requires: examples/CMakeFiles/test.dir/test.cpp.o.requires
.PHONY : examples/CMakeFiles/test.dir/requires

examples/CMakeFiles/test.dir/clean:
	cd /home/francesco/Programming/C++/libraries/s3d/examples && $(CMAKE_COMMAND) -P CMakeFiles/test.dir/cmake_clean.cmake
.PHONY : examples/CMakeFiles/test.dir/clean

examples/CMakeFiles/test.dir/depend:
	cd /home/francesco/Programming/C++/libraries/s3d && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/francesco/Programming/C++/libraries/s3d /home/francesco/Programming/C++/libraries/s3d/examples /home/francesco/Programming/C++/libraries/s3d /home/francesco/Programming/C++/libraries/s3d/examples /home/francesco/Programming/C++/libraries/s3d/examples/CMakeFiles/test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/CMakeFiles/test.dir/depend
