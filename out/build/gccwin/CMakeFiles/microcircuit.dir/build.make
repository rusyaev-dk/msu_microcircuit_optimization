# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.26

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
CMAKE_COMMAND = "C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\ASUS\Desktop\Discrete optimization\microcircuit"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\ASUS\Desktop\Discrete optimization\microcircuit\out\build\gccwin"

# Include any dependencies generated for this target.
include CMakeFiles/microcircuit.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/microcircuit.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/microcircuit.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/microcircuit.dir/flags.make

CMakeFiles/microcircuit.dir/main.cpp.obj: CMakeFiles/microcircuit.dir/flags.make
CMakeFiles/microcircuit.dir/main.cpp.obj: C:/Users/ASUS/Desktop/Discrete\ optimization/microcircuit/main.cpp
CMakeFiles/microcircuit.dir/main.cpp.obj: CMakeFiles/microcircuit.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\ASUS\Desktop\Discrete optimization\microcircuit\out\build\gccwin\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/microcircuit.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/microcircuit.dir/main.cpp.obj -MF CMakeFiles\microcircuit.dir\main.cpp.obj.d -o CMakeFiles\microcircuit.dir\main.cpp.obj -c "C:\Users\ASUS\Desktop\Discrete optimization\microcircuit\main.cpp"

CMakeFiles/microcircuit.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/microcircuit.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\ASUS\Desktop\Discrete optimization\microcircuit\main.cpp" > CMakeFiles\microcircuit.dir\main.cpp.i

CMakeFiles/microcircuit.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/microcircuit.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\ASUS\Desktop\Discrete optimization\microcircuit\main.cpp" -o CMakeFiles\microcircuit.dir\main.cpp.s

CMakeFiles/microcircuit.dir/microcircuit.cpp.obj: CMakeFiles/microcircuit.dir/flags.make
CMakeFiles/microcircuit.dir/microcircuit.cpp.obj: C:/Users/ASUS/Desktop/Discrete\ optimization/microcircuit/microcircuit.cpp
CMakeFiles/microcircuit.dir/microcircuit.cpp.obj: CMakeFiles/microcircuit.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\ASUS\Desktop\Discrete optimization\microcircuit\out\build\gccwin\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/microcircuit.dir/microcircuit.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/microcircuit.dir/microcircuit.cpp.obj -MF CMakeFiles\microcircuit.dir\microcircuit.cpp.obj.d -o CMakeFiles\microcircuit.dir\microcircuit.cpp.obj -c "C:\Users\ASUS\Desktop\Discrete optimization\microcircuit\microcircuit.cpp"

CMakeFiles/microcircuit.dir/microcircuit.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/microcircuit.dir/microcircuit.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\ASUS\Desktop\Discrete optimization\microcircuit\microcircuit.cpp" > CMakeFiles\microcircuit.dir\microcircuit.cpp.i

CMakeFiles/microcircuit.dir/microcircuit.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/microcircuit.dir/microcircuit.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\ASUS\Desktop\Discrete optimization\microcircuit\microcircuit.cpp" -o CMakeFiles\microcircuit.dir\microcircuit.cpp.s

# Object files for target microcircuit
microcircuit_OBJECTS = \
"CMakeFiles/microcircuit.dir/main.cpp.obj" \
"CMakeFiles/microcircuit.dir/microcircuit.cpp.obj"

# External object files for target microcircuit
microcircuit_EXTERNAL_OBJECTS =

microcircuit.exe: CMakeFiles/microcircuit.dir/main.cpp.obj
microcircuit.exe: CMakeFiles/microcircuit.dir/microcircuit.cpp.obj
microcircuit.exe: CMakeFiles/microcircuit.dir/build.make
microcircuit.exe: CMakeFiles/microcircuit.dir/linkLibs.rsp
microcircuit.exe: CMakeFiles/microcircuit.dir/objects1.rsp
microcircuit.exe: CMakeFiles/microcircuit.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\ASUS\Desktop\Discrete optimization\microcircuit\out\build\gccwin\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable microcircuit.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\microcircuit.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/microcircuit.dir/build: microcircuit.exe
.PHONY : CMakeFiles/microcircuit.dir/build

CMakeFiles/microcircuit.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\microcircuit.dir\cmake_clean.cmake
.PHONY : CMakeFiles/microcircuit.dir/clean

CMakeFiles/microcircuit.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\ASUS\Desktop\Discrete optimization\microcircuit" "C:\Users\ASUS\Desktop\Discrete optimization\microcircuit" "C:\Users\ASUS\Desktop\Discrete optimization\microcircuit\out\build\gccwin" "C:\Users\ASUS\Desktop\Discrete optimization\microcircuit\out\build\gccwin" "C:\Users\ASUS\Desktop\Discrete optimization\microcircuit\out\build\gccwin\CMakeFiles\microcircuit.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/microcircuit.dir/depend

