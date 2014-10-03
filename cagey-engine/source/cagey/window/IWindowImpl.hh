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


#ifndef CAGEY_WINDOW_WINDOWIMPL_HH_
#define CAGEY_WINDOW_WINDOWIMPL_HH_


#include <cagey/window/WindowHandle.hh>
#include <cagey/math/Point.hh>
#include <memory>

namespace cagey {
namespace window {
namespace detail {

class IWindowImpl {
public:
  virtual ~IWindowImpl() = default;

  virtual auto getTitle() const -> std::string = 0;
  virtual auto setTitle(std::string const & newTitle) -> void = 0;

	virtual auto getSize() const -> math::Point2u = 0;
  virtual auto setSize(math::Point2u dim) -> void = 0;

  virtual auto getVisible() const -> bool = 0;
  virtual auto setVisible(bool visible) -> void = 0;

  virtual auto getWindowHandle() const -> window::WindowHandle;
};

} //namespace detail
} //namespace window
} //namespace cagey

#endif // CAGEY_WINDOW_WINDOWIMPL_HH_