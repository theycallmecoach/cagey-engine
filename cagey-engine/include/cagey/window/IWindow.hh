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

#ifndef CAGEY_WINDOW_IWINDOW_HH_
#define CAGEY_WINDOW_IWINDOW_HH_

#include <cagey/util/EnumClassSet.hh>
#include <cagey/window/VideoMode.hh>
#include <memory>

namespace cagey {
namespace window {

//forward declarations
class VideoMode;

class IWindow {
public:

  /**
  * All possible window styles
  */
  enum class Style
      : unsigned int {
    None,
    Titlebar,
    Resize,
    Close,
    Fullscreen,
  };

  using StyleSet = cagey::util::EnumClassSet <Style, 5>;

  /**
  * Default destructor
  */
  virtual ~IWindow() = default;

//  /**
//  * Cannot copy a IWindow
//  */
//  IWindow(IWindow const & window) = delete;
//
//  /**
//  * Cannot copy a Iwindow
//  */
//  auto operator=(IWindow const & other) = delete;

  /**
  * Returns the title of this Window
  *
  * @param the window title as a std::string
  */
  virtual auto getTitle() const -> std::string = 0;

  /**
  * Sets the title of this window to the given string
  *
  * @param newTitle the new title for this window as a std::string
  */
  virtual auto setTitle(std::string const & newTitle) -> void = 0;

};

} //namespace window
} //namespace cagey

#endif //CAGEY_WINDOW_VIDEOMODE_HH_
