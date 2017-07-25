# Install script for directory: D:/workspace/proyecto-de-graduacion/srpg-engine

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/srpg-engine")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/srpg-engine/lib/static" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/workspace/proyecto-de-graduacion/srpg-engine/cmake-build-debug/libsrpg-engine-lib.dll.a")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/srpg-engine/bin" TYPE SHARED_LIBRARY FILES "D:/workspace/proyecto-de-graduacion/srpg-engine/cmake-build-debug/libsrpg-engine-lib.dll")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/srpg-engine/bin/libsrpg-engine-lib.dll" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/srpg-engine/bin/libsrpg-engine-lib.dll")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "C:/app/mingw64/mingw32/bin/strip.exe" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/srpg-engine/bin/libsrpg-engine-lib.dll")
    endif()
  endif()
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/srpg-engine/include" TYPE FILE FILES
    "D:/workspace/proyecto-de-graduacion/srpg-engine/include/collection.hpp"
    "D:/workspace/proyecto-de-graduacion/srpg-engine/include/common.hpp"
    "D:/workspace/proyecto-de-graduacion/srpg-engine/include/configuration-manager.hpp"
    "D:/workspace/proyecto-de-graduacion/srpg-engine/include/core-vocabulary.hpp"
    "D:/workspace/proyecto-de-graduacion/srpg-engine/include/filter.hpp"
    "D:/workspace/proyecto-de-graduacion/srpg-engine/include/game-controller.hpp"
    "D:/workspace/proyecto-de-graduacion/srpg-engine/include/gamecommon.hpp"
    "D:/workspace/proyecto-de-graduacion/srpg-engine/include/gamecore.hpp"
    "D:/workspace/proyecto-de-graduacion/srpg-engine/include/gameobject.hpp"
    "D:/workspace/proyecto-de-graduacion/srpg-engine/include/gameobjectfactory.hpp"
    "D:/workspace/proyecto-de-graduacion/srpg-engine/include/gameobjectloader.hpp"
    "D:/workspace/proyecto-de-graduacion/srpg-engine/include/gamesystem.hpp"
    "D:/workspace/proyecto-de-graduacion/srpg-engine/include/luautil.hpp"
    "D:/workspace/proyecto-de-graduacion/srpg-engine/include/observer.hpp"
    "D:/workspace/proyecto-de-graduacion/srpg-engine/include/property.hpp"
    "D:/workspace/proyecto-de-graduacion/srpg-engine/include/repository.hpp"
    "D:/workspace/proyecto-de-graduacion/srpg-engine/include/scene.hpp"
    "D:/workspace/proyecto-de-graduacion/srpg-engine/include/sol.hpp"
    "D:/workspace/proyecto-de-graduacion/srpg-engine/include/state-machine.hpp"
    "D:/workspace/proyecto-de-graduacion/srpg-engine/include/state.hpp"
    "D:/workspace/proyecto-de-graduacion/srpg-engine/include/systemgeneral.hpp"
    "D:/workspace/proyecto-de-graduacion/srpg-engine/include/vocabulary.hpp"
    )
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/srpg-engine/cmake/srpg-engineConfig.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/srpg-engine/cmake/srpg-engineConfig.cmake"
         "D:/workspace/proyecto-de-graduacion/srpg-engine/cmake-build-debug/CMakeFiles/Export/srpg-engine/cmake/srpg-engineConfig.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/srpg-engine/cmake/srpg-engineConfig-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/srpg-engine/cmake/srpg-engineConfig.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/srpg-engine/cmake" TYPE FILE FILES "D:/workspace/proyecto-de-graduacion/srpg-engine/cmake-build-debug/CMakeFiles/Export/srpg-engine/cmake/srpg-engineConfig.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/srpg-engine/cmake" TYPE FILE FILES "D:/workspace/proyecto-de-graduacion/srpg-engine/cmake-build-debug/CMakeFiles/Export/srpg-engine/cmake/srpg-engineConfig-debug.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "D:/workspace/proyecto-de-graduacion/srpg-engine/cmake-build-debug/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
