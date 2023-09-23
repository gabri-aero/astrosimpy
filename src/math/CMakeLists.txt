set(CPP_SOURCES Vector.cpp)
set(HPP_HEADERS Vector.hpp)
target_sources(${CPP_TARGET} PRIVATE  ${CPP_SOURCES} ${HPP_HEADERS})

message(STATUS "Utils included")

add_subdirectory(tests)