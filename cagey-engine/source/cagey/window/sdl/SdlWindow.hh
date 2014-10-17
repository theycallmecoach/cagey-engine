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

#ifndef CAGEY_WINDOW_SDL_SDLWINDOW_HH_
#define CAGEY_WINDOW_SDL_SDLWINDOW_HH_


#include "cagey/window/IWindow.hh"
#include <cagey/math/Point.hh>
#include "cagey/window/sdl/SdlContext.hh"
#include <SDL2/SDL.h>
#include <memory>

namespace cagey {
namespace window {
namespace sdl {

class SdlWindow : private SdlContext, public IWindow {
public:
  SdlWindow(std::string const & title, VideoMode const & mode);
  ~SdlWindow();

  auto getTitle() const -> std::string override;
  auto setTitle(std::string const & newTitle) -> void;

  auto getSize() const -> math::Point2u override;
  auto setSize(math::Point2u dim) -> void override ;

  auto getVisible() const -> bool override;
  auto setVisible(bool visible) -> void override;

  auto getWindowHandle() const -> window::WindowHandle override;

private:
  using SdlWindowPtr = std::unique_ptr<SDL_Window, void(*)(SDL_Window*)>;
  SdlWindowPtr mWindow;
};

} //namespace sdl
} //namespace window
} //namespace cagey


#endif //CAGEY_WINDOW_SDL_SDLWINDOW_HH_