# DO NOT MODIFY THIS FILE, IT WILL BE OVERRIDE!!!

# set this will supress some warnings
set(BUILDING_SDK "yes" CACHE INTERNAL "")

# basic config
if (NOT PROJ)
    set(PROJ "hello_world")
    get_filename_component(PROJ ${CMAKE_CURRENT_BINARY_DIR} DIRECTORY)
    get_filename_component(PROJ ${PROJ} NAME)
    string(REPLACE " " "_" PROJ ${PROJ})
    message(STATUS "PROJ not set, use ${PROJ} as PROJ. Also, you can set it manually.")
endif ()

cmake_minimum_required(VERSION 3.0)
include(./cmake/common.cmake)

project(${PROJ} C CXX ASM)

# config self use headers
include(./cmake/macros.internal.cmake)

# 在编译之前注释下面两行，comment these two lines before build
header_directories(../_tool/kendryte-toolchain/riscv64-unknown-elf/include)
header_directories(../_tool/kendryte-toolchain/lib/gcc/riscv64-unknown-elf/8.2.0/include)

# 定义库所在的位置
header_directories(${SDK_ROOT}/lib)
header_directories(Projects/${PROJ})


# build library first
add_subdirectory(lib)

# compile project
add_source_files(Projects/${PROJ}/*.c Projects/${PROJ}/*.s Projects/${PROJ}/*.S Projects/${PROJ}/*.cpp)

include(./cmake/executable.cmake)

