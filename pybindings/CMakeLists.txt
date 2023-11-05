set(PYTHON_PROJECT_NAME ${PROJECT_NAME}py)

include_directories(${CMAKE_SOURCE_DIR}/src)

pybind11_add_module(${PYTHON_PROJECT_NAME} 
    py_astrosimpy.cpp 
    py_math.hpp 
    py_bodies.hpp 
    py_numerical.hpp 
    py_engine.hpp
    py_orbit.hpp)

target_link_libraries(${PYTHON_PROJECT_NAME} PRIVATE ${CPP_TARGET})

target_compile_definitions(${PYTHON_PROJECT_NAME}
                           PRIVATE VERSION_INFO=${EXAMPLE_VERSION_INFO})