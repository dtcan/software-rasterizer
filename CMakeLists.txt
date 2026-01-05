############################################
#           Software Rasterizer            #
#------------------------------------------#
# @author  Nikolaus Rauch                  #
# @date    14.12.2021                      #
#------------------------------------------#
############################################
cmake_minimum_required( VERSION 3.9 )
project( software-rasterizer )

message("\n * CPU Software Rasterizer ")

message(STATUS "${PROJECT_NAME} build environment --")
message(STATUS "Build system:     ${CMAKE_SYSTEM_NAME}-${CMAKE_HOST_SYSTEM_PROCESSOR}")


#########################################
#              CMake-Stuff              #
#########################################
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin)


#########################################
#        Global Compiler Options        #
#########################################
set(GCC_COMPILE_OPTIONS "-W;-Wall;-Wno-unused-variable;-Wno-unused-parameter")
set(GCC_COMPILE_DEBUG_OPTIONS "${GCC_COMPILE_OPTIONS};-ggdb;-O0")
set(GCC_COMPILE_RELEASE_OPTIONS "${GCC_COMPILE_OPTIONS};-O3;-march=native;-ffast-math;")
set(GCC_COMPILE_SUPPRESS_WARING "-w")

set(MSVC_COMPILE_OPTIONS "/W3;/wd4244;/wd4305")
set(MSVC_COMPILE_DEBUG_OPTIONS "${MSVC_COMPILE_OPTIONS};/Zi")
set(MSVC_COMPILE_RELEASE_OPTIONS "${MSVC_COMPILE_OPTIONS};/O2;/fp:fast;/arch")
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_compile_options("$<$<AND:$<CXX_COMPILER_ID:GNU>,$<CONFIG:DEBUG>>:${GCC_COMPILE_DEBUG_OPTIONS}>")
add_compile_options("$<$<AND:$<CXX_COMPILER_ID:GNU>,$<CONFIG:RELEASE>>:${GCC_COMPILE_RELEASE_OPTIONS}>")

add_compile_options("$<$<AND:$<CXX_COMPILER_ID:MSVC>,$<CONFIG:DEBUG>>:${MSVC_COMPILE_DEBUG_OPTIONS}>")
add_compile_options("$<$<AND:$<CXX_COMPILER_ID:MSVC>,$<CONFIG:RELEASE>>:${MSVC_COMPILE_RELEASE_OPTIONS}>")


#########################################
#        Build Software Rasterizer      #
#########################################
add_subdirectory(rasterizer)
