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

#ifndef CAGEY_MATH_CONSTANTS_HH_
#define CAGEY_MATH_CONSTANTS_HH_

namespace cagey { 
namespace math { 
namespace constants {

  /**
   * The mystical value of pi (3.14....) to the accuracy of T.
   *
   * @tparam T the desired type of Pi
   */
  template<typename T>
  constexpr T pi = T(3.141592653589793238462643383279502884);

  /**
   * Value to convert between degrees and radians.
   * Equivalent to pi / 180
   
   * @tparam T the desired type of converstion value
   */
  template <typename T>
  constexpr T degToRad = pi<T> / T(180.0);

  /**
   * Value to convert between radians and degrees.
   * Equivalent to 180 / pi
   *
   * @tparam T the desired type of converstion value
   */
  template <typename T>
  constexpr T radToDeg = T(180.0) / pi<T>;

}  // namespace constants
}  // namespace math 
}  // namespace cagey

#endif /* CAGEY_MATH_CONSTANTS_HH_ */
