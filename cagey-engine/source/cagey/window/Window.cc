//////////////////////////////////////////////////////////////////////////////////
////
//// cagey-engine - Toy 3D Engine
//// Copyright (c) 2014 Kyle Girard <theycallmecoach@gmail.com>
////
//// The MIT License (MIT)
////
//// Permission is hereby granted, free of charge, to any person obtaining a copy
//// of this software and associated documentation files (the "Software"), to deal
//// in the Software without restriction, including without limitation the rights
//// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//// copies of the Software, and to permit persons to whom the Software is
//// furnished to do so, subject to the following conditions:
////
//// The above copyright notice and this permission notice shall be included in
//// all copies or substantial portions of the Software.
////
//// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//// SOFTWARE.
////
//////////////////////////////////////////////////////////////////////////////////
//
//#include <cagey/window/Window.hh>
//#include <cagey/window/VideoMode.hh>
//#include "cagey/window/WindowFactory.hh"
//#include "cagey/window/IWindowImpl.hh"
//#include <iostream>
//
//namespace {
// cagey::window::Window const * fullScreenWindow = nullptr;
//}
//
//namespace cagey {
//namespace window {
//
//Window::Window(VideoMode const & vidMode, std::string const & winName, StyleSet const & winStyle)
//  : mImpl{},
//    mVideoMode{vidMode},
//    mName{winName},
//    mStyle{winStyle},
//    mVisible{false} {
//
//  if (winStyle.test(Style::Fullscreen)) {
//    if (fullScreenWindow) {
//      std::cerr << "Unable to create two fullscreen windows" << std::endl;
//      mStyle.flip(Style::Fullscreen);
//    } else {
//      if (!mVideoMode.isValid()) {
//        //@TODO invalid video mode...should have better exception
//        throw 0;
//      }
//      fullScreenWindow = this;
//    }
//  }
//
//  mImpl = detail::WindowFactory::create(mVideoMode, mName, mStyle);
//  mVisible = true;
//}
//
//auto Window::getTitle() const -> std::string {
//  return mName;
//}
//
//auto Window::setTitle(std::string const & newTitle) -> void {
//  mName = newTitle;
//  mImpl->setTitle(newTitle);
//}
//
//} // namespace window
//} // namespace cagey
//
//
//
