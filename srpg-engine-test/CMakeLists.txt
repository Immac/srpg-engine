project(srpg-engine-test)
cmake_minimum_required(VERSION 3.1)
set (CMAKE_CXX_STANDARD 14)
#sources
aux_source_directory(. SRC_LIST)
#include
include_directories(${CMAKE_INSTALL_PREFIX}/srpg-engine/include)
include_directories(${CMAKE_INSTALL_PREFIX}/srpg-engine/include)
include_directories(${CMAKE_INSTALL_PREFIX}/srpg-s2dge-system/include)
include_directories(${CMAKE_INSTALL_PREFIX}/simple-position-system/include)
include_directories(${CMAKE_INSTALL_PREFIX}/lua53/include)
include_directories(${CMAKE_INSTALL_PREFIX}/s2dge-tilepos-adapter/include)
include_directories(${CMAKE_INSTALL_PREFIX}/simple-tile-movement-system/include)
include_directories(${CMAKE_INSTALL_PREFIX}/simple-sound-system/include)
message(${CMAKE_INSTALL_PREFIX}/lua53/include)
#linking-directory
link_directories(${CMAKE_INSTALL_PREFIX}/srpg-engine/bin/)
link_directories(${CMAKE_INSTALL_PREFIX}/srpg-s2dge-system/bin/)
link_directories(${CMAKE_INSTALL_PREFIX}/lua53/bin/)
link_directories(${CMAKE_INSTALL_PREFIX}/s2dge-tilepos-adapter/bin/)
link_directories(${CMAKE_INSTALL_PREFIX}/simple-tile-movement-system/bin/)
link_directories(${CMAKE_INSTALL_PREFIX}/simple-position-system/bin/)
link_directories(${CMAKE_INSTALL_PREFIX}/simple-sound-system/bin/)

#targets
add_executable(${PROJECT_NAME} ${SRC_LIST})
# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_INSTALL_PREFIX}/sfml/cmake/Modules" ${CMAKE_MODULE_PATH})
message("${CMAKE_INSTALL_PREFIX}/sfml/cmake/Modules")
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
set (SFML_ROOT ${CMAKE_INSTALL_PREFIX}/sfml)
find_package(SFML 2 REQUIRED system window graphics network audio)
if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})
endif()
#linking-phase
TARGET_LINK_LIBRARIES(${PROJECT_NAME} srpg-engine-lib)
TARGET_LINK_LIBRARIES(${PROJECT_NAME} simple-position-system-lib)
TARGET_LINK_LIBRARIES(${PROJECT_NAME} srpg-s2dge-system-lib)
TARGET_LINK_LIBRARIES(${PROJECT_NAME} lua53-lib)
TARGET_LINK_LIBRARIES(${PROJECT_NAME} s2dge-tilepos-adapter-lib)
TARGET_LINK_LIBRARIES(${PROJECT_NAME} simple-tile-movement-system-lib)
TARGET_LINK_LIBRARIES(${PROJECT_NAME} simple-sound-system-lib)
