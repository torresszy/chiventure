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
include tests/playerclass/CMakeFiles/test-playerclass.dir/depend.make

# Include the progress variables for this target.
include tests/playerclass/CMakeFiles/test-playerclass.dir/progress.make

# Include the compile flags for this target's objects.
include tests/playerclass/CMakeFiles/test-playerclass.dir/flags.make

tests/playerclass/CMakeFiles/test-playerclass.dir/test_class.c.o: tests/playerclass/CMakeFiles/test-playerclass.dir/flags.make
tests/playerclass/CMakeFiles/test-playerclass.dir/test_class.c.o: tests/playerclass/test_class.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kabirdubey/cs220/chiventure/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object tests/playerclass/CMakeFiles/test-playerclass.dir/test_class.c.o"
	cd /home/kabirdubey/cs220/chiventure/tests/playerclass && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test-playerclass.dir/test_class.c.o   -c /home/kabirdubey/cs220/chiventure/tests/playerclass/test_class.c

tests/playerclass/CMakeFiles/test-playerclass.dir/test_class.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test-playerclass.dir/test_class.c.i"
	cd /home/kabirdubey/cs220/chiventure/tests/playerclass && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/kabirdubey/cs220/chiventure/tests/playerclass/test_class.c > CMakeFiles/test-playerclass.dir/test_class.c.i

tests/playerclass/CMakeFiles/test-playerclass.dir/test_class.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test-playerclass.dir/test_class.c.s"
	cd /home/kabirdubey/cs220/chiventure/tests/playerclass && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/kabirdubey/cs220/chiventure/tests/playerclass/test_class.c -o CMakeFiles/test-playerclass.dir/test_class.c.s

tests/playerclass/CMakeFiles/test-playerclass.dir/test_class_item.c.o: tests/playerclass/CMakeFiles/test-playerclass.dir/flags.make
tests/playerclass/CMakeFiles/test-playerclass.dir/test_class_item.c.o: tests/playerclass/test_class_item.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kabirdubey/cs220/chiventure/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object tests/playerclass/CMakeFiles/test-playerclass.dir/test_class_item.c.o"
	cd /home/kabirdubey/cs220/chiventure/tests/playerclass && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test-playerclass.dir/test_class_item.c.o   -c /home/kabirdubey/cs220/chiventure/tests/playerclass/test_class_item.c

tests/playerclass/CMakeFiles/test-playerclass.dir/test_class_item.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test-playerclass.dir/test_class_item.c.i"
	cd /home/kabirdubey/cs220/chiventure/tests/playerclass && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/kabirdubey/cs220/chiventure/tests/playerclass/test_class_item.c > CMakeFiles/test-playerclass.dir/test_class_item.c.i

tests/playerclass/CMakeFiles/test-playerclass.dir/test_class_item.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test-playerclass.dir/test_class_item.c.s"
	cd /home/kabirdubey/cs220/chiventure/tests/playerclass && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/kabirdubey/cs220/chiventure/tests/playerclass/test_class_item.c -o CMakeFiles/test-playerclass.dir/test_class_item.c.s

tests/playerclass/CMakeFiles/test-playerclass.dir/test_class_prefabs.c.o: tests/playerclass/CMakeFiles/test-playerclass.dir/flags.make
tests/playerclass/CMakeFiles/test-playerclass.dir/test_class_prefabs.c.o: tests/playerclass/test_class_prefabs.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kabirdubey/cs220/chiventure/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object tests/playerclass/CMakeFiles/test-playerclass.dir/test_class_prefabs.c.o"
	cd /home/kabirdubey/cs220/chiventure/tests/playerclass && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test-playerclass.dir/test_class_prefabs.c.o   -c /home/kabirdubey/cs220/chiventure/tests/playerclass/test_class_prefabs.c

tests/playerclass/CMakeFiles/test-playerclass.dir/test_class_prefabs.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test-playerclass.dir/test_class_prefabs.c.i"
	cd /home/kabirdubey/cs220/chiventure/tests/playerclass && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/kabirdubey/cs220/chiventure/tests/playerclass/test_class_prefabs.c > CMakeFiles/test-playerclass.dir/test_class_prefabs.c.i

tests/playerclass/CMakeFiles/test-playerclass.dir/test_class_prefabs.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test-playerclass.dir/test_class_prefabs.c.s"
	cd /home/kabirdubey/cs220/chiventure/tests/playerclass && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/kabirdubey/cs220/chiventure/tests/playerclass/test_class_prefabs.c -o CMakeFiles/test-playerclass.dir/test_class_prefabs.c.s

tests/playerclass/CMakeFiles/test-playerclass.dir/main.c.o: tests/playerclass/CMakeFiles/test-playerclass.dir/flags.make
tests/playerclass/CMakeFiles/test-playerclass.dir/main.c.o: tests/playerclass/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kabirdubey/cs220/chiventure/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object tests/playerclass/CMakeFiles/test-playerclass.dir/main.c.o"
	cd /home/kabirdubey/cs220/chiventure/tests/playerclass && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test-playerclass.dir/main.c.o   -c /home/kabirdubey/cs220/chiventure/tests/playerclass/main.c

tests/playerclass/CMakeFiles/test-playerclass.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test-playerclass.dir/main.c.i"
	cd /home/kabirdubey/cs220/chiventure/tests/playerclass && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/kabirdubey/cs220/chiventure/tests/playerclass/main.c > CMakeFiles/test-playerclass.dir/main.c.i

tests/playerclass/CMakeFiles/test-playerclass.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test-playerclass.dir/main.c.s"
	cd /home/kabirdubey/cs220/chiventure/tests/playerclass && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/kabirdubey/cs220/chiventure/tests/playerclass/main.c -o CMakeFiles/test-playerclass.dir/main.c.s

# Object files for target test-playerclass
test__playerclass_OBJECTS = \
"CMakeFiles/test-playerclass.dir/test_class.c.o" \
"CMakeFiles/test-playerclass.dir/test_class_item.c.o" \
"CMakeFiles/test-playerclass.dir/test_class_prefabs.c.o" \
"CMakeFiles/test-playerclass.dir/main.c.o"

# External object files for target test-playerclass
test__playerclass_EXTERNAL_OBJECTS =

tests/playerclass/test-playerclass: tests/playerclass/CMakeFiles/test-playerclass.dir/test_class.c.o
tests/playerclass/test-playerclass: tests/playerclass/CMakeFiles/test-playerclass.dir/test_class_item.c.o
tests/playerclass/test-playerclass: tests/playerclass/CMakeFiles/test-playerclass.dir/test_class_prefabs.c.o
tests/playerclass/test-playerclass: tests/playerclass/CMakeFiles/test-playerclass.dir/main.c.o
tests/playerclass/test-playerclass: tests/playerclass/CMakeFiles/test-playerclass.dir/build.make
tests/playerclass/test-playerclass: /usr/lib/libcriterion.so
tests/playerclass/test-playerclass: src/action_management/libaction_management.a
tests/playerclass/test-playerclass: src/battle/libbattle.a
tests/playerclass/test-playerclass: src/cli/libcli.a
tests/playerclass/test-playerclass: src/common/libcommon.a
tests/playerclass/test-playerclass: src/custom-actions/libcustom-actions.a
tests/playerclass/test-playerclass: src/game-state/libgame-state.a
tests/playerclass/test-playerclass: src/libobj/liblibobj.a
tests/playerclass/test-playerclass: src/quests/libquests.a
tests/playerclass/test-playerclass: src/sound/libsound.a
tests/playerclass/test-playerclass: src/npc/libnpc.a
tests/playerclass/test-playerclass: src/openworld/libopenworld.a
tests/playerclass/test-playerclass: src/playerclass/libplayerclass.a
tests/playerclass/test-playerclass: src/skilltrees/libskilltrees.a
tests/playerclass/test-playerclass: src/ui/libui.a
tests/playerclass/test-playerclass: src/wdl/libwdl.a
tests/playerclass/test-playerclass: src/custom-scripts/libcustom-scripts.a
tests/playerclass/test-playerclass: src/cli/libcli.a
tests/playerclass/test-playerclass: src/common/libcommon.a
tests/playerclass/test-playerclass: src/game-state/libgame-state.a
tests/playerclass/test-playerclass: src/cli/libcli.a
tests/playerclass/test-playerclass: src/common/libcommon.a
tests/playerclass/test-playerclass: src/game-state/libgame-state.a
tests/playerclass/test-playerclass: src/action_management/libaction_management.a
tests/playerclass/test-playerclass: src/ui/libui.a
tests/playerclass/test-playerclass: /usr/lib/x86_64-linux-gnu/libncursesw.so
tests/playerclass/test-playerclass: /usr/lib/x86_64-linux-gnu/libformw.so
tests/playerclass/test-playerclass: src/quests/libquests.a
tests/playerclass/test-playerclass: src/wdl/libwdl.a
tests/playerclass/test-playerclass: src/libobj/liblibobj.a
tests/playerclass/test-playerclass: src/npc/libnpc.a
tests/playerclass/test-playerclass: src/battle/libbattle.a
tests/playerclass/test-playerclass: src/playerclass/libplayerclass.a
tests/playerclass/test-playerclass: src/skilltrees/libskilltrees.a
tests/playerclass/test-playerclass: /usr/lib/x86_64-linux-gnu/libzip.so
tests/playerclass/test-playerclass: /usr/lib/x86_64-linux-gnu/libjson-c.so
tests/playerclass/test-playerclass: /usr/lib/x86_64-linux-gnu/liblua5.3.so
tests/playerclass/test-playerclass: /usr/lib/x86_64-linux-gnu/libm.so
tests/playerclass/test-playerclass: tests/playerclass/CMakeFiles/test-playerclass.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kabirdubey/cs220/chiventure/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable test-playerclass"
	cd /home/kabirdubey/cs220/chiventure/tests/playerclass && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test-playerclass.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/playerclass/CMakeFiles/test-playerclass.dir/build: tests/playerclass/test-playerclass

.PHONY : tests/playerclass/CMakeFiles/test-playerclass.dir/build

tests/playerclass/CMakeFiles/test-playerclass.dir/clean:
	cd /home/kabirdubey/cs220/chiventure/tests/playerclass && $(CMAKE_COMMAND) -P CMakeFiles/test-playerclass.dir/cmake_clean.cmake
.PHONY : tests/playerclass/CMakeFiles/test-playerclass.dir/clean

tests/playerclass/CMakeFiles/test-playerclass.dir/depend:
	cd /home/kabirdubey/cs220/chiventure && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kabirdubey/cs220/chiventure /home/kabirdubey/cs220/chiventure/tests/playerclass /home/kabirdubey/cs220/chiventure /home/kabirdubey/cs220/chiventure/tests/playerclass /home/kabirdubey/cs220/chiventure/tests/playerclass/CMakeFiles/test-playerclass.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/playerclass/CMakeFiles/test-playerclass.dir/depend

