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


#include "cagey/window/WindowFactory.hh"
#include <cagey/window/IWindow.hh>
#include <cagey/window/IDisplayConfig.hh>
#include <memory>


#ifdef USE_SDL
#include "cagey/window/sdl/SdlWindow.hh"
#include "cagey/window/sdl/SdlDisplayConfig.hh"
#elif USE_X11
#include "cagey/window/x11/X11Window.hh"
#endif

namespace cagey {
namespace window {

auto WindowFactory::createWindow(std::string const & winName,
    VideoMode const & vidMode,
    IWindow::StyleSet const & winStyle) -> std::unique_ptr<IWindow> {
#ifdef USE_X11
  return std::unique_ptr<IWindow>{std::make_unique<x11::X11Window>()};
#else
  return std::unique_ptr<IWindow>{std::make_unique<window::sdl::SdlWindow>(winName, vidMode)};
#endif
}

auto WindowFactory::createDisplayConfig() -> std::unique_ptr<IDisplayConfig> {
#ifdef USE_X11
  return std::unique_ptr<IDisplayConfig>{std::make_unique<x11::X11DisplayConfig>()};
#else
  return std::unique_ptr<IDisplayConfig>{std::make_unique<window::sdl::SdlDisplayConfig>()};
#endif

}

} //namespace window
} //namespace cagey
