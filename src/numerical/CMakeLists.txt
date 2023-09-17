set(CPP_SOURCES Euler.cpp RK4.cpp)
set(HPP_HEADERS Euler.hpp RK4.hpp BaseIntegrator.hpp)
target_sources(${CPP_TARGET} PRIVATE  ${CPP_SOURCES} ${HPP_HEADERS})

message(STATUS "Engine included")

add_subdirectory(tests)