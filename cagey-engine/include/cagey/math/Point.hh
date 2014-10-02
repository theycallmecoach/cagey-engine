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

#ifndef CAGEY_MATH_POINT_HH_
#define CAGEY_MATH_POINT_HH_

#include <cagey/math/BasePoint.hh>

namespace cagey {
namespace math {

template<typename T, std::size_t N>
class Point : public BasePoint<Point, T, N> {
public:
  /** @cond doxygen has some issues with static assert */
  static_assert(N != 0, "Point cannot have zero elements");
  static_assert(std::is_arithmetic<T>::value, "Underlying type must be a number");
  /** @endcond */

  /// The underlying type of this Point
  using Type = T;

  /// The number of elements in this Point
  const static std::size_t Size = N;

  /**
  * Construct a Point with all elements initialized to Zero
  */
  constexpr Point() noexcept = default;

  /**
  * Construct a Point with all elements initialized to the given value
  *
  * @param v the value to assign to all elements of this Point
  */
  explicit Point(T const v) noexcept : BasePoint<math::Point, T, N>{v} {};

  /**
  * Construct a Point using the given pointer.  Note: It assumed the given pointer contains N values;
  */
  explicit Point(T * const v) noexcept : BasePoint<math::Point, T, N>{v} {};

  /**
  * Construct a Point using the values from the given std::array
  *
  * @param vals vals[0] is assigned to data[0] etc. etc.
  */
  constexpr explicit Point(std::array<T, Size> const & vals) : BasePoint<math::Point, T, N>{vals} {};

  /**
  * Conversion Copy Constructor.  Construct a Point using a Point with a different
  * underlying type.  Only simple type conversion is performed
  */
  template <typename U>
  explicit Point(Point<U, Size> const & other) : BasePoint<math::Point, U, N>{other} {};

public:
  ///Array containing Point elements
  std::array<T, N> data;
};


/**
* Point two element specialization
*/
template<typename T>
class Point<T,2> : public BasePoint<Point, T, 2>
{
  /** @cond doxygen has issues with static_assert */
  static_assert(std::is_arithmetic<T>::value, "Underlying type must be a number");
  /** @endcond */
public:
  /// The number of elements in this BasePoint
  const static std::size_t Size = 2;

  /**
  * Construct a Point with all elements initialized to Zero
  */
  constexpr Point() noexcept = default;

  /**
  * Construct a Point with all elements initialized to the given value
  *
  * @param v the value to assign to all elements of this Point
  */
  explicit Point(T const v) noexcept : BasePoint<math::Point, T, Size>{v} {};

  /**
  * Construct a Point with the given elements a and b are assigned to x and y respectively
  */
  constexpr Point(T const a, T const b) noexcept : BasePoint<math::Point, T, Size>{a, b} {};

  /**
  * Construct a Point using the given pointer.  Note: It assumed the given pointer contains two values;
  */
  explicit Point(T * const v) noexcept : BasePoint<math::Point, T, Size>{v} {};

  /**
  * Construct a Point using the values from the given std::array
  *
  * @param vals vals[0] is assigned to data[0] etc. etc.
  */
  constexpr explicit Point(std::array<T, Size> const & vals) : BasePoint<math::Point, T, Size>{vals} {};

  /**
  * Conversion Copy Constructor.  Construct a Point using a Point with a different
  * underlying type.  Only simple type conversion is performed
  */
  template <typename U>
  explicit Point(Point<U, Size> const & other) : BasePoint<math::Point, T, Size>{other} {};
};


/**
* Point three element specialization
*/
template<typename T>
class Point<T,3> : public BasePoint<Point, T, 3>
{
  /** @cond doxygen has issues with static_assert */
  static_assert(std::is_arithmetic<T>::value, "Underlying type must be a number");
  /** @endcond */
public:
  /// The number of elements in this BasePoint
  const static std::size_t Size = 3;

  /**
  * Construct a Point with all elements initialized to Zero
  */
  constexpr Point() noexcept = default;

  /**
  * Construct a Point with all elements initialized to the given value
  *
  * @param v the value to assign to all elements of this Point
  */
  explicit Point(T const v) noexcept : BasePoint<math::Point, T, Size>{v} {};

  /**
  * Construct a Point with the given elements a and b and c are assigned to x y an z respectively
  */
  constexpr Point(T const a, T const b, T const c) noexcept : BasePoint<math::Point, T, Size>{a, b,c} {};

  /**
  * Construct a Point using the given pointer.  Note: It assumed the given pointer contains two values;
  */
  explicit Point(T * const v) noexcept : BasePoint<math::Point, T, Size>{v} {};

  /**
  * Construct a Point using the values from the given std::array
  *
  * @param vals vals[0] is assigned to data[0] etc. etc.
  */
  constexpr explicit Point(std::array<T, Size> const & vals) : BasePoint<math::Point, T, Size>{vals} {};

  /**
  * Conversion Copy Constructor.  Construct a Point using a Point with a different
  * underlying type.  Only simple type conversion is performed
  */
  template <typename U>
  explicit Point(Point<U, Size> const & other) : BasePoint<math::Point, T, Size>{other} {};
};

template<typename T> using Point2 = Point<T,2>;
template<typename T> using Point3 = Point<T,3>;
template<typename T> using Point4 = Point<T,4>;

using Point2u = Point<unsigned, 2>;
using Point2i = Point<int, 2>;
using Point2f = Point<float, 2>;
using Point2d = Point<double, 2>;

using Point3u = Point<unsigned, 3>;
using Point3i = Point<int, 3>;
using Point3f = Point<float, 3>;
using Point3d = Point<double, 3>;

} //namespace math
} //namespace cagey

#endif //CAGEY_MATH_POINT_HH_
