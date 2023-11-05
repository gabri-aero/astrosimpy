set(CPP_SOURCES
    Vector.cpp
    Matrix.cpp)

set(HPP_HEADERS
    Vector.hpp 
    Matrix.hpp 
    Legendre.hpp 
    Utils.hpp 
    SphericalHarmonics.hpp
    Rotation.hpp)
    
target_sources(${CPP_TARGET} PRIVATE  ${CPP_SOURCES} ${HPP_HEADERS})

message(STATUS "Utils included")

add_subdirectory(tests)