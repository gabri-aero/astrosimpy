set(CPP_SOURCES Math.cpp)
set(HPP_HEADERS Math.hpp)
target_sources(${CPP_TARGET} PRIVATE  ${HPP_HEADERS}) #${CPP_SOURCES}

message(STATUS "Utils included")

add_subdirectory(tests)