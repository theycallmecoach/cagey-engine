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

#include <cagey/math/Matrix.hh>
#include "gtest/gtest.h"
#include <algorithm>
#include <type_traits>

using namespace cagey::math;


TEST(Matrix, DefaultConstructor) {
  typedef Matrix<int, 5, 5> Mat5f;

  Mat5f ident;

  EXPECT_EQ(1, ident(2,2));
  EXPECT_EQ(0, ident(2,3));
}

TEST(Matrix, FillConstructor) {
  Mat4<int> mat(4,4);
  EXPECT_EQ(4, mat(3,0));
  EXPECT_EQ(0, mat(0,1));
  Mat4<int> mata(2);
  EXPECT_EQ(2, mata(3,0));
}

TEST(Matrix, ArrayConstructor) {
  Mat2i ma{{{1, 2, 3, 4}}};
  EXPECT_EQ(4, ma(1,1));
  std::array<int, 4> b{{1, 2, 3, 4}};
  Mat2i mb{b};
  EXPECT_EQ(4, mb(1,1));
}


TEST(Matrix, DifferentTypeConstructor) {
  Mat2f ma{{{1.0, 2.0, 3.0, 4.0}}};
  Mat2i mb{ma};
  EXPECT_EQ(4, mb(1,1));
}

TEST(Matrix, PodTest) {
  EXPECT_EQ(false, std::is_pod<Mat2f>::value);
}

TEST(Matrix, operatorScale) {
  Mat2f ma{{{1.0, 2.0, 3.0, 4.0}}};
  ma *= 2.0f;
  EXPECT_EQ(8, ma(1,1));
}

TEST(Matrix, operatorNegate) {
  Mat2f ma{{{1.0, 2.0, 3.0, 4.0}}};
  ma = -ma;
  EXPECT_EQ(-4, ma(1,1));
}

TEST(Matrix, adjugateTest) {
  Mat2f ma{{{1.0, 2.0, 3.0, 4.0}}};
  auto adj = adjugate(ma);
  EXPECT_EQ(1, adj(1,1));
  EXPECT_EQ(4, adj(0,0));
}

TEST(Matrix, makeScaleTest) {
  auto scale = makeScale(2.0f, 2.0f, 2.0f);
  EXPECT_EQ(2, scale(1,1));
}

TEST(Matrix, makeTranslationTest) {
  auto trans = makeTranslation(2.0f, 2.0f, 2.0f);
  EXPECT_EQ(2, trans(0,3));
}
