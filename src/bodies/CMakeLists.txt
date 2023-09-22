set(CPP_SOURCES 
    ${CMAKE_CURRENT_SOURCE_DIR}/Body.cpp)
set(HPP_HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/Body.hpp)
target_sources(${CPP_TARGET} PRIVATE ${CPP_SOURCES} ${HPP_HEADERS})

message(STATUS "Bodies included")

add_subdirectory(tests)