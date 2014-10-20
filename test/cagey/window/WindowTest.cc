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

#include <cagey/window/WindowFactory.hh>
#include <cagey/input/InputManager.hh>
#include <cagey/input/Mouse.hh>
#include <gtest/gtest.h>
#include <thread>

using namespace cagey::window;
using namespace cagey::input;
using namespace std::literals; //need this for fancy chrono_literals

namespace {
  bool pressedState = false;

}


void pressedListener() {
  std::cout << "PRESSED YAY";
  pressedState = true;
}

TEST(Window, DefaultConstructor) {
  auto win = WindowFactory::createWindow("HelloWorld", VideoMode{640,480});
  auto winp = std::shared_ptr<IWindow>{std::move(win)};

  InputManager inputMan{winp};

  if (auto mouse = inputMan.getMouse().lock()) {
    mouse->addPressedListener(pressedListener);
  }

  while(!pressedState) {
    inputMan.update();
  }

  std::this_thread::sleep_for( 2000ms );
}