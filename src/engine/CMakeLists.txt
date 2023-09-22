set(CPP_SOURCES AstroEngine.cpp)
set(HPP_HEADERS AstroEngine.hpp)
target_sources(${CPP_TARGET} PRIVATE  ${CPP_SOURCES} ${HPP_HEADERS})

message(STATUS "Engine included")

add_subdirectory(tests)