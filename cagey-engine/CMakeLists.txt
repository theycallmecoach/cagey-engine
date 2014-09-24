
#Add all public headers
file(GLOB_RECURSE Cagey_HEADERS "include/*.hh")

add_subdirectory(source)

add_library(cagey, OBJECT ${CageyInput_SRCS})

#Make Visible in IDE's
add_custom_target(CageyFoo SOURCES ${Cagey_HEADERS})
