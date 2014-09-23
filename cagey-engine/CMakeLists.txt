
#Add all public headers
file(GLOB_RECURSE Cagey_HEADERS "include/*.hh")


add_subdirectory(source)

#Make Visible in IDE's
add_custom_target(CageyFoo SOURCES ${Cagey_HEADERS})
