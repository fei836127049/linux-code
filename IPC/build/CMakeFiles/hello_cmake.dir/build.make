# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/code/linux/linux-code/IPC

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/code/linux/linux-code/IPC/build

# Include any dependencies generated for this target.
include CMakeFiles/hello_cmake.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/hello_cmake.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/hello_cmake.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hello_cmake.dir/flags.make

CMakeFiles/hello_cmake.dir/src/hello.c.o: CMakeFiles/hello_cmake.dir/flags.make
CMakeFiles/hello_cmake.dir/src/hello.c.o: ../src/hello.c
CMakeFiles/hello_cmake.dir/src/hello.c.o: CMakeFiles/hello_cmake.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/code/linux/linux-code/IPC/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/hello_cmake.dir/src/hello.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/hello_cmake.dir/src/hello.c.o -MF CMakeFiles/hello_cmake.dir/src/hello.c.o.d -o CMakeFiles/hello_cmake.dir/src/hello.c.o -c /home/code/linux/linux-code/IPC/src/hello.c

CMakeFiles/hello_cmake.dir/src/hello.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/hello_cmake.dir/src/hello.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/code/linux/linux-code/IPC/src/hello.c > CMakeFiles/hello_cmake.dir/src/hello.c.i

CMakeFiles/hello_cmake.dir/src/hello.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/hello_cmake.dir/src/hello.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/code/linux/linux-code/IPC/src/hello.c -o CMakeFiles/hello_cmake.dir/src/hello.c.s

CMakeFiles/hello_cmake.dir/src/main.c.o: CMakeFiles/hello_cmake.dir/flags.make
CMakeFiles/hello_cmake.dir/src/main.c.o: ../src/main.c
CMakeFiles/hello_cmake.dir/src/main.c.o: CMakeFiles/hello_cmake.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/code/linux/linux-code/IPC/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/hello_cmake.dir/src/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/hello_cmake.dir/src/main.c.o -MF CMakeFiles/hello_cmake.dir/src/main.c.o.d -o CMakeFiles/hello_cmake.dir/src/main.c.o -c /home/code/linux/linux-code/IPC/src/main.c

CMakeFiles/hello_cmake.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/hello_cmake.dir/src/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/code/linux/linux-code/IPC/src/main.c > CMakeFiles/hello_cmake.dir/src/main.c.i

CMakeFiles/hello_cmake.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/hello_cmake.dir/src/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/code/linux/linux-code/IPC/src/main.c -o CMakeFiles/hello_cmake.dir/src/main.c.s

# Object files for target hello_cmake
hello_cmake_OBJECTS = \
"CMakeFiles/hello_cmake.dir/src/hello.c.o" \
"CMakeFiles/hello_cmake.dir/src/main.c.o"

# External object files for target hello_cmake
hello_cmake_EXTERNAL_OBJECTS =

../code-out/hello_cmake: CMakeFiles/hello_cmake.dir/src/hello.c.o
../code-out/hello_cmake: CMakeFiles/hello_cmake.dir/src/main.c.o
../code-out/hello_cmake: CMakeFiles/hello_cmake.dir/build.make
../code-out/hello_cmake: CMakeFiles/hello_cmake.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/code/linux/linux-code/IPC/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable ../code-out/hello_cmake"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hello_cmake.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/hello_cmake.dir/build: ../code-out/hello_cmake
.PHONY : CMakeFiles/hello_cmake.dir/build

CMakeFiles/hello_cmake.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/hello_cmake.dir/cmake_clean.cmake
.PHONY : CMakeFiles/hello_cmake.dir/clean

CMakeFiles/hello_cmake.dir/depend:
	cd /home/code/linux/linux-code/IPC/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/code/linux/linux-code/IPC /home/code/linux/linux-code/IPC /home/code/linux/linux-code/IPC/build /home/code/linux/linux-code/IPC/build /home/code/linux/linux-code/IPC/build/CMakeFiles/hello_cmake.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/hello_cmake.dir/depend

