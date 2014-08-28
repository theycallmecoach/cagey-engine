#include <cagey/math/Degree.hh>
#include <gtest/gtest.h>


using namespace cagey::math;

TEST(Degree, DefaultConstructor) {
  Degree<float> d;

  EXPECT_FLOAT_EQ(0.0f, float(d));
}

TEST(Degree, ValueConstructor) {
  Degree<float> d{45.0f};

  EXPECT_FLOAT_EQ(45.0f, float(d));
}


TEST(Degree, AddAssignOperator) {
  Degree<float> d{45.0f};
  Degree<float> d2{45.0f};
  d += d2;

  EXPECT_FLOAT_EQ(90.0f, float(d));
}

TEST(Degree, AddOperator) {
  Degree<float> d{45.0f};
  Degree<float> d2{45.0f};
  auto d3 = d + d2;

  EXPECT_FLOAT_EQ(90.0f, float(d3));
}
