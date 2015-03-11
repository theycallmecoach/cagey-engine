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

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include <functional>
#include <map>
#include <memory>

namespace cagey { namespace core {

template <typename> class Signal;

/**
 * Represents a connection between a signal and a slot (function).  Can
 * be used to disconnect from a signal.
 */
template <typename Func>
class Connection {
  friend class Signal<Func>;
public:
  /**
   * Disconnects a signal and slot
   * 
   * @return true if the disconnect was successful
   */
  auto disconnect() -> bool {
    if (mSignal) {
      return mSignal->disconnect(*this);
    }
    return false;
  } 
  
  /** 
   * Default copy constructor 
   * 
   * @param other an other Connection
   */
  Connection(Connection<Func> const & other) = default;
  
protected:
  /**
   * Protected constructor to prevent unauthorized construction
   */
  Connection(int id, Signal<Func> * signal) : mId{id}, mSignal{signal} { }
  /// Non-owning point to the signal end of the connection
  Signal<Func>* mSignal;
  /// Unique id for this connection
  int mId;
};

/**
 * Connection between a Signal and a slot(function) that disconnects when
 * it is destroyed.
 */
template <typename Func>
class ScopedConnection : public Connection<Func> {
public:
  explicit ScopedConnection(Connection<Func> const && con) : Connection<Func>{con}{}
  ~ScopedConnection() { 
    Connection<Func>::disconnect(); 
  }
};

/**
 * A Signal represents the subject in the Observer/Subject pattern.  Observers 
 * can register 'slots' to receive messages from the Signal.  A slot can be 
 * any function with the matching signature.
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
  Signal() : mConnectionId{0} {}

  /**
   * Default Destructor
   */
  ~Signal() {
    mCallbacks.clear();
  }

  /**
   * Register the given function to be called when this signal emits a signal
   *
   * @param func the function to be called when emitting a signal
   * @return a connection between this signal and the given function
   */
  auto connect(Function const & func) -> Connection {
    int conId = mConnectionId++;
    mCallbacks.emplace(std::make_pair(conId, std::make_shared<Function>(func)));
    return Connection{conId, this};
  }

  /**
   * Disconnect the slot at the given connection
   *
   */
  auto disconnect(Connection const & con) -> bool {
    return mCallbacks.erase(con.mId) > 0;
  }

  /**
   * Call all connected slots
   *
   * @param args the parameters required by the signal type
   */
  template<typename... Args>
  auto operator() (Args... args) -> void {
    for (auto & cb : mCallbacks) {
      if (cb.second) {
        (*cb.second)(args...);
      }
    }
  }

  /**
   * Signals are not copyable
   */
  Signal(Signal const &) = delete;

  /**
   * Signals are not copyable
   */
  auto operator=(Signal const &) -> Signal& = delete;
  
private:
  /// Map of id to slots
  std::map<int, std::shared_ptr<Function>> mCallbacks;
  /// Unique ids for each connection
  int mConnectionId;
};


//Idea for these functions taken from here: https://testbit.eu/cpp11-signal-system-performance/
//these provide a short hand to std::bind

/// This function creates a std::function by binding @a object to the member function pointer @a method.
template<class Instance, class Class, class R, class... Args>
auto slot (Instance &object, R (Class::*method) (Args...)) -> std::function<R (Args...)>
{
  return [&object, method] (Args... args) { return (object .* method) (args...); };
}

/// This function creates a std::function by binding @a object to the member function pointer @a method.
template<class Class, class R, class... Args>
auto slot (Class *object, R (Class::*method) (Args...)) -> std::function<R (Args...)>
{
  return [object, method] (Args... args) { return (object ->* method) (args...); };
}



} //namespace core
} //namespace cagey

#endif //CAGEY_CORE_SIGNAL_HH_
