#config
project(srpg-engine)
cmake_minimum_required(VERSION 3.1)
set (CMAKE_CXX_STANDARD 14)
#sources
aux_source_directory(. SRC_LIST)
aux_source_directory(./src GENERAL_LIST)

#includes
include_directories(
    ${CMAKE_INSTALL_PREFIX}/lua53/include
    #${CMAKE_INSTALL_PREFIX}/sol2
    ./include)
#linking dir
link_directories(${CMAKE_INSTALL_PREFIX}/lua53/bin)
#sources
FILE(GLOB_RECURSE HEADERS
    (*.hpp)
    | (*.h)
    )

#targets
add_executable(${PROJECT_NAME} ${SRC_LIST}  ${GENERAL_LIST} ${HEADERS})
add_library(${PROJECT_NAME}-lib SHARED ${SRC_LIST} ${GENERAL_LIST} ${HEADERS} )

TARGET_LINK_LIBRARIES(${PROJECT_NAME} lua53-lib)
TARGET_LINK_LIBRARIES(${PROJECT_NAME}-lib lua53-lib)

#install
install(TARGETS ${PROJECT_NAME}-lib EXPORT ${PROJECT_NAME}Config
            RUNTIME DESTINATION ${PROJECT_NAME}/bin
            LIBRARY DESTINATION ${PROJECT_NAME}/lib
            ARCHIVE DESTINATION ${PROJECT_NAME}/lib/static)
install (FILES ${HEADERS} DESTINATION ${PROJECT_NAME}/include)
install(EXPORT ${PROJECT_NAME}Config DESTINATION ${PROJECT_NAME}/cmake)


