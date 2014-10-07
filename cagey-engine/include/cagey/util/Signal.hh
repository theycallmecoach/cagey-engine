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

#ifndef CAGEY_UTIL_SIGNAL_HH_
#define CAGEY_UTIL_SIGNAL_HH_

namespace cagey {
namespace util {

#include <vector>
#include <iostream>
#include <functional>
#include <memory>
#include <set>
#include <stdarg.h>
#include <assert.h>
template <typename> class Signal;
template <typename> class Connection;

template <typename Ret, typename... Args>
class Connection<Ret (Args...)> {
public:
  using Function = std::function<Ret (Args...)>;
  using Type = std::shared_ptr<Connection<Ret(Args...)>>;

  Connection(Function const & func) :  mFunc{func}, mId{uniqueId++} {}

  auto operator()(Args... arg) -> void {
    if (mFunc) {
      mFunc(arg...);
    }
  }

  friend auto operator < (Connection<Ret (Args...)> const & lhs, Connection<Ret (Args...)> const & rhs) -> bool;
  friend auto operator > (Connection<Ret (Args...)> const & lhs, Connection<Ret (Args...)> const & rhs) -> bool;
  friend auto operator == (Connection<Ret (Args...)> const & lhs, Connection<Ret (Args...)> const & rhs) -> bool;
  friend auto operator != (Connection<Ret (Args...)> const & lhs, Connection<Ret (Args...)> const & rhs) -> bool;

private:
  Function mFunc;
  int mId;
  static int uniqueId;
};

template <typename Ret, typename... Args>
int Connection<Ret (Args...)>::uniqueId = 0;


template <typename Ret, typename... Args>
auto operator < (Connection<Ret (Args...)> const & lhs, Connection<Ret (Args...)> const & rhs) -> bool {
  return lhs.mId < rhs.mId;
}

template <typename Ret, typename... Args>
auto operator > (Connection<Ret (Args...)> const & lhs, Connection<Ret (Args...)> const & rhs) -> bool {
  return lhs.mId < rhs.mId;
}

template <typename Ret, typename... Args>
auto operator == (Connection<Ret (Args...)> const & lhs, Connection<Ret (Args...)> const & rhs) -> bool {
  return lhs.mId == rhs.mId;
}

template <typename Ret, typename... Args>
auto operator != (Connection<Ret (Args...)> const & lhs, Connection<Ret (Args...)> const & rhs) -> bool {
  return !(lhs == rhs.mId);
}


template <typename Ret, typename... Args>
class Signal<Ret (Args...)> {
public:
  using Function = std::function<Ret (Args...)>;
  using ConnectionType = std::shared_ptr<Connection<Ret (Args...)>>;

  auto connect(Function const & func) -> ConnectionType {
    auto connection = std::make_shared<Connection<Ret (Args...)>>(Connection<Ret (Args...)>(func));
    mConnections.insert(connection);
    return connection;
  }

  auto operator()(Args... arg) -> void {
    for (auto i = std::begin(mConnections); i != std::end(mConnections);++i) {
      if (auto ptr = i->lock()) {
        (*ptr)(arg...);
      } else {
        mConnections.erase(i++);
      }
    }
  }

private:
  using ConnectionPtr = std::weak_ptr<Connection<Ret (Args...)>>;
  using ConnectionSet = std::set<ConnectionPtr, std::owner_less<ConnectionPtr>>;
  ConnectionSet mConnections;
};



template <typename> class Signal;

template <typename ReturnType, typename... Args>
class Signal<ReturnType (Args...)> {
public:
  using Function = std::function<ReturnType (Args...)>;

  auto connect(Function const & func) -> void {
    mFuncs.emplace_back(func);
  }

  auto operator()(Args... arg) -> void {
     for (auto & func: mFuncs) {
      func(arg...);
    }
  }

private:
  std::vector<Function> mFuncs;

};





template<typename... Args>
class Signal<Function> {
public:
  Signal() = default;
  auto connect(Function callback) -> void {

  }

  auto fire(Args... args) {

  }
};

} // namespace util
} // namespace cagey

#endif //CAGEY_UTIL_SIGNAL_HH_