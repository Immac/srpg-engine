# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = C:\tools\clion-2017-2\bin\cmake\bin\cmake.exe

# The command to remove a file.
RM = C:\tools\clion-2017-2\bin\cmake\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\workspace\proyecto-de-graduacion\srpg-engine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\workspace\proyecto-de-graduacion\srpg-engine\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/srpg-engine.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/srpg-engine.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/srpg-engine.dir/flags.make

CMakeFiles/srpg-engine.dir/src/collection.cpp.obj: CMakeFiles/srpg-engine.dir/flags.make
CMakeFiles/srpg-engine.dir/src/collection.cpp.obj: CMakeFiles/srpg-engine.dir/includes_CXX.rsp
CMakeFiles/srpg-engine.dir/src/collection.cpp.obj: ../src/collection.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\workspace\proyecto-de-graduacion\srpg-engine\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/srpg-engine.dir/src/collection.cpp.obj"
	C:\app\mingw64\mingw32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\srpg-engine.dir\src\collection.cpp.obj -c D:\workspace\proyecto-de-graduacion\srpg-engine\src\collection.cpp

CMakeFiles/srpg-engine.dir/src/collection.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/srpg-engine.dir/src/collection.cpp.i"
	C:\app\mingw64\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\workspace\proyecto-de-graduacion\srpg-engine\src\collection.cpp > CMakeFiles\srpg-engine.dir\src\collection.cpp.i

CMakeFiles/srpg-engine.dir/src/collection.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/srpg-engine.dir/src/collection.cpp.s"
	C:\app\mingw64\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\workspace\proyecto-de-graduacion\srpg-engine\src\collection.cpp -o CMakeFiles\srpg-engine.dir\src\collection.cpp.s

CMakeFiles/srpg-engine.dir/src/collection.cpp.obj.requires:

.PHONY : CMakeFiles/srpg-engine.dir/src/collection.cpp.obj.requires

CMakeFiles/srpg-engine.dir/src/collection.cpp.obj.provides: CMakeFiles/srpg-engine.dir/src/collection.cpp.obj.requires
	$(MAKE) -f CMakeFiles\srpg-engine.dir\build.make CMakeFiles/srpg-engine.dir/src/collection.cpp.obj.provides.build
.PHONY : CMakeFiles/srpg-engine.dir/src/collection.cpp.obj.provides

CMakeFiles/srpg-engine.dir/src/collection.cpp.obj.provides.build: CMakeFiles/srpg-engine.dir/src/collection.cpp.obj


CMakeFiles/srpg-engine.dir/src/configuration-manager.cpp.obj: CMakeFiles/srpg-engine.dir/flags.make
CMakeFiles/srpg-engine.dir/src/configuration-manager.cpp.obj: CMakeFiles/srpg-engine.dir/includes_CXX.rsp
CMakeFiles/srpg-engine.dir/src/configuration-manager.cpp.obj: ../src/configuration-manager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\workspace\proyecto-de-graduacion\srpg-engine\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/srpg-engine.dir/src/configuration-manager.cpp.obj"
	C:\app\mingw64\mingw32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\srpg-engine.dir\src\configuration-manager.cpp.obj -c D:\workspace\proyecto-de-graduacion\srpg-engine\src\configuration-manager.cpp

CMakeFiles/srpg-engine.dir/src/configuration-manager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/srpg-engine.dir/src/configuration-manager.cpp.i"
	C:\app\mingw64\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\workspace\proyecto-de-graduacion\srpg-engine\src\configuration-manager.cpp > CMakeFiles\srpg-engine.dir\src\configuration-manager.cpp.i

CMakeFiles/srpg-engine.dir/src/configuration-manager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/srpg-engine.dir/src/configuration-manager.cpp.s"
	C:\app\mingw64\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\workspace\proyecto-de-graduacion\srpg-engine\src\configuration-manager.cpp -o CMakeFiles\srpg-engine.dir\src\configuration-manager.cpp.s

CMakeFiles/srpg-engine.dir/src/configuration-manager.cpp.obj.requires:

.PHONY : CMakeFiles/srpg-engine.dir/src/configuration-manager.cpp.obj.requires

CMakeFiles/srpg-engine.dir/src/configuration-manager.cpp.obj.provides: CMakeFiles/srpg-engine.dir/src/configuration-manager.cpp.obj.requires
	$(MAKE) -f CMakeFiles\srpg-engine.dir\build.make CMakeFiles/srpg-engine.dir/src/configuration-manager.cpp.obj.provides.build
.PHONY : CMakeFiles/srpg-engine.dir/src/configuration-manager.cpp.obj.provides

CMakeFiles/srpg-engine.dir/src/configuration-manager.cpp.obj.provides.build: CMakeFiles/srpg-engine.dir/src/configuration-manager.cpp.obj


CMakeFiles/srpg-engine.dir/src/core-vocabulary.cpp.obj: CMakeFiles/srpg-engine.dir/flags.make
CMakeFiles/srpg-engine.dir/src/core-vocabulary.cpp.obj: CMakeFiles/srpg-engine.dir/includes_CXX.rsp
CMakeFiles/srpg-engine.dir/src/core-vocabulary.cpp.obj: ../src/core-vocabulary.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\workspace\proyecto-de-graduacion\srpg-engine\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/srpg-engine.dir/src/core-vocabulary.cpp.obj"
	C:\app\mingw64\mingw32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\srpg-engine.dir\src\core-vocabulary.cpp.obj -c D:\workspace\proyecto-de-graduacion\srpg-engine\src\core-vocabulary.cpp

CMakeFiles/srpg-engine.dir/src/core-vocabulary.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/srpg-engine.dir/src/core-vocabulary.cpp.i"
	C:\app\mingw64\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\workspace\proyecto-de-graduacion\srpg-engine\src\core-vocabulary.cpp > CMakeFiles\srpg-engine.dir\src\core-vocabulary.cpp.i

CMakeFiles/srpg-engine.dir/src/core-vocabulary.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/srpg-engine.dir/src/core-vocabulary.cpp.s"
	C:\app\mingw64\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\workspace\proyecto-de-graduacion\srpg-engine\src\core-vocabulary.cpp -o CMakeFiles\srpg-engine.dir\src\core-vocabulary.cpp.s

CMakeFiles/srpg-engine.dir/src/core-vocabulary.cpp.obj.requires:

.PHONY : CMakeFiles/srpg-engine.dir/src/core-vocabulary.cpp.obj.requires

CMakeFiles/srpg-engine.dir/src/core-vocabulary.cpp.obj.provides: CMakeFiles/srpg-engine.dir/src/core-vocabulary.cpp.obj.requires
	$(MAKE) -f CMakeFiles\srpg-engine.dir\build.make CMakeFiles/srpg-engine.dir/src/core-vocabulary.cpp.obj.provides.build
.PHONY : CMakeFiles/srpg-engine.dir/src/core-vocabulary.cpp.obj.provides

CMakeFiles/srpg-engine.dir/src/core-vocabulary.cpp.obj.provides.build: CMakeFiles/srpg-engine.dir/src/core-vocabulary.cpp.obj


CMakeFiles/srpg-engine.dir/src/game-controller.cpp.obj: CMakeFiles/srpg-engine.dir/flags.make
CMakeFiles/srpg-engine.dir/src/game-controller.cpp.obj: CMakeFiles/srpg-engine.dir/includes_CXX.rsp
CMakeFiles/srpg-engine.dir/src/game-controller.cpp.obj: ../src/game-controller.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\workspace\proyecto-de-graduacion\srpg-engine\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/srpg-engine.dir/src/game-controller.cpp.obj"
	C:\app\mingw64\mingw32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\srpg-engine.dir\src\game-controller.cpp.obj -c D:\workspace\proyecto-de-graduacion\srpg-engine\src\game-controller.cpp

CMakeFiles/srpg-engine.dir/src/game-controller.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/srpg-engine.dir/src/game-controller.cpp.i"
	C:\app\mingw64\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\workspace\proyecto-de-graduacion\srpg-engine\src\game-controller.cpp > CMakeFiles\srpg-engine.dir\src\game-controller.cpp.i

CMakeFiles/srpg-engine.dir/src/game-controller.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/srpg-engine.dir/src/game-controller.cpp.s"
	C:\app\mingw64\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\workspace\proyecto-de-graduacion\srpg-engine\src\game-controller.cpp -o CMakeFiles\srpg-engine.dir\src\game-controller.cpp.s

CMakeFiles/srpg-engine.dir/src/game-controller.cpp.obj.requires:

.PHONY : CMakeFiles/srpg-engine.dir/src/game-controller.cpp.obj.requires

CMakeFiles/srpg-engine.dir/src/game-controller.cpp.obj.provides: CMakeFiles/srpg-engine.dir/src/game-controller.cpp.obj.requires
	$(MAKE) -f CMakeFiles\srpg-engine.dir\build.make CMakeFiles/srpg-engine.dir/src/game-controller.cpp.obj.provides.build
.PHONY : CMakeFiles/srpg-engine.dir/src/game-controller.cpp.obj.provides

CMakeFiles/srpg-engine.dir/src/game-controller.cpp.obj.provides.build: CMakeFiles/srpg-engine.dir/src/game-controller.cpp.obj


CMakeFiles/srpg-engine.dir/src/gamecore.cpp.obj: CMakeFiles/srpg-engine.dir/flags.make
CMakeFiles/srpg-engine.dir/src/gamecore.cpp.obj: CMakeFiles/srpg-engine.dir/includes_CXX.rsp
CMakeFiles/srpg-engine.dir/src/gamecore.cpp.obj: ../src/gamecore.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\workspace\proyecto-de-graduacion\srpg-engine\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/srpg-engine.dir/src/gamecore.cpp.obj"
	C:\app\mingw64\mingw32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\srpg-engine.dir\src\gamecore.cpp.obj -c D:\workspace\proyecto-de-graduacion\srpg-engine\src\gamecore.cpp

CMakeFiles/srpg-engine.dir/src/gamecore.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/srpg-engine.dir/src/gamecore.cpp.i"
	C:\app\mingw64\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\workspace\proyecto-de-graduacion\srpg-engine\src\gamecore.cpp > CMakeFiles\srpg-engine.dir\src\gamecore.cpp.i

CMakeFiles/srpg-engine.dir/src/gamecore.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/srpg-engine.dir/src/gamecore.cpp.s"
	C:\app\mingw64\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\workspace\proyecto-de-graduacion\srpg-engine\src\gamecore.cpp -o CMakeFiles\srpg-engine.dir\src\gamecore.cpp.s

CMakeFiles/srpg-engine.dir/src/gamecore.cpp.obj.requires:

.PHONY : CMakeFiles/srpg-engine.dir/src/gamecore.cpp.obj.requires

CMakeFiles/srpg-engine.dir/src/gamecore.cpp.obj.provides: CMakeFiles/srpg-engine.dir/src/gamecore.cpp.obj.requires
	$(MAKE) -f CMakeFiles\srpg-engine.dir\build.make CMakeFiles/srpg-engine.dir/src/gamecore.cpp.obj.provides.build
.PHONY : CMakeFiles/srpg-engine.dir/src/gamecore.cpp.obj.provides

CMakeFiles/srpg-engine.dir/src/gamecore.cpp.obj.provides.build: CMakeFiles/srpg-engine.dir/src/gamecore.cpp.obj


CMakeFiles/srpg-engine.dir/src/gameobject.cpp.obj: CMakeFiles/srpg-engine.dir/flags.make
CMakeFiles/srpg-engine.dir/src/gameobject.cpp.obj: CMakeFiles/srpg-engine.dir/includes_CXX.rsp
CMakeFiles/srpg-engine.dir/src/gameobject.cpp.obj: ../src/gameobject.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\workspace\proyecto-de-graduacion\srpg-engine\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/srpg-engine.dir/src/gameobject.cpp.obj"
	C:\app\mingw64\mingw32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\srpg-engine.dir\src\gameobject.cpp.obj -c D:\workspace\proyecto-de-graduacion\srpg-engine\src\gameobject.cpp

CMakeFiles/srpg-engine.dir/src/gameobject.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/srpg-engine.dir/src/gameobject.cpp.i"
	C:\app\mingw64\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\workspace\proyecto-de-graduacion\srpg-engine\src\gameobject.cpp > CMakeFiles\srpg-engine.dir\src\gameobject.cpp.i

CMakeFiles/srpg-engine.dir/src/gameobject.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/srpg-engine.dir/src/gameobject.cpp.s"
	C:\app\mingw64\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\workspace\proyecto-de-graduacion\srpg-engine\src\gameobject.cpp -o CMakeFiles\srpg-engine.dir\src\gameobject.cpp.s

CMakeFiles/srpg-engine.dir/src/gameobject.cpp.obj.requires:

.PHONY : CMakeFiles/srpg-engine.dir/src/gameobject.cpp.obj.requires

CMakeFiles/srpg-engine.dir/src/gameobject.cpp.obj.provides: CMakeFiles/srpg-engine.dir/src/gameobject.cpp.obj.requires
	$(MAKE) -f CMakeFiles\srpg-engine.dir\build.make CMakeFiles/srpg-engine.dir/src/gameobject.cpp.obj.provides.build
.PHONY : CMakeFiles/srpg-engine.dir/src/gameobject.cpp.obj.provides

CMakeFiles/srpg-engine.dir/src/gameobject.cpp.obj.provides.build: CMakeFiles/srpg-engine.dir/src/gameobject.cpp.obj


CMakeFiles/srpg-engine.dir/src/luautil.cpp.obj: CMakeFiles/srpg-engine.dir/flags.make
CMakeFiles/srpg-engine.dir/src/luautil.cpp.obj: CMakeFiles/srpg-engine.dir/includes_CXX.rsp
CMakeFiles/srpg-engine.dir/src/luautil.cpp.obj: ../src/luautil.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\workspace\proyecto-de-graduacion\srpg-engine\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/srpg-engine.dir/src/luautil.cpp.obj"
	C:\app\mingw64\mingw32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\srpg-engine.dir\src\luautil.cpp.obj -c D:\workspace\proyecto-de-graduacion\srpg-engine\src\luautil.cpp

CMakeFiles/srpg-engine.dir/src/luautil.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/srpg-engine.dir/src/luautil.cpp.i"
	C:\app\mingw64\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\workspace\proyecto-de-graduacion\srpg-engine\src\luautil.cpp > CMakeFiles\srpg-engine.dir\src\luautil.cpp.i

CMakeFiles/srpg-engine.dir/src/luautil.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/srpg-engine.dir/src/luautil.cpp.s"
	C:\app\mingw64\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\workspace\proyecto-de-graduacion\srpg-engine\src\luautil.cpp -o CMakeFiles\srpg-engine.dir\src\luautil.cpp.s

CMakeFiles/srpg-engine.dir/src/luautil.cpp.obj.requires:

.PHONY : CMakeFiles/srpg-engine.dir/src/luautil.cpp.obj.requires

CMakeFiles/srpg-engine.dir/src/luautil.cpp.obj.provides: CMakeFiles/srpg-engine.dir/src/luautil.cpp.obj.requires
	$(MAKE) -f CMakeFiles\srpg-engine.dir\build.make CMakeFiles/srpg-engine.dir/src/luautil.cpp.obj.provides.build
.PHONY : CMakeFiles/srpg-engine.dir/src/luautil.cpp.obj.provides

CMakeFiles/srpg-engine.dir/src/luautil.cpp.obj.provides.build: CMakeFiles/srpg-engine.dir/src/luautil.cpp.obj


CMakeFiles/srpg-engine.dir/src/main.cpp.obj: CMakeFiles/srpg-engine.dir/flags.make
CMakeFiles/srpg-engine.dir/src/main.cpp.obj: CMakeFiles/srpg-engine.dir/includes_CXX.rsp
CMakeFiles/srpg-engine.dir/src/main.cpp.obj: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\workspace\proyecto-de-graduacion\srpg-engine\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/srpg-engine.dir/src/main.cpp.obj"
	C:\app\mingw64\mingw32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\srpg-engine.dir\src\main.cpp.obj -c D:\workspace\proyecto-de-graduacion\srpg-engine\src\main.cpp

CMakeFiles/srpg-engine.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/srpg-engine.dir/src/main.cpp.i"
	C:\app\mingw64\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\workspace\proyecto-de-graduacion\srpg-engine\src\main.cpp > CMakeFiles\srpg-engine.dir\src\main.cpp.i

CMakeFiles/srpg-engine.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/srpg-engine.dir/src/main.cpp.s"
	C:\app\mingw64\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\workspace\proyecto-de-graduacion\srpg-engine\src\main.cpp -o CMakeFiles\srpg-engine.dir\src\main.cpp.s

CMakeFiles/srpg-engine.dir/src/main.cpp.obj.requires:

.PHONY : CMakeFiles/srpg-engine.dir/src/main.cpp.obj.requires

CMakeFiles/srpg-engine.dir/src/main.cpp.obj.provides: CMakeFiles/srpg-engine.dir/src/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\srpg-engine.dir\build.make CMakeFiles/srpg-engine.dir/src/main.cpp.obj.provides.build
.PHONY : CMakeFiles/srpg-engine.dir/src/main.cpp.obj.provides

CMakeFiles/srpg-engine.dir/src/main.cpp.obj.provides.build: CMakeFiles/srpg-engine.dir/src/main.cpp.obj


CMakeFiles/srpg-engine.dir/src/observer.cpp.obj: CMakeFiles/srpg-engine.dir/flags.make
CMakeFiles/srpg-engine.dir/src/observer.cpp.obj: CMakeFiles/srpg-engine.dir/includes_CXX.rsp
CMakeFiles/srpg-engine.dir/src/observer.cpp.obj: ../src/observer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\workspace\proyecto-de-graduacion\srpg-engine\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/srpg-engine.dir/src/observer.cpp.obj"
	C:\app\mingw64\mingw32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\srpg-engine.dir\src\observer.cpp.obj -c D:\workspace\proyecto-de-graduacion\srpg-engine\src\observer.cpp

CMakeFiles/srpg-engine.dir/src/observer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/srpg-engine.dir/src/observer.cpp.i"
	C:\app\mingw64\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\workspace\proyecto-de-graduacion\srpg-engine\src\observer.cpp > CMakeFiles\srpg-engine.dir\src\observer.cpp.i

CMakeFiles/srpg-engine.dir/src/observer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/srpg-engine.dir/src/observer.cpp.s"
	C:\app\mingw64\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\workspace\proyecto-de-graduacion\srpg-engine\src\observer.cpp -o CMakeFiles\srpg-engine.dir\src\observer.cpp.s

CMakeFiles/srpg-engine.dir/src/observer.cpp.obj.requires:

.PHONY : CMakeFiles/srpg-engine.dir/src/observer.cpp.obj.requires

CMakeFiles/srpg-engine.dir/src/observer.cpp.obj.provides: CMakeFiles/srpg-engine.dir/src/observer.cpp.obj.requires
	$(MAKE) -f CMakeFiles\srpg-engine.dir\build.make CMakeFiles/srpg-engine.dir/src/observer.cpp.obj.provides.build
.PHONY : CMakeFiles/srpg-engine.dir/src/observer.cpp.obj.provides

CMakeFiles/srpg-engine.dir/src/observer.cpp.obj.provides.build: CMakeFiles/srpg-engine.dir/src/observer.cpp.obj


CMakeFiles/srpg-engine.dir/src/scene.cpp.obj: CMakeFiles/srpg-engine.dir/flags.make
CMakeFiles/srpg-engine.dir/src/scene.cpp.obj: CMakeFiles/srpg-engine.dir/includes_CXX.rsp
CMakeFiles/srpg-engine.dir/src/scene.cpp.obj: ../src/scene.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\workspace\proyecto-de-graduacion\srpg-engine\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/srpg-engine.dir/src/scene.cpp.obj"
	C:\app\mingw64\mingw32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\srpg-engine.dir\src\scene.cpp.obj -c D:\workspace\proyecto-de-graduacion\srpg-engine\src\scene.cpp

CMakeFiles/srpg-engine.dir/src/scene.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/srpg-engine.dir/src/scene.cpp.i"
	C:\app\mingw64\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\workspace\proyecto-de-graduacion\srpg-engine\src\scene.cpp > CMakeFiles\srpg-engine.dir\src\scene.cpp.i

CMakeFiles/srpg-engine.dir/src/scene.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/srpg-engine.dir/src/scene.cpp.s"
	C:\app\mingw64\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\workspace\proyecto-de-graduacion\srpg-engine\src\scene.cpp -o CMakeFiles\srpg-engine.dir\src\scene.cpp.s

CMakeFiles/srpg-engine.dir/src/scene.cpp.obj.requires:

.PHONY : CMakeFiles/srpg-engine.dir/src/scene.cpp.obj.requires

CMakeFiles/srpg-engine.dir/src/scene.cpp.obj.provides: CMakeFiles/srpg-engine.dir/src/scene.cpp.obj.requires
	$(MAKE) -f CMakeFiles\srpg-engine.dir\build.make CMakeFiles/srpg-engine.dir/src/scene.cpp.obj.provides.build
.PHONY : CMakeFiles/srpg-engine.dir/src/scene.cpp.obj.provides

CMakeFiles/srpg-engine.dir/src/scene.cpp.obj.provides.build: CMakeFiles/srpg-engine.dir/src/scene.cpp.obj


CMakeFiles/srpg-engine.dir/src/state-machine.cpp.obj: CMakeFiles/srpg-engine.dir/flags.make
CMakeFiles/srpg-engine.dir/src/state-machine.cpp.obj: CMakeFiles/srpg-engine.dir/includes_CXX.rsp
CMakeFiles/srpg-engine.dir/src/state-machine.cpp.obj: ../src/state-machine.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\workspace\proyecto-de-graduacion\srpg-engine\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/srpg-engine.dir/src/state-machine.cpp.obj"
	C:\app\mingw64\mingw32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\srpg-engine.dir\src\state-machine.cpp.obj -c D:\workspace\proyecto-de-graduacion\srpg-engine\src\state-machine.cpp

CMakeFiles/srpg-engine.dir/src/state-machine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/srpg-engine.dir/src/state-machine.cpp.i"
	C:\app\mingw64\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\workspace\proyecto-de-graduacion\srpg-engine\src\state-machine.cpp > CMakeFiles\srpg-engine.dir\src\state-machine.cpp.i

CMakeFiles/srpg-engine.dir/src/state-machine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/srpg-engine.dir/src/state-machine.cpp.s"
	C:\app\mingw64\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\workspace\proyecto-de-graduacion\srpg-engine\src\state-machine.cpp -o CMakeFiles\srpg-engine.dir\src\state-machine.cpp.s

CMakeFiles/srpg-engine.dir/src/state-machine.cpp.obj.requires:

.PHONY : CMakeFiles/srpg-engine.dir/src/state-machine.cpp.obj.requires

CMakeFiles/srpg-engine.dir/src/state-machine.cpp.obj.provides: CMakeFiles/srpg-engine.dir/src/state-machine.cpp.obj.requires
	$(MAKE) -f CMakeFiles\srpg-engine.dir\build.make CMakeFiles/srpg-engine.dir/src/state-machine.cpp.obj.provides.build
.PHONY : CMakeFiles/srpg-engine.dir/src/state-machine.cpp.obj.provides

CMakeFiles/srpg-engine.dir/src/state-machine.cpp.obj.provides.build: CMakeFiles/srpg-engine.dir/src/state-machine.cpp.obj


CMakeFiles/srpg-engine.dir/src/state.cpp.obj: CMakeFiles/srpg-engine.dir/flags.make
CMakeFiles/srpg-engine.dir/src/state.cpp.obj: CMakeFiles/srpg-engine.dir/includes_CXX.rsp
CMakeFiles/srpg-engine.dir/src/state.cpp.obj: ../src/state.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\workspace\proyecto-de-graduacion\srpg-engine\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/srpg-engine.dir/src/state.cpp.obj"
	C:\app\mingw64\mingw32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\srpg-engine.dir\src\state.cpp.obj -c D:\workspace\proyecto-de-graduacion\srpg-engine\src\state.cpp

CMakeFiles/srpg-engine.dir/src/state.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/srpg-engine.dir/src/state.cpp.i"
	C:\app\mingw64\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\workspace\proyecto-de-graduacion\srpg-engine\src\state.cpp > CMakeFiles\srpg-engine.dir\src\state.cpp.i

CMakeFiles/srpg-engine.dir/src/state.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/srpg-engine.dir/src/state.cpp.s"
	C:\app\mingw64\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\workspace\proyecto-de-graduacion\srpg-engine\src\state.cpp -o CMakeFiles\srpg-engine.dir\src\state.cpp.s

CMakeFiles/srpg-engine.dir/src/state.cpp.obj.requires:

.PHONY : CMakeFiles/srpg-engine.dir/src/state.cpp.obj.requires

CMakeFiles/srpg-engine.dir/src/state.cpp.obj.provides: CMakeFiles/srpg-engine.dir/src/state.cpp.obj.requires
	$(MAKE) -f CMakeFiles\srpg-engine.dir\build.make CMakeFiles/srpg-engine.dir/src/state.cpp.obj.provides.build
.PHONY : CMakeFiles/srpg-engine.dir/src/state.cpp.obj.provides

CMakeFiles/srpg-engine.dir/src/state.cpp.obj.provides.build: CMakeFiles/srpg-engine.dir/src/state.cpp.obj


CMakeFiles/srpg-engine.dir/src/vocabulary.cpp.obj: CMakeFiles/srpg-engine.dir/flags.make
CMakeFiles/srpg-engine.dir/src/vocabulary.cpp.obj: CMakeFiles/srpg-engine.dir/includes_CXX.rsp
CMakeFiles/srpg-engine.dir/src/vocabulary.cpp.obj: ../src/vocabulary.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\workspace\proyecto-de-graduacion\srpg-engine\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/srpg-engine.dir/src/vocabulary.cpp.obj"
	C:\app\mingw64\mingw32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\srpg-engine.dir\src\vocabulary.cpp.obj -c D:\workspace\proyecto-de-graduacion\srpg-engine\src\vocabulary.cpp

CMakeFiles/srpg-engine.dir/src/vocabulary.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/srpg-engine.dir/src/vocabulary.cpp.i"
	C:\app\mingw64\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\workspace\proyecto-de-graduacion\srpg-engine\src\vocabulary.cpp > CMakeFiles\srpg-engine.dir\src\vocabulary.cpp.i

CMakeFiles/srpg-engine.dir/src/vocabulary.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/srpg-engine.dir/src/vocabulary.cpp.s"
	C:\app\mingw64\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\workspace\proyecto-de-graduacion\srpg-engine\src\vocabulary.cpp -o CMakeFiles\srpg-engine.dir\src\vocabulary.cpp.s

CMakeFiles/srpg-engine.dir/src/vocabulary.cpp.obj.requires:

.PHONY : CMakeFiles/srpg-engine.dir/src/vocabulary.cpp.obj.requires

CMakeFiles/srpg-engine.dir/src/vocabulary.cpp.obj.provides: CMakeFiles/srpg-engine.dir/src/vocabulary.cpp.obj.requires
	$(MAKE) -f CMakeFiles\srpg-engine.dir\build.make CMakeFiles/srpg-engine.dir/src/vocabulary.cpp.obj.provides.build
.PHONY : CMakeFiles/srpg-engine.dir/src/vocabulary.cpp.obj.provides

CMakeFiles/srpg-engine.dir/src/vocabulary.cpp.obj.provides.build: CMakeFiles/srpg-engine.dir/src/vocabulary.cpp.obj


# Object files for target srpg-engine
srpg__engine_OBJECTS = \
"CMakeFiles/srpg-engine.dir/src/collection.cpp.obj" \
"CMakeFiles/srpg-engine.dir/src/configuration-manager.cpp.obj" \
"CMakeFiles/srpg-engine.dir/src/core-vocabulary.cpp.obj" \
"CMakeFiles/srpg-engine.dir/src/game-controller.cpp.obj" \
"CMakeFiles/srpg-engine.dir/src/gamecore.cpp.obj" \
"CMakeFiles/srpg-engine.dir/src/gameobject.cpp.obj" \
"CMakeFiles/srpg-engine.dir/src/luautil.cpp.obj" \
"CMakeFiles/srpg-engine.dir/src/main.cpp.obj" \
"CMakeFiles/srpg-engine.dir/src/observer.cpp.obj" \
"CMakeFiles/srpg-engine.dir/src/scene.cpp.obj" \
"CMakeFiles/srpg-engine.dir/src/state-machine.cpp.obj" \
"CMakeFiles/srpg-engine.dir/src/state.cpp.obj" \
"CMakeFiles/srpg-engine.dir/src/vocabulary.cpp.obj"

# External object files for target srpg-engine
srpg__engine_EXTERNAL_OBJECTS =

srpg-engine.exe: CMakeFiles/srpg-engine.dir/src/collection.cpp.obj
srpg-engine.exe: CMakeFiles/srpg-engine.dir/src/configuration-manager.cpp.obj
srpg-engine.exe: CMakeFiles/srpg-engine.dir/src/core-vocabulary.cpp.obj
srpg-engine.exe: CMakeFiles/srpg-engine.dir/src/game-controller.cpp.obj
srpg-engine.exe: CMakeFiles/srpg-engine.dir/src/gamecore.cpp.obj
srpg-engine.exe: CMakeFiles/srpg-engine.dir/src/gameobject.cpp.obj
srpg-engine.exe: CMakeFiles/srpg-engine.dir/src/luautil.cpp.obj
srpg-engine.exe: CMakeFiles/srpg-engine.dir/src/main.cpp.obj
srpg-engine.exe: CMakeFiles/srpg-engine.dir/src/observer.cpp.obj
srpg-engine.exe: CMakeFiles/srpg-engine.dir/src/scene.cpp.obj
srpg-engine.exe: CMakeFiles/srpg-engine.dir/src/state-machine.cpp.obj
srpg-engine.exe: CMakeFiles/srpg-engine.dir/src/state.cpp.obj
srpg-engine.exe: CMakeFiles/srpg-engine.dir/src/vocabulary.cpp.obj
srpg-engine.exe: CMakeFiles/srpg-engine.dir/build.make
srpg-engine.exe: CMakeFiles/srpg-engine.dir/linklibs.rsp
srpg-engine.exe: CMakeFiles/srpg-engine.dir/objects1.rsp
srpg-engine.exe: CMakeFiles/srpg-engine.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\workspace\proyecto-de-graduacion\srpg-engine\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Linking CXX executable srpg-engine.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\srpg-engine.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/srpg-engine.dir/build: srpg-engine.exe

.PHONY : CMakeFiles/srpg-engine.dir/build

CMakeFiles/srpg-engine.dir/requires: CMakeFiles/srpg-engine.dir/src/collection.cpp.obj.requires
CMakeFiles/srpg-engine.dir/requires: CMakeFiles/srpg-engine.dir/src/configuration-manager.cpp.obj.requires
CMakeFiles/srpg-engine.dir/requires: CMakeFiles/srpg-engine.dir/src/core-vocabulary.cpp.obj.requires
CMakeFiles/srpg-engine.dir/requires: CMakeFiles/srpg-engine.dir/src/game-controller.cpp.obj.requires
CMakeFiles/srpg-engine.dir/requires: CMakeFiles/srpg-engine.dir/src/gamecore.cpp.obj.requires
CMakeFiles/srpg-engine.dir/requires: CMakeFiles/srpg-engine.dir/src/gameobject.cpp.obj.requires
CMakeFiles/srpg-engine.dir/requires: CMakeFiles/srpg-engine.dir/src/luautil.cpp.obj.requires
CMakeFiles/srpg-engine.dir/requires: CMakeFiles/srpg-engine.dir/src/main.cpp.obj.requires
CMakeFiles/srpg-engine.dir/requires: CMakeFiles/srpg-engine.dir/src/observer.cpp.obj.requires
CMakeFiles/srpg-engine.dir/requires: CMakeFiles/srpg-engine.dir/src/scene.cpp.obj.requires
CMakeFiles/srpg-engine.dir/requires: CMakeFiles/srpg-engine.dir/src/state-machine.cpp.obj.requires
CMakeFiles/srpg-engine.dir/requires: CMakeFiles/srpg-engine.dir/src/state.cpp.obj.requires
CMakeFiles/srpg-engine.dir/requires: CMakeFiles/srpg-engine.dir/src/vocabulary.cpp.obj.requires

.PHONY : CMakeFiles/srpg-engine.dir/requires

CMakeFiles/srpg-engine.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\srpg-engine.dir\cmake_clean.cmake
.PHONY : CMakeFiles/srpg-engine.dir/clean

CMakeFiles/srpg-engine.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\workspace\proyecto-de-graduacion\srpg-engine D:\workspace\proyecto-de-graduacion\srpg-engine D:\workspace\proyecto-de-graduacion\srpg-engine\cmake-build-debug D:\workspace\proyecto-de-graduacion\srpg-engine\cmake-build-debug D:\workspace\proyecto-de-graduacion\srpg-engine\cmake-build-debug\CMakeFiles\srpg-engine.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/srpg-engine.dir/depend

