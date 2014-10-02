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

#include <cagey/input/Event.hh>
#include <cagey/input/Mouse.hh>

namespace cagey {
namespace input {


class MouseEvent : public Event {
protected:
  MouseEvent(Mouse const & source, MouseButonState const & buttonState, math::Point2i const & pos);
  virtual ~Mouse() = default;

protected:

private:
  MouseButtonState mButtonState;
  math::Point2i mPos;
};

class MouseButtonEvent : public MouseEvent {
public:
  MouseButtonEvent(Mouse const & source, MouseButtonState const & buttonState, math::Point2i const & pos);
};

class MouseMotionEvent : public MouseEvent {
public:
  MouseMotionEvent(Mouse const & source, MouseButtonState const & buttonState, math::Point2i const & pos);
};

class MouseWindowEvent : public MouseEvent {
public:
  MouseWindowEvent(Mouse const & source, MouseButtonState const & buttonState, math::Point2i const & pos);
};


} //namespace input
} //namespace cagey

#endif //CAGEY_INPUT_MOUSEEVENT_HH_