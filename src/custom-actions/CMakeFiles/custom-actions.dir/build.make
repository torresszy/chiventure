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
include src/custom-actions/CMakeFiles/custom-actions.dir/depend.make

# Include the progress variables for this target.
include src/custom-actions/CMakeFiles/custom-actions.dir/progress.make

# Include the compile flags for this target's objects.
include src/custom-actions/CMakeFiles/custom-actions.dir/flags.make

src/custom-actions/CMakeFiles/custom-actions.dir/src/ast_block.c.o: src/custom-actions/CMakeFiles/custom-actions.dir/flags.make
src/custom-actions/CMakeFiles/custom-actions.dir/src/ast_block.c.o: src/custom-actions/src/ast_block.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kabirdubey/cs220/chiventure/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/custom-actions/CMakeFiles/custom-actions.dir/src/ast_block.c.o"
	cd /home/kabirdubey/cs220/chiventure/src/custom-actions && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/custom-actions.dir/src/ast_block.c.o   -c /home/kabirdubey/cs220/chiventure/src/custom-actions/src/ast_block.c

src/custom-actions/CMakeFiles/custom-actions.dir/src/ast_block.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/custom-actions.dir/src/ast_block.c.i"
	cd /home/kabirdubey/cs220/chiventure/src/custom-actions && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/kabirdubey/cs220/chiventure/src/custom-actions/src/ast_block.c > CMakeFiles/custom-actions.dir/src/ast_block.c.i

src/custom-actions/CMakeFiles/custom-actions.dir/src/ast_block.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/custom-actions.dir/src/ast_block.c.s"
	cd /home/kabirdubey/cs220/chiventure/src/custom-actions && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/kabirdubey/cs220/chiventure/src/custom-actions/src/ast_block.c -o CMakeFiles/custom-actions.dir/src/ast_block.c.s

src/custom-actions/CMakeFiles/custom-actions.dir/src/branch_block.c.o: src/custom-actions/CMakeFiles/custom-actions.dir/flags.make
src/custom-actions/CMakeFiles/custom-actions.dir/src/branch_block.c.o: src/custom-actions/src/branch_block.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kabirdubey/cs220/chiventure/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object src/custom-actions/CMakeFiles/custom-actions.dir/src/branch_block.c.o"
	cd /home/kabirdubey/cs220/chiventure/src/custom-actions && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/custom-actions.dir/src/branch_block.c.o   -c /home/kabirdubey/cs220/chiventure/src/custom-actions/src/branch_block.c

src/custom-actions/CMakeFiles/custom-actions.dir/src/branch_block.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/custom-actions.dir/src/branch_block.c.i"
	cd /home/kabirdubey/cs220/chiventure/src/custom-actions && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/kabirdubey/cs220/chiventure/src/custom-actions/src/branch_block.c > CMakeFiles/custom-actions.dir/src/branch_block.c.i

src/custom-actions/CMakeFiles/custom-actions.dir/src/branch_block.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/custom-actions.dir/src/branch_block.c.s"
	cd /home/kabirdubey/cs220/chiventure/src/custom-actions && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/kabirdubey/cs220/chiventure/src/custom-actions/src/branch_block.c -o CMakeFiles/custom-actions.dir/src/branch_block.c.s

src/custom-actions/CMakeFiles/custom-actions.dir/src/control_block.c.o: src/custom-actions/CMakeFiles/custom-actions.dir/flags.make
src/custom-actions/CMakeFiles/custom-actions.dir/src/control_block.c.o: src/custom-actions/src/control_block.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kabirdubey/cs220/chiventure/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object src/custom-actions/CMakeFiles/custom-actions.dir/src/control_block.c.o"
	cd /home/kabirdubey/cs220/chiventure/src/custom-actions && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/custom-actions.dir/src/control_block.c.o   -c /home/kabirdubey/cs220/chiventure/src/custom-actions/src/control_block.c

src/custom-actions/CMakeFiles/custom-actions.dir/src/control_block.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/custom-actions.dir/src/control_block.c.i"
	cd /home/kabirdubey/cs220/chiventure/src/custom-actions && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/kabirdubey/cs220/chiventure/src/custom-actions/src/control_block.c > CMakeFiles/custom-actions.dir/src/control_block.c.i

src/custom-actions/CMakeFiles/custom-actions.dir/src/control_block.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/custom-actions.dir/src/control_block.c.s"
	cd /home/kabirdubey/cs220/chiventure/src/custom-actions && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/kabirdubey/cs220/chiventure/src/custom-actions/src/control_block.c -o CMakeFiles/custom-actions.dir/src/control_block.c.s

src/custom-actions/CMakeFiles/custom-actions.dir/src/custom_action.c.o: src/custom-actions/CMakeFiles/custom-actions.dir/flags.make
src/custom-actions/CMakeFiles/custom-actions.dir/src/custom_action.c.o: src/custom-actions/src/custom_action.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kabirdubey/cs220/chiventure/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object src/custom-actions/CMakeFiles/custom-actions.dir/src/custom_action.c.o"
	cd /home/kabirdubey/cs220/chiventure/src/custom-actions && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/custom-actions.dir/src/custom_action.c.o   -c /home/kabirdubey/cs220/chiventure/src/custom-actions/src/custom_action.c

src/custom-actions/CMakeFiles/custom-actions.dir/src/custom_action.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/custom-actions.dir/src/custom_action.c.i"
	cd /home/kabirdubey/cs220/chiventure/src/custom-actions && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/kabirdubey/cs220/chiventure/src/custom-actions/src/custom_action.c > CMakeFiles/custom-actions.dir/src/custom_action.c.i

src/custom-actions/CMakeFiles/custom-actions.dir/src/custom_action.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/custom-actions.dir/src/custom_action.c.s"
	cd /home/kabirdubey/cs220/chiventure/src/custom-actions && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/kabirdubey/cs220/chiventure/src/custom-actions/src/custom_action.c -o CMakeFiles/custom-actions.dir/src/custom_action.c.s

src/custom-actions/CMakeFiles/custom-actions.dir/src/action_block.c.o: src/custom-actions/CMakeFiles/custom-actions.dir/flags.make
src/custom-actions/CMakeFiles/custom-actions.dir/src/action_block.c.o: src/custom-actions/src/action_block.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kabirdubey/cs220/chiventure/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object src/custom-actions/CMakeFiles/custom-actions.dir/src/action_block.c.o"
	cd /home/kabirdubey/cs220/chiventure/src/custom-actions && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/custom-actions.dir/src/action_block.c.o   -c /home/kabirdubey/cs220/chiventure/src/custom-actions/src/action_block.c

src/custom-actions/CMakeFiles/custom-actions.dir/src/action_block.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/custom-actions.dir/src/action_block.c.i"
	cd /home/kabirdubey/cs220/chiventure/src/custom-actions && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/kabirdubey/cs220/chiventure/src/custom-actions/src/action_block.c > CMakeFiles/custom-actions.dir/src/action_block.c.i

src/custom-actions/CMakeFiles/custom-actions.dir/src/action_block.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/custom-actions.dir/src/action_block.c.s"
	cd /home/kabirdubey/cs220/chiventure/src/custom-actions && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/kabirdubey/cs220/chiventure/src/custom-actions/src/action_block.c -o CMakeFiles/custom-actions.dir/src/action_block.c.s

src/custom-actions/CMakeFiles/custom-actions.dir/src/conditional_block.c.o: src/custom-actions/CMakeFiles/custom-actions.dir/flags.make
src/custom-actions/CMakeFiles/custom-actions.dir/src/conditional_block.c.o: src/custom-actions/src/conditional_block.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kabirdubey/cs220/chiventure/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object src/custom-actions/CMakeFiles/custom-actions.dir/src/conditional_block.c.o"
	cd /home/kabirdubey/cs220/chiventure/src/custom-actions && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/custom-actions.dir/src/conditional_block.c.o   -c /home/kabirdubey/cs220/chiventure/src/custom-actions/src/conditional_block.c

src/custom-actions/CMakeFiles/custom-actions.dir/src/conditional_block.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/custom-actions.dir/src/conditional_block.c.i"
	cd /home/kabirdubey/cs220/chiventure/src/custom-actions && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/kabirdubey/cs220/chiventure/src/custom-actions/src/conditional_block.c > CMakeFiles/custom-actions.dir/src/conditional_block.c.i

src/custom-actions/CMakeFiles/custom-actions.dir/src/conditional_block.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/custom-actions.dir/src/conditional_block.c.s"
	cd /home/kabirdubey/cs220/chiventure/src/custom-actions && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/kabirdubey/cs220/chiventure/src/custom-actions/src/conditional_block.c -o CMakeFiles/custom-actions.dir/src/conditional_block.c.s

src/custom-actions/CMakeFiles/custom-actions.dir/src/custom-actions-cond.c.o: src/custom-actions/CMakeFiles/custom-actions.dir/flags.make
src/custom-actions/CMakeFiles/custom-actions.dir/src/custom-actions-cond.c.o: src/custom-actions/src/custom-actions-cond.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kabirdubey/cs220/chiventure/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object src/custom-actions/CMakeFiles/custom-actions.dir/src/custom-actions-cond.c.o"
	cd /home/kabirdubey/cs220/chiventure/src/custom-actions && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/custom-actions.dir/src/custom-actions-cond.c.o   -c /home/kabirdubey/cs220/chiventure/src/custom-actions/src/custom-actions-cond.c

src/custom-actions/CMakeFiles/custom-actions.dir/src/custom-actions-cond.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/custom-actions.dir/src/custom-actions-cond.c.i"
	cd /home/kabirdubey/cs220/chiventure/src/custom-actions && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/kabirdubey/cs220/chiventure/src/custom-actions/src/custom-actions-cond.c > CMakeFiles/custom-actions.dir/src/custom-actions-cond.c.i

src/custom-actions/CMakeFiles/custom-actions.dir/src/custom-actions-cond.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/custom-actions.dir/src/custom-actions-cond.c.s"
	cd /home/kabirdubey/cs220/chiventure/src/custom-actions && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/kabirdubey/cs220/chiventure/src/custom-actions/src/custom-actions-cond.c -o CMakeFiles/custom-actions.dir/src/custom-actions-cond.c.s

src/custom-actions/CMakeFiles/custom-actions.dir/src/custom-actions-effect.c.o: src/custom-actions/CMakeFiles/custom-actions.dir/flags.make
src/custom-actions/CMakeFiles/custom-actions.dir/src/custom-actions-effect.c.o: src/custom-actions/src/custom-actions-effect.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kabirdubey/cs220/chiventure/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object src/custom-actions/CMakeFiles/custom-actions.dir/src/custom-actions-effect.c.o"
	cd /home/kabirdubey/cs220/chiventure/src/custom-actions && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/custom-actions.dir/src/custom-actions-effect.c.o   -c /home/kabirdubey/cs220/chiventure/src/custom-actions/src/custom-actions-effect.c

src/custom-actions/CMakeFiles/custom-actions.dir/src/custom-actions-effect.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/custom-actions.dir/src/custom-actions-effect.c.i"
	cd /home/kabirdubey/cs220/chiventure/src/custom-actions && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/kabirdubey/cs220/chiventure/src/custom-actions/src/custom-actions-effect.c > CMakeFiles/custom-actions.dir/src/custom-actions-effect.c.i

src/custom-actions/CMakeFiles/custom-actions.dir/src/custom-actions-effect.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/custom-actions.dir/src/custom-actions-effect.c.s"
	cd /home/kabirdubey/cs220/chiventure/src/custom-actions && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/kabirdubey/cs220/chiventure/src/custom-actions/src/custom-actions-effect.c -o CMakeFiles/custom-actions.dir/src/custom-actions-effect.c.s

src/custom-actions/CMakeFiles/custom-actions.dir/src/interface.c.o: src/custom-actions/CMakeFiles/custom-actions.dir/flags.make
src/custom-actions/CMakeFiles/custom-actions.dir/src/interface.c.o: src/custom-actions/src/interface.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kabirdubey/cs220/chiventure/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object src/custom-actions/CMakeFiles/custom-actions.dir/src/interface.c.o"
	cd /home/kabirdubey/cs220/chiventure/src/custom-actions && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/custom-actions.dir/src/interface.c.o   -c /home/kabirdubey/cs220/chiventure/src/custom-actions/src/interface.c

src/custom-actions/CMakeFiles/custom-actions.dir/src/interface.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/custom-actions.dir/src/interface.c.i"
	cd /home/kabirdubey/cs220/chiventure/src/custom-actions && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/kabirdubey/cs220/chiventure/src/custom-actions/src/interface.c > CMakeFiles/custom-actions.dir/src/interface.c.i

src/custom-actions/CMakeFiles/custom-actions.dir/src/interface.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/custom-actions.dir/src/interface.c.s"
	cd /home/kabirdubey/cs220/chiventure/src/custom-actions && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/kabirdubey/cs220/chiventure/src/custom-actions/src/interface.c -o CMakeFiles/custom-actions.dir/src/interface.c.s

# Object files for target custom-actions
custom__actions_OBJECTS = \
"CMakeFiles/custom-actions.dir/src/ast_block.c.o" \
"CMakeFiles/custom-actions.dir/src/branch_block.c.o" \
"CMakeFiles/custom-actions.dir/src/control_block.c.o" \
"CMakeFiles/custom-actions.dir/src/custom_action.c.o" \
"CMakeFiles/custom-actions.dir/src/action_block.c.o" \
"CMakeFiles/custom-actions.dir/src/conditional_block.c.o" \
"CMakeFiles/custom-actions.dir/src/custom-actions-cond.c.o" \
"CMakeFiles/custom-actions.dir/src/custom-actions-effect.c.o" \
"CMakeFiles/custom-actions.dir/src/interface.c.o"

# External object files for target custom-actions
custom__actions_EXTERNAL_OBJECTS =

src/custom-actions/libcustom-actions.a: src/custom-actions/CMakeFiles/custom-actions.dir/src/ast_block.c.o
src/custom-actions/libcustom-actions.a: src/custom-actions/CMakeFiles/custom-actions.dir/src/branch_block.c.o
src/custom-actions/libcustom-actions.a: src/custom-actions/CMakeFiles/custom-actions.dir/src/control_block.c.o
src/custom-actions/libcustom-actions.a: src/custom-actions/CMakeFiles/custom-actions.dir/src/custom_action.c.o
src/custom-actions/libcustom-actions.a: src/custom-actions/CMakeFiles/custom-actions.dir/src/action_block.c.o
src/custom-actions/libcustom-actions.a: src/custom-actions/CMakeFiles/custom-actions.dir/src/conditional_block.c.o
src/custom-actions/libcustom-actions.a: src/custom-actions/CMakeFiles/custom-actions.dir/src/custom-actions-cond.c.o
src/custom-actions/libcustom-actions.a: src/custom-actions/CMakeFiles/custom-actions.dir/src/custom-actions-effect.c.o
src/custom-actions/libcustom-actions.a: src/custom-actions/CMakeFiles/custom-actions.dir/src/interface.c.o
src/custom-actions/libcustom-actions.a: src/custom-actions/CMakeFiles/custom-actions.dir/build.make
src/custom-actions/libcustom-actions.a: src/custom-actions/CMakeFiles/custom-actions.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kabirdubey/cs220/chiventure/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking C static library libcustom-actions.a"
	cd /home/kabirdubey/cs220/chiventure/src/custom-actions && $(CMAKE_COMMAND) -P CMakeFiles/custom-actions.dir/cmake_clean_target.cmake
	cd /home/kabirdubey/cs220/chiventure/src/custom-actions && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/custom-actions.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/custom-actions/CMakeFiles/custom-actions.dir/build: src/custom-actions/libcustom-actions.a

.PHONY : src/custom-actions/CMakeFiles/custom-actions.dir/build

src/custom-actions/CMakeFiles/custom-actions.dir/clean:
	cd /home/kabirdubey/cs220/chiventure/src/custom-actions && $(CMAKE_COMMAND) -P CMakeFiles/custom-actions.dir/cmake_clean.cmake
.PHONY : src/custom-actions/CMakeFiles/custom-actions.dir/clean

src/custom-actions/CMakeFiles/custom-actions.dir/depend:
	cd /home/kabirdubey/cs220/chiventure && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kabirdubey/cs220/chiventure /home/kabirdubey/cs220/chiventure/src/custom-actions /home/kabirdubey/cs220/chiventure /home/kabirdubey/cs220/chiventure/src/custom-actions /home/kabirdubey/cs220/chiventure/src/custom-actions/CMakeFiles/custom-actions.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/custom-actions/CMakeFiles/custom-actions.dir/depend

