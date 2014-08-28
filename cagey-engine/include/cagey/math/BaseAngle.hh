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

#include "cagey/math/Constants.hh"
#include "cagey/math/Util.hh"

namespace cagey { 
namespace math { 


/**
 * Base for Angle representation classes.
 *
 * @tparam T Underlying type
 */
template<template<typename> class D, typename T> class BaseAngle {

  template<template<typename> class, typename> friend class BaseAngle;
  
public:

  ///Underlying type
  using Type = T; 

  /** 
   * Default Constructor. Initialize to 0
   */
  constexpr BaseAngle(): value{0} {}
  
  /**
   * Explicit conversion constructor from raw value
   *
   * @param value a unitless value
   */
  constexpr explicit BaseAngle(T value) : value{value} {}
  
  /**
   * Conversion constructor.  Constructs a BaseAngle from one with a different 
   * underlying type
   * 
   * @tparam U a underlying type
   * @param value a BaseAngle to convert to this
   */
  template<typename U> constexpr explicit BaseAngle(BaseAngle<D, U> other): value(T(other.value)) {}

  /**
   * Explicit conversion operator to raw value
   *
   * @param value a unitless value
   */
  constexpr explicit operator T() const { return value; }

  /**
   * Assign Addition Operator.  The value in the given BaseAngle is added to 
   * the value of this BaseAngle.
   *
   * @param other an other instance of BaseAngle
   */
  constexpr auto operator+=(BaseAngle<D, T> const & other) -> BaseAngle<D, T> & {
    value += other.value;
    return *this;
  }

  /**
   * Substract Assign Operator.  The value in the given BaseAngle is subtracted
   * from the value of this BaseAngle.
   *
   * @param other an other instance of BaseAngle
   */
  constexpr auto operator-=(BaseAngle<D, T> const & other) -> BaseAngle<D, T> & {
    value -= other.value;
    return *this;
  }
  

  /**
   * Multiplication Assign Operator.  The value of this BaseAngle is multiplied
   * by the given value.
   *
   * @param val the scaling factor
   */
  constexpr auto operator*=(T val) -> BaseAngle<D, T> & {
    value *= val;
    return *this;
  }
  
/*
  constexpr auto operator/=(T val) -> BaseAngle<D, T> & {
    value /= val;
    return *this;
  }
*/

  /**
   * Addition Operator.  
   *
   * Note: implemented as a friend function defined within the template, makes invisible to non-ADL lookup.
   *
   * @param lhs the left hand side of the addition
   * @param rhs the right hand side of the addition
   */
  friend constexpr auto operator+(BaseAngle<D, T> lhs, BaseAngle<D, T> const & rhs) -> BaseAngle<D, T> {
    return lhs += rhs;
  }

  /**
   * Subtraction Operator.  
   *
   * Note: implemented as a friend function defined within the template, makes invisible to non-ADL lookup.
   *
   * @param lhs the left hand side of the subtraction
   * @param rhs the right hand side of the subtraction
   */
  friend constexpr auto operator-(BaseAngle<D, T> lhs, BaseAngle<D, T> const & rhs) -> BaseAngle<D, T> {
    return lhs -= rhs;
  }
  
/*
  friend constexpr auto operator==(BaseAngle<D, T> const & lhs, BaseAngle<D, T> const & rhs) -> bool {
    return lhs.value = rhs.value;
  }

  friend constexpr auto operator!=(BaseAngle<D, T> const & lhs, BaseAngle<D, T> const & rhs) -> bool {
    return !(lhs==rhs);
  }

  friend constexpr auto operator<(BaseAngle<D, T> const & lhs, BaseAngle<D, T> const & rhs) -> bool {
    return lhs.value < rhs.value;
  }

  friend constexpr auto operator>(BaseAngle<D, T> const & lhs, BaseAngle<D, T> const & rhs) -> bool {
    return rhs < lhs;
  }

  friend constexpr auto operator<=(BaseAngle<D, T> const & lhs, BaseAngle<D, T> const & rhs) -> bool {
    return !(lhs>rhs);
  }

  friend constexpr auto operator>=(BaseAngle<D, T> const & lhs, BaseAngle<D, T> const & rhs) -> bool {
    return !(lhs<rhs);
  }

  friend constexpr auto operator-(BaseAngle<D, T> const & lhs) -> BaseAngle<D, T> {
    return BaseAngle<D, T>{-lhs.value};
  }
*/

  
  /**
   * Multiplication Operator.  
   *
   * Note: implemented as a friend function defined within the template, makes invisible to non-ADL lookup.
   *
   * @param lhs the left hand side of the multiplication
   * @param val the amount to scale by
   */
  friend constexpr auto operator*(BaseAngle<D, T> lhs, T val) -> BaseAngle<D, T> {
    return lhs *= val;
  }

  /**
   * Multiplication Operator.  
   *
   * Note: implemented as a friend function defined within the template, makes invisible to non-ADL lookup.
   *
   * @param rhs the rhs hand side of the multiplication
   * @param val the amount to scale by
   */
  friend constexpr auto operator*(T val, BaseAngle<D, T> rhs) -> BaseAngle<D, T> {
    return rhs *= val;
  }

  friend constexpr auto equals(BaseAngle<D, T> const & rhs,BaseAngle<D, T> const & lhs) {
    return equals(rhs.value, lhs.value);
  }

/*
  friend constexpr auto operator/(BaseAngle<D, T> lhs, T val) -> BaseAngle<D, T> {
    return lhs /= val;
  }

  friend constexpr auto operator/(BaseAngle<D, T> lhs, BaseAngle<D, T> const & rhs) -> BaseAngle<D, T> {
    return lhs /= rhs.value;
  }
*/
private:
  Type value;
};




} // namespace math
} // namespace cagey

#endif /* CAGEY_MATH_BASEANGLE_HH_ */
