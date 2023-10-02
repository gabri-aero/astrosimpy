set(CPP_SOURCES 
    ${CMAKE_CURRENT_SOURCE_DIR}/Orbit.cpp)
set(HPP_HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/Orbit.hpp)
target_sources(${CPP_TARGET} PRIVATE ${CPP_SOURCES} ${HPP_HEADERS})

message(STATUS "Orbit included")

add_subdirectory(tests)