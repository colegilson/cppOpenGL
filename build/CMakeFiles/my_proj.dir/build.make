# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_SOURCE_DIR = /home/colegilson/c++_play

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/colegilson/c++_play/build

# Include any dependencies generated for this target.
include CMakeFiles/my_proj.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/my_proj.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/my_proj.dir/flags.make

CMakeFiles/my_proj.dir/src/play.cpp.o: CMakeFiles/my_proj.dir/flags.make
CMakeFiles/my_proj.dir/src/play.cpp.o: ../src/play.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/colegilson/c++_play/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/my_proj.dir/src/play.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/my_proj.dir/src/play.cpp.o -c /home/colegilson/c++_play/src/play.cpp

CMakeFiles/my_proj.dir/src/play.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/my_proj.dir/src/play.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/colegilson/c++_play/src/play.cpp > CMakeFiles/my_proj.dir/src/play.cpp.i

CMakeFiles/my_proj.dir/src/play.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/my_proj.dir/src/play.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/colegilson/c++_play/src/play.cpp -o CMakeFiles/my_proj.dir/src/play.cpp.s

CMakeFiles/my_proj.dir/src/glew.c.o: CMakeFiles/my_proj.dir/flags.make
CMakeFiles/my_proj.dir/src/glew.c.o: ../src/glew.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/colegilson/c++_play/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/my_proj.dir/src/glew.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/my_proj.dir/src/glew.c.o -c /home/colegilson/c++_play/src/glew.c

CMakeFiles/my_proj.dir/src/glew.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/my_proj.dir/src/glew.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/colegilson/c++_play/src/glew.c > CMakeFiles/my_proj.dir/src/glew.c.i

CMakeFiles/my_proj.dir/src/glew.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/my_proj.dir/src/glew.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/colegilson/c++_play/src/glew.c -o CMakeFiles/my_proj.dir/src/glew.c.s

# Object files for target my_proj
my_proj_OBJECTS = \
"CMakeFiles/my_proj.dir/src/play.cpp.o" \
"CMakeFiles/my_proj.dir/src/glew.c.o"

# External object files for target my_proj
my_proj_EXTERNAL_OBJECTS =

my_proj: CMakeFiles/my_proj.dir/src/play.cpp.o
my_proj: CMakeFiles/my_proj.dir/src/glew.c.o
my_proj: CMakeFiles/my_proj.dir/build.make
my_proj: /usr/lib/x86_64-linux-gnu/libGL.so
my_proj: CMakeFiles/my_proj.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/colegilson/c++_play/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable my_proj"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/my_proj.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/my_proj.dir/build: my_proj

.PHONY : CMakeFiles/my_proj.dir/build

CMakeFiles/my_proj.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/my_proj.dir/cmake_clean.cmake
.PHONY : CMakeFiles/my_proj.dir/clean

CMakeFiles/my_proj.dir/depend:
	cd /home/colegilson/c++_play/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/colegilson/c++_play /home/colegilson/c++_play /home/colegilson/c++_play/build /home/colegilson/c++_play/build /home/colegilson/c++_play/build/CMakeFiles/my_proj.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/my_proj.dir/depend

