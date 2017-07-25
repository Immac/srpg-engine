project(menu-system)
cmake_minimum_required(VERSION 3.1)
set (CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-long-long -pedantic")
#sources
aux_source_directory(. SRC_LIST)
aux_source_directory(./src GENERAL_LIST)
#headers
FILE(GLOB_RECURSE HEADERS (*.hpp) | (*.h))
#include
include_directories(${CMAKE_INSTALL_PREFIX}/srpg-engine/include)
include_directories(${CMAKE_INSTALL_PREFIX}/sqlite/include)
include_directories(include)
#linking-directory
link_directories(${CMAKE_INSTALL_PREFIX}/sqlite/bin)
link_directories(${CMAKE_INSTALL_PREFIX}/srpg-engine/bin/)
#targets
add_executable(${PROJECT_NAME} ${SRC_LIST} ${GENERAL_LIST} ${HEADERS})
add_library(${PROJECT_NAME}-lib SHARED ${SRC_LIST} ${GENERAL_LIST} ${HEADERS})

#linking-phase
TARGET_LINK_LIBRARIES(${PROJECT_NAME} srpg-engine-lib)
TARGET_LINK_LIBRARIES(${PROJECT_NAME}-lib srpg-engine-lib)
target_link_libraries(${PROJECT_NAME} sqlite3)
target_link_libraries(${PROJECT_NAME}-lib sqlite3)
#install
install(TARGETS ${PROJECT_NAME}-lib EXPORT ${PROJECT_NAME}Config
            RUNTIME DESTINATION ${PROJECT_NAME}/bin
            LIBRARY DESTINATION ${PROJECT_NAME}/lib
            ARCHIVE DESTINATION ${PROJECT_NAME}/lib/static)
FILE(GLOB_RECURSE LibFiles *.hpp)
install (FILES ${LibFiles} DESTINATION ${PROJECT_NAME}/include)
install(EXPORT ${PROJECT_NAME}Config DESTINATION ${PROJECT_NAME}/cmake)

