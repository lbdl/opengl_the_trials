# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Produce verbose output by default.
VERBOSE = 1

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/timS/DATA/opengl/attempt_the_one/graphics_test/graphics_test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/timS/DATA/opengl/attempt_the_one/graphics_test/graphics_test/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/LIB_GLFW.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/LIB_GLFW.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LIB_GLFW.dir/flags.make

# Object files for target LIB_GLFW
LIB_GLFW_OBJECTS =

# External object files for target LIB_GLFW
LIB_GLFW_EXTERNAL_OBJECTS =

libLIB_GLFW.dylib: CMakeFiles/LIB_GLFW.dir/build.make
libLIB_GLFW.dylib: CMakeFiles/LIB_GLFW.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/timS/DATA/opengl/attempt_the_one/graphics_test/graphics_test/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Linking CXX shared library libLIB_GLFW.dylib"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LIB_GLFW.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/LIB_GLFW.dir/build: libLIB_GLFW.dylib

.PHONY : CMakeFiles/LIB_GLFW.dir/build

CMakeFiles/LIB_GLFW.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/LIB_GLFW.dir/cmake_clean.cmake
.PHONY : CMakeFiles/LIB_GLFW.dir/clean

CMakeFiles/LIB_GLFW.dir/depend:
	cd /Users/timS/DATA/opengl/attempt_the_one/graphics_test/graphics_test/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/timS/DATA/opengl/attempt_the_one/graphics_test/graphics_test /Users/timS/DATA/opengl/attempt_the_one/graphics_test/graphics_test /Users/timS/DATA/opengl/attempt_the_one/graphics_test/graphics_test/cmake-build-debug /Users/timS/DATA/opengl/attempt_the_one/graphics_test/graphics_test/cmake-build-debug /Users/timS/DATA/opengl/attempt_the_one/graphics_test/graphics_test/cmake-build-debug/CMakeFiles/LIB_GLFW.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/LIB_GLFW.dir/depend
