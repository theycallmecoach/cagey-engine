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

#ifndef CAGEY_ERROR_CAGEYEXCEPTION_HH_
#define CAGEY_ERROR_CAGEYEXCEPTION_HH_

#include <boost/exception/all.hpp>  //Cagey exceptions are based on boost::exception
#include <string>
#include <exception>


namespace cagey {
namespace core {

/**
 *  Structure Tag to allow user defined string to an exception object
 */
typedef boost::error_info<struct TagThrowMsg, std::string> ThrowMsg;

/**
 * Base Exception for all Cagey Engine Exceptions.
 *
 */
class Exception : public virtual boost::exception, public virtual std::exception {
  /**
   * Override what to output boost::diagnostic_information
   * 
   * @return the text returned from diagnostic_information_what(*this)
   */
  virtual auto what() const noexcept -> const char* override {
    return diagnostic_information_what(*this); 
  }
};


class DivideByZeroException : public virtual Exception {}; /// An Exception for when a division by zero is attempted
class IOException : public virtual Exception{}; /// An Exception for when there is an error with Input or Output
class IndexOutOfBoundsException : public virtual Exception{}; /// An Exception when there is an attempt to access an invalid index
class FileNotFoundException : public virtual IOException{}; /// An exception when a file is not found
class InvalidArgumentException :public virtual Exception{}; /// An exception when a invalid argument is passed to a function/method
class SingularMatrixException : public virtual Exception{}; /// An exception when a Matrix does have a inverse
} // namespace core
} // namespace cagey

#endif //CAGEY_ERROR_CAGEYEXCEPTION_HH_
