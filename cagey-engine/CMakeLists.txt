
#Add all public headers
file(GLOB_RECURSE Cagey_HEADERS "include/*.hh")


file(GLOB CageyInputPrivateHeaders "source/cagey/input/*.hh")
file(GLOB CageyInputSources "source/cagey/input/*.cc")

if (USE_SDL)
    file(GLOB CageyInputSdlPrivateHeaders "source/cagey/input/sdl/*.hh")
    file(GLOB CageyInputSdlSources "source/cagey/input/sdl/*.cc")
    set(CageyInputImplSources ${CageyInputSdlPrivateHeaders} ${CageyInputSdlSources})
elseif (USE_X11)
    file(GLOB CageyInputX11PrivateHeaders "source/cagey/input/x11/*.hh")
    file(GLOB CageyInputX11Sources "source/cagey/input/x11/*.cc")
    set(CageyInputImplSources ${CageyInputX11PrivateHeaders} ${CageyInputX11Sources})
endif()

file(GLOB CageyWindowPrivateHeaders "source/cagey/window/*.hh")
file(GLOB CageyWindowSources "source/cagey/window/*.cc")


add_library(cageyEngine
            ${Cagey_HEADERS}
            ${CageyInputPrivateHeaders}
            ${CageyInputSources}
            ${CageyInputImplSources}
            ${CageyWindowPrivateHeaders}
            ${CageyWindowSources})
