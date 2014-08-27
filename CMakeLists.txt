cmake_minimum_required(VERSION 2.8)

project("cagey-engine")

enable_testing()

include_directories(cagey-engine/include)
add_subdirectory(cagey-engine/source)

add_subdirectory(test)
