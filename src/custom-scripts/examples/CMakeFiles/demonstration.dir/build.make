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
include src/custom-scripts/examples/CMakeFiles/demonstration.dir/depend.make

# Include the progress variables for this target.
include src/custom-scripts/examples/CMakeFiles/demonstration.dir/progress.make

# Include the compile flags for this target's objects.
include src/custom-scripts/examples/CMakeFiles/demonstration.dir/flags.make

src/custom-scripts/examples/CMakeFiles/demonstration.dir/demonstration.c.o: src/custom-scripts/examples/CMakeFiles/demonstration.dir/flags.make
src/custom-scripts/examples/CMakeFiles/demonstration.dir/demonstration.c.o: src/custom-scripts/examples/demonstration.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kabirdubey/cs220/chiventure/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/custom-scripts/examples/CMakeFiles/demonstration.dir/demonstration.c.o"
	cd /home/kabirdubey/cs220/chiventure/src/custom-scripts/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/demonstration.dir/demonstration.c.o   -c /home/kabirdubey/cs220/chiventure/src/custom-scripts/examples/demonstration.c

src/custom-scripts/examples/CMakeFiles/demonstration.dir/demonstration.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/demonstration.dir/demonstration.c.i"
	cd /home/kabirdubey/cs220/chiventure/src/custom-scripts/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/kabirdubey/cs220/chiventure/src/custom-scripts/examples/demonstration.c > CMakeFiles/demonstration.dir/demonstration.c.i

src/custom-scripts/examples/CMakeFiles/demonstration.dir/demonstration.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/demonstration.dir/demonstration.c.s"
	cd /home/kabirdubey/cs220/chiventure/src/custom-scripts/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/kabirdubey/cs220/chiventure/src/custom-scripts/examples/demonstration.c -o CMakeFiles/demonstration.dir/demonstration.c.s

# Object files for target demonstration
demonstration_OBJECTS = \
"CMakeFiles/demonstration.dir/demonstration.c.o"

# External object files for target demonstration
demonstration_EXTERNAL_OBJECTS =

src/custom-scripts/examples/demonstration: src/custom-scripts/examples/CMakeFiles/demonstration.dir/demonstration.c.o
src/custom-scripts/examples/demonstration: src/custom-scripts/examples/CMakeFiles/demonstration.dir/build.make
src/custom-scripts/examples/demonstration: /usr/lib/x86_64-linux-gnu/liblua5.3.so
src/custom-scripts/examples/demonstration: /usr/lib/x86_64-linux-gnu/libm.so
src/custom-scripts/examples/demonstration: src/action_management/libaction_management.a
src/custom-scripts/examples/demonstration: src/battle/libbattle.a
src/custom-scripts/examples/demonstration: src/cli/libcli.a
src/custom-scripts/examples/demonstration: src/common/libcommon.a
src/custom-scripts/examples/demonstration: src/custom-actions/libcustom-actions.a
src/custom-scripts/examples/demonstration: src/game-state/libgame-state.a
src/custom-scripts/examples/demonstration: src/libobj/liblibobj.a
src/custom-scripts/examples/demonstration: src/quests/libquests.a
src/custom-scripts/examples/demonstration: src/sound/libsound.a
src/custom-scripts/examples/demonstration: src/npc/libnpc.a
src/custom-scripts/examples/demonstration: src/openworld/libopenworld.a
src/custom-scripts/examples/demonstration: src/playerclass/libplayerclass.a
src/custom-scripts/examples/demonstration: src/skilltrees/libskilltrees.a
src/custom-scripts/examples/demonstration: src/ui/libui.a
src/custom-scripts/examples/demonstration: src/wdl/libwdl.a
src/custom-scripts/examples/demonstration: src/custom-scripts/libcustom-scripts.a
src/custom-scripts/examples/demonstration: src/cli/libcli.a
src/custom-scripts/examples/demonstration: src/common/libcommon.a
src/custom-scripts/examples/demonstration: src/game-state/libgame-state.a
src/custom-scripts/examples/demonstration: src/cli/libcli.a
src/custom-scripts/examples/demonstration: src/common/libcommon.a
src/custom-scripts/examples/demonstration: src/game-state/libgame-state.a
src/custom-scripts/examples/demonstration: src/action_management/libaction_management.a
src/custom-scripts/examples/demonstration: src/ui/libui.a
src/custom-scripts/examples/demonstration: /usr/lib/x86_64-linux-gnu/libncursesw.so
src/custom-scripts/examples/demonstration: /usr/lib/x86_64-linux-gnu/libformw.so
src/custom-scripts/examples/demonstration: src/quests/libquests.a
src/custom-scripts/examples/demonstration: src/wdl/libwdl.a
src/custom-scripts/examples/demonstration: src/libobj/liblibobj.a
src/custom-scripts/examples/demonstration: src/npc/libnpc.a
src/custom-scripts/examples/demonstration: src/battle/libbattle.a
src/custom-scripts/examples/demonstration: src/playerclass/libplayerclass.a
src/custom-scripts/examples/demonstration: src/skilltrees/libskilltrees.a
src/custom-scripts/examples/demonstration: /usr/lib/x86_64-linux-gnu/libzip.so
src/custom-scripts/examples/demonstration: /usr/lib/x86_64-linux-gnu/libjson-c.so
src/custom-scripts/examples/demonstration: /usr/lib/x86_64-linux-gnu/liblua5.3.so
src/custom-scripts/examples/demonstration: /usr/lib/x86_64-linux-gnu/libm.so
src/custom-scripts/examples/demonstration: src/custom-scripts/examples/CMakeFiles/demonstration.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kabirdubey/cs220/chiventure/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable demonstration"
	cd /home/kabirdubey/cs220/chiventure/src/custom-scripts/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/demonstration.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/custom-scripts/examples/CMakeFiles/demonstration.dir/build: src/custom-scripts/examples/demonstration

.PHONY : src/custom-scripts/examples/CMakeFiles/demonstration.dir/build

src/custom-scripts/examples/CMakeFiles/demonstration.dir/clean:
	cd /home/kabirdubey/cs220/chiventure/src/custom-scripts/examples && $(CMAKE_COMMAND) -P CMakeFiles/demonstration.dir/cmake_clean.cmake
.PHONY : src/custom-scripts/examples/CMakeFiles/demonstration.dir/clean

src/custom-scripts/examples/CMakeFiles/demonstration.dir/depend:
	cd /home/kabirdubey/cs220/chiventure && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kabirdubey/cs220/chiventure /home/kabirdubey/cs220/chiventure/src/custom-scripts/examples /home/kabirdubey/cs220/chiventure /home/kabirdubey/cs220/chiventure/src/custom-scripts/examples /home/kabirdubey/cs220/chiventure/src/custom-scripts/examples/CMakeFiles/demonstration.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/custom-scripts/examples/CMakeFiles/demonstration.dir/depend

