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
 * @ref cagey::math::Matrix classes.
 */

#ifndef CAGEY_MATH_MATRIX_HH_
#define CAGEY_MATH_MATRIX_HH_

#include <cstddef>
#include <array>
#include <algorithm>
#include <utility>
#include <iostream>

#include "cagey/math/Vector.hh"

namespace cagey {
namespace math {

/**
 * Use this type to construct an identity matrix
 */
enum class IdentityTag { Identity };

/**
 * @class Matrix 
 * Base Matrix class with R rows and C columns.  Matrix uses column vectors.
 * 
 * The idea here is to use template specializations to implement Matrices of 
 * different size.  To DRY up the code as much as possble the smallest set of 
 * methods possible will be implemented... all other are free functions.  So
 * the idea goes... it might get annoying I don't know yet. 
 * 
 * @tparam T underlying data type of this matrix
 * @tparam R the number of rows in this matrix
 * @tparam C the number of columns in this matrix
 */
template<typename T, std::size_t R, std::size_t C>
class Matrix {
  /** @cond doxygen has an issue with static assert */
  static_assert(C*R > 0, "Cannot have a zero sized matrix");
  static_assert(std::is_arithmetic<T>::value, "Underlying type must be a number");
  /** @endcond */


public:
  /// The Underlying type of this matrix
  using Type = T;
  /// the number of rows in this matrix
  static const int Rows = R;
  /// the number of columns in this matrix
  static const int Cols = C;
  /// the number of elements in this matrix
  static const int Size = Rows * Cols;

  /**
   * Default constructor.  Initializes to the identity matrix
   * 
   */
  constexpr explicit Matrix(IdentityTag = IdentityTag::Identity);

  /**
   * Constructs a matrix filling the first num elements with given value
   *
   * @param val the number to initialize this matrix
   * @param num the number of elements to initialize with num
   */
  Matrix(T const val, std::size_t num = Size);

  /**
   * Construct a matrix from a std::array
   *
   * @param other an array of values to initialize this matrix
   */
  constexpr explicit Matrix(std::array<T, Size> const & other);

  /**
   * Construct a matrix using a Matrix of the same size but different type.
   * 
   * Only does the basic casting from type T to type U
   * 
   * @param other a matrix with a different type
   */
  template <typename U, typename I = std::make_index_sequence<Size>>
  constexpr explicit Matrix(Matrix<U, Rows, Cols> const & other);

  /**
   * Copy Constructor.
   *
   * @param other the other matrix
   */
  constexpr Matrix(Matrix const & other) = default;

  /**
   * Index Operator.
   * 
   * @param i index into this matrix, must be less than Size
   * @return a reference to the value at index i
   */
  constexpr auto operator[](std::size_t i) -> T&;

  /**
   * Index Operator.
   * 
   * @param i index into this matrix, must be less than Size
   * @return a reference to the value at index i
   */
  constexpr auto operator[](std::size_t i) const -> T const &;

  /**
   * Matrix Index Operator
   * 
   * @param r row index must be less than Rows
   * @param c column index must be less than Cols
   * @return a reference to the value at row index r and column index c
   */
  constexpr auto operator()(std::size_t r, std::size_t c) -> T&;

  /**
   * Matrix Index Operator
   * 
   * @param r row index must be less than Rows
   * @param c column index must be less than Cols
   * @return a reference to the value at row index r and column index c   */
  constexpr auto operator()(std::size_t r, std::size_t c) const -> T const &;

  /**
   * Return an iterator to the first element of the data array
   * @return an interator
   */
  constexpr auto begin()  noexcept-> T*;

  /**
   * Return an iterator to the first element of the data array
   * @return an interator
   */
  constexpr auto begin() const noexcept -> T const *;

  /**
   * Return an iterator to the end of the data array
   * @return an interator (one-past-the-end)
   */
  constexpr auto end()  noexcept-> T*;

  /**
   * Return an iterator to the end of the data array
   * @return an interator (one-past-the-end)   */
  constexpr auto end() const noexcept -> T const *;

private:
  /**
   * Private constructor to generate index_sequence at compile time
   */
  template <typename U, std::size_t... I>
  constexpr Matrix(Matrix<U, Rows, Cols> const & other, std::index_sequence<I...>);

public:
  /// Data representation
  std::array<T, Size> data;
};

/**
 * 2X2 Matrix specialization
 */
template<typename T>
class Matrix<T, 2, 2> {
  /** @cond doxygen has an issue with static assert */  
  static_assert(std::is_arithmetic<T>::value, "Underlying type must be a number");
  /** @endcond */

public:
  /// The Underlying type of this matrix
  using Type = T;
  /// the number of rows in this matrix
  static const int Rows = 2;
  /// the number of columns in this matrix
  static const int Cols = 2;
  /// the number of elements in this matrix
  static const int Size = Rows * Cols;

  /**
   * Default constructor.
   * 
   */
  explicit constexpr Matrix(IdentityTag = IdentityTag::Identity);

  /**
   * Constructs a matrix filling the first num elements with given value
   *
   * @param val the number to initialize this matrix
   * @param num the number of elements to initialize with num
   */
  Matrix(T const val, std::size_t num = Size);

  /**
   * Construct a matrix from a std::array
   *
   * @param other an array of values to initialize this matrix
   */
  constexpr explicit Matrix(std::array<T, Size> const & other);

  /**
   * Construct a matrix using a Matrix of the same size but different type.
   * 
   * Only does the basic casting from type T to type U
   * 
   * @param other a matrix with a different type
   */
  template <typename U, typename I = std::make_index_sequence<Size>>
  constexpr explicit Matrix(Matrix<U, Rows, Cols> const & other);

  /**
   * Copy Constructor.
   *
   * @param other the other matrix
   */
  constexpr Matrix(Matrix const & other) = default;

  /**
   * Index Operator.
   * 
   * @param i index into this matrix, must be less than Size
   * @return a reference to the value at index i
   */
  constexpr auto operator[](std::size_t i) -> T&;

  /**
   * Index Operator.
   * 
   * @param i index into this matrix, must be less than Size
   * @return a reference to the value at index i
   */
  constexpr auto operator[](std::size_t i) const -> T const &;

  /**
   * Matrix Index Operator
   * 
   * @param r row index must be less than Rows
   * @param c column index must be less than Cols
   * @return a reference to the value at row index r and column index c
   */
  constexpr auto operator()(std::size_t r, std::size_t c) -> T&;

  /**
   * Matrix Index Operator
   * 
   * @param r row index must be less than Rows
   * @param c column index must be less than Cols
   * @return a reference to the value at row index r and column index c   */
  constexpr auto operator()(std::size_t r, std::size_t c) const -> T const &;

  /**
   * Return an iterator to the first element of the data array
   * @return an interator
   */
  constexpr auto begin()  noexcept-> T*;

  /**
   * Return an iterator to the first element of the data array
   * @return an interator
   */
  constexpr auto begin() const noexcept -> T const *;

  /**
   * Return an iterator to the end of the data array
   * @return an interator (one-past-the-end)
   */
  constexpr auto end()  noexcept-> T*;

  /**
   * Return an iterator to the end of the data array
   * @return an interator (one-past-the-end)   */
  constexpr auto end() const noexcept -> T const *;

private:
  /**
   * Private constructor to generate index_sequence at compile time
   */
  template <typename U, std::size_t... I>
  constexpr Matrix(Matrix<U, Rows, Cols> const & other, std::index_sequence<I...>);

public:
  /// Data representation
  std::array<T, Size> data;
};

/**
 * 3X3 Matrix specialization
 */
template<typename T>
class Matrix<T, 3, 3> {
  /** @cond doxygen has an issue with static assert */  
  static_assert(std::is_arithmetic<T>::value, "Underlying type must be a number");
  /** @endcond */

public:
  /// The Underlying type of this matrix
  using Type = T;
  /// the number of rows in this matrix
  static const int Rows = 3;
  /// the number of columns in this matrix
  static const int Cols = 3;
  /// the number of elements in this matrix
  static const int Size = Rows * Cols;

  /**
   * Default constructor.
   * 
   */
  explicit constexpr Matrix(IdentityTag = IdentityTag::Identity);

  /**
   * Constructs a matrix filling the first num elements with given value
   *
   * @param val the number to initialize this matrix
   * @param num the number of elements to initialize with num
   */
  Matrix(T const val, std::size_t num = Size);

  /**
   * Construct a matrix from a std::array
   *
   * @param other an array of values to initialize this matrix
   */
  constexpr explicit Matrix(std::array<T, Size> const & other);

  /**
   * Construct a matrix using a Matrix of the same size but different type.
   * 
   * Only does the basic casting from type T to type U
   * 
   * @param other a matrix with a different type
   */
  template <typename U, typename I = std::make_index_sequence<Size>>
  constexpr explicit Matrix(Matrix<U, Rows, Cols> const & other);

  /**
   * Copy Constructor.
   *
   * @param other the other matrix
   */
  constexpr Matrix(Matrix const & other) = default;

  /**
   * Index Operator.
   * 
   * @param i index into this matrix, must be less than Size
   * @return a reference to the value at index i
   */
  constexpr auto operator[](std::size_t i) -> T&;

  /**
   * Index Operator.
   * 
   * @param i index into this matrix, must be less than Size
   * @return a reference to the value at index i
   */
  constexpr auto operator[](std::size_t i) const -> T const &;

  /**
   * Matrix Index Operator
   * 
   * @param r row index must be less than Rows
   * @param c column index must be less than Cols
   * @return a reference to the value at row index r and column index c
   */
  constexpr auto operator()(std::size_t r, std::size_t c) -> T&;

  /**
   * Matrix Index Operator
   * 
   * @param r row index must be less than Rows
   * @param c column index must be less than Cols
   * @return a reference to the value at row index r and column index c   */
  constexpr auto operator()(std::size_t r, std::size_t c) const -> T const &;

  /**
   * Return an iterator to the first element of the data array
   * @return an interator
   */
  constexpr auto begin()  noexcept-> T*;

  /**
   * Return an iterator to the first element of the data array
   * @return an interator
   */
  constexpr auto begin() const noexcept -> T const *;

  /**
   * Return an iterator to the end of the data array
   * @return an interator (one-past-the-end)
   */
  constexpr auto end()  noexcept-> T*;

  /**
   * Return an iterator to the end of the data array
   * @return an interator (one-past-the-end)   */
  constexpr auto end() const noexcept -> T const *;

private:
  /**
   * Private constructor to generate index_sequence at compile time
   */
  template <typename U, std::size_t... I>
  constexpr Matrix(Matrix<U, Rows, Cols> const & other, std::index_sequence<I...>);

public:
  /// Data representation
  std::array<T, Size> data;
};

/**
 * 4X4 Matrix specialization
 */template<typename T>
class Matrix<T, 4, 4> {
  /** @cond doxygen has an issue with static assert */  
  static_assert(std::is_arithmetic<T>::value, "Underlying type must be a number");
  /** @endcond */

public:
  /// The Underlying type of this matrix
  using Type = T;
  /// the number of rows in this matrix
  static const int Rows = 4;
  /// the number of columns in this matrix
  static const int Cols = 4;
  /// the number of elements in this matrix
  static const int Size = Rows * Cols;

  /**
   * Default constructor.
   * 
   */
  explicit constexpr Matrix(IdentityTag = IdentityTag::Identity);

  /**
   * Constructs a matrix filling the first num elements with given value
   *
   * @param val the number to initialize this matrix
   * @param num the number of elements to initialize with num
   */
  Matrix(T const val, std::size_t num = Size);

  /**
   * Construct a matrix from a std::array
   *
   * @param other an array of values to initialize this matrix
   */
  constexpr explicit Matrix(std::array<T, Size> const & other);

  /**
   * Construct a matrix using a Matrix of the same size but different type.
   * 
   * Only does the basic casting from type T to type U
   * 
   * @param other a matrix with a different type
   */
  template <typename U, typename I = std::make_index_sequence<Size>>
  constexpr explicit Matrix(Matrix<U, Rows, Cols> const & other);

  /**
   * Copy Constructor.
   *
   * @param other the other matrix
   */
  constexpr Matrix(Matrix const & other) = default;

  /**
   * Index Operator.
   * 
   * @param i index into this matrix, must be less than Size
   * @return a reference to the value at index i
   */
  constexpr auto operator[](std::size_t i) -> T&;

  /**
   * Index Operator.
   * 
   * @param i index into this matrix, must be less than Size
   * @return a reference to the value at index i
   */
  constexpr auto operator[](std::size_t i) const -> T const &;

  /**
   * Matrix Index Operator
   * 
   * @param r row index must be less than Rows
   * @param c column index must be less than Cols
   * @return a reference to the value at row index r and column index c
   */
  constexpr auto operator()(std::size_t r, std::size_t c) -> T&;

  /**
   * Matrix Index Operator
   * 
   * @param r row index must be less than Rows
   * @param c column index must be less than Cols
   * @return a reference to the value at row index r and column index c   */
  constexpr auto operator()(std::size_t r, std::size_t c) const -> T const &;

  /**
   * Return an iterator to the first element of the data array
   * @return an interator
   */
  constexpr auto begin()  noexcept-> T*;

  /**
   * Return an iterator to the first element of the data array
   * @return an interator
   */
  constexpr auto begin() const noexcept -> T const *;

  /**
   * Return an iterator to the end of the data array
   * @return an interator (one-past-the-end)
   */
  constexpr auto end()  noexcept-> T*;

  /**
   * Return an iterator to the end of the data array
   * @return an interator (one-past-the-end)   */
  constexpr auto end() const noexcept -> T const *;

private:
  /**
   * Private constructor to generate index_sequence at compile time
   */
  template <typename U, std::size_t... I>
  constexpr Matrix(Matrix<U, Rows, Cols> const & other, std::index_sequence<I...>);

public:
  /// Data representation
  std::array<T, Size> data;
};

template<typename T> using Mat2 = Matrix<T, 2, 2>;
template<typename T> using Mat3 = Matrix<T, 3, 3>;
template<typename T> using Mat4 = Matrix<T, 4, 4>;


namespace detail {

//got the idea for this from Cubbbi in the cplusplus.com forums
//http://www.cplusplus.com/forum/general/121300/

/**
 * Given position in the 1D representation of an R*C matrix,
 * return the value to put in that cell
 */
template<typename T, std::size_t R, std::size_t C>
constexpr int getElement(int pos)
{
    return (pos % R == pos / C); // 1 if row == col, 0 otherwise
}

/**
 * build the 1D representation of the matrix
 */
template<typename T, std::size_t R, std::size_t C, std::size_t ...I>
constexpr auto getElementArray(std::index_sequence<I...>) -> std::array<T, R*C> {
  return std::array<T, R*C>{{getElement<T,R,C>(I)...}};
}

/**
 * Create an array of indexes
 */
template<typename T, std::size_t R, std::size_t C, typename Indices = std::make_index_sequence<R*C>>
constexpr auto makeIdentityArray() -> std::array<T, R*C> {
  /** @cond doxygen has an issue with static assert */  
  static_assert(R*C>0, "Identity Matrix cannot have zero size");
  /** @endcond */
  return getElementArray<T, R, C>(Indices());
}

} // namespace detail


template<typename T, std::size_t R, std::size_t C>
constexpr Matrix<T, R, C>::Matrix(IdentityTag) : data(detail::makeIdentityArray<T,R,C>()) {};

template<typename T>
constexpr Mat2<T>::Matrix(IdentityTag) : data(detail::makeIdentityArray<T,Rows,Cols>()) {};

template<typename T>
constexpr Mat3<T>::Matrix(IdentityTag) : data(detail::makeIdentityArray<T,Rows,Cols>()) {};

template<typename T>
constexpr Mat4<T>::Matrix(IdentityTag) : data(detail::makeIdentityArray<T,Rows,Cols>()) {};



template<typename T, std::size_t R, std::size_t C>
Matrix<T, R, C>::Matrix(T const v, std::size_t num) {
  if ( num > Size ) {
    num = Size;
  }
  std::fill(data.begin(), data.begin()+num, v);
  std::fill(data.begin()+num, data.end(), T{0});
}

template<typename T>
Mat2<T>::Matrix(T const v, std::size_t num) {
  if ( num > Size ) {
    num = Size;
  }
  std::fill(data.begin(), data.begin()+num, v);
  std::fill(data.begin()+num, data.end(), T{0});
}

template<typename T>
Mat3<T>::Matrix(T const v, std::size_t num) {
  if ( num > Size ) {
    num = Size;
  }
  std::fill(data.begin(), data.begin()+num, v);
  std::fill(data.begin()+num, data.end(), T{0});
}

template<typename T>
Mat4<T>::Matrix(T const v, std::size_t num) {
  if ( num > Size ) {
    num = Size;
  }
  std::fill(data.begin(), data.begin()+num, v);
  std::fill(data.begin()+num, data.end(), T{0});
}



template<typename T, std::size_t R, std::size_t C>
constexpr Matrix<T, R, C>::Matrix(std::array<T, Size> const & other) : data(other) {}

template<typename T>
constexpr Mat2<T>::Matrix(std::array<T, Size> const & other) : data(other) {}

template<typename T>
constexpr Mat3<T>::Matrix(std::array<T, Size> const & other) : data(other) {}

template<typename T>
constexpr Mat4<T>::Matrix(std::array<T, Size> const & other) : data(other) {}


template <typename T, std::size_t R, std::size_t C>
template <typename U, typename I>
constexpr Matrix<T, R, C>::Matrix(Matrix<U, Rows, Cols> const & other)
 : Matrix(other, I()) {}

//template <typename T, std::size_t R, std::size_t C>
//template <typename U, std::size_t... I>
//constexpr Matrix<T, R, C>::Matrix(Matrix<U, Rows, Cols> const & other, std::index_sequence<I...>)
// : data {{(T(other.data[I]))...}} {}

//template <typename T>
//template <typename U, typename I>
//constexpr Mat2<T>::Matrix(Matrix<U, Rows, Cols> const & other)
// : Matrix(other, I()) {}

//template <typename T>
//template <typename U, std::size_t... I>
//constexpr Mat2<T>::Matrix(Matrix<U, Rows, Cols> const & other, std::index_sequence<I...>)
// : data {{(T(other.data[I]))...}} {}

//template <typename T>
//template <typename U, typename I>
//constexpr Mat3<T>::Matrix(Matrix<U, Rows, Cols> const & other)
//  : Matrix(other, I()) {}

//template <typename T>
//template <typename U, std::size_t... I>
//constexpr Mat3<T>::Matrix(Matrix<U, Rows, Cols> const & other, std::index_sequence<I...>)
//  : data {{(T(other.data[I]))...}} {}

//template <typename T>
//template <typename U, typename I>
//constexpr Mat4<T>::Matrix(Matrix<U, Rows, Cols> const & other)
//  : Matrix(other, I()) {}

//template <typename T>
//template <typename U, std::size_t... I>
//constexpr Mat4<T>::Matrix(Matrix<U, Rows, Cols> const & other, std::index_sequence<I...>)
//  : data {{(T(other.data[I]))...}} {}



template<typename T, std::size_t R, std::size_t C>
constexpr auto Matrix<T, R, C>::begin() noexcept -> T* { return data.begin(); }

template<typename T>
constexpr auto Mat2<T>::begin() noexcept -> T* { return data.begin(); }

template<typename T>
constexpr auto Mat3<T>::begin() noexcept -> T* { return data.begin(); }

template<typename T>
constexpr auto Mat4<T>::begin() noexcept -> T* { return data.begin(); }


template<typename T, std::size_t R, std::size_t C>
constexpr auto Matrix<T, R, C>::begin() const noexcept -> T const * { return data.begin(); }

template<typename T>
constexpr auto Mat2<T>::begin() const noexcept -> T const * { return data.begin(); }

template<typename T>
constexpr auto Mat3<T>::begin() const noexcept -> T const * { return data.begin(); }

template<typename T>
constexpr auto Mat4<T>::begin() const noexcept -> T const * { return data.begin(); }


template<typename T, std::size_t R, std::size_t C>
constexpr auto Matrix<T, R, C>::end() noexcept -> T* { return data.end(); }

template<typename T>
constexpr auto Mat2<T>::end() noexcept -> T* { return data.end(); }

template<typename T>
constexpr auto Mat3<T>::end() noexcept -> T* { return data.end(); }

template<typename T>
constexpr auto Mat4<T>::end() noexcept -> T* { return data.end(); }


template<typename T, std::size_t R, std::size_t C>
constexpr auto Matrix<T, R, C>::end() const noexcept -> T const * { return data.end(); }

template<typename T>
constexpr auto Mat2<T>::end() const noexcept -> T const * { return data.end(); }

template<typename T>
constexpr auto Mat3<T>::end() const noexcept -> T const * { return data.end(); }

template<typename T>
constexpr auto Mat4<T>::end() const noexcept -> T const * { return data.end(); }


template<typename T, std::size_t R, std::size_t C>
constexpr auto Matrix<T, R, C>::operator[](std::size_t i) -> T & { return data[i]; }

template<typename T>
constexpr auto Mat2<T>::operator[](std::size_t i) -> T & { return data[i]; }

template<typename T>
constexpr auto Mat3<T>::operator[](std::size_t i) -> T & { return data[i]; }

template<typename T>
constexpr auto Mat4<T>::operator[](std::size_t i) -> T & { return data[i]; }


template<typename T, std::size_t R, std::size_t C>
constexpr auto Matrix<T, R, C>::operator[](std::size_t i) const -> T const & { return data[i]; }

template<typename T>
constexpr auto Mat2<T>::operator[](std::size_t i) const -> T const & { return data[i]; }

template<typename T>
constexpr auto Mat3<T>::operator[](std::size_t i) const -> T const & { return data[i]; }

template<typename T>
constexpr auto Mat4<T>::operator[](std::size_t i) const -> T const & { return data[i]; }


template<typename T, std::size_t R, std::size_t C>
constexpr auto Matrix<T, R, C>::operator()(std::size_t r, std::size_t c) -> T & { return data[r+(C*c)]; }

template<typename T>
constexpr auto Mat2<T>::operator()(std::size_t r, std::size_t c) -> T & { return data[r+(Cols*c)]; }

template<typename T>
constexpr auto Mat3<T>::operator()(std::size_t r, std::size_t c) -> T & { return data[r+(Cols*c)]; }

template<typename T>
constexpr auto Mat4<T>::operator()(std::size_t r, std::size_t c) -> T & { return data[r+(Cols*c)]; }


template<typename T, std::size_t R, std::size_t C>
constexpr auto Matrix<T, R, C>::operator()(std::size_t r, std::size_t c) const -> T const & { return data[r+(C*c)]; }

template<typename T>
constexpr auto Mat2<T>::operator()(std::size_t r, std::size_t c) const -> T const & { return data[r+(Cols*c)]; }

template<typename T>
constexpr auto Mat3<T>::operator()(std::size_t r, std::size_t c) const -> T const & { return data[r+(Cols*c)]; }

template<typename T>
constexpr auto Mat4<T>::operator()(std::size_t r, std::size_t c) const -> T const & { return data[r+(Cols*c)]; }

/**
 * Add two Matrices componentwise
 * @param lhs the matrix to alter
 * @param rhs the Matrix to add to lhs
 * @return the result of adding rhs to lhs
 */
template<typename T, std::size_t R, std::size_t C>
auto operator+=(Matrix<T, R, C> & lhs, Matrix<T, R, C> const & rhs) -> Matrix<T, R, C> & {
  std::transform(lhs.begin(), lhs.end(), rhs.begin(), lhs.begin(), std::plus<T>());
  return lhs;
}

template<typename T, std::size_t R, std::size_t C>
auto operator-=(Matrix<T, R, C> & lhs, Matrix<T, R, C> const & rhs) -> Matrix<T, R, C> & {
  std::transform(lhs.begin(), lhs.end(), rhs.begin(), lhs.begin(), std::minus<T>());
  return lhs;
}

template<typename T, std::size_t R, std::size_t C>
constexpr auto operator*=(Matrix<T, R, C> & lhs, T const val) -> Matrix<T, R, C> & {
  std::for_each(lhs.begin(), lhs.end(), [val](T& v) {v*=val;});
  return lhs;
}

template<typename T, std::size_t R, std::size_t C>
auto operator-(Matrix<T, R, C> mat) -> Matrix<T, R, C> {
  std::for_each(mat.begin(), mat.end(), [](T& v) {v=-v;});
  return mat;
}


template<typename T, std::size_t R, std::size_t C>
auto operator/=(Matrix<T, R, C> & lhs, T const val) -> Matrix<T, R, C> & {
  std::for_each(lhs.begin(), lhs.end(), [val](T& v) {v/=val;});
  return lhs;
}

template<typename T, std::size_t R, std::size_t C>
auto operator==(Matrix<T, R, C> const & lhs, Matrix<T, R, C> const & rhs) -> bool {
  return std::equal(lhs.begin(), lhs.end(), rhs.begin());
}

template<typename T, std::size_t R, std::size_t C>
auto operator!=(Matrix<T, R, C> const & lhs, Matrix<T, R, C> const & rhs) -> bool {
  return !(lhs ==rhs);
}

template<typename T, std::size_t R, std::size_t C>
auto operator+(Matrix<T, R, C> lhs, Matrix<T, R, C> const & rhs) -> Matrix<T, R, C> {
  return lhs += rhs;
}

template<typename T, std::size_t R, std::size_t C>
auto operator-(Matrix<T, R, C> lhs, Matrix<T, R, C> const & rhs) -> Matrix<T, R, C> {
  return lhs -= rhs;
}

template<typename T, std::size_t R, std::size_t C>
auto operator*(Matrix<T, R, C> lhs, T val) -> Matrix<T, R, C> {
  return lhs *= val;
}

template<typename T, std::size_t R, std::size_t C>
auto operator*(T val, Matrix<T, R, C> rhs) -> Matrix<T, R, C> {
  return rhs *= val;
}

template<typename T, std::size_t R, std::size_t C>
auto operator/(Matrix<T, R, C> lhs, T val) -> Matrix<T, R, C> {
  return lhs *= val;
}

template<typename T, std::size_t R1, std::size_t C1, std::size_t C2>
auto operator*(Matrix<T, R1, C1> const & lhs, Matrix<T, R1, C2> const & rhs) -> bool {
  Matrix<T, R1, C2> ret;
  for (std::size_t i = 0; i < R1; ++i) {
    for (std::size_t j = 0; j < C2; ++j) {
      for (std::size_t k = 0; k < C1; ++k)  {
        ret(i, j) += lhs(i, k) * rhs(k, j);
      }
    }
  }
  return ret;
}

/**
 * Return the determinant of the given matrix.  
 */
template<typename T>
constexpr auto det(Mat2<T> const & mat) -> T {
  return mat[0]*mat[3] - mat[2]*mat[1];
}

/**
 * Return the determinant of the given matrix.  
 */
template<typename T>
constexpr auto det(Mat3<T> const & mat) -> T {
  return mat[0]*(mat[4]*mat[8] - mat[7]*mat[5]) -
         mat[3]*(mat[1]*mat[8] - mat[7]*mat[2]) +
         mat[6]*(mat[1]*mat[5] - mat[4]*mat[2]);
}

/**
 * Return the determinant of the given matrix.  
 */
template<typename T>
constexpr auto det(Mat4<T> const & mat) -> T {
  //cofactor expansion
  return (mat[0]*mat[5] - mat[1]*mat[4]) * (mat[10]*mat[15] - mat[11]*mat[14]) -
         (mat[0]*mat[6] - mat[2]*mat[4]) * (mat[9]*mat[15] - mat[11]*mat[13]) +
         (mat[0]*mat[7] - mat[3]*mat[4]) * (mat[9]*mat[14] - mat[10]*mat[13]) +
         (mat[1]*mat[6] - mat[2]*mat[5]) * (mat[8]*mat[15] - mat[11]*mat[12]) -
         (mat[1]*mat[7] - mat[3]*mat[5]) * (mat[8]*mat[14] - mat[10]*mat[12]) +
         (mat[2]*mat[7] - mat[3]*mat[6]) * (mat[8]*mat[13] - mat[9]*mat[12]);
}

/** 
 * Return the adjugate matrix of the given matrix 
 */
template <typename T>
constexpr auto adjugate(Mat2<T> const & mat) -> Mat2<T> {
  return Mat2<T> {{{mat[3], -mat[1], -mat[2], mat[0]}}};
}

/**
 * Return the adjufate of the given matrix 
 */
template <typename T>
constexpr auto adjugate(Mat3<T> const & mat) -> Mat3<T> {
  return Mat3<T> {{{
    mat[4] * mat[8] - mat[5] * mat[7],
    mat[2] * mat[7] - mat[1] * mat[8],
    mat[1] * mat[5] - mat[2] * mat[4],
    mat[5] * mat[6] - mat[3] * mat[8],
    mat[0] * mat[8] - mat[2] * mat[6],
    mat[2] * mat[3] - mat[0] * mat[5],
    mat[3] * mat[7] - mat[4] * mat[6],
    mat[1] * mat[6] - mat[0] * mat[7],
    mat[0] * mat[4] - mat[1] * mat[3]}}};
}

/**
 * Calculate the adjugate of the given matrix and return it in a Mat3
 */
template <typename T>
constexpr auto adjugate(Mat4<T> const & mat) -> Mat3<T> {
  //Common co-factors
  T i0 = mat[0]*mat[5] - mat[1]*mat[4];
  T i1 = mat[0]*mat[6] - mat[2]*mat[4];
  T i2 = mat[0]*mat[7] - mat[3]*mat[4];
  T i3 = mat[1]*mat[6] - mat[2]*mat[5];
  T i4 = mat[1]*mat[7] - mat[3]*mat[5];
  T i5 = mat[2]*mat[7] - mat[3]*mat[6];
  T j0 = mat[8]*mat[13] - mat[9]*mat[12];
  T j1 = mat[8]*mat[14] - mat[10]*mat[12];
  T j2 = mat[8]*mat[15] - mat[11]*mat[12];
  T j3 = mat[9]*mat[14] - mat[10]*mat[13];
  T j4 = mat[9]*mat[15] - mat[11]*mat[13];
  T j5 = mat[10]*mat[15] - mat[11]*mat[14];

  return Mat4<T> {{{
     mat[5] * j5 - mat[6] * j4 + mat[7] * j3,
    -mat[1] * j5 + mat[2] * j4 - mat[3] * j3,
     mat[13] * i5 - mat[14] * i4 + mat[15] * i3,
    -mat[9] * i5 + mat[10] * i4 - mat[11] * i3,
    -mat[4] * j5 + mat[6] * j2 - mat[7] * j1,
     mat[0] * j5 - mat[2] * j2 + mat[3] * j1,
    -mat[12] * i5 + mat[14] * i2 - mat[15] * i1,
     mat[8] * i5 - mat[10] * i2 + mat[11] * i1,
     mat[4] * j4 - mat[5] * j2 + mat[7] * j0,
    -mat[0] * j4 + mat[1] * j2 - mat[3] * j0,
     mat[12] * i4 - mat[13] * i2 + mat[15] * i0,
    -mat[8] * i4 + mat[9] * i2 - mat[11] * i0,
    -mat[4] * j3 + mat[5] * j1 - mat[6] * j0,
     mat[0] * j3 - mat[1] * j1 + mat[2] * j0,
    -mat[12] * i3 + mat[13] * i1 - mat[14] * i0,
     mat[8] * i3 - mat[9] * i1 + mat[10] * i0
  }}};
}


/**
 * Return a Matrix containing the inverse of the given matrix
 */
template <typename T, std::size_t S>
constexpr auto inverse(Matrix<T, S, S> const & mat) -> Matrix<T, S, S> {
  /** @cond */
  static_assert(S==2 | S == 3 | S == 4, "Only matrices of 2,3 or 4 are supported");
  /** @endcond */

  // Using formula:
  //
  //            1
  // A^(-1) = ------ * adjugate(A)
  //          det(A)
  //
  T d = det(mat);

  if (std::abs(d) < std::numeric_limits<T>::epsilon()) {
    //@todo throw exception?
  }
  return static_cast<T> (1.0 / d) * adjugate(mat);
}

/** 
 * Return a transposed copy of the given Matrix
 */
template <typename T, std::size_t R, std::size_t C>
auto transpose(Matrix<T, R, C> const & mat) -> Matrix<T, C, R> {
  Matrix<T, C, R> ret;
  for (std::size_t r = 0; r < C; ++r) {
    for (std::size_t c = 0; c < R; ++ c) {
      ret(r, c) = mat(c,r);
    }
  }
  return mat;
}

/**
 * Transpose the given 2x2 matrix
 */
template <typename T>
constexpr auto transpose(Mat2<T> const & mat) -> Mat2<T> {
  return Mat2<T>{{{mat[0],mat[2], mat[1], mat[3]}}};
}

/**
 * Fuzzy equals.
 * 
 * @todo switch to better equals
 */
template<typename T, std::size_t R, std::size_t C>
auto equal(Matrix<T, R, C> const & lhs, Matrix<T, R, C> const & rhs, T const epsilon = std::numeric_limits<T>::epsilon())
{
  return std::equal(lhs.begin(), lhs.end(), rhs.begin(),
      [epsilon] (T r, T l) { using std::abs; return static_cast<T>(abs(l - r)) <= epsilon; });
} //equals


/**
 * Output the given matrix to the given output stream
 */
template<typename T, std::size_t R, std::size_t C>
auto operator<<(std::ostream & os, Matrix<T, R, C> const & mat) -> std::ostream & {
  for (std::size_t i = 0; i < R; ++i) {
    os << "\n[ ";
    for (std::size_t j = 0; j < C - 1; ++j){
      os << mat(i, j) << '\t';
    }
    os << mat(i, C - 1);
    os << " ]";
  }
  return os;
}// operator <<


/**
 * Read a matrix from the input stream to the given Matrix
 */
template<typename T, std::size_t R, std::size_t C>
auto operator>>(std::istream &is, Matrix<T, R, C> & mat) -> std::istream & {
  if (!is.good()) {
    return is;
  }

  char c = '\0';
  is >> c;
  if (c != '(') {
    is.unget();
    is.clear(std::ios::failbit);
    return is;
  }

  for (std::size_t i = 0; i < mat.size(); ++i) {
    is >> mat[i];
    is.clear(is.rdstate() & ~std::ios::failbit);
    if (!is.good())
      return is;

    c = '\0';
    is >> c;
    is.clear(is.rdstate() & ~std::ios::failbit);
    if (c != ((i == mat.size() - 1) ? ')' : ',')) {
      is.unget();
      is.clear(std::ios::failbit);
      return is;
    }
    if (!is.good()) {
      return is;
    }
  }
  return is;
} // operator >>

/**
 * Construct a translation Matrix
 */
template<typename T>
auto makeTranslation(T const x, T const y, T const z) -> Mat4<T>{
  return Mat4<T>{{{1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, x, y, z, 1.0f}}};
}

/**
 * Construct a translation Matrix
 */
template<typename T>
auto makeTranslation(Vec3<T> const & vec) -> Mat4<T>{
  return makeTranslation(vec.x, vec.y, vec.z);
}

/**
 * Construct a Scaling Matrix
 */
template<typename T>
auto makeScale(T const x, T const y, T const z) -> Mat4<T> {
  return Mat4<T>{{{x, 0.0f, 0.0f, 0.0f, 0.0f, y, 0.0f, 0.0f, 0.0f, 0.0f, z, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f}}};
}

/**
 * Construct a scaling Matrix
 */
template<typename T>
auto makeScale(Vec3<T> const & vec) -> Mat4<T>{
  return makeTranslation(vec.x, vec.y, vec.z);
}


using Mat2i = Matrix<int, 2, 2>;
using Mat3i = Matrix<int, 3, 3>;
using Mat4i = Matrix<int, 4, 4>;

using Mat2f = Matrix<float, 2, 2>;
using Mat3f = Matrix<float, 3, 3>;
using Mat4f = Matrix<float, 4, 4>;

using Mat2d = Matrix<double, 2, 2>;
using Mat3d = Matrix<double, 3, 3>;
using Mat4d = Matrix<double, 4, 4>;


}  // namespace math

}  // namespace cagey


#endif /* MATRIX_HH_ */
