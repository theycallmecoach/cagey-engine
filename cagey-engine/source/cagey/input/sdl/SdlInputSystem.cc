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


#include "cagey/input/sdl/SdlInputSystem.hh"
#include "cagey/input/sdl/SdlMouse.hh"
#include "cagey/input/sdl/SdlKeyboard.hh"
#include "cagey/input/sdl/SdlDeviceFactory.hh"
#include "cagey/input/Device.hh"


namespace cagey {
namespace input {
namespace sdl {

///////////////////////////////////////////////////////////////////////////////
SdlInputSystem::SdlInputSystem(window::IWindow const * win, cagey::input::StringMap const & param)  :
  mWindow(win) {

}

///////////////////////////////////////////////////////////////////////////////
auto SdlInputSystem::getName() const -> std::string {
  return "SDL";
}

///////////////////////////////////////////////////////////////////////////////
auto SdlInputSystem::getWindow() const -> window::IWindow const * {
  return mWindow;
}

///////////////////////////////////////////////////////////////////////////////
auto SdlInputSystem::createDevice(DeviceType const &type) -> cagey::input::Device * {
  mDevices[type] = SdlDeviceFactory::createDevice(*this, type);
  return mDevices[type].get();
}

} //namespace sdl;
} //namespace input
} //namespace cagey