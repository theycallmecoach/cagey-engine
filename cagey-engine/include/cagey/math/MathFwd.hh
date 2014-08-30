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

#ifndef CAGEY_MATH_MATH_HH_
#define CAGEY_MATH_MATH_HH_

#include <cstddef>

namespace cagey { 
namespace math { 

template<typename> class Degree;
template<typename> class Radian;

template<typename T> using Degf = Degree<float>;
template<typename T> using Degd = Degree<double>;

template<typename T> using Radf = Radian<float>;
template<typename T> using Radd = Radian<double>;

template<typename, std::size_t> class Vector;
template<typename T> using Vec2 = Vector<T,2>;
template<typename T> using Vec3 = Vector<T,3>;
template<typename T> using Vec4 = Vector<T,4>;

using Vec2u = Vector<unsigned, 2>;
using Vec2i = Vector<int, 2>;
using Vec2f = Vector<float, 2>;
using Vec2d = Vector<double, 2>;

using Vec3u = Vector<unsigned, 3>;
using Vec3i = Vector<int, 3>;
using Vec3f = Vector<float, 3>;
using Vec3d = Vector<double, 3>;

using Vec4u = Vector<unsigned, 4>;
using Vec4i = Vector<int, 4>;
using Vec4f = Vector<float, 4>;
using Vec4d = Vector<double, 4>;

} // namespace math
} // namespace cagey

#endif /* CAGEY_MATH_MATH_HH_ */
