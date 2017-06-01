# Install script for directory: D:/workspace/proyecto-de-graduacion/s2dge-tilepos-adapter

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/s2dge-tilepos-adapter")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/s2dge-tilepos-adapter/lib/static" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/workspace/proyecto-de-graduacion/build-s2dge-tilepos-adapter-Desktop-Default/libs2dge-tilepos-adapter-lib.dll.a")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/s2dge-tilepos-adapter/bin" TYPE SHARED_LIBRARY FILES "D:/workspace/proyecto-de-graduacion/build-s2dge-tilepos-adapter-Desktop-Default/libs2dge-tilepos-adapter-lib.dll")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/s2dge-tilepos-adapter/bin/libs2dge-tilepos-adapter-lib.dll" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/s2dge-tilepos-adapter/bin/libs2dge-tilepos-adapter-lib.dll")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "C:/app/mingw64/mingw32/bin/strip.exe" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/s2dge-tilepos-adapter/bin/libs2dge-tilepos-adapter-lib.dll")
    endif()
  endif()
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/s2dge-tilepos-adapter/cmake/s2dge-tilepos-adapterConfig.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/s2dge-tilepos-adapter/cmake/s2dge-tilepos-adapterConfig.cmake"
         "D:/workspace/proyecto-de-graduacion/build-s2dge-tilepos-adapter-Desktop-Default/CMakeFiles/Export/s2dge-tilepos-adapter/cmake/s2dge-tilepos-adapterConfig.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/s2dge-tilepos-adapter/cmake/s2dge-tilepos-adapterConfig-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/s2dge-tilepos-adapter/cmake/s2dge-tilepos-adapterConfig.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/s2dge-tilepos-adapter/cmake" TYPE FILE FILES "D:/workspace/proyecto-de-graduacion/build-s2dge-tilepos-adapter-Desktop-Default/CMakeFiles/Export/s2dge-tilepos-adapter/cmake/s2dge-tilepos-adapterConfig.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^()$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/s2dge-tilepos-adapter/cmake" TYPE FILE FILES "D:/workspace/proyecto-de-graduacion/build-s2dge-tilepos-adapter-Desktop-Default/CMakeFiles/Export/s2dge-tilepos-adapter/cmake/s2dge-tilepos-adapterConfig-noconfig.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "D:/workspace/proyecto-de-graduacion/build-s2dge-tilepos-adapter-Desktop-Default/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
