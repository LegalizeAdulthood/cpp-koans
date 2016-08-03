cmake_minimum_required(VERSION 2.8.11)
project(koans CXX)

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost 1.60 REQUIRED COMPONENTS unit_test_framework)

if("${CMAKE_CXX_COMPILER_ID}" MATCHES "(GNU|Clang)")
    set(CMAKE_CXX_FLAGS "-std=c++11")
endif()

add_executable(type_traits type_traits.cpp type_traits.h)
target_include_directories(type_traits PRIVATE ${Boost_INCLUDE_DIRS})
target_link_libraries(type_traits ${Boost_LIBRARIES})
add_custom_command(TARGET type_traits POST_BUILD COMMAND type_traits)

add_executable(iterator iterator.cpp iterator.h)
target_include_directories(iterator PRIVATE ${Boost_INCLUDE_DIRS})
target_link_libraries(iterator ${Boost_LIBRARIES})
add_custom_command(TARGET iterator POST_BUILD COMMAND iterator)
