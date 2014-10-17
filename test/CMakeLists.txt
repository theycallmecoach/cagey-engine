set(GTEST_DIR "/usr/src/gtest/"
    CACHE PATH "The path to the GoogleTest test framework.")
    
add_subdirectory(${GTEST_DIR} ${CMAKE_BINARY_DIR}/gtest)    
#add_subdirectory(cagey/math)    

add_executable(CageyMathTest
               cagey/math/ConstantsTest.cc
               cagey/math/DegreeTest.cc 
               cagey/math/VectorTest.cc 
               cagey/math/MatrixTest.cc 
               cagey/math/PointTest.cc
               CageyTestMain.cc)

add_executable(CageyWindowTest
               cagey/window/VideoModeTest.cc
               cagey/window/WindowTest.cc
               cagey/window/DisplayConfigTest.cc
               CageyTestMain.cc)


target_link_libraries(CageyMathTest gtest_main)
target_link_libraries(CageyWindowTest gtest_main CageyEngine)


add_test(CageyMathTest CageyMathTest)
add_test(CageyWindowTest CageyWindowTest)
