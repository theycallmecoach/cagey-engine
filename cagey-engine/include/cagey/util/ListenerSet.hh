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

#ifndef CAGEY_UTIL_LISTENERSET_HH_
#define CAGEY_UTIL_LISTENERSET_HH_

#include <set>

namespace cagey {
namespace util {

template<typename T>
class ListenerSet<T> {
public:
  auto add(T listener) -> void { mListeners.insert(listener);}
  auto remove(T listener) -> void { mListeners.erase(listener);}

template <class F, class... A>
inline void notify(F&& f, A&&... args) {
    m_notifying = true;
    for (auto & listener : m_listeners)
    {
        auto method = std::bind(f, listener, args...);
        if (method) {
          method();
        } else {
          remove(listener);
        }
    }
}
private:
  std::set<T> mListeners;
};

} //namespace util
} //namespace cagey

#endif //CAGEY_UTIL_LISTENERSET_HH_
