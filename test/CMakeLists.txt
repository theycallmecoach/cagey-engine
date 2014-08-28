set(GTEST_DIR "/usr/src/gtest/"
    CACHE PATH "The path to the GoogleTest test framework.")
    
add_subdirectory(${GTEST_DIR} ${CMAKE_BINARY_DIR}/gtest)    
#add_subdirectory(cagey/math)    

add_executable(CageyTest cagey/math/ConstantsTest.cc cagey/math/DegreeTest.cc CageyTestMain.cc)

#target_link_libraries(CageyTest CageyConstantsTest gtest_main)
target_link_libraries(CageyTest gtest_main)

add_test(CageyTest CageyTest)
