#config
project(srpg-engine)
cmake_minimum_required(VERSION 3.1)
set (CMAKE_CXX_STANDARD 14)
#sources
aux_source_directory(. SRC_LIST)
aux_source_directory(./lua/src LUA_LIST)
aux_source_directory(./src GENERAL_LIST)
aux_source_directory(${CMAKE_INSTALL_PREFIX}/selene SELENE_LIST)
#includes
include_directories(./lua/include ./include)
include_directories(${CMAKE_INSTALL_PREFIX}/selene/include)
#linking dir

FILE(GLOB_RECURSE HEADERS (*.hpp) | (*.h))
#targets
add_executable(${PROJECT_NAME} ${SRC_LIST} ${LUA_LIST} ${GENERAL_LIST} ${HEADERS} ${SELENE_LIST})
add_library(${PROJECT_NAME}-lib SHARED ${SRC_LIST} ${LUA_LIST} ${GENERAL_LIST} ${HEADERS} )

#install
install(TARGETS ${PROJECT_NAME}-lib EXPORT ${PROJECT_NAME}Config
            RUNTIME DESTINATION ${PROJECT_NAME}/bin
            LIBRARY DESTINATION ${PROJECT_NAME}/lib
            ARCHIVE DESTINATION ${PROJECT_NAME}/lib/static)
install (FILES ${HEADERS} DESTINATION ${PROJECT_NAME}/include)
install(EXPORT ${PROJECT_NAME}Config DESTINATION ${PROJECT_NAME}/cmake)


