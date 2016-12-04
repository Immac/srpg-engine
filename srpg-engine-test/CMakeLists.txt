project(srpg-engine-test)
cmake_minimum_required(VERSION 3.1)
set (CMAKE_CXX_STANDARD 14)
#sources
aux_source_directory(. SRC_LIST)
#include
include_directories(${CMAKE_INSTALL_PREFIX}/srpg-engine/include)
#linking-directory
link_directories(${CMAKE_INSTALL_PREFIX}/srpg-engine/bin/)
#targets
add_executable(${PROJECT_NAME} ${SRC_LIST})
#linking-phase
TARGET_LINK_LIBRARIES(${PROJECT_NAME} srpg-engine-lib)
