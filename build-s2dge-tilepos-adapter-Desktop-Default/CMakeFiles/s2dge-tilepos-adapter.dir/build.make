# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.7

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
CMAKE_COMMAND = C:\lib\cmake-3.7.0-rc2\bin\cmake.exe

# The command to remove a file.
RM = C:\lib\cmake-3.7.0-rc2\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\workspace\proyecto-de-graduacion\s2dge-tilepos-adapter

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\workspace\proyecto-de-graduacion\build-s2dge-tilepos-adapter-Desktop-Default

# Include any dependencies generated for this target.
include CMakeFiles/s2dge-tilepos-adapter.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/s2dge-tilepos-adapter.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/s2dge-tilepos-adapter.dir/flags.make

CMakeFiles/s2dge-tilepos-adapter.dir/main.cpp.obj: CMakeFiles/s2dge-tilepos-adapter.dir/flags.make
CMakeFiles/s2dge-tilepos-adapter.dir/main.cpp.obj: CMakeFiles/s2dge-tilepos-adapter.dir/includes_CXX.rsp
CMakeFiles/s2dge-tilepos-adapter.dir/main.cpp.obj: D:/workspace/proyecto-de-graduacion/s2dge-tilepos-adapter/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\workspace\proyecto-de-graduacion\build-s2dge-tilepos-adapter-Desktop-Default\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/s2dge-tilepos-adapter.dir/main.cpp.obj"
	C:\app\mingw64\mingw32\bin\i686-w64-mingw32-g++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\s2dge-tilepos-adapter.dir\main.cpp.obj -c D:\workspace\proyecto-de-graduacion\s2dge-tilepos-adapter\main.cpp

CMakeFiles/s2dge-tilepos-adapter.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/s2dge-tilepos-adapter.dir/main.cpp.i"
	C:\app\mingw64\mingw32\bin\i686-w64-mingw32-g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\workspace\proyecto-de-graduacion\s2dge-tilepos-adapter\main.cpp > CMakeFiles\s2dge-tilepos-adapter.dir\main.cpp.i

CMakeFiles/s2dge-tilepos-adapter.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/s2dge-tilepos-adapter.dir/main.cpp.s"
	C:\app\mingw64\mingw32\bin\i686-w64-mingw32-g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\workspace\proyecto-de-graduacion\s2dge-tilepos-adapter\main.cpp -o CMakeFiles\s2dge-tilepos-adapter.dir\main.cpp.s

CMakeFiles/s2dge-tilepos-adapter.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/s2dge-tilepos-adapter.dir/main.cpp.obj.requires

CMakeFiles/s2dge-tilepos-adapter.dir/main.cpp.obj.provides: CMakeFiles/s2dge-tilepos-adapter.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\s2dge-tilepos-adapter.dir\build.make CMakeFiles/s2dge-tilepos-adapter.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/s2dge-tilepos-adapter.dir/main.cpp.obj.provides

CMakeFiles/s2dge-tilepos-adapter.dir/main.cpp.obj.provides.build: CMakeFiles/s2dge-tilepos-adapter.dir/main.cpp.obj


# Object files for target s2dge-tilepos-adapter
s2dge__tilepos__adapter_OBJECTS = \
"CMakeFiles/s2dge-tilepos-adapter.dir/main.cpp.obj"

# External object files for target s2dge-tilepos-adapter
s2dge__tilepos__adapter_EXTERNAL_OBJECTS =

s2dge-tilepos-adapter.exe: CMakeFiles/s2dge-tilepos-adapter.dir/main.cpp.obj
s2dge-tilepos-adapter.exe: CMakeFiles/s2dge-tilepos-adapter.dir/build.make
s2dge-tilepos-adapter.exe: CMakeFiles/s2dge-tilepos-adapter.dir/linklibs.rsp
s2dge-tilepos-adapter.exe: CMakeFiles/s2dge-tilepos-adapter.dir/objects1.rsp
s2dge-tilepos-adapter.exe: CMakeFiles/s2dge-tilepos-adapter.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\workspace\proyecto-de-graduacion\build-s2dge-tilepos-adapter-Desktop-Default\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable s2dge-tilepos-adapter.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\s2dge-tilepos-adapter.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/s2dge-tilepos-adapter.dir/build: s2dge-tilepos-adapter.exe

.PHONY : CMakeFiles/s2dge-tilepos-adapter.dir/build

CMakeFiles/s2dge-tilepos-adapter.dir/requires: CMakeFiles/s2dge-tilepos-adapter.dir/main.cpp.obj.requires

.PHONY : CMakeFiles/s2dge-tilepos-adapter.dir/requires

CMakeFiles/s2dge-tilepos-adapter.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\s2dge-tilepos-adapter.dir\cmake_clean.cmake
.PHONY : CMakeFiles/s2dge-tilepos-adapter.dir/clean

CMakeFiles/s2dge-tilepos-adapter.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\workspace\proyecto-de-graduacion\s2dge-tilepos-adapter D:\workspace\proyecto-de-graduacion\s2dge-tilepos-adapter D:\workspace\proyecto-de-graduacion\build-s2dge-tilepos-adapter-Desktop-Default D:\workspace\proyecto-de-graduacion\build-s2dge-tilepos-adapter-Desktop-Default D:\workspace\proyecto-de-graduacion\build-s2dge-tilepos-adapter-Desktop-Default\CMakeFiles\s2dge-tilepos-adapter.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/s2dge-tilepos-adapter.dir/depend

