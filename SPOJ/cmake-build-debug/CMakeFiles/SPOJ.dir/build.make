# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.19

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Piotrek\CLionProjects\SPOJ

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Piotrek\CLionProjects\SPOJ\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/SPOJ.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SPOJ.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SPOJ.dir/flags.make

CMakeFiles/SPOJ.dir/main.cpp.obj: CMakeFiles/SPOJ.dir/flags.make
CMakeFiles/SPOJ.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Piotrek\CLionProjects\SPOJ\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SPOJ.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\SPOJ.dir\main.cpp.obj -c C:\Users\Piotrek\CLionProjects\SPOJ\main.cpp

CMakeFiles/SPOJ.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SPOJ.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Piotrek\CLionProjects\SPOJ\main.cpp > CMakeFiles\SPOJ.dir\main.cpp.i

CMakeFiles/SPOJ.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SPOJ.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Piotrek\CLionProjects\SPOJ\main.cpp -o CMakeFiles\SPOJ.dir\main.cpp.s

# Object files for target SPOJ
SPOJ_OBJECTS = \
"CMakeFiles/SPOJ.dir/main.cpp.obj"

# External object files for target SPOJ
SPOJ_EXTERNAL_OBJECTS =

SPOJ.exe: CMakeFiles/SPOJ.dir/main.cpp.obj
SPOJ.exe: CMakeFiles/SPOJ.dir/build.make
SPOJ.exe: CMakeFiles/SPOJ.dir/linklibs.rsp
SPOJ.exe: CMakeFiles/SPOJ.dir/objects1.rsp
SPOJ.exe: CMakeFiles/SPOJ.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Piotrek\CLionProjects\SPOJ\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable SPOJ.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\SPOJ.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SPOJ.dir/build: SPOJ.exe

.PHONY : CMakeFiles/SPOJ.dir/build

CMakeFiles/SPOJ.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\SPOJ.dir\cmake_clean.cmake
.PHONY : CMakeFiles/SPOJ.dir/clean

CMakeFiles/SPOJ.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Piotrek\CLionProjects\SPOJ C:\Users\Piotrek\CLionProjects\SPOJ C:\Users\Piotrek\CLionProjects\SPOJ\cmake-build-debug C:\Users\Piotrek\CLionProjects\SPOJ\cmake-build-debug C:\Users\Piotrek\CLionProjects\SPOJ\cmake-build-debug\CMakeFiles\SPOJ.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SPOJ.dir/depend

