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

# Include any dependencies generated for this target.
include src/sound/CMakeFiles/sound.dir/depend.make

# Include the progress variables for this target.
include src/sound/CMakeFiles/sound.dir/progress.make

# Include the compile flags for this target's objects.
include src/sound/CMakeFiles/sound.dir/flags.make

src/sound/CMakeFiles/sound.dir/src/sound.c.o: src/sound/CMakeFiles/sound.dir/flags.make
src/sound/CMakeFiles/sound.dir/src/sound.c.o: src/sound/src/sound.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kabirdubey/cs220/chiventure/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/sound/CMakeFiles/sound.dir/src/sound.c.o"
	cd /home/kabirdubey/cs220/chiventure/src/sound && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sound.dir/src/sound.c.o   -c /home/kabirdubey/cs220/chiventure/src/sound/src/sound.c

src/sound/CMakeFiles/sound.dir/src/sound.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sound.dir/src/sound.c.i"
	cd /home/kabirdubey/cs220/chiventure/src/sound && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/kabirdubey/cs220/chiventure/src/sound/src/sound.c > CMakeFiles/sound.dir/src/sound.c.i

src/sound/CMakeFiles/sound.dir/src/sound.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sound.dir/src/sound.c.s"
	cd /home/kabirdubey/cs220/chiventure/src/sound && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/kabirdubey/cs220/chiventure/src/sound/src/sound.c -o CMakeFiles/sound.dir/src/sound.c.s

# Object files for target sound
sound_OBJECTS = \
"CMakeFiles/sound.dir/src/sound.c.o"

# External object files for target sound
sound_EXTERNAL_OBJECTS =

src/sound/libsound.a: src/sound/CMakeFiles/sound.dir/src/sound.c.o
src/sound/libsound.a: src/sound/CMakeFiles/sound.dir/build.make
src/sound/libsound.a: src/sound/CMakeFiles/sound.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kabirdubey/cs220/chiventure/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libsound.a"
	cd /home/kabirdubey/cs220/chiventure/src/sound && $(CMAKE_COMMAND) -P CMakeFiles/sound.dir/cmake_clean_target.cmake
	cd /home/kabirdubey/cs220/chiventure/src/sound && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sound.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/sound/CMakeFiles/sound.dir/build: src/sound/libsound.a

.PHONY : src/sound/CMakeFiles/sound.dir/build

src/sound/CMakeFiles/sound.dir/clean:
	cd /home/kabirdubey/cs220/chiventure/src/sound && $(CMAKE_COMMAND) -P CMakeFiles/sound.dir/cmake_clean.cmake
.PHONY : src/sound/CMakeFiles/sound.dir/clean

src/sound/CMakeFiles/sound.dir/depend:
	cd /home/kabirdubey/cs220/chiventure && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kabirdubey/cs220/chiventure /home/kabirdubey/cs220/chiventure/src/sound /home/kabirdubey/cs220/chiventure /home/kabirdubey/cs220/chiventure/src/sound /home/kabirdubey/cs220/chiventure/src/sound/CMakeFiles/sound.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/sound/CMakeFiles/sound.dir/depend

