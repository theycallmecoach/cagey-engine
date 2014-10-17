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
#ifndef CAGEY_INPUT_MOUSE_HH_
#define CAGEY_INPUT_MOUSE_HH_

#include <cagey/input/Device.hh>
#include <cagey/util/EnumClassSet.hh>
#include <cagey/input/IInputSystem.hh>
#include <cagey/core/Signal.hh>
#include <functional>
#include <utility>

namespace cagey {
namespace input {

/**
* All supported mouse buttons
*/
enum class MouseButton : int {
  Left,
  Middle,
  Right,
  Extra1,
  Extra2
};
using MouseButtonState = util::EnumClassSet<MouseButton, 5>;

//class IMouseListener {
//public:
//  virtual ~IMouseListener() = default;
//  virtual auto mousePressed() -> void = 0;
//  virtual auto mouseReleased() -> void = 0;
//  virtual auto mouseMoved() -> void = 0;
//  virtual auto mouseWheelMoved() -> void = 0;
//  virtual auto mouseEntered() -> void = 0;
//  virtual auto mouseExited() -> void = 0;
//};


class Mouse : public Device {
public:
  Mouse(IInputSystem const & inputSystem) : Device{inputSystem} {}
  ~Mouse() = default;

  using PressedSignal = core::Signal<void()>;
  using ReleasedSignal = core::Signal<void()>;
  using MovedSignal = core::Signal<void()>;
  using WheelMovedSignal = core::Signal<void()>;
  using EnteredSignal = core::Signal<void()>;
  using ExitedSignal = core::Signal<void()>;

//  auto addMouseListener(IMouseListener* listener) -> void;
//  auto removeMouseListener(IMouseListener* listener) -> void;

  auto addPressedListener(std::function<void()> const & func) -> PressedSignal::Connection { return mPressed.connect(func);}
  auto addReleasedListener(std::function<void()> const & func) -> ReleasedSignal::Connection { return mReleased.connect(func);}
  auto addMovedListener(std::function<void()> const & func) -> MovedSignal::Connection { return mMoved.connect(func);}
  auto addWheelMovedListener(std::function<void()> const & func) -> WheelMovedSignal::Connection { return mWheelMoved.connect(func);}
  auto addEnteredListener(std::function<void()> const & func) -> EnteredSignal::Connection { return mEntered.connect(func);}
  auto addExitedListener(std::function<void()> const & func) -> ExitedSignal::Connection { return mExited.connect(func);}

  void update() {};

protected:
  
  PressedSignal mPressed;
  ReleasedSignal mReleased;
  MovedSignal mMoved;
  WheelMovedSignal mWheelMoved;
  EnteredSignal mEntered;
  ExitedSignal mExited;
  
private:

};


} //namespace input
} //namespace cagey

#endif //CAGEY_INPUT_MOUSE_HH_