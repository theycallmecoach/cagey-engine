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



#include "cagey/window/sdl/SdlWindow.hh"
#include <cagey/math/Point.hh>
#include "cagey/window/sdl/SdlException.hh"


namespace {

using SdlWindowPtr = std::unique_ptr<SDL_Window, void(*)(SDL_Window*)>;

}

namespace cagey {
namespace window {
namespace sdl {

///////////////////////////////////////////////////////////////////////////////
SdlWindow::SdlWindow(std::string const & title, VideoMode const & mode) :
  mWindow{nullptr, SDL_DestroyWindow} {

  if (!SDL_WasInit(SDL_INIT_VIDEO)) {
    BOOST_THROW_EXCEPTION(SdlInitException() << core::ThrowMsg(SDL_GetError()));
  }
  int flags = SDL_WINDOW_OPENGL;


  mWindow.reset(SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, mode.getWidth(), mode.getHeight(), flags));
  if (!mWindow) {
    BOOST_THROW_EXCEPTION(SdlInitException() << core::ThrowMsg("Failed to create window"));
  }
}

///////////////////////////////////////////////////////////////////////////////
SdlWindow::~SdlWindow() {

}


///////////////////////////////////////////////////////////////////////////////
auto SdlWindow::getTitle() const -> std::string {
  return SDL_GetWindowTitle(mWindow.get());
};

///////////////////////////////////////////////////////////////////////////////
auto SdlWindow::setTitle(std::string const & newTitle) -> void {
  SDL_SetWindowTitle(mWindow.get(), newTitle.c_str());
};

///////////////////////////////////////////////////////////////////////////////
auto SdlWindow::getSize() const -> math::Point2u {
  int w;
  int h;
  SDL_GetWindowSize(mWindow.get(), &w, &h);
  return {unsigned(w),unsigned(h)};
};

///////////////////////////////////////////////////////////////////////////////
auto SdlWindow::setSize(math::Point2u dim) -> void {
  SDL_SetWindowSize(mWindow.get(), dim.w, dim.h);
};

///////////////////////////////////////////////////////////////////////////////
auto SdlWindow::getVisible() const -> bool {
  return (SDL_GetWindowFlags(mWindow.get()) & SDL_WINDOW_SHOWN) != 0;
};

///////////////////////////////////////////////////////////////////////////////
auto SdlWindow::setVisible(bool visible) -> void {
  std::function<void (SDL_Window*)> func = visible ? SDL_HideWindow : SDL_ShowWindow;
  func(mWindow.get());
};

///////////////////////////////////////////////////////////////////////////////
auto SdlWindow::getWindowHandle() const -> WindowHandle {
  return mWindow.get();
};

} //namespace sdl
} //namespace window
} //namespace cagey

