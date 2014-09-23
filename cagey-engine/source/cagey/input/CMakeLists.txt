

add_subdirectory(sdl)

set(CageyInput_SRCS
    InputManager.cc)

set(CageyInput_HEADERS IInputSystem.hh)

#Make this sources visible in editors
add_custom_target(CageyInput SOURCES ${CageyInput_SRCS} ${CageyInput_HEADERS})

