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

#include <cagey/math/Point.hh>
#include "gtest/gtest.h"
#include <algorithm>
#include <sstream>
using namespace cagey::math;

TEST(Point, DefaultConstructor) {
  Point2i point2i;
  Point3i point3i;
  EXPECT_EQ(0, point2i.x);
  EXPECT_EQ(0, point2i.y);
  EXPECT_EQ(0, point2i.data[0]);
  EXPECT_EQ(0, point2i.data[1]);

  EXPECT_EQ(0, point3i.x);
  EXPECT_EQ(0, point3i.y);
  EXPECT_EQ(0, point3i.z);
  EXPECT_EQ(0, point3i.r);
  EXPECT_EQ(0, point3i.g);
  EXPECT_EQ(0, point3i.b);
  EXPECT_EQ(0, point3i.data[0]);
  EXPECT_EQ(0, point3i.data[1]);
  EXPECT_EQ(0, point3i.data[2]);
}

TEST(Point, SingleArgumentConstructor) {
  Point2i point2{0};
  Point3i point3{0};

  EXPECT_EQ(0, point2.x);
  EXPECT_EQ(0, point2.y);
  EXPECT_EQ(0, point3.x);
  EXPECT_EQ(0, point3.y);
  EXPECT_EQ(0, point3.z);

  Point2i point2a{1};
  Point3i point3a{1};

  EXPECT_EQ(1, point2a.x);
  EXPECT_EQ(1, point2a.y);
  EXPECT_EQ(1, point3a.x);
  EXPECT_EQ(1, point3a.y);
  EXPECT_EQ(1, point3a.z);
}

TEST(Point, ScalarArgumentConstructor) {
  Point2i point2{0, 1};
  EXPECT_EQ(0, point2.x);
  EXPECT_EQ(1, point2.y);
  Point3i point3{0, 1, 2};
  EXPECT_EQ(0, point3.x);
  EXPECT_EQ(1, point3.y);
  EXPECT_EQ(2, point3.z);
}

TEST(Point, ArrayArgumentConstructor) {
  int values[] = { 0, 1 };
  Point2i point2{values};
  EXPECT_EQ(0, point2.x);
  EXPECT_EQ(1, point2.y);
}

TEST(Point, ArrayArgumentConstructor2) {
  float values[3] = { 0.0f, 1.0f, 3.0f };
  Point3f point3{values};
  EXPECT_EQ(0, point3.x);
  EXPECT_EQ(1, point3.y);
  EXPECT_EQ(3, point3.z);
}

TEST(Point, ArrayObjectArgumentConstructor) {
  std::array<int, 2> values = {{ 0, 1 }};
  Point2i point2{values};
  EXPECT_EQ(0, point2.x);
  EXPECT_EQ(1, point2.y);

  std::array<int, 3> longVal = {{ 3, 2, 1 }};
  Point3i point3{longVal};
  EXPECT_EQ(3, point3.x);
  EXPECT_EQ(2, point3.y);
  EXPECT_EQ(1, point3.z);
}

TEST(Point, CopyConstructor) {
  Point2i point2{2,3};
  Point2i point2a{point2};
  EXPECT_EQ(2, point2a.x);
  EXPECT_EQ(3, point2a.y);
}

TEST(Point, CopyConstructorDifferentType) {
  Point2f point2{2.0f,3.0f};
  Point2i point2a{point2};
  EXPECT_EQ(2, point2a.x);
  EXPECT_EQ(3, point2a.y);
}

TEST(Point, CopyConstructorDifferentType2) {
  Point3d point3{2.0f,3.0f, 5.5f};
  Point3i point3a{point3};
  EXPECT_EQ(2.0f, point3a.x);
  EXPECT_EQ(3.0f, point3a.y);
  EXPECT_EQ(5.0f, point3a.z);
}

TEST(Point, CopyAssignmentOperator) {
  Point2i point2a = {2, 3};
  EXPECT_EQ(2, point2a.x);
  EXPECT_EQ(3, point2a.y);
}

TEST(Point, PointSwap) {
  Point2i point2a = {2, 3};
  Point2i point2b = {5, 6};
  swap(point2a, point2b);
  EXPECT_EQ(2, point2b.x);
  EXPECT_EQ(3, point2b.y);
  EXPECT_EQ(5, point2a.x);
  EXPECT_EQ(6, point2a.y);
}

TEST(Point, indexOperator) {
  Point2i point2a = {2, 3};
  EXPECT_EQ(2, point2a[0]);
  EXPECT_EQ(3, point2a[1]);
  point2a[0] = 6;
  point2a[1] = 8;
  EXPECT_EQ(6, point2a.x);
  EXPECT_EQ(8, point2a.y);
}

TEST(Point, beginEnd) {
  Point2i point2a = {2, 3};
  std::transform(std::begin(point2a), std::end(point2a), std::begin(point2a), [] (int i) { return i * 2;});
  EXPECT_EQ(4, point2a.x);
  EXPECT_EQ(6, point2a.y);
}

TEST(Point, addEqualsOperator) {
  Point2i point2a = {2, 3};
  Point2i point2b = {2, 3};
  point2a += point2b;
  EXPECT_EQ(4, point2a.x);
  EXPECT_EQ(6, point2a.y);
}

TEST(Point, minusEqualsOperator) {
  Point2i point2a = {2, 3};
  Point2i point2b = {2, 3};
  point2a -= point2b;
  EXPECT_EQ(0, point2a.x);
  EXPECT_EQ(0, point2a.y);
}

TEST(Point, multiplyOperator) {
  Point2i point2a = {2, 3};
  point2a *= 2;
  EXPECT_EQ(4, point2a.x);
  EXPECT_EQ(6, point2a.y);
}

TEST(Point, divideOperator) {
  Point2i point2a = {4, 8};
  point2a /= 2;
  EXPECT_EQ(2, point2a.x);
  EXPECT_EQ(4, point2a.y);
}

TEST(Point, PointMinMax) {
  Point2i point2a = {4, 8};
  EXPECT_EQ(4, min(point2a));
  EXPECT_EQ(8, max(point2a));
}

TEST(Point, PointSum) {
  Point2i point2a = {4, 8};
  EXPECT_EQ(12, sum(point2a));
}

TEST(Point, PointPrint) {
  Point2i point2a = {4, 8};
  std::ostringstream str;
  str << point2a;
  EXPECT_EQ(str.str(), "( 4, 8 )");
}


