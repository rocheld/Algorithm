# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/Hyun/CLionProjects/korasaju

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/Hyun/CLionProjects/korasaju/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/korasaju.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/korasaju.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/korasaju.dir/flags.make

CMakeFiles/korasaju.dir/main.cpp.o: CMakeFiles/korasaju.dir/flags.make
CMakeFiles/korasaju.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Hyun/CLionProjects/korasaju/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/korasaju.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/korasaju.dir/main.cpp.o -c /Users/Hyun/CLionProjects/korasaju/main.cpp

CMakeFiles/korasaju.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/korasaju.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Hyun/CLionProjects/korasaju/main.cpp > CMakeFiles/korasaju.dir/main.cpp.i

CMakeFiles/korasaju.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/korasaju.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Hyun/CLionProjects/korasaju/main.cpp -o CMakeFiles/korasaju.dir/main.cpp.s

# Object files for target korasaju
korasaju_OBJECTS = \
"CMakeFiles/korasaju.dir/main.cpp.o"

# External object files for target korasaju
korasaju_EXTERNAL_OBJECTS =

korasaju: CMakeFiles/korasaju.dir/main.cpp.o
korasaju: CMakeFiles/korasaju.dir/build.make
korasaju: CMakeFiles/korasaju.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/Hyun/CLionProjects/korasaju/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable korasaju"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/korasaju.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/korasaju.dir/build: korasaju

.PHONY : CMakeFiles/korasaju.dir/build

CMakeFiles/korasaju.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/korasaju.dir/cmake_clean.cmake
.PHONY : CMakeFiles/korasaju.dir/clean

CMakeFiles/korasaju.dir/depend:
	cd /Users/Hyun/CLionProjects/korasaju/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Hyun/CLionProjects/korasaju /Users/Hyun/CLionProjects/korasaju /Users/Hyun/CLionProjects/korasaju/cmake-build-debug /Users/Hyun/CLionProjects/korasaju/cmake-build-debug /Users/Hyun/CLionProjects/korasaju/cmake-build-debug/CMakeFiles/korasaju.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/korasaju.dir/depend
