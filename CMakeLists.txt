cmake_minimum_required(VERSION 2.8.11)
project(koans CXX)

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost 1.60 REQUIRED COMPONENTS unit_test_framework)

if("${CMAKE_CXX_COMPILER_ID}" MATCHES "(GNU|Clang)")
    set(CMAKE_CXX_FLAGS "-std=c++11")
endif()

function(add_koan name)
    add_executable(${name} ${name}.cpp ${name}.h)
    target_include_directories(${name} PRIVATE . ${Boost_INCLUDE_DIRS})
    target_link_libraries(${name} PRIVATE ${Boost_LIBRARIES})
    add_custom_command(TARGET ${name} POST_BUILD COMMAND ${name})
endfunction()

add_subdirectory(type_traits)
add_subdirectory(iterator)
add_subdirectory(c_strings)
add_subdirectory(strings)
add_subdirectory(string_view)
