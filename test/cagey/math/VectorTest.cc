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

#include <cagey/math/Vector.hh>
#include "gtest/gtest.h"
#include <algorithm>
#include <sstream>
using namespace cagey::math;

TEST(Vector, DefaultConstructor) {
  Vec2i vec2i;
  Vec3i vec3i;
  Vec4i vec4i;
  EXPECT_EQ(0, vec2i.x);
  EXPECT_EQ(0, vec2i.y);
  EXPECT_EQ(0, vec2i.data[0]);
  EXPECT_EQ(0, vec2i.data[1]);

  EXPECT_EQ(0, vec3i.x);
  EXPECT_EQ(0, vec3i.y);
  EXPECT_EQ(0, vec3i.z);
  EXPECT_EQ(0, vec3i.r);
  EXPECT_EQ(0, vec3i.g);
  EXPECT_EQ(0, vec3i.b);
  EXPECT_EQ(0, vec3i.data[0]);
  EXPECT_EQ(0, vec3i.data[1]);
  EXPECT_EQ(0, vec3i.data[2]);
  EXPECT_EQ(0, vec3i.xy.x);
  EXPECT_EQ(0, vec3i.xy.y);

  EXPECT_EQ(0, vec4i.x);
  EXPECT_EQ(0, vec4i.y);
  EXPECT_EQ(0, vec4i.z);
  EXPECT_EQ(0, vec4i.w);
  EXPECT_EQ(0, vec4i.r);
  EXPECT_EQ(0, vec4i.g);
  EXPECT_EQ(0, vec4i.b);
  EXPECT_EQ(0, vec4i.a);
  EXPECT_EQ(0, vec4i.data[0]);
  EXPECT_EQ(0, vec4i.data[1]);
  EXPECT_EQ(0, vec4i.data[2]);
  EXPECT_EQ(0, vec4i.data[3]);
  EXPECT_EQ(0, vec4i.xyz.x);
  EXPECT_EQ(0, vec4i.xyz.y);
  EXPECT_EQ(0, vec4i.xyz.z);
  EXPECT_EQ(0, vec4i.rgb.x);
  EXPECT_EQ(0, vec4i.rgb.y);
  EXPECT_EQ(0, vec4i.rgb.z);
  EXPECT_EQ(0, vec4i.xy.x);
  EXPECT_EQ(0, vec4i.xy.y);
}

TEST(Vector, SingleArgumentConstructor) {
  Vec2i vec2{0};
  Vec3i vec3{0};
  Vec4i vec4{0};

  EXPECT_EQ(0, vec2.x);
  EXPECT_EQ(0, vec2.y);
  EXPECT_EQ(0, vec3.x);
  EXPECT_EQ(0, vec3.y);
  EXPECT_EQ(0, vec3.z);
  EXPECT_EQ(0, vec4.x);
  EXPECT_EQ(0, vec4.y);
  EXPECT_EQ(0, vec4.z);
  EXPECT_EQ(0, vec4.w);

  Vec2i vec2a{1};
  Vec3i vec3a{1};
  Vec4i vec4a{1};

  EXPECT_EQ(1, vec2a.x);
  EXPECT_EQ(1, vec2a.y);
  EXPECT_EQ(1, vec3a.x);
  EXPECT_EQ(1, vec3a.y);
  EXPECT_EQ(1, vec3a.z);
  EXPECT_EQ(1, vec4a.x);
  EXPECT_EQ(1, vec4a.y);
  EXPECT_EQ(1, vec4a.z);
  EXPECT_EQ(1, vec4a.w);

}

TEST(Vector, ScalarArgumentConstructor) {
  Vec2i vec2{0, 1};
  EXPECT_EQ(0, vec2.x);
  EXPECT_EQ(1, vec2.y);
  Vec3i vec3{0, 1, 2};
  EXPECT_EQ(0, vec3.x);
  EXPECT_EQ(1, vec3.y);
  EXPECT_EQ(2, vec3.z);
  Vec4i vec4{0, 1, 2, 3};
  EXPECT_EQ(0, vec4.x);
  EXPECT_EQ(1, vec4.y);
  EXPECT_EQ(2, vec4.z);
  EXPECT_EQ(3, vec4.w);
}

TEST(Vector, ArrayArgumentConstructor) {
  int values[] = { 0, 1 };
  Vec2i vec2{values};
  EXPECT_EQ(0, vec2.x);
  EXPECT_EQ(1, vec2.y);
}

TEST(Vector, ArrayArgumentConstructor2) {
  float values[3] = { 0.0f, 1.0f, 3.0f };
  Vec3f vec3{values};
  EXPECT_EQ(0, vec3.x);
  EXPECT_EQ(1, vec3.y);
  EXPECT_EQ(3, vec3.z);
}

TEST(Vector, ArrayObjectArgumentConstructor) {
  std::array<int, 2> values = {{ 0, 1 }};
  Vec2i vec2{values};
  EXPECT_EQ(0, vec2.x);
  EXPECT_EQ(1, vec2.y);

  std::array<int, 3> longVal = {{ 3, 2, 1 }};
  Vec3i vec3{longVal};
  EXPECT_EQ(3, vec3.x);
  EXPECT_EQ(2, vec3.y);
  EXPECT_EQ(1, vec3.z);
}

TEST(Vector, CopyConstructor) {
  Vec2i vec2{2,3};
  Vec2i vec2a{vec2};
  EXPECT_EQ(2, vec2a.x);
  EXPECT_EQ(3, vec2a.y);
}

TEST(Vector, CopyConstructorDifferentType) {
  Vec2f vec2{2.0f,3.0f};
  Vec2i vec2a{vec2};
  EXPECT_EQ(2, vec2a.x);
  EXPECT_EQ(3, vec2a.y);
}

TEST(Vector, CopyConstructorDifferentType2) {
  Vec3d vec3{2.0f,3.0f, 5.5f};
  Vec3i vec3a{vec3};
  EXPECT_EQ(2.0f, vec3a.x);
  EXPECT_EQ(3.0f, vec3a.y);
  EXPECT_EQ(5.0f, vec3a.z);
}

TEST(Vector, CopyAssignmentOperator) {
  Vec2i vec2a = {2, 3};
  EXPECT_EQ(2, vec2a.x);
  EXPECT_EQ(3, vec2a.y);
}

TEST(Vector, VectorSwap) {
  Vec2i vec2a = {2, 3};
  Vec2i vec2b = {5, 6};
  swap(vec2a, vec2b);
  EXPECT_EQ(2, vec2b.x);
  EXPECT_EQ(3, vec2b.y);
  EXPECT_EQ(5, vec2a.x);
  EXPECT_EQ(6, vec2a.y);
}

TEST(Vector, indexOperator) {
  Vec2i vec2a = {2, 3};
  EXPECT_EQ(2, vec2a[0]);
  EXPECT_EQ(3, vec2a[1]);
  vec2a[0] = 6;
  vec2a[1] = 8;
  EXPECT_EQ(6, vec2a.x);
  EXPECT_EQ(8, vec2a.y);
}

TEST(Vector, beginEnd) {
  Vec2i vec2a = {2, 3};
  std::transform(std::begin(vec2a), std::end(vec2a), std::begin(vec2a), [] (int i) { return i * 2;});
  EXPECT_EQ(4, vec2a.x);
  EXPECT_EQ(6, vec2a.y);
}

TEST(Vector, addEqualsOperator) {
  Vec2i vec2a = {2, 3};
  Vec2i vec2b = {2, 3};
  vec2a += vec2b;
  EXPECT_EQ(4, vec2a.x);
  EXPECT_EQ(6, vec2a.y);
}

TEST(Vector, minusEqualsOperator) {
  Vec2i vec2a = {2, 3};
  Vec2i vec2b = {2, 3};
  vec2a -= vec2b;
  EXPECT_EQ(0, vec2a.x);
  EXPECT_EQ(0, vec2a.y);
}

TEST(Vector, multiplyOperator) {
  Vec2i vec2a = {2, 3};
  vec2a *= 2;
  EXPECT_EQ(4, vec2a.x);
  EXPECT_EQ(6, vec2a.y);
}

TEST(Vector, divideOperator) {
  Vec2i vec2a = {4, 8};
  vec2a /= 2;
  EXPECT_EQ(2, vec2a.x);
  EXPECT_EQ(4, vec2a.y);
}

TEST(Vector, VectorMinMax) {
  Vec2i vec2a = {4, 8};
  EXPECT_EQ(4, min(vec2a));
  EXPECT_EQ(8, max(vec2a));
}

TEST(Vector, VectorSum) {
  Vec2i vec2a = {4, 8};
  EXPECT_EQ(12, sum(vec2a));
}

TEST(Vector, VectorPrint) {
  Vec2i vec2a = {4, 8};
  std::ostringstream str;
  str << vec2a;
  EXPECT_EQ(str.str(), "( 4, 8 )");
}


