
set(CageySdlInputSystem_SRCS
    SdlInputSystem.cc
    SdlKeyboard.cc
    SdlMouse.hh)

set(CageySdlInputSystem_HEADERS
    SdlInputSystem.hh
    SdlKeyboard.hh
    SdlMouse.hh)

#Make this sources visible in editors
add_custom_target(CageySdlInputSystem SOURCES ${CageySdlInputSystem_SRCS} ${CageySdlInputSystem_HEADERS})
