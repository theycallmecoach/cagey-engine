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

#ifndef CAGEY_INPUT_SDL_SDLIINPUTSYSTEM_HH_
#define CAGEY_INPUT_SDL_SDLIINPUTSYSTEM_HH_

#include "../IInputSystem.hh"



namespace cagey {
namespace input {
namespace detail {
namespace sdl {

class SdlInputSystem : public IInputSystem {
public:
  SdlInputSystem();
  virtual auto getName() const -> std::string override;

  virtual auto createDevice(DeviceType const & type) -> std::weak_ptr<Device> override;

private:
  using std::shared_ptr<Device> DevicePtr;
  std::map<DeviceType, DevicePtr> mDevices;
};

} //namespace sdl;
} //namespace detail;
} //namespace input
} //namespace cagey

#endif // CAGEY_INPUT_SDL_SDLIINPUTSYSTEM_HH_