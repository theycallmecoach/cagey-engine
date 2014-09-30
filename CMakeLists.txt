cmake_minimum_required(VERSION 2.8)
project("cagey-engine")

LIST(APPEND CMAKE_MODULE_PATH "${cagey-engine_SOURCE_DIR}/cmake")

include(CheckCXXCompilerFlag)
include(CMakeDependentOption)
#We require C++-14
CHECK_CXX_COMPILER_FLAG("-std=c++1y" COMPILER_SUPPORTS_CXX14)
if(COMPILER_SUPPORTS_CXX14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")
else()
  message(STATUS "The compiler ${CMAKE_CXX_COMPILER} does not support C++14. Please use a different C++ compiler.")
endif()

find_package(Boost 1.53.0 REQUIRED)


CMAKE_DEPENDENT_OPTION(USE_SDL "Use SDL" ON "USE_X11" FALSE)
CMAKE_DEPENDENT_OPTION(USE_X11 "Use X11" ON "USE_SDL" FALSE)


if (USE_X11)
  find_package(X11 REQUIRED)
  MESSAGE(STATUS "Using X11")
  add_definitions(-DUSE_X11)
else()
  find_package(SDL2 REQUIRED)
  MESSAGE(STATUS "Using SDL")
  add_definitions(-DUSE_SDL)
endif()



enable_testing()

include_directories(cagey-engine/include)
include_directories(cagey-engine/source)


add_subdirectory(cagey-engine)
add_subdirectory(test)
