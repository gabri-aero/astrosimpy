cmake_minimum_required(VERSION 3.22.1)

project(astrosimpy)

include_directories(external)
find_package(Python REQUIRED COMPONENTS Interpreter Development.Module)
add_subdirectory(external/pybind11)
add_subdirectory(astrosimcpp)

python_add_library(_core MODULE pybindings/py_astrosimpy.cpp WITH_SOABI)
target_link_libraries(_core PRIVATE astrosim) 
target_link_libraries(_core PRIVATE pybind11::headers)
target_compile_definitions(_core PRIVATE VERSION_INFO=${PROJECT_VERSION})

install(TARGETS _core DESTINATION astrosimpy)

# Python binding stuff
message(STATUS "Creating python package")
