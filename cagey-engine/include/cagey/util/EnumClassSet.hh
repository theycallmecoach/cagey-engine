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

#ifndef CAGEY_UTIL_ENUMCLASSSET_HH_
#define CAGEY_UTIL_ENUMCLASSSET_HH_

#include <type_traits>
#include <bitset>

namespace cagey {
namespace util {

template<typename E, std::size_t S>
class EnumClassSet {
  static_assert(std::is_enum<E>::value, "EnumSet type must be a strongly typed enum");
public:
  auto test(E pos) const -> bool {
    return bits.test(value(pos));
  }

  auto flip(E pos) -> EnumClassSet & {
    bits.flip(value(pos));
    return *this;
  }

  auto reset() -> EnumClassSet & {
    bits.reset();
    return *this;
  }

  auto set(E pos) -> EnumClassSet & {
    bits.set(value(pos));
    return *this;
  }

  explicit operator bool() const {
    return bits.any();
  }

private:
  typename std::underlying_type<E>::type value(E v) const {
    return static_cast<typename std::underlying_type<E>::type>(v);
  }

  std::bitset <static_cast<typename std::underlying_type<E>::type>(S)> bits{};
};


} //namespace util
} //namespace cagey

#endif //CAGEY_UTIL_ENUMCLASSSET_HH_
