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
#ifndef CAGEY_CORE_SIGNAL_HH_
#define CAGEY_CORE_SIGNAL_HH_

#include <functional>
#include <map>
#include <memory>

namespace cagey {
namespace core {

template <typename> class Signal;

template <typename Func>
class Connection {
  friend class Signal<Func>;
public:
  auto disconnect() -> bool {
    if (mSignal) {
      return mSignal->disconnect(*this);
    }
    return false;
  } 
  Connection(Connection<Func> const & other) = default;
  
protected:
  Connection(int id, Signal<Func> * signal) : mId{id}, mSignal{signal} { }
  Signal<Func>* mSignal;
  int mId;
};

template <typename Func>
class ScopedConnection : public Connection<Func> {
public:
  explicit ScopedConnection(Connection<Func> const && con) : Connection<Func>{con}{}
  ~ScopedConnection() { 
    Connection<Func>::disconnect(); 
  }
};

/**
* A Signal represents the subject in the Observer/Subject pattern.  Observers can register 'slots'
* to receive messages from the Signal.
*/
template <typename Func>
class Signal {
public:
  using Function = std::function<Func>;
  using Connection = Connection<Func>;
  using ScopedConnection = ScopedConnection<Func>;

  /**
  * Default constructor
  */
  Signal() : mConnectionId{0} {
  }

  ~Signal() {
    mCallbacks.clear();
  }

  auto connect(Function const & func) -> Connection {
    int conId = mConnectionId++;
    mCallbacks.emplace(std::make_pair(conId, std::make_shared<Function>(func)));
    return Connection{conId, this};
  }

  auto disconnect(Connection const & con) -> bool {
    return mCallbacks.erase(con.mId) > 0;
  }

  template<typename... Args>
  auto operator() (Args... args) -> void {
    for (auto & cb : mCallbacks) {
      if (cb.second) {
        (*cb.second)(args...);
      }
    }
  }
  Signal(Signal const &) = delete;
  auto operator=(Signal const &) = delete;
  
private:
  std::map<int, std::shared_ptr<Function>> mCallbacks;
  int mConnectionId;
};


//Idea for these functions taken from here: https://testbit.eu/cpp11-signal-system-performance/
//these provide a short hand to std::bind

/// This function creates a std::function by binding @a object to the member function pointer @a method.
template<class Instance, class Class, class R, class... Args> std::function<R (Args...)>
slot (Instance &object, R (Class::*method) (Args...))
{
  return [&object, method] (Args... args) { return (object .* method) (args...); };
}

/// This function creates a std::function by binding @a object to the member function pointer @a method.
template<class Class, class R, class... Args> std::function<R (Args...)>
slot (Class *object, R (Class::*method) (Args...))
{
  return [object, method] (Args... args) { return (object ->* method) (args...); };
}



} //namespace core
} //namespace cagey

#endif //CAGEY_CORE_SIGNAL_HH_
