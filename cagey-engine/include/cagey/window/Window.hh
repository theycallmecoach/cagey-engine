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

#ifndef CAGEY_WINDOW_WINDOW_HH_
#define CAGEY_WINDOW_WINDOW_HH_

namespace cagey {
namespace window {

class Window {
public:
    enum class Style
      : unsigned int {
        None,
        Titlebar,
        Resize,
        Close,
        Fullscreen,
    };
    typedef kgml::util::EnumClassSet<Style, 5> StyleSet;

   /**
     * Create an instance of a window.
     *
     * @param vidMode
     * @param winName
     * @param winStyle
     */
    Window(VideoMode const & vidMode,
           std::string const & winName,
           StyleSet const & winStyle = StyleSet{}.set(Style::Titlebar)
                                                 .set(Style::Resize)
                                                 .set(Style::Close));


  auto getTitle() const -> std::string;
  auto setTitle(std::string const & newTitle) -> void;

private:

};

} //namespace window
} //namespace cagey

#endif //CAGEY_WINDOW_VIDEOMODE_HH_
