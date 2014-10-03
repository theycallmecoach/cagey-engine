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

#include <cagey/input/InputManager.hh>
#include "cagey/input/InputSystemFactory.hh"
#include <cagey/input/IInputSystem.hh>
#include <cagey/input/Mouse.hh>
#include <cagey/input/Keyboard.hh>
#include <memory>

//#include "sdl/SdlInputSystem.hh"
//#include "x11/X11InputSystem.hh"

namespace {
  using StringMap = std::map<std::string, std::string>;
}

namespace cagey {
namespace input {

InputManager::InputManager()
 : mInputSystem{InputSystemFactory::create(StringMap())} {

  if (auto mouse = mInputSystem->createDevice(DeviceType::Mouse).lock()) {
    mMouse = std::dynamic_pointer_cast<Mouse>(mouse);
  }
  if (auto keyboard = mInputSystem->createDevice(DeviceType::Keyboard).lock()) {
    mKeyboard = std::dynamic_pointer_cast<Keyboard>(keyboard);
  }
}

} //namepsace input
} // namespace cagey