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

  /** @cond doxygen has some issues with static assert */  
  static_assert(std::is_arithmetic<T>::value, "Underlying type must be a number");
  /** @endcond */

  ///Underlying type
  using Type = T; 

protected:
  /** 
   * Default Constructor. Initialize to 0
   */
  constexpr BaseAngle() = default;
  
  /**
   * Explicit conversion constructor from raw value
   *
   * @param value a unitless value
   */
  constexpr explicit BaseAngle(T const value) : value{value} {}
  
  /**
   * Copy constructor creates a BaseAngle from one with possibly different 
   * underlying type.
   * 
   * @tparam U a underlying type
   * @param other a BaseAngle to convert to this
   */
  template<typename U> constexpr explicit BaseAngle(BaseAngle<D, U> const & other): value(T(other.value)) {}

public:

  /**
   * Explicit conversion operator to raw value
   *
   * @return a unitless value
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
  constexpr auto operator*=(T const val) -> BaseAngle<D, T> & {
    value *= val;
    return *this;
  }
  

  /**
   * Division Assign Operator.  The value of this BaseAngle is divided
   * by the given value.
   *
   * @param val the scaling factor
   */
  constexpr auto operator/=(T const val) -> BaseAngle<D, T> & {
    value /= val;
    return *this;
  }


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
  

  /**
   * Equality Operator. Checks BaseAngles for exact equality.  Not really 
   * useful with floating point based angles
   *
   * Note: implemented as a friend function defined within the template, makes invisible to non-ADL lookup.
   *
   * @param lhs the left hand side of the equality operation
   * @param rhs the right hand side of the equality operation
   */
  friend constexpr auto operator==(BaseAngle<D, T> const & lhs, BaseAngle<D, T> const & rhs) -> bool {
    return lhs.value == rhs.value;
  }

  /**
   * Inequality Operator. Checks BaseAngles for inequality.  
   *
   * Note: implemented as a friend function defined within the template, makes invisible to non-ADL lookup.
   *
   * @param lhs the left hand side of the inequality operation
   * @param rhs the right hand side of the inequality operation
   */
  friend constexpr auto operator!=(BaseAngle<D, T> const & lhs, BaseAngle<D, T> const & rhs) -> bool {
    return !(lhs==rhs);
  }
  
  

  /**
   * LessThan Operator. Checks if the lhs BaseAngle is less than the rhs 
   * BaseAngle  
   *
   * Note: implemented as a friend function defined within the template, makes invisible to non-ADL lookup.
   *
   * @param lhs the left hand side BaseAngle
   * @param rhs the right hand side BaseAngle
   */
  friend constexpr auto operator<(BaseAngle<D, T> const & lhs, BaseAngle<D, T> const & rhs) -> bool {
    return lhs.value < rhs.value;
  }

  /**
   * GreaterThan Operator. Checks if the lhs BaseAngle is greater than the rhs 
   * BaseAngle  
   *
   * Note: implemented as a friend function defined within the template, makes invisible to non-ADL lookup.
   *
   * @param lhs the left hand side BaseAngle
   * @param rhs the right hand side BaseAngle
   */
  friend constexpr auto operator>(BaseAngle<D, T> const & lhs, BaseAngle<D, T> const & rhs) -> bool {
    return rhs < lhs;
  }

  /**
   * LessThanEqual Operator. Checks if the lhs BaseAngle is less or equal 
   * than the rhs BaseAngle  
   *
   * Note: implemented as a friend function defined within the template, makes invisible to non-ADL lookup.
   *
   * @param lhs the left hand side BaseAngle
   * @param rhs the right hand side BaseAngle
   */
  friend constexpr auto operator<=(BaseAngle<D, T> const & lhs, BaseAngle<D, T> const & rhs) -> bool {
    return !(lhs>rhs);
  }

  /**
   * GreaterThanEqual Operator. Checks if the lhs BaseAngle is greater than or 
   * equal to the rhs BaseAngle  
   *
   * Note: implemented as a friend function defined within the template, makes invisible to non-ADL lookup.
   *
   * @param lhs the left hand side BaseAngle
   * @param rhs the right hand side BaseAngle
   *
   * @return true if the lhs value is greater than or equal to rhs value
   */
  friend constexpr auto operator>=(BaseAngle<D, T> const & lhs, BaseAngle<D, T> const & rhs) -> bool {
    return !(lhs<rhs);
  }

  /**
   * Negation Operator.  Returns a negative copy of the given element  
   *
   * Note: implemented as a friend function defined within the template, makes invisible to non-ADL lookup.
   *
   * @param lhs the left hand side BaseAngle
   *
   * @return a negative angle equal in magnatude to this
   */
  friend constexpr auto operator-(BaseAngle<D, T> const & lhs) -> BaseAngle<D, T> {
    return BaseAngle<D, T>{-lhs.value};
  }
  
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

  /**
   * Divison Operator.  Divide an angle by a value
   *
   * Note: implemented as a friend function defined within the template, makes invisible to non-ADL lookup.
   *
   * @param lhs the lhs hand side of the division
   * @param val the amount to scale by
   */
  friend constexpr auto operator/(BaseAngle<D, T> lhs, T const val) -> BaseAngle<D, T> {
    return lhs /= val;
  }

  /**
   * Divison Operator. Return the ratio between the two angles
   *
   * Note: implemented as a friend function defined within the template, makes invisible to non-ADL lookup.
   *
   * @param rhs the rhs hand side of the division
   * @param lhs the lhs hand side of the division
   */
  friend constexpr auto operator/(BaseAngle<D, T> lhs, BaseAngle<D, T> const & rhs) -> T {
    return lhs.value / rhs.value;
  }

  /** 
   * Fuzzy Equals for BaseAngles
   *
   * Note: implemented as a friend function defined within the template, makes invisible to non-ADL lookup.
   *
   * @param rhs a BaseAngle
   * @param lhs a BaseAngle
   */
  friend constexpr auto equals(BaseAngle<D, T> const & rhs,BaseAngle<D, T> const & lhs) {
    return equals(rhs.value, lhs.value);
  }


private:
  Type value;
};


} // namespace math
} // namespace cagey

#endif /* CAGEY_MATH_BASEANGLE_HH_ */
