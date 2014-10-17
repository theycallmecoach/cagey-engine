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


#include "cagey/window/sdl/SdlDisplayConfig.hh"
#include "cagey/window/sdl/SdlContext.hh"
#include <cagey/window/VideoMode.hh>
#include <SDL2/SDL.h>
#include <algorithm>

namespace {

  auto initSdl() {
    static bool initFlag = false;
    if (!initFlag) {
      if (SDL_VideoInit(nullptr) < 0) {
        //@TODO put better exception here...
        SDL_Quit();
        throw 0;
      }
    }
  }

}


namespace cagey {
namespace window {
namespace sdl {

auto SdlDisplayConfig::getFullScreenModes() -> std::vector<window::VideoMode> {
  std::vector<window::VideoMode> retModes;
  auto displayIndex = 0;

  //assume only one display...
  auto numModes = SDL_GetNumDisplayModes(displayIndex);
  for (int i =0; i < numModes; ++i) {
    SDL_DisplayMode mode;
    if(SDL_GetDisplayMode(displayIndex, i, &mode) < 0){
      //@TODO throw better exception
      throw 0;
    }
    retModes.emplace_back(window::VideoMode{unsigned(mode.w), unsigned(mode.h), (unsigned short)(SDL_BITSPERPIXEL(mode.format)) });
  }

  std::sort(std::begin(retModes), std::end(retModes),
        [] (VideoMode const & a, VideoMode const & b)
        {
          return a > b;
        });
  return retModes;
}

auto SdlDisplayConfig::getCurrentMode() -> window::VideoMode {
  SDL_DisplayMode mode;
  SDL_GetDesktopDisplayMode(0,&mode);
  return {unsigned(mode.w), unsigned(mode.h), (unsigned short)SDL_BITSPERPIXEL(mode.format)};
}

} //namespace sdl;
} //namespace window
} //namespace cagey
