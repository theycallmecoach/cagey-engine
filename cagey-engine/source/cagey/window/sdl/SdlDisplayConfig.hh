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

#ifndef CAGEY_WINDOW_SDL_SDLDISPLAYCONFIG_HH_
#define CAGEY_WINDOW_SDL_SDLDISPLAYCONFIG_HH_

#include <SDL2/SDL.h>
#include "cagey/window/IDisplayConfig.hh"
#include "cagey/window/sdl/SdlContext.hh"

namespace cagey {
namespace window {
namespace sdl {

class SdlDisplayConfig : private SdlContext, public window::IDisplayConfig {
public:
  SdlDisplayConfig() : SdlContext(SDL_INIT_VIDEO) {};
  auto getFullScreenModes() -> std::vector<window::VideoMode> override;
  auto getCurrentMode() -> window::VideoMode override;
};

} //namespace sdl;
} //namespace window
} //namespace cagey


#endif //CAGEY_WINDOW_SDL_SDLVIDEOMODEIMPL_HH_