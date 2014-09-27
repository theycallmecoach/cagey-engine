
#Add all public headers
file(GLOB_RECURSE Cagey_HEADERS "include/*.hh")


file(GLOB CageyInputPrivateHeaders "source/cagey/input/*.hh")
file(GLOB CageyInputSources "source/cagey/input/*.cc")


file(GLOB CageyInputSdlPrivateHeaders "source/cagey/input/sdl/*.hh")
file(GLOB CageyInputSdlSources "source/cagey/input/sdl/*.cc")

file(GLOB CageyInputX11PrivateHeaders "source/cagey/input/x11/*.hh")
file(GLOB CageyInputX11Sources "source/cagey/input/x11/*.cc")

file(GLOB CageyWindowPrivateHeaders "source/cagey/window/*.hh")
file(GLOB CageyWindowSources "source/cagey/window/*.cc")


add_library(cageyEngine
            ${Cagey_HEADERS}
            ${CageyInputPrivateHeaders}
            ${CageyInputSources}
            ${CageyInputSdlSources}
            ${CageyInputSdlPrivateHeaders}
            ${CageyWindowPrivateHeaders}
            ${CageyWindowSources})
#set_target_properties(cageyEngine PROPERTIES LINKER_LANGUAGE C++)


#Make Visible in IDE's
#${Cagey_HEADERS}add_custom_target(CageyFoo SOURCES ${Cagey_HEADERS})
