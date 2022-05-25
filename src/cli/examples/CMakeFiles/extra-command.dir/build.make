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
include src/cli/examples/CMakeFiles/extra-command.dir/depend.make

# Include the progress variables for this target.
include src/cli/examples/CMakeFiles/extra-command.dir/progress.make

# Include the compile flags for this target's objects.
include src/cli/examples/CMakeFiles/extra-command.dir/flags.make

src/cli/examples/CMakeFiles/extra-command.dir/extra-command.c.o: src/cli/examples/CMakeFiles/extra-command.dir/flags.make
src/cli/examples/CMakeFiles/extra-command.dir/extra-command.c.o: src/cli/examples/extra-command.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kabirdubey/cs220/chiventure/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/cli/examples/CMakeFiles/extra-command.dir/extra-command.c.o"
	cd /home/kabirdubey/cs220/chiventure/src/cli/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/extra-command.dir/extra-command.c.o   -c /home/kabirdubey/cs220/chiventure/src/cli/examples/extra-command.c

src/cli/examples/CMakeFiles/extra-command.dir/extra-command.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/extra-command.dir/extra-command.c.i"
	cd /home/kabirdubey/cs220/chiventure/src/cli/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/kabirdubey/cs220/chiventure/src/cli/examples/extra-command.c > CMakeFiles/extra-command.dir/extra-command.c.i

src/cli/examples/CMakeFiles/extra-command.dir/extra-command.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/extra-command.dir/extra-command.c.s"
	cd /home/kabirdubey/cs220/chiventure/src/cli/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/kabirdubey/cs220/chiventure/src/cli/examples/extra-command.c -o CMakeFiles/extra-command.dir/extra-command.c.s

# Object files for target extra-command
extra__command_OBJECTS = \
"CMakeFiles/extra-command.dir/extra-command.c.o"

# External object files for target extra-command
extra__command_EXTERNAL_OBJECTS =

src/cli/examples/extra-command: src/cli/examples/CMakeFiles/extra-command.dir/extra-command.c.o
src/cli/examples/extra-command: src/cli/examples/CMakeFiles/extra-command.dir/build.make
src/cli/examples/extra-command: src/action_management/libaction_management.a
src/cli/examples/extra-command: src/battle/libbattle.a
src/cli/examples/extra-command: src/cli/libcli.a
src/cli/examples/extra-command: src/common/libcommon.a
src/cli/examples/extra-command: src/custom-actions/libcustom-actions.a
src/cli/examples/extra-command: src/game-state/libgame-state.a
src/cli/examples/extra-command: src/libobj/liblibobj.a
src/cli/examples/extra-command: src/quests/libquests.a
src/cli/examples/extra-command: src/sound/libsound.a
src/cli/examples/extra-command: src/npc/libnpc.a
src/cli/examples/extra-command: src/openworld/libopenworld.a
src/cli/examples/extra-command: src/playerclass/libplayerclass.a
src/cli/examples/extra-command: src/skilltrees/libskilltrees.a
src/cli/examples/extra-command: src/ui/libui.a
src/cli/examples/extra-command: src/wdl/libwdl.a
src/cli/examples/extra-command: src/custom-scripts/libcustom-scripts.a
src/cli/examples/extra-command: src/cli/libcli.a
src/cli/examples/extra-command: src/common/libcommon.a
src/cli/examples/extra-command: src/game-state/libgame-state.a
src/cli/examples/extra-command: src/cli/libcli.a
src/cli/examples/extra-command: src/common/libcommon.a
src/cli/examples/extra-command: src/game-state/libgame-state.a
src/cli/examples/extra-command: src/action_management/libaction_management.a
src/cli/examples/extra-command: src/ui/libui.a
src/cli/examples/extra-command: /usr/lib/x86_64-linux-gnu/libncursesw.so
src/cli/examples/extra-command: /usr/lib/x86_64-linux-gnu/libformw.so
src/cli/examples/extra-command: src/quests/libquests.a
src/cli/examples/extra-command: src/wdl/libwdl.a
src/cli/examples/extra-command: src/libobj/liblibobj.a
src/cli/examples/extra-command: src/npc/libnpc.a
src/cli/examples/extra-command: src/battle/libbattle.a
src/cli/examples/extra-command: src/playerclass/libplayerclass.a
src/cli/examples/extra-command: src/skilltrees/libskilltrees.a
src/cli/examples/extra-command: /usr/lib/x86_64-linux-gnu/libzip.so
src/cli/examples/extra-command: /usr/lib/x86_64-linux-gnu/libjson-c.so
src/cli/examples/extra-command: /usr/lib/x86_64-linux-gnu/liblua5.3.so
src/cli/examples/extra-command: /usr/lib/x86_64-linux-gnu/libm.so
src/cli/examples/extra-command: src/cli/examples/CMakeFiles/extra-command.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kabirdubey/cs220/chiventure/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable extra-command"
	cd /home/kabirdubey/cs220/chiventure/src/cli/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/extra-command.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/cli/examples/CMakeFiles/extra-command.dir/build: src/cli/examples/extra-command

.PHONY : src/cli/examples/CMakeFiles/extra-command.dir/build

src/cli/examples/CMakeFiles/extra-command.dir/clean:
	cd /home/kabirdubey/cs220/chiventure/src/cli/examples && $(CMAKE_COMMAND) -P CMakeFiles/extra-command.dir/cmake_clean.cmake
.PHONY : src/cli/examples/CMakeFiles/extra-command.dir/clean

src/cli/examples/CMakeFiles/extra-command.dir/depend:
	cd /home/kabirdubey/cs220/chiventure && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kabirdubey/cs220/chiventure /home/kabirdubey/cs220/chiventure/src/cli/examples /home/kabirdubey/cs220/chiventure /home/kabirdubey/cs220/chiventure/src/cli/examples /home/kabirdubey/cs220/chiventure/src/cli/examples/CMakeFiles/extra-command.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/cli/examples/CMakeFiles/extra-command.dir/depend

