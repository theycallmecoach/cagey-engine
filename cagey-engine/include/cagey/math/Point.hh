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

namespace cagey {
namespace math {

template<typename T, std::size_t N>
class Point
{
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
  constexpr Point() noexcept;

  /**
  * Construct a Point with all elements initialized to the given value
  *
  * @param v the value to assign to all elements of this Point
  */
  explicit Point(T const v) noexcept;

  /**
  * Construct a Point using the given pointer.  Note: It assumed the given pointer contains N values;
  */
  explicit Point(T * const v) noexcept;

  /**
  * Construct a Point using the values from the given std::array
  *
  * @param vals vals[0] is assigned to data[0] etc. etc.
  */
  constexpr explicit Point(std::array<T, Size> const & vals);

  /**
  * Conversion Copy Constructor.  Construct a Point using a Point with a different
  * underlying type.  Only simple type conversion is performed
  */
  template <typename U, typename I = std::make_index_sequence<Size>>
  explicit Point(Point<U, Size> const & other);

  /**
  * Index operator
  *
  * @param i index into this Point
  * @return a reference to the element at index i
  */
  constexpr auto operator[](std::size_t i) -> T&;

  /**
  * Index operator
  *
  * @param i index into this Point
  * @return a reference to the element at index i
  */
  constexpr auto operator[](std::size_t i) const -> T&;

  /**
  * Return an iterator to the first element of this Point
  *
  * @return an iterator pointing to the begining of this Point
  */
  constexpr auto begin() noexcept -> T*;

  /**
  * Return an iterator to the first element of this Point
  *
  * @return an iterator pointing to the begining of this Point
  */
  constexpr auto begin() const noexcept -> T*;

  /**
  * Return an iterator to the end of this Point.
  *
  * @return an iterator pointing to the end of this Point
  */
  constexpr auto end() noexcept -> T*;

  /**
  * Return an iterator to the end of this Point.
  *
  * @return an iterator pointing to the end of this Point
  */
  constexpr auto end() const noexcept -> T*;

private:
  template<class U, std::size_t... I>
  constexpr explicit Point(Point<U, Size> const & other, std::index_sequence<I...>);

public:
  ///Array containing Point elements
  std::array<T, N> data;
};


/**
* Point two element specialization
*/
template<typename T>
class Point<T,2>
{
  /** @cond doxygen has issues with static_assert */
  static_assert(std::is_arithmetic<T>::value, "Underlying type must be a number");
  /** @endcond */
public:
  /// The underlying type of this Point
  using Type = T;

  /// The number of elements in this Point
  const static std::size_t Size = 2;

  /**
  * Construct a Point with all elements initialized to Zero
  */
  constexpr Point() noexcept;

  /**
  * Construct a Point with all elements initialized to the given value
  *
  * @param v the value to assign to all elements of this Point
  */
  explicit Point(T const v) noexcept;

  /**
  * Construct a Point with the given elements a and b are assigned to x and y respectively
  */
  constexpr Point(T const a, T const b) noexcept;

  /**
  * Construct a Point using the given pointer.  Note: It assumed the given pointer contains two values;
  */
  explicit Point(T * const v) noexcept;

  /**
  * Construct a Point using the values from the given std::array
  *
  * @param vals vals[0] is assigned to data[0] etc. etc.
  */
  constexpr explicit Point(std::array<T, Size> const & vals);

  /**
  * Conversion Copy Constructor.  Construct a Point using a Point with a different
  * underlying type.  Only simple type conversion is performed
  */
  template <typename U, typename I = std::make_index_sequence<Size>>
  explicit Point(Point<U, Size> const & other);

  /**
  * Index operator
  *
  * @param i index into this Point
  * @return a reference to the element at index i
  */
  constexpr auto operator[](std::size_t i) -> T&;

  /**
  * Index operator
  *
  * @param i index into this Point
  * @return a reference to the element at index i
  */
  constexpr auto operator[](std::size_t i) const -> T&;

  /**
  * Return an iterator to the first element of this Point
  *
  * @return an iterator pointing to the begining of this Point
  */
  constexpr auto begin() noexcept -> T*;

  /**
  * Return an iterator to the first element of this Point
  *
  * @return an iterator pointing to the begining of this Point
  */
  constexpr auto begin() const noexcept -> T*;

  /**
  * Return an iterator to the end of this Point.
  *
  * @return an iterator pointing to the end of this Point
  */
  constexpr auto end() noexcept -> T*;

  /**
  * Return an iterator to the end of this Point.
  *
  * @return an iterator pointing to the end of this Point
  */
  constexpr auto end() const noexcept -> T*;
public:
  /**
  * Anonymous union to allow access to members using different names
  */
  union
  {
    ///Data represented as a std::array
    std::array<T, 2> data;
    struct {
      T x; ///< The first element
      T y; ///<The second element
    };
  };

};

/**
* Point three element specialization
*/
template<typename T> class Point<T, 3>
{
  /** @cond doxygen has issues with static_assert */
  static_assert(std::is_arithmetic<T>::value, "Underlying type must be a number");
  /** @endcond */

public:
  /// The underlying type of this Point
  using Type = T;
  /// The number of elements in this Point
  static const std::size_t Size = 3;

  /**
  * Construct a Point with all elements initialized to Zero
  */
  constexpr Point() noexcept;

  /**
  * Construct a Point with all elements initialized to the given value
  *
  * @param v the value to assign to all elements of this Point
  */
  explicit Point(T const v) noexcept;

  /**
  * Construct a Point using the given pointer.  Note: It assumed the given pointer contains N values;
  */
  explicit Point(T * const v) noexcept;

  /**
  * Construct a Point with the given elements a,b,c -> x, y, z
  * @param a value to assign to x
  * @param b value to assign to y
  * @param c value to assign to z
  */
  constexpr Point(T const a, T const b, T const c) noexcept;

  /**
  * Construct a Point using the values from the given std::array
  *
  * @param vals vals[0] is assigned to data[0] etc. etc.
  */
  constexpr explicit Point(std::array<T, Size> const & vals);

  /**
  * Conversion Copy Constructor.  Construct a Point using a Point with a different
  * underlying type.  Only simple type conversion is performed
  */
  template <typename U, typename I = std::make_index_sequence<Size>>
  explicit Point(Point<U, Size> const & other);

  /**
  * Index operator
  *
  * @param i index into this Point
  * @return a reference to the element at index i
  */
  constexpr auto operator[](std::size_t i) -> T&;

  /**
  * Index operator
  *
  * @param i index into this Point
  * @return a reference to the element at index i
  */
  constexpr auto operator[](std::size_t i) const -> T&;

  /**
  * Return an iterator to the first element of this Point
  *
  * @return an iterator pointing to the begining of this Point
  */
  constexpr auto begin() noexcept -> T*;

  /**
  * Return an iterator to the first element of this Point
  *
  * @return an iterator pointing to the begining of this Point
  */
  constexpr auto begin() const noexcept -> T*;

  /**
  * Return an iterator to the end of this Point.
  *
  * @return an iterator pointing to the end of this Point
  */
  constexpr auto end() noexcept -> T*;

  /**
  * Return an iterator to the end of this Point.
  *
  * @return an iterator pointing to the end of this Point
  */
  constexpr auto end() const noexcept -> T*;

public:
  /**
  * Anonymous union to allow access to members using different names
  */
  union
  {
    ///All elements of the array
    std::array<T, 3> data;
    struct
    {
      T x; ///< First element
      T y; ///< Second element
      T z; ///< Third element
    };
    struct
    {
      T r; ///< First element
      T g; ///< Second element
      T b; ///< Third element
    };
    ///The first two elements
    Point<T, 2> xy;
  };
};

/**
* Point four element specialization
*/
template<typename T> class Point<T, 4>
{
  /** @cond doxygen has issues with static_assert */
  static_assert(std::is_arithmetic<T>::value, "Underlying type must be a number");
  /** @endcond */
public:
  /// The underlying type of this Point
  using Type = T;
  /// The number of elements in this Point
  static const std::size_t Size = 4;

  /**
  * Construct a Point with all elements initialized to Zero
  */
  constexpr Point() noexcept;

  /**
  * Construct a Point with all elements initialized to the given value
  *
  * @param v the value to assign to all elements of this Point
  */
  explicit Point(T const v) noexcept;

  /**
  * Construct a Point using the given pointer.  Note: It assumed the given pointer contains N values;
  */
  explicit Point(T * const v) noexcept;

  /**
  * Construct a Point using the values from the given std::array
  *
  * @param vals vals[0] is assigned to data[0] etc. etc.
  */
  constexpr explicit Point(std::array<T, Size> const & vals);

  /**
  * Construct a Point with the given elements a,b,c, d -> x, y, z, w
  * @param a value to assign to x
  * @param b value to assign to y
  * @param c value to assign to z
  * @param d value to assign to w
  */
  constexpr Point(T const a, T const b, T const c, T const d) noexcept;

  /**
  * Construct a Point from an existing point and a scalar
  * @param v the other Point for the x, y, z components
  * @param scalar the w component
  */
  constexpr Point(Point<T, 3> v, T scalar) noexcept;

  /**
  * Conversion Copy Constructor.  Construct a Point using a Point with a different
  * underlying type.  Only simple type conversion is performed
  */
  template <typename U, typename I = std::make_index_sequence<Size>>
  explicit Point(Point<U, Size> const & other);

  /**
  * Index operator
  *
  * @param i index into this Point
  * @return a reference to the element at index i
  */
  constexpr auto operator[](std::size_t i) -> T&;

  /**
  * Index operator
  *
  * @param i index into this Point
  * @return a reference to the element at index i
  */
  constexpr auto operator[](std::size_t i) const -> T&;

  /**
  * Return an iterator to the first element of this Point
  *
  * @return an iterator pointing to the begining of this Point
  */
  constexpr auto begin() noexcept -> T*;

  /**
  * Return an iterator to the first element of this Point
  *
  * @return an iterator pointing to the begining of this Point
  */
  constexpr auto begin() const noexcept -> T*;

  /**
  * Return an iterator to the end of this Point.
  *
  * @return an iterator pointing to the end of this Point
  */
  constexpr auto end() noexcept -> T*;

  /**
  * Return an iterator to the end of this Point.
  *
  * @return an iterator pointing to the end of this Point
  */
  constexpr auto end() const noexcept -> T*;

public:
  /**
  * Anonymous union to allow access to members using different names
  */
  union
  {
    ///All elements of the array    
    std::array<T, 4> data;
    struct
    {
      T x; ///< First Element
      T y; ///< Second Element
      T z; ///< Third Element
      T w; ///< Fourth Element
    };
    //Allow access to elements with a different name
    struct
    {
      T r; ///< First Element
      T g; ///< Second Element
      T b; ///< Third Element
      T a; ///< Fourth Element
    };
    ///The first two elements
    Point<T, 2> xy;
    ///The first three Elements
    Point<T, 3> xyz;
    ///The first Three Elements
    Point<T, 3> rgb;
  };
};



} //namespace math
} //namespace cagey

#endif //CAGEY_MATH_POINT_HH_
