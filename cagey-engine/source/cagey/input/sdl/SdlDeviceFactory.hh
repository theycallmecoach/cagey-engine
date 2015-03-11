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

#ifndef CAGEY_INPUT_SDL_SDLDEVICEFACTORY_HH_
#define CAGEY_INPUT_SDL_SDLDEVICEFACTORY_HH_

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include <cagey/input/Types.hh>
#include <string>
#include <memory>
#include <map>

namespace cagey { namespace input {

///////////////////////////////////////////////////////////////////////////////
// Forward declaration
///////////////////////////////////////////////////////////////////////////////
class Device;

namespace sdl {

///////////////////////////////////////////////////////////////////////////////
// Forward declaration
///////////////////////////////////////////////////////////////////////////////
class SdlInputSystem;

/**
* A factory to create SDL devices
*/
class SdlDeviceFactory {
public:
  /**
   * Construct a device of the given type
   *
   * @param is the input system to use to create the device
  * @param type the type of device to be created
   */
  static auto createDevice(cagey::input::sdl::SdlInputSystem const &is, cagey::input::DeviceType const &type) -> std::unique_ptr<cagey::input::Device>;
};

} //namespace sdl
} //namespace input
} //namespace cagey

#endif // CAGEY_INPUT_SDL_SDLDEVICEFACTORY_HH_