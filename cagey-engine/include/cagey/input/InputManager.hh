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
#ifndef CAGEY_INPUT_INPUTMANAGER_HH_
#define CAGEY_INPUT_INPUTMANAGER_HH_

#include "cagey/input/Device.hh"

#include <memory>

namespace cagey {
namespace input {

//Forward declarations
class IInputSystem;
class Mouse;
class Keyboard;

class InputManager {
public:
  InputManager() = default;
  virtual ~InputManager() = default;

protected:

private:
  using MouseWeakPtr = std::weak_ptr<Mouse>;
  using KeyboardWeakPtr = std::weak_ptr<Keyboard>;

  MouseWeakPtr mMouse;
  KeyboardWeakPtr mKeyboard;
  std::unique_ptr<IInputSystem> mInputSystem;
};


} //namespace input
} //namespace cagey

#endif //CAGEY_INPUT_INPUTMANAGER_HH_