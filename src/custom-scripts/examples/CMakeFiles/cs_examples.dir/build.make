# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/kabirdubey/cs220/chiventure

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kabirdubey/cs220/chiventure

# Utility rule file for cs_examples.

# Include the progress variables for this target.
include src/custom-scripts/examples/CMakeFiles/cs_examples.dir/progress.make

src/custom-scripts/examples/CMakeFiles/cs_examples: src/custom-scripts/examples/demonstration


cs_examples: src/custom-scripts/examples/CMakeFiles/cs_examples
cs_examples: src/custom-scripts/examples/CMakeFiles/cs_examples.dir/build.make

.PHONY : cs_examples

# Rule to build all files generated by this target.
src/custom-scripts/examples/CMakeFiles/cs_examples.dir/build: cs_examples

.PHONY : src/custom-scripts/examples/CMakeFiles/cs_examples.dir/build

src/custom-scripts/examples/CMakeFiles/cs_examples.dir/clean:
	cd /home/kabirdubey/cs220/chiventure/src/custom-scripts/examples && $(CMAKE_COMMAND) -P CMakeFiles/cs_examples.dir/cmake_clean.cmake
.PHONY : src/custom-scripts/examples/CMakeFiles/cs_examples.dir/clean

src/custom-scripts/examples/CMakeFiles/cs_examples.dir/depend:
	cd /home/kabirdubey/cs220/chiventure && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kabirdubey/cs220/chiventure /home/kabirdubey/cs220/chiventure/src/custom-scripts/examples /home/kabirdubey/cs220/chiventure /home/kabirdubey/cs220/chiventure/src/custom-scripts/examples /home/kabirdubey/cs220/chiventure/src/custom-scripts/examples/CMakeFiles/cs_examples.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/custom-scripts/examples/CMakeFiles/cs_examples.dir/depend

