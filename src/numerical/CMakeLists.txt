set(CPP_SOURCES Euler.cpp)
set(HPP_HEADERS Euler.hpp BaseIntegrator.hpp)
target_sources(${CPP_TARGET} PRIVATE  ${CPP_SOURCES} ${HPP_HEADERS})

message(STATUS "Engine included")

add_subdirectory(tests)