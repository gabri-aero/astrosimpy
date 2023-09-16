set(HPP_HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/Gravity.hpp)
target_sources(${CPP_TARGET} PRIVATE ${HPP_HEADERS}) #${CPP_SOURCES} 

message(STATUS "Accelerations included")

add_subdirectory(tests)