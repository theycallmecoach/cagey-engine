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

#ifndef CAGEY_WINDOW_SDL_SDLWINDOWIMPL_HH_
#define CAGEY_WINDOW_SDL_SDLWINDOWIMPL_HH_


#include "cagey/window/IWindowImpl.hh"

namespace cagey {
namespace window {
namespace sdl {

class SdlWindowImpl : public detail::IWindowImpl {
public:
  auto getTitle() const -> std::string override {return "";};
  auto setTitle(std::string const & newTitle) -> void override {};

  auto getSize() const -> math::Point2u override {return {0,0};};
  auto setSize(math::Point2u dim) -> void override {};

  auto getVisible() const -> bool override {return false;};
  auto setVisible(bool visible) -> void override {};

  auto getWindowHandle() const -> window::WindowHandle override { return 0;};
};

} //namespace sdl;
} //namespace window
} //namespace cagey


#endif //CAGEY_WINDOW_SDL_SDLWINDOWIMPL_HH_