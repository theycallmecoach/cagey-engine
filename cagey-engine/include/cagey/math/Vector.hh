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

#ifndef CAGEY_MATH_VECTOR_HH_
#define CAGEY_MATH_VECTOR_HH_

#include <cstddef> //for std::size_t
#include <array> //for std::array
#include <algorithm> //for std::transform, std::negate, std::equal
#include <numeric> //for std::numeric_limits
#include <cmath> //for std::abs
#include <utility> //for std::index_sequence
#include <iostream>


namespace cagey
{
namespace math
{

template<typename T, std::size_t N>
class Vector
{
public:
  static_assert(N != 0, "Vector cannot have zero elements");
  static_assert(std::is_arithmetic<T>::value, "Underlying type must be a number");

  /// The underlying type of this Vector
  using Type = T;

  /// The number of elements in this Vector
  const static std::size_t Size = N;

  /**
   * Construct a Vector with all elements initialized to Zero
   */
  constexpr Vector() noexcept;

  /**
   * Construct a Vector with all elements initialized to the given value
   *
   * @param v the value to assign to all elements of this Vector
   */
  explicit Vector(T const v) noexcept;

  /**
   * Construct a Vector using the given pointer.  Note: It assumed the given pointer contains N values;
   */
  explicit Vector(T * const v) noexcept;

  /**
   * Construct a Vector using the values from the given std::array
   *
   * @param vals vals[0] is assigned to data[0] etc. etc.
   */
  constexpr explicit Vector(std::array<T, Size> const & vals);

  template <typename U, typename I = std::make_index_sequence<Size>>
  explicit Vector(Vector<U, Size> const & other);

  constexpr auto operator[](std::size_t i) -> T&;
  constexpr auto operator[](std::size_t i) const -> T&;

  constexpr auto begin() noexcept -> T*;
  constexpr auto begin() const noexcept -> T*;
  constexpr auto end() noexcept -> T*;
  constexpr auto end() const noexcept -> T*;

private:
  template<class U, std::size_t... I>
  constexpr explicit Vector(Vector<U, Size> const & other, std::index_sequence<I...>);

public:
  std::array<T, N> data;
};


template<typename T>
class Vector<T,2>
{
  static_assert(std::is_arithmetic<T>::value, "Underlying type must be a number");
public:
  /// The underlying type of this Vector
  using Type = T;

  /// The number of elements in this Vector
  const static std::size_t Size = 2;

  /**
   * Construct a Vector with all elements initialized to Zero
   */
  constexpr Vector() noexcept;

  /**
   * Construct a Vector with all elements initialized to the given value
   *
   * @param v the value to assign to all elements of this Vector
   */
  explicit Vector(T const v) noexcept;

  /**
   * Construct a Vector with the given elements a and b are assigned to x and y respectively
   */
  constexpr Vector(T const a, T const b) noexcept;

  /**
   * Construct a Vector using the given pointer.  Note: It assumed the given pointer contains two values;
   */
  explicit Vector(T * const v) noexcept;

  /**
   * Construct a Vector using the values from the given std::array
   *
   * @param vals vals[0] is assigned to data[0] etc. etc.
   */
  constexpr explicit Vector(std::array<T, Size> const & vals);

  template <typename U, typename I = std::make_index_sequence<Size>>
  explicit Vector(Vector<U, Size> const & other);

  constexpr auto operator[](std::size_t i) -> T&;
  constexpr auto operator[](std::size_t i) const -> T&;

  constexpr auto begin() noexcept -> T*;
  constexpr auto begin() const noexcept -> T*;
  constexpr auto end() noexcept -> T*;
  constexpr auto end() const noexcept -> T*;
public:
  union
  {
    std::array<T, 2> data;
    struct { T x, y; };
  };

};

template<typename T> class Vector<T, 3>
{
  static_assert(std::is_arithmetic<T>::value, "Underlying type must be a number");
public:
  /// The underlying type of this Vector
  using Type = T;
  /// The number of elements in this Vector
  static const std::size_t Size = 3;

  /**
   * Construct a Vector with all elements initialized to Zero
   */
  constexpr Vector() noexcept;

  /**
   * Construct a Vector with all elements initialized to the given value
   *
   * @param v the value to assign to all elements of this Vector
   */
  explicit Vector(T const v) noexcept;

  /**
   * Construct a Vector using the given pointer.  Note: It assumed the given pointer contains N values;
   */
  explicit Vector(T * const v) noexcept;

  /**
   * Construct a Vector with the given elements a,b,c -> x, y, z
   * @param a value to assign to x
   * @param b value to assign to y
   * @param c value to assign to z
   */
  constexpr Vector(T const a, T const b, T const c) noexcept;

  /**
   * Construct a Vector using the values from the given std::array
   *
   * @param vals vals[0] is assigned to data[0] etc. etc.
   */
  constexpr explicit Vector(std::array<T, Size> const & vals);

  template <typename U, typename I = std::make_index_sequence<Size>>
  explicit Vector(Vector<U, Size> const & other);

  constexpr auto operator[](std::size_t i) -> T&;
  constexpr auto operator[](std::size_t i) const -> T&;

  constexpr auto begin() noexcept -> T*;
  constexpr auto begin() const noexcept -> T*;
  constexpr auto end() noexcept -> T*;
  constexpr auto end() const noexcept -> T*;

public:
  union
  {
    std::array<T, 3> data;
    struct
    {
      T x, y, z;
    };
    struct
    {
      T r, g, b;
    };
    Vector<T, 2> xy;
  };
};

template<typename T> class Vector<T, 4>
{
  static_assert(std::is_arithmetic<T>::value, "Underlying type must be a number");
public:
  /// The underlying type of this Vector
  using Type = T;
  /// The number of elements in this Vector
  static const std::size_t Size = 4;

  /**
   * Construct a Vector with all elements initialized to Zero
   */
  constexpr Vector() noexcept;

  /**
   * Construct a Vector with all elements initialized to the given value
   *
   * @param v the value to assign to all elements of this Vector
   */
  explicit Vector(T const v) noexcept;

  /**
   * Construct a Vector using the given pointer.  Note: It assumed the given pointer contains N values;
   */
  explicit Vector(T * const v) noexcept;

  /**
   * Construct a Vector using the values from the given std::array
   *
   * @param vals vals[0] is assigned to data[0] etc. etc.
   */
  constexpr explicit Vector(std::array<T, Size> const & vals);

  /**
   * Construct a Vector with the given elements a,b,c, d -> x, y, z, w
   * @param a value to assign to x
   * @param b value to assign to y
   * @param c value to assign to z
   * @param d value to assign to w
   */
  constexpr Vector(T const a, T const b, T const c, T const d) noexcept;

  /**
   * Construct a Vector from an existing vector and a scalar
   * @param v the other Vector for the x, y, z components
   * @param scalar the w component
   */
  constexpr Vector(Vector<T, 3> v, T scalar) noexcept;

  template <typename U, typename I = std::make_index_sequence<Size>>
  explicit Vector(Vector<U, Size> const & other);

  constexpr auto operator[](std::size_t i) -> T&;
  constexpr auto operator[](std::size_t i) const -> T&;

  constexpr auto begin() noexcept -> T*;
  constexpr auto begin() const noexcept -> T*;
  constexpr auto end() noexcept -> T*;
  constexpr auto end() const noexcept -> T*;

public:
  union
  {
    std::array<T, 4> data;
    struct
    {
      T x, y, z, w;
    };
    struct
    {
      T r, g, b, a;
    };
    Vector<T, 2> xy;
    Vector<T, 3> xyz;
    Vector<T, 3> rgb;
  };
};


template<typename T> using Vec2 = Vector<T,2>;
template<typename T> using Vec3 = Vector<T,3>;
template<typename T> using Vec4 = Vector<T,4>;


/**
 * Return the length(magnitude) of the vector
 *
 * Note: involves a square root
 */
template<typename T, std::size_t S>
auto length(Vector<T, S> const & rhs) -> T {
  using std::sqrt;
  return sqrt(dot(rhs, rhs));
}

template<typename T, std::size_t S>
auto equals(Vector<T, S> const & lhs, Vector<T, S> const & rhs, T const epsilon = std::numeric_limits<T>::epsilon()) -> bool {
  return std::equal(lhs.begin(), lhs.end(), rhs.begin(),
      [epsilon] (T r, T l) { using std::abs; return static_cast<T>(abs(l - r)) <= epsilon; });
}

template<typename T, std::size_t S>
auto dot(Vector<T, S> const & lhs, Vector<T, S> const & rhs) -> T {
  return std::inner_product(lhs.begin(), rhs.begin(), rhs.begin(), T{0});
}

template<typename T, std::size_t S>
auto dotAbsolute(Vector<T, S> const & lhs, Vector<T, S> const & rhs) -> T {
  std::inner_product(lhs.begin(), lhs.end(), lhs.begin(), T{0}, std::plus<T>(), [](T l, T r) -> T { return std::abs(l * r);});
}

template<typename T>
auto cross(Vec2<T> const rhs, Vec2<T> const & lhs) -> T {
  return lhs.x*rhs.y-lhs.y*rhs.x;
}

template<typename T>
auto cross(Vec3<T> const rhs, Vec3<T> const & lhs) -> Vector<T,3> {
  return Vec3<T>{lhs.y*rhs.z-lhs.z*rhs.y,
                      lhs.z*rhs.x-lhs.x*rhs.z,
                      lhs.x*rhs.y-lhs.y*rhs.x
  };
}

/**
 * Normalize the given vector or make a unit vector.
 * If the length is zero returns the given vector unmodified
 *
 * @param the vector to normalize
 */
template<typename T, std::size_t S>
auto normalize(Vector<T, S> const vec) -> Vector<T, S> {
  T len = length(vec);
  if (len > 0) {
    vec *= (T{1} / len);
  } else {
    //bad things happen... zero length vector;
  }
  return vec;
}

/**
 * Swap the contents of the two vectors
 */
template<typename T, std::size_t S>
auto swap(Vector<T, S> & rhs, Vector<T, S> & lhs) -> void {
  std::swap(rhs.data, lhs.data);
}


template<typename T, std::size_t S>
inline auto isZeroLength(Vector<T, S> const & vec) -> bool {
  T epsilon = std::numeric_limits<T>::epsilon();
  return std::abs(lengthSquared(vec)) < (epsilon * epsilon);
}

template<typename T, std::size_t S>
inline auto lengthSquared(Vector<T,S> const & vec) -> T {
  return cagey::math::dot(vec,vec);
}

template<typename T, std::size_t S>
inline auto min(Vector<T, S> const & vec) -> T {
  return *std::min_element(std::begin(vec), std::end(vec));
}

template<typename T, std::size_t S>
inline auto max(Vector<T, S> const & vec) -> T {
  return *std::max_element(std::begin(vec), std::end(vec));
}

template<typename T, std::size_t S>
inline auto sum(Vector<T, S> const & vec) -> T {
  return std::accumulate(std::begin(vec), std::end(vec), T(0));
}

template<typename T, std::size_t S>
inline auto distance(Vector<T, S> const & lhs, Vector<T, S> const & rhs) -> T {
  return length(lhs -rhs);
}

template<typename T, std::size_t S>
inline auto distanceSquared(Vector<T, S> const & lhs, Vector<T, S> const & rhs) -> T {
  return lengthSquared(lhs -rhs);
}


//////////////////////////////////////////////////////////////////////////////
// Vector() Impl
//////////////////////////////////////////////////////////////////////////////
template<typename T, std::size_t S>
inline constexpr Vector<T,S>::Vector() noexcept : data() {};

template<typename T>
inline constexpr Vector<T,2>::Vector() noexcept : data() {};

template<typename T>
inline constexpr Vector<T,3>::Vector() noexcept : data() {};

template<typename T>
inline constexpr Vector<T,4>::Vector() noexcept : data() {};


//////////////////////////////////////////////////////////////////////////////
// Vector(T) Impl
//////////////////////////////////////////////////////////////////////////////


template<typename T, std::size_t S>
inline Vector<T,S>::Vector(T const v) noexcept  { data.fill(v); }

template<typename T>
inline Vector<T,2>::Vector(T const v) noexcept  { data.fill(v); }

template<typename T>
inline Vector<T,3>::Vector(T const v) noexcept  { data.fill(v); }

template<typename T>
inline Vector<T,4>::Vector(T const v) noexcept  { data.fill(v); }


//////////////////////////////////////////////////////////////////////////////
// Vector() Component Impl
//////////////////////////////////////////////////////////////////////////////

template<typename T>
inline constexpr Vector<T,2>::Vector(T const a, T const b) noexcept  : x{a}, y{b} {}

template<typename T>
inline constexpr Vector<T,3>::Vector(T const a, T const b, T const c) noexcept  : x{a}, y{b}, z{c} {}

template<typename T>
inline constexpr Vector<T,4>::Vector(T const a, T const b, T const c, T const d) noexcept  : x{a}, y{b}, z{c}, w{d} {}


//////////////////////////////////////////////////////////////////////////////
// Vector(T*) Impl
//////////////////////////////////////////////////////////////////////////////

template<typename T, std::size_t S>
inline Vector<T,S>::Vector(T * const v) noexcept {
  std::copy(std::begin(v), std::end(v), data.begin());
}

template<typename T>
inline Vector<T,2>::Vector(T * const v) noexcept : x{v[0]}, y{v[1]} {}

template<typename T>
inline Vector<T,3>::Vector(T * const v) noexcept : x{v[0]}, y{v[1]}, z{v[2]} {}

template<typename T>
inline Vector<T,4>::Vector(T * const v) noexcept : x{v[0]}, y{v[1]}, z{v[2]}, w{v[3]} {}

//////////////////////////////////////////////////////////////////////////////
// Vector(std::array) Impl
//////////////////////////////////////////////////////////////////////////////

template<typename T, std::size_t S>
inline constexpr Vector<T, S>::Vector(std::array<T, Size> const & vals) : data(vals) {}

template<typename T>
inline constexpr Vec2<T>::Vector(std::array<T, Size> const & vals) : data(vals) {}

template<typename T>
inline constexpr Vec3<T>::Vector(std::array<T, Size> const & vals) : data(vals) {}

template<typename T>
inline constexpr Vec4<T>::Vector(std::array<T, Size> const & vals) : data(vals) {}

//////////////////////////////////////////////////////////////////////////////
// Vector(Vector<U>) Impl
//////////////////////////////////////////////////////////////////////////////

template <typename T, size_t S>
template <typename U, typename I>
inline Vector<T, S>::Vector(Vector<U, Size> const & other)
 : Vector(other, I()) {}

template <typename T, size_t S>
template <typename U, std::size_t... I>
inline constexpr Vector<T, S>::Vector(Vector<U, Size> const & other, std::index_sequence<I...>)
 : data {{(T(other.data[I]))...}} {}

template <typename T>
template <typename U, typename I>
inline Vec2<T>::Vector(Vector<U, Size> const & other)
 : Vector(T(other[0]), T(other[1])) {}

template <typename T>
template <typename U, typename I>
inline Vec3<T>::Vector(Vector<U, Size> const & other)
 : Vector(T(other[0]), T(other[1]), T(other[2])) {}

template <typename T>
template <typename U, typename I>
inline Vec4<T>::Vector(Vector<U, Size> const & other)
 : Vector(T(other[0]), T(other[1]), T(other[2]), T(other[3])) {}



//////////////////////////////////////////////////////////////////////////////
// Vector::operator[] Impl
//////////////////////////////////////////////////////////////////////////////


template<typename T, std::size_t S>
inline constexpr auto Vector<T, S>::operator[](std::size_t i) -> T& {
  return data[i];
}

template<typename T>
inline constexpr auto Vec2<T>::operator[](std::size_t i) -> T& {
  return data[i];
}

template<typename T>
inline constexpr auto Vec3<T>::operator[](std::size_t i) -> T& {
  return data[i];
}

template<typename T>
inline constexpr auto Vec4<T>::operator[](std::size_t i) -> T& {
  return data[i];
}

template<typename T, std::size_t S>
inline constexpr auto Vector<T, S>::operator[](std::size_t i) const -> T& {
  return data[i];
}

template<typename T>
inline constexpr auto Vec2<T>::operator[](std::size_t i) const -> T& {
  return data[i];
}

template<typename T>
inline constexpr auto Vec3<T>::operator[](std::size_t i) const -> T& {
  return data[i];
}

template<typename T>
inline constexpr auto Vec4<T>::operator[](std::size_t i) const -> T& {
  return data[i];
}


//////////////////////////////////////////////////////////////////////////////
// Vector::begin() Impl
//////////////////////////////////////////////////////////////////////////////

template<typename T, std::size_t S>
inline constexpr auto Vector<T, S>::begin() noexcept -> T* { return data.begin(); }

template<typename T>
inline constexpr auto Vec2<T>::begin() noexcept -> T* { return data.begin(); }

template<typename T>
inline constexpr auto Vec3<T>::begin() noexcept -> T* { return data.begin(); }

template<typename T>
inline constexpr auto Vec4<T>::begin() noexcept -> T* { return data.begin(); }

template<typename T, std::size_t S>
inline constexpr auto Vector<T, S>::begin() const  noexcept -> T* { return data.begin(); }

template<typename T>
inline constexpr auto Vec2<T>::begin() const  noexcept -> T* { return data.begin(); }

template<typename T>
inline constexpr auto Vec3<T>::begin() const  noexcept -> T* { return data.begin(); }

template<typename T>
inline constexpr auto Vec4<T>::begin() const  noexcept -> T* { return data.begin(); }


//////////////////////////////////////////////////////////////////////////////
// Vector::end() Impl
//////////////////////////////////////////////////////////////////////////////

template<typename T, std::size_t S>
inline constexpr auto Vector<T, S>::end() noexcept -> T* { return data.end(); }

template<typename T>
inline constexpr auto Vec2<T>::end() noexcept -> T* { return data.end(); }

template<typename T>
inline constexpr auto Vec3<T>::end() noexcept -> T* { return data.end(); }

template<typename T>
inline constexpr auto Vec4<T>::end() noexcept -> T* { return data.end(); }


template<typename T, std::size_t S>
inline constexpr auto Vector<T, S>::end() const noexcept -> T* { return data.end(); }

template<typename T>
inline constexpr auto Vec2<T>::end() const noexcept -> T* { return data.end(); }

template<typename T>
inline constexpr auto Vec3<T>::end() const noexcept -> T* { return data.end(); }

template<typename T>
inline constexpr auto Vec4<T>::end() const noexcept -> T* { return data.end(); }


//////////////////////////////////////////////////////////////////////////////
// Vector::operator+= Impl
//////////////////////////////////////////////////////////////////////////////

template<typename T, std::size_t S>
inline auto operator+=(Vector<T,S> & lhs, Vector<T,S> & rhs) -> void {
  std::transform(lhs.begin(), lhs.end(), rhs.begin(), lhs.begin(), [](T l, T r) -> T { return l + r; } );
}

//////////////////////////////////////////////////////////////////////////////
// Vector::operator-= Impl
//////////////////////////////////////////////////////////////////////////////

template<typename T, std::size_t S>
inline auto operator-=(Vector<T,S> & lhs, Vector<T,S> & rhs) -> void {
  std::transform(lhs.begin(), lhs.end(), rhs.begin(), lhs.begin(), [](T l, T r) -> T { return l - r; } );
}

//////////////////////////////////////////////////////////////////////////////
// Vector::operator*= Impl
//////////////////////////////////////////////////////////////////////////////

template<typename T, std::size_t S>
inline auto operator*=(Vector<T, S> & lhs, T value) -> void {
  std::for_each(lhs.begin(), lhs.end(), [value](T&t) { t*=value; });
}

//////////////////////////////////////////////////////////////////////////////
// Vector::operator/= Impl
//////////////////////////////////////////////////////////////////////////////

template<typename T, std::size_t S>
inline auto operator/=(Vector<T, S> & lhs, T value) -> void {
  std::for_each(lhs.begin(), lhs.end(), [value](T&t) { t/=value; });
}



template<typename T, std::size_t S>
auto operator==(Vector<T, S> const & rhs, Vector<T, S> const & lhs) -> Vector<T, S> {
  return rhs.data == rhs.data;
}

template<typename T, std::size_t S>
auto operator!=(Vector<T, S> const & rhs, Vector<T, S> const & lhs) -> Vector<T, S> {
  return !(rhs.data == rhs.data);
}

template<typename T, std::size_t S>
auto operator+(Vector<T, S> rhs, Vector<T, S> const & lhs) -> Vector<T, S> {
  rhs += lhs;
  return rhs;
}

template<typename T, std::size_t S>
auto operator-(Vector<T, S> vec) -> Vector<T, S> {
  std::transform(vec.begin(), vec.end(), vec.begin(), std::negate<T>());
  return vec;
}

template<typename T, std::size_t S>
auto operator-(Vector<T, S> rhs, Vector<T, S> const & lhs) -> Vector<T, S> {
  rhs -= lhs;
  return rhs;
}

template<typename T, std::size_t S>
auto operator*(Vector<T, S> rhs, T lhs) -> Vector<T, S> {
  rhs *= lhs;
  return rhs;
}

template<typename T, std::size_t S>
auto operator/(Vector<T, S> rhs, T lhs) -> Vector<T, S> {
  rhs /= lhs;
  return rhs;
}

template <typename T, std::size_t S>
std::ostream &operator<<(std::ostream &sink, Vector<T,S> const &vec) {
    sink << "( ";
    std::for_each(vec.begin(), vec.end()-1, [&sink](T&v) { sink << v << ", ";});
    sink << vec[S-1] << " )";
    return sink;
}

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

//#pragma clang diagnostic pop


#endif /* KGML_MATH_VECTOR_HH_ */