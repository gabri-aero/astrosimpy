cmake_minimum_required(VERSION 3.22.1)

project(astrosim)

set(CPP_TARGET AstroSim)
add_library(${CPP_TARGET} STATIC)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-std=c++17)
add_compile_options(-Wno-terminate)
add_compile_options(-Wno-return-type)

set(CMAKE_BUILD_TYPE Debug)

# Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include_directories(external)

add_subdirectory(src)

# Python binding stuff
message(STATUS "Creating python package")

add_subdirectory(external/pybind11)
add_subdirectory(pybindings)
