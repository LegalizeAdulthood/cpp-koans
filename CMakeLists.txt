cmake_minimum_required(VERSION 3.8.0)
project(koans CXX)

add_library(catch2 STATIC common/main.cpp catch2/catch.hpp)
target_include_directories(catch2 PUBLIC ${PROJECT_SOURCE_DIR}/catch2)

if("${CMAKE_CXX_COMPILER_ID}" MATCHES "(GNU|Clang)")
    set(CMAKE_CXX_FLAGS "-std=c++11")
endif()

function(add_koan name)
    add_executable(${name} ${name}.cpp ${name}.h)
    target_link_libraries(${name} PRIVATE catch2)
    add_custom_command(TARGET ${name} POST_BUILD COMMAND ${name} --reporter compact)
endfunction()

add_subdirectory(type_traits)
add_subdirectory(iterator)
add_subdirectory(c_strings)
add_subdirectory(strings)
add_subdirectory(string_view)
