cmake_minimum_required(VERSION 2.8)
project("cagey-engine")

include(CheckCXXCompilerFlag)

#We require C++-14
CHECK_CXX_COMPILER_FLAG("-std=c++1y" COMPILER_SUPPORTS_CXX14)
if(COMPILER_SUPPORTS_CXX14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")
else()
  message(STATUS "The compiler ${CMAKE_CXX_COMPILER} does not support C++14. Please use a different C++ compiler.")
endif()


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")

enable_testing()

include_directories(cagey-engine/include)
add_subdirectory(cagey-engine/source)

add_subdirectory(test)
