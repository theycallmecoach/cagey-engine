////////////////////////////////////////////////////////////////////////////////
//
// cagey-engine - Toy 3D Engine 
// Copyright (c) 2014 Kyle Girard <theycallmecoach@gmail.com>
//
// The MIT License (MIT)
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in 
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
////////////////////////////////////////////////////////////////////////////////

#include <cagey/math/Constants.hh>
#include <gtest/gtest.h>

using namespace cagey::math;

template <typename T>
class ConstantTestFixture : public ::testing::Test {
};
TYPED_TEST_CASE_P(ConstantTestFixture);


TYPED_TEST_P(ConstantTestFixture, ChecksPiValue) {
  EXPECT_EQ(TypeParam(3.141592653589793238462643383279502884), constants::pi<TypeParam>);
}

TYPED_TEST_P(ConstantTestFixture, ChecksDegToRadValue) {
  EXPECT_EQ(constants::degToRad<TypeParam>, constants::pi<TypeParam> / TypeParam(180.0f));
}

TYPED_TEST_P(ConstantTestFixture, ChecksRadToDegValue) {
  EXPECT_EQ(constants::radToDeg<TypeParam>, TypeParam(180.0f) / constants::pi<TypeParam> );
}

REGISTER_TYPED_TEST_CASE_P(ConstantTestFixture, ChecksPiValue, ChecksDegToRadValue, ChecksRadToDegValue);

typedef ::testing::Types<int, float, double> SupportedTypes;
INSTANTIATE_TYPED_TEST_CASE_P(Cagey, ConstantTestFixture, SupportedTypes);


//TEST(Vector, Pi) {
//  EXPECT_EQ(3, constants::pi<int>);
//}

