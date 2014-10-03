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

#include <cagey/window/VideoMode.hh>
#include "cagey/window/IVideoModeImpl.hh"
#include "cagey/window/VideoModeFactory.hh"
#include <algorithm>

namespace {
  auto fullScreenModes = std::vector<cagey::window::VideoMode>{};
}

namespace cagey {
namespace window {

///////////////////////////////////////////////////////////////////////////////
auto VideoMode::getCurrent() -> VideoMode {
  return window::detail::VideoModeFactory::create()->getCurrentMode();
}

///////////////////////////////////////////////////////////////////////////////
auto VideoMode::getFullScreenModes() -> std::vector<VideoMode> const & {
  if (fullScreenModes.empty()) {
    fullScreenModes = window::detail::VideoModeFactory::create()->getFullScreenModes();
    std::sort(std::begin(fullScreenModes), std::end(fullScreenModes),
        [] (VideoMode const & a, VideoMode const & b)
        {
          return a > b;
        });
  }
  return fullScreenModes;
}

///////////////////////////////////////////////////////////////////////////////
constexpr VideoMode::VideoMode(unsigned const width, unsigned const height, unsigned short const bpp) :
 mWidth(width),
 mHeight(height),
 mBitsPerPixel(bpp) {

}


///////////////////////////////////////////////////////////////////////////////
auto VideoMode::isValid() const -> bool {
  auto modes = cagey::window::VideoMode::getFullScreenModes();
  return std::find(std::begin(modes), std::end(modes), *this) != modes.end();
}


///////////////////////////////////////////////////////////////////////////////
auto operator ==(VideoMode const & lhs, VideoMode const & rhs) -> bool {
	return lhs.getHeight() == rhs.getHeight() && lhs.getWidth() == rhs.getWidth()
			&& lhs.getBitsPerPixel() == rhs.getBitsPerPixel();
}

///////////////////////////////////////////////////////////////////////////////
auto operator !=(VideoMode const & lhs, VideoMode const & rhs) -> bool {
	return !(lhs == rhs);
}

///////////////////////////////////////////////////////////////////////////////
auto operator <(VideoMode const & lhs, VideoMode const & rhs) -> bool {
	if (lhs.getBitsPerPixel() == rhs.getBitsPerPixel()) {
		if (lhs.getWidth() == rhs.getWidth()) {
			return lhs.getHeight() < rhs.getHeight();
		} else {
			return lhs.getWidth() < rhs.getWidth();
		}
	} else {
		return lhs.getBitsPerPixel() < rhs.getBitsPerPixel();
	}
}

///////////////////////////////////////////////////////////////////////////////
auto operator >(VideoMode const & lhs, VideoMode const & rhs) -> bool {
	return rhs < lhs;
}

///////////////////////////////////////////////////////////////////////////////
auto operator <=(VideoMode const & lhs, VideoMode const & rhs) -> bool {
	return !(rhs < lhs);
}

///////////////////////////////////////////////////////////////////////////////
auto operator >=(VideoMode const & lhs, VideoMode const & rhs) -> bool {
	return !(lhs < rhs);
}

} // namespace window
} // namespace cagey
