# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.9

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "E:\CLion 2017.3.4\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "E:\CLion 2017.3.4\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Kitsch\Desktop\IS590PZ\Github Code\590PZ-Project\ChessAi"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Kitsch\Desktop\IS590PZ\Github Code\590PZ-Project\ChessAi\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/ChessAi.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ChessAi.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ChessAi.dir/flags.make

CMakeFiles/ChessAi.dir/main.cpp.obj: CMakeFiles/ChessAi.dir/flags.make
CMakeFiles/ChessAi.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Kitsch\Desktop\IS590PZ\Github Code\590PZ-Project\ChessAi\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ChessAi.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\ChessAi.dir\main.cpp.obj -c "C:\Users\Kitsch\Desktop\IS590PZ\Github Code\590PZ-Project\ChessAi\main.cpp"

CMakeFiles/ChessAi.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ChessAi.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Kitsch\Desktop\IS590PZ\Github Code\590PZ-Project\ChessAi\main.cpp" > CMakeFiles\ChessAi.dir\main.cpp.i

CMakeFiles/ChessAi.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ChessAi.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Kitsch\Desktop\IS590PZ\Github Code\590PZ-Project\ChessAi\main.cpp" -o CMakeFiles\ChessAi.dir\main.cpp.s

CMakeFiles/ChessAi.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/ChessAi.dir/main.cpp.obj.requires

CMakeFiles/ChessAi.dir/main.cpp.obj.provides: CMakeFiles/ChessAi.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\ChessAi.dir\build.make CMakeFiles/ChessAi.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/ChessAi.dir/main.cpp.obj.provides

CMakeFiles/ChessAi.dir/main.cpp.obj.provides.build: CMakeFiles/ChessAi.dir/main.cpp.obj


# Object files for target ChessAi
ChessAi_OBJECTS = \
"CMakeFiles/ChessAi.dir/main.cpp.obj"

# External object files for target ChessAi
ChessAi_EXTERNAL_OBJECTS =

ChessAi.exe: CMakeFiles/ChessAi.dir/main.cpp.obj
ChessAi.exe: CMakeFiles/ChessAi.dir/build.make
ChessAi.exe: CMakeFiles/ChessAi.dir/linklibs.rsp
ChessAi.exe: CMakeFiles/ChessAi.dir/objects1.rsp
ChessAi.exe: CMakeFiles/ChessAi.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Kitsch\Desktop\IS590PZ\Github Code\590PZ-Project\ChessAi\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ChessAi.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\ChessAi.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ChessAi.dir/build: ChessAi.exe

.PHONY : CMakeFiles/ChessAi.dir/build

CMakeFiles/ChessAi.dir/requires: CMakeFiles/ChessAi.dir/main.cpp.obj.requires

.PHONY : CMakeFiles/ChessAi.dir/requires

CMakeFiles/ChessAi.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ChessAi.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ChessAi.dir/clean

CMakeFiles/ChessAi.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Kitsch\Desktop\IS590PZ\Github Code\590PZ-Project\ChessAi" "C:\Users\Kitsch\Desktop\IS590PZ\Github Code\590PZ-Project\ChessAi" "C:\Users\Kitsch\Desktop\IS590PZ\Github Code\590PZ-Project\ChessAi\cmake-build-debug" "C:\Users\Kitsch\Desktop\IS590PZ\Github Code\590PZ-Project\ChessAi\cmake-build-debug" "C:\Users\Kitsch\Desktop\IS590PZ\Github Code\590PZ-Project\ChessAi\cmake-build-debug\CMakeFiles\ChessAi.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/ChessAi.dir/depend
