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

#ifndef CAGEY_MATH_BASEANGLE_HH_
#define CAGEY_MATH_BASEANGLE_HH_

/**
 * hmm
 */
namespace cagey { 
/**
 * ha
 */
namespace math { 

#include <cmath>
#include <numeric> //for std::numeric_limits
#include <iostream> //for std::ostream
#include "cagey/math/Math.hh"
#include "cagey/math/Constants.hh"

/**
 * Base for BaseAngle classes.
 *
 * @tparam T Underlying type
 */
template<template<typename> class Derived, typename T> class BaseAngle {
public:

  ///Underlying type
  using Type = T; 

  constexpr BaseAngle(): value{0} {}
  constexpr explicit BaseAngle(T value) : value{value} {}
  
  template<class U> constexpr explicit BaseAngle(BaseAngle<Derived, U> value): value(T(value.value)) {}

  constexpr explicit operator T() const { return value; }


  constexpr auto operator+=(BaseAngle<Derived, T> & other) -> BaseAngle<Derived, T> & {
    value += other.value;
    return *this;
  }

  constexpr auto operator-=(BaseAngle<Derived, T> & other) -> BaseAngle<Derived, T> & {
    value -= other.value;
    return *this;
  }

  constexpr auto operator*=(T val) -> BaseAngle<Derived, T> & {
    value *= val;
    return *this;
  }

  constexpr auto operator/=(T val) -> BaseAngle<Derived, T> & {
    value /= val;
    return *this;
  }

  friend constexpr auto operator+(BaseAngle<Derived, T> lhs, BaseAngle<Derived, T> const & rhs) -> BaseAngle<Derived, T> {
    return lhs += rhs;
  }

  friend constexpr auto operator-(BaseAngle<Derived, T> lhs, BaseAngle<Derived, T> const & rhs) -> BaseAngle<Derived, T> {
    return lhs -= rhs;
  }

  friend constexpr auto operator==(BaseAngle<Derived, T> const & lhs, BaseAngle<Derived, T> const & rhs) -> bool {
    return lhs.value = rhs.value;
  }

  friend constexpr auto operator!=(BaseAngle<Derived, T> const & lhs, BaseAngle<Derived, T> const & rhs) -> bool {
    return !(lhs==rhs);
  }

  friend constexpr auto operator<(BaseAngle<Derived, T> const & lhs, BaseAngle<Derived, T> const & rhs) -> bool {
    return lhs.value < rhs.value;
  }

  friend constexpr auto operator>(BaseAngle<Derived, T> const & lhs, BaseAngle<Derived, T> const & rhs) -> bool {
    return rhs < lhs;
  }

  friend constexpr auto operator<=(BaseAngle<Derived, T> const & lhs, BaseAngle<Derived, T> const & rhs) -> bool {
    return !(lhs>rhs);
  }

  friend constexpr auto operator>=(BaseAngle<Derived, T> const & lhs, BaseAngle<Derived, T> const & rhs) -> bool {
    return !(lhs<rhs);
  }

  friend constexpr auto operator-(BaseAngle<Derived, T> const & lhs) -> BaseAngle<Derived, T> {
    return BaseAngle<Derived, T>{-lhs.value};
  }

  friend constexpr auto operator*(BaseAngle<Derived, T> lhs, T val) -> BaseAngle<Derived, T> {
    return lhs *= val;
  }

  friend constexpr auto operator*(T val, BaseAngle<Derived, T> rhs) -> BaseAngle<Derived, T> {
    return rhs *= val;
  }

  friend constexpr auto operator/(BaseAngle<Derived, T> lhs, T val) -> BaseAngle<Derived, T> {
    return lhs /= val;
  }

  friend constexpr auto operator/(BaseAngle<Derived, T> lhs, BaseAngle<Derived, T> const & rhs) -> BaseAngle<Derived, T> {
    return lhs /= rhs.value;
  }

public:
  Type value;
};

} // namespace math
} // namespace cagey

#endif /* CAGEY_MATH_BASEANGLE_HH_ */
