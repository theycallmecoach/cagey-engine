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

#ifndef CAGEY_INPUT_X11_X11IINPUTSYSTEM_HH_
#define CAGEY_INPUT_X11_X11IINPUTSYSTEM_HH_

#include <map>
#include <memory>

#include "cagey/input/IInputSystem.hh"


namespace cagey {
namespace input {
namespace x11 {

class X11InputSystem : public IInputSystem {
public:
  X11InputSystem();

  virtual auto getName() const -> std::string override;

  virtual auto createDevice(DeviceType const &type) -> std::weak_ptr<Device> override;

private:
  using DevicePtr = std::shared_ptr<Device>;
  std::map<DeviceType, DevicePtr> mDevices;
};

} //namespace x11;
} //namespace input
} //namespace cagey

#endif // CAGEY_INPUT_X11_X11IINPUTSYSTEM_HH_