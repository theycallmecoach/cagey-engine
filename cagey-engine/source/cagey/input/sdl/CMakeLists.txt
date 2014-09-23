
set(CageySdlInputSystem_SRCS
    SdlInputSystem.cc)

set(CageySdlInputSystem_HEADERS SdlInputSystem.hh)

#Make this sources visible in editors
add_custom_target(CageySdlInputSystem SOURCES ${CageySdlInputSystem_SRCS} ${CageySdlInputSystem_HEADERS})
