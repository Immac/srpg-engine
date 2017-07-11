project(lua53)
cmake_minimum_required(VERSION 3.1)
set (CMAKE_CXX_STANDARD 14)

aux_source_directory(. SRC_LIST)
aux_source_directory(./src SRC_LIST)
FILE(GLOB_RECURSE HEADERS (*.hpp) | (*.h))

add_library(${PROJECT_NAME}-lib SHARED ${SRC_LIST} ${GENERAL_LIST} ${HEADERS})

#install
install(TARGETS ${PROJECT_NAME}-lib EXPORT ${PROJECT_NAME}Config
            RUNTIME DESTINATION ${PROJECT_NAME}/bin
            LIBRARY DESTINATION ${PROJECT_NAME}/lib
            ARCHIVE DESTINATION ${PROJECT_NAME}/lib/static)

install (FILES ${HEADERS} DESTINATION ${PROJECT_NAME}/include)
install(EXPORT ${PROJECT_NAME}Config DESTINATION ${PROJECT_NAME}/cmake)
