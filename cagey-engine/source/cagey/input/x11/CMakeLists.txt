
set(CageyX11InputSystem_SRCS
    X11InputSystem.cc)

set(CageyX11InputSystem_HEADERS SdlInputSystem.hh)


#Make this sources visible in editors
add_custom_target(CageySdlInputSystem SOURCES ${CageySdlInputSystem_SRCS} ${CageySdl2InputSystem_HEADERS})
