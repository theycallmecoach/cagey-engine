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

#ifndef CAGEY_MATH_DEGREE_HH_
#define CAGEY_MATH_DEGREE_HH_

#include <cagey/math/MathFwd.hh>
#include <cagey/math/BaseAngle.hh>
#include <cagey/math/Constants.hh>

namespace cagey { 
namespace math { 

/**
 * Represents an Angle using Degrees
 *
 * @tparam T Underlying type
 */
template<typename T> class Degree : public BaseAngle<Degree, T> {
public:
  /**
   * Default constructor.  Initializes values to 0
   */
  constexpr Degree() = default;
  
  /**
   * Value Constructor.  Initializes the angle to the given value
   *
   * @param val the value for this degree
   */
  constexpr explicit Degree(T const val) : BaseAngle<math::Degree, T>{val} {}
  
  /**
   * Conversion Constructor.  Initializes this Degree using the value from the
   * given Degree
   *
   * @tparam U an arithmatic type
   * @param val the Degree to copy
   */
  template<typename U>
  constexpr explicit Degree(BaseAngle<math::Degree, U> val) : BaseAngle<math::Degree, T>{val} {}
  
  /**
   * Convert Radian to Degree.
   * 
   * @param val radian to convert to a Degree
   */
  constexpr explicit Degree(BaseAngle<math::Radian, T> val) : BaseAngle<math::Degree, T>{T{val}*constants::radToDeg<T>}{}
};

/**
 * Literal Operator. Converts a double to a Degree
 */
constexpr Degree<double> operator "" _deg(long double value) { return Degree<double>(value); }

/**
 * Literal Operator. Converts a float to a Degree
 */
constexpr Degree<float> operator "" _degf(long double value) { return Degree<float>(value); }

} // namespace math
} // namespace cagey


#endif /* CAGEY_MATH_DEGREE_HH_ */
