#CMakeLists.txt to build project using cmake
#run $cmake CMakeLists.txt

cmake_minimum_required(VERSION 2.6)

project( ProjectiveRendering )

# Configure Project
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR} )

set( SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src" )
set( DATA_DIR "${CMAKE_CURRENT_SOURCE_DIR}/data" )
set( CMAKE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/CMake" )

configure_file( ${CMAKE_DIR}/Project_Config.h.in
  ${CMAKE_CURRENT_BINARY_DIR}/Project_Config.h @ONLY )

# add_executable sources
file( GLOB_RECURSE SRC ${SRC_DIR}/*.[ch]* )

include_directories( ${SRC_DIR} ${CMAKE_CURRENT_BINARY_DIR} )

# Specify g++ option
add_definitions( -O2 -Wall -Wextra -std=c++11 -Wno-comment -DCORRECTION)

add_executable( ${PROJECT_NAME} ${SRC} )
target_link_libraries( ${PROJECT_NAME} -lm -ldl -pthread )


