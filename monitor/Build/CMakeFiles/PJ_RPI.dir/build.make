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
CMAKE_SOURCE_DIR = /home/pi/trailer/school/embedded/rpimonitor-c/a/monitor

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pi/trailer/school/embedded/rpimonitor-c/a/monitor/Build

# Include any dependencies generated for this target.
include CMakeFiles/PJ_RPI.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/PJ_RPI.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PJ_RPI.dir/flags.make

CMakeFiles/PJ_RPI.dir/PJ_RPI.c.o: CMakeFiles/PJ_RPI.dir/flags.make
CMakeFiles/PJ_RPI.dir/PJ_RPI.c.o: ../PJ_RPI.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/trailer/school/embedded/rpimonitor-c/a/monitor/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/PJ_RPI.dir/PJ_RPI.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/PJ_RPI.dir/PJ_RPI.c.o   -c /home/pi/trailer/school/embedded/rpimonitor-c/a/monitor/PJ_RPI.c

CMakeFiles/PJ_RPI.dir/PJ_RPI.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/PJ_RPI.dir/PJ_RPI.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/pi/trailer/school/embedded/rpimonitor-c/a/monitor/PJ_RPI.c > CMakeFiles/PJ_RPI.dir/PJ_RPI.c.i

CMakeFiles/PJ_RPI.dir/PJ_RPI.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/PJ_RPI.dir/PJ_RPI.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/pi/trailer/school/embedded/rpimonitor-c/a/monitor/PJ_RPI.c -o CMakeFiles/PJ_RPI.dir/PJ_RPI.c.s

# Object files for target PJ_RPI
PJ_RPI_OBJECTS = \
"CMakeFiles/PJ_RPI.dir/PJ_RPI.c.o"

# External object files for target PJ_RPI
PJ_RPI_EXTERNAL_OBJECTS =

libPJ_RPI.a: CMakeFiles/PJ_RPI.dir/PJ_RPI.c.o
libPJ_RPI.a: CMakeFiles/PJ_RPI.dir/build.make
libPJ_RPI.a: CMakeFiles/PJ_RPI.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pi/trailer/school/embedded/rpimonitor-c/a/monitor/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libPJ_RPI.a"
	$(CMAKE_COMMAND) -P CMakeFiles/PJ_RPI.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PJ_RPI.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PJ_RPI.dir/build: libPJ_RPI.a

.PHONY : CMakeFiles/PJ_RPI.dir/build

CMakeFiles/PJ_RPI.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/PJ_RPI.dir/cmake_clean.cmake
.PHONY : CMakeFiles/PJ_RPI.dir/clean

CMakeFiles/PJ_RPI.dir/depend:
	cd /home/pi/trailer/school/embedded/rpimonitor-c/a/monitor/Build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/trailer/school/embedded/rpimonitor-c/a/monitor /home/pi/trailer/school/embedded/rpimonitor-c/a/monitor /home/pi/trailer/school/embedded/rpimonitor-c/a/monitor/Build /home/pi/trailer/school/embedded/rpimonitor-c/a/monitor/Build /home/pi/trailer/school/embedded/rpimonitor-c/a/monitor/Build/CMakeFiles/PJ_RPI.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/PJ_RPI.dir/depend

