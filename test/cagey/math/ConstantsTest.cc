#include <cagey/math/Constants.hh>
#include <gtest/gtest.h>
#include <cstdint>

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
