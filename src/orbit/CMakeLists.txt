set(CPP_SOURCES 
    Orbit.cpp 
    StateVector.cpp)

set(HPP_HEADERS 
    Orbit.hpp 
    StateVector.hpp)

target_sources(${CPP_TARGET} PRIVATE  ${CPP_SOURCES} ${HPP_HEADERS})

message(STATUS "Orbit included")

add_subdirectory(tests)