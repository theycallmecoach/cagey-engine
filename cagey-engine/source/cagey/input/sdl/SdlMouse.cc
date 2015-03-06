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

#include <SDL2/SDL.h>
#include <complex>
#include <iostream>
#include "cagey/input/sdl/SdlMouse.hh"
#include "cagey/window/IWindow.hh"


namespace {
  const int MouseBufferSize = 50;
}

namespace cagey {
namespace input {
namespace sdl {

///////////////////////////////////////////////////////////////////////////////
SdlMouse::SdlMouse(SdlInputSystem const & inputSystem)
    : SdlContext(SDL_INIT_VIDEO),
      Mouse(inputSystem),
      mInputSystem(inputSystem) {
}


///////////////////////////////////////////////////////////////////////////////
auto SdlMouse::update() -> void {
  std::cout << "SdlMouse::update" << std::endl;
  auto win = mInputSystem.getWindow();
  SDL_Event events[MouseBufferSize];
  SDL_PumpEvents();
  int count = SDL_PeepEvents(events, MouseBufferSize, SDL_GETEVENT, SDL_MOUSEMOTION, SDL_MOUSEWHEEL);
  std::cout << "SdlMouse::count"<< count << std::endl;
  for (int i = 0; i < count; ++i) {
    switch(events[i].type) {
      case SDL_MOUSEMOTION: {
        std::cout << "SdlMouse::motion" << std::endl;
        break;
      }
      case SDL_MOUSEBUTTONDOWN: {
        std::cout << "SdlMouse::pressed" << std::endl;
        mPressed();
        break;
      }
      case SDL_MOUSEBUTTONUP: {
        std::cout << "SdlMouse::released" << std::endl;
        mReleased();
        break;
      }
    }
  }
}

} //namespace sdl;
} // namespace input
} // namespace cagey
