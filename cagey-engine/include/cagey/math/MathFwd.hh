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

/** 
 * @file
 * Forward declarations for the cagey::math namespace
 */

#ifndef CAGEY_MATH_MATH_HH_
#define CAGEY_MATH_MATH_HH_

#include <cstdint>
#include <cstddef>

/**
 * Namespace to contain all cagey 
 */
namespace cagey { 
/**
 * Namespace for all Math related classes
 */
namespace math { 

template<typename> class Degree;
template<typename> class Radian;


///Shorthand for float Degree template
template<typename T> using Degf = Degree<float>;
///Shorthand for double Degree template
template<typename T> using Degd = Degree<double>;
///Shorthand for float Radian template
template<typename T> using Radf = Radian<float>;
///Shorthand for double Radian template
template<typename T> using Radd = Radian<double>;


template<typename, std::size_t> class Point;
///Shorthand for the two element Point
template<typename T> using Point2 = Point<T,2>;
///Shorthand for the three element Point
template<typename T> using Point3 = Point<T,3>;
///Shorthand for the four element Point
template<typename T> using Point4 = Point<T,4>;

///Shorthand for the two element unsigned Point
using Point2u = Point<std::uint32_t, 2>;
///Shorthand for the two element int Point
using Point2i = Point<std::int32_t, 2>;
///Shorthand for the two element float Point
using Point2f = Point<float, 2>;
///Shorthand for the two element double Point
using Point2d = Point<double, 2>;

///Shorthand for the three element unsigned Point
using Point3u = Point<std::uint32_t, 3>;
///Shorthand for the three element int Point
using Point3i = Point<std::int32_t, 3>;
///Shorthand for the three element float Point
using Point3f = Point<float, 3>;
///Shorthand for the three element double Point
using Point3d = Point<double, 3>;


template<typename, std::size_t> class Vector;
///Shorthand for the two element Vector
template<typename T> using Vec2 = Vector<T,2>;
///Shorthand for the three element Vector
template<typename T> using Vec3 = Vector<T,3>;
///Shorthand for the four element Vector
template<typename T> using Vec4 = Vector<T,4>;

///Shorthand for the two element unsigned Vector
using Vec2u = Vector<std::uint32_t, 2>;
///Shorthand for the two element int Vector
using Vec2i = Vector<std::int32_t, 2>;
///Shorthand for the two element float Vector
using Vec2f = Vector<float, 2>;
///Shorthand for the two element double Vector
using Vec2d = Vector<double, 2>;

///Shorthand for the three element unsigned Vector
using Vec3u = Vector<std::uint32_t, 3>;
///Shorthand for the three element int Vector
using Vec3i = Vector<std::int32_t, 3>;
///Shorthand for the three element float Vector
using Vec3f = Vector<float, 3>;
///Shorthand for the three element double Vector
using Vec3d = Vector<double, 3>;


///Shorthand for the four element unsigned Vector
using Vec4u = Vector<std::uint32_t, 4>;
///Shorthand for the four element int Vector
using Vec4i = Vector<std::int32_t, 4>;
///Shorthand for the four element float Vector
using Vec4f = Vector<float, 4>;
///Shorthand for the four element double Vector
using Vec4d = Vector<double, 4>;

template<typename, std::size_t, std::size_t> class Matrix;
///Shorthand for 2x2 square matrix
template<typename T> using Mat2 = Matrix<T, 2, 2>;
///Shorthand for 3x3 square matrix
template<typename T> using Mat3 = Matrix<T, 3, 3>;
///Shorthand for 4x4 square matrix
template<typename T> using Mat4 = Matrix<T, 4, 4>;

///Shorthand for 2x2 square int matrix
using Mat2i = Matrix<std::int32_t, 2, 2>;
///Shorthand for 2x2 square int matrix
using Mat3i = Matrix<std::int32_t, 3, 3>;
///Shorthand for 2x2 square int matrix
using Mat4i = Matrix<std::int32_t, 4, 4>;

///Shorthand for 2x2 square float matrix
using Mat2f = Matrix<float, 2, 2>;
///Shorthand for 3x3 square float matrix
using Mat3f = Matrix<float, 3, 3>;
///Shorthand for 4x4 square float matrix
using Mat4f = Matrix<float, 4, 4>;

///Shorthand for 2x2 square double matrix
using Mat2d = Matrix<double, 2, 2>;
///Shorthand for 3x3 square double matrix
using Mat3d = Matrix<double, 3, 3>;
///Shorthand for 4x4 square double matrix
using Mat4d = Matrix<double, 4, 4>;


} // namespace math
} // namespace cagey

#endif /* CAGEY_MATH_MATH_HH_ */
