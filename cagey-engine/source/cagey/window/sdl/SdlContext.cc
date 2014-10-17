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

#include "cagey/window/sdl/SdlContext.hh"
#include "cagey/window/sdl/SdlException.hh"

#include <SDL2/SDL.h>
#include <mutex>

namespace {
  unsigned int usageCount = 0;
  std::mutex usageMutex;
}

namespace cagey {
namespace window {
namespace sdl {


SdlContext::SdlContext(std::uint32_t flags) {
  std::lock_guard<std::mutex> lock(usageMutex);

  if (usageCount++ == 0) {
    if (SDL_Init(0) != 0) {
      BOOST_THROW_EXCEPTION(SdlInitException() << core::ThrowMsg(SDL_GetError()));
    }
  }
  if (!SDL_WasInit(SDL_INIT_VIDEO & flags)) {
    SDL_InitSubSystem(SDL_INIT_VIDEO);
  }
  if (!SDL_WasInit(SDL_INIT_JOYSTICK & flags)) {
    SDL_InitSubSystem(SDL_INIT_JOYSTICK);
  }
  if (!SDL_WasInit(SDL_INIT_HAPTIC & flags)) {
    SDL_InitSubSystem(SDL_INIT_HAPTIC);
  }
  if (!SDL_WasInit(SDL_INIT_GAMECONTROLLER & flags)) {
    SDL_InitSubSystem(SDL_INIT_GAMECONTROLLER);
  }
  if (!SDL_WasInit(SDL_INIT_AUDIO & flags)) {
    SDL_InitSubSystem(SDL_INIT_AUDIO);
  }
  if (!SDL_WasInit(SDL_INIT_TIMER & flags)) {
    SDL_InitSubSystem(SDL_INIT_TIMER);
  }
};

SdlContext::~SdlContext() {
  std::lock_guard<std::mutex> lock(usageMutex);
  if (--usageCount == 0) {
    SDL_Quit();
  }
}
} //namespace sdl
} //namespace window
} //namespace cagey

