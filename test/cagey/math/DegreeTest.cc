
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

TEST(Degree, CoversionCopyConstructor) {
  Degree<int> d{45};
  Degree<float> d2{d};

  EXPECT_FLOAT_EQ(45.0f, float(d2));
}

TEST(Degree, CopyConstructor) {
  Degree<float> d{45};
  Degree<float> d2{d};

  EXPECT_FLOAT_EQ(45.0f, float(d2));
}

TEST(Degree, AddAssignOperator) {
  Degree<float> d{45.0f};
  Degree<float> d2{45.0f};
  d += d2;

  EXPECT_FLOAT_EQ(90.0f, float(d));
}

TEST(Degree, SubtractAssignOperator) {
  Degree<float> d{45.0f};
  Degree<float> d2{45.0f};
  d -= d2;

  EXPECT_FLOAT_EQ(0.0f, float(d));
}

TEST(Degree, MultiplicationAssignOperator) {
  Degree<float> d{45.0f};
  d *= 3.0f;

  EXPECT_FLOAT_EQ(135.0f, float(d));
}

TEST(Degree, AddOperator) {
  Degree<float> d{45.0f};
  Degree<float> d2{45.0f};
  auto d3 = d + d2;

  EXPECT_FLOAT_EQ(90.0f, float(d3));
}

TEST(Degree, SubtractOperator) {
  Degree<float> d{45.0f};
  Degree<float> d2{45.0f};
  auto d3 = d - d2;

  EXPECT_FLOAT_EQ(0.0f, float(d3));
}

TEST(Degree, MultiplicationOperator) {
  Degree<float> d{45.0f};
  auto d2 = d * 3.0f;
  auto d3 = 2.0f * d;

  EXPECT_FLOAT_EQ(135.0f, float(d2));
  EXPECT_FLOAT_EQ(90.0f, float(d3));
}

TEST(Degree, equals) {
  Degree<float> d{45.0f};
  Degree<float> d2{45.0f};
  EXPECT_TRUE(equals(d,d2));
  EXPECT_FALSE(equals(d,Degree<float>{30}));
}

