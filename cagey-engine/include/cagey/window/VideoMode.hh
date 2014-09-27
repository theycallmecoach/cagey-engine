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

#ifndef CAGEY_WINDOW_VIDEOMODE_HH_
#define CAGEY_WINDOW_VIDEOMODE_HH_

#include <vector>

namespace cagey {
namespace window {

class VideoMode {
public:
  static auto getCurrent() -> VideoMode;
  static auto getFullScreenModes() -> std::vector<VideoMode> const &;

  /**
  * Create a VideoMode
  *
  * @param width in pixels
  * @param height in pixels
  * @param bpp bits per pixel
  */
  VideoMode(unsigned const width, unsigned const height, unsigned short const bpp = 32);

  /**
  * Return the width of this VideoMode
  * @return width of this VideoMode in pixels
  */
  constexpr auto getWidth() const -> unsigned { return mWidth; }

  /**
  * Return the height of this video mode
  *
  * @return height of this VideMode in pixels
  */
  constexpr auto getHeight() const -> unsigned { return mHeight; }

  /**
  * Return the number of bits per pixel for this VideoMode
  *
  * @return the number of bits per pixel
  */
  constexpr auto getBitsPerPixel() const -> unsigned short { return mBitsPerPixel; }

  /**
  * Return true if this VideoMode is supported by the system
  *
  * @return true if this is a supported VideoMode
  */
  auto isValid() const -> bool;

private:
  /// width in pixels
  unsigned mWidth;
  /// heigh in pixels
  unsigned mHeight;
  /// bits per pixel
  unsigned short mBitsPerPixel;
};

auto operator == (VideoMode const & lhs, VideoMode const & rhs) -> bool;
auto operator != (VideoMode const & lhs, VideoMode const & rhs) -> bool ;
auto operator < (VideoMode const & lhs, VideoMode const & rhs) -> bool;
auto operator > (VideoMode const & lhs, VideoMode const & rhs) -> bool;
auto operator <= (VideoMode const & lhs, VideoMode const & rhs) -> bool;
auto operator >= (VideoMode const & lhs, VideoMode const & rhs) -> bool;

} //namespace window
} //namespace cagey

#endif //CAGEY_WINDOW_VIDEOMODE_HH_
