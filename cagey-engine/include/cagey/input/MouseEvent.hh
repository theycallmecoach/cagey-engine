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
#ifndef CAGEY_INPUT_MOUSEEVENT_HH_
#define CAGEY_INPUT_MOUSEEVENT_HH_


///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include <cagey/input/Event.hh>
#include <cagey/math/Point.hh>
#include <cagey/util/EnumClassSet.hh>

namespace cagey { namespace input {

class Mouse;

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


class MouseEvent : public cagey::input::Event {
protected:
  MouseEvent(cagey::input::Mouse const * source);
  virtual ~MouseEvent() = default;

private:
};

class MouseButtonEvent : public cagey::input::MouseEvent {
public:
  MouseButtonEvent(cagey::input::Mouse const * source,
      cagey::input::MouseButtonState const & buttonState,
      cagey::math::Point2i const & pos);

  auto getPosition() const -> math::Point2i { return mPos; };

private:
  MouseButtonState mButtonState;
  math::Point2i mPos;
};

class MouseMotionEvent : public cagey::input::MouseEvent {
public:
  MouseMotionEvent(cagey::input::Mouse const * source,
      cagey::math::Point2i const & pos);
private:
  math::Point2i mPos;
};

class MouseWindowEvent : public cagey::input::MouseEvent {
public:
  MouseWindowEvent(cagey::input::Mouse const * source,
      cagey::math::Point2i const & pos);
private:
  math::Point2i mPos;
};


} //namespace input
} //namespace cagey

#endif //CAGEY_INPUT_MOUSEEVENT_HH_