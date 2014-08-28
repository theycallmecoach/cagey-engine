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

#include <cagey/math/BaseAngle.hh>

namespace cagey { 
namespace math { 

template<typename T> class Degree : public BaseAngle<Degree, T> {
public:
  constexpr Degree() {}
  constexpr explicit Degree(T val) : BaseAngle<math::Degree, T>{val} {}
  constexpr Degree(BaseAngle<math::Degree, T> const & val) : BaseAngle<math::Degree, T>{val} {}

  template<typename U>
  constexpr explicit Degree(BaseAngle<math::Degree, U> val) : BaseAngle<math::Degree, T>{val} {}
  /*constexpr Degree(Angle<Radian, T> val);*/
};

constexpr Degree<double> operator "" _deg(long double value) { return Degree<double>(value); }
constexpr Degree<float> operator "" _degf(long double value) { return Degree<float>(value); }



} // namespace math
} // namespace cagey


#endif /* CAGEY_MATH_DEGREE_HH_ */
