#ifndef CAGEY_WINDOW_VIDEOMODE_HH_
#define CAGEY_WINDOW_VIDEOMODE_HH_

namespace cagey {
namespace window {

class VideoMode {
public:
  //static auto CurrentMode() -> VideoMode;
  //static auto FullScreenModes() -> std::vector<VideoMode> const;

  VideoMode();
  VideoMode(unsigned width, unsigned height, unsigned short bpp = 32);
  
  constexpr auto getWidth() const -> unsigned { return mWidth; }
  constexpr auto getHeight() const -> unsigned { return mHeight; }
  constexpr auto getBitsPerPixel() const -> unsigned short { return mBitsPerPixel; }
  auto valid() const -> bool;


private:
  unsigned mWidth;
  unsigned mHeight;
  unsigned short mBitsPerPixel;
};


} //namespace window
} //namespace cagey

#endif //CAGEY_WINDOW_VIDEOMODE_HH_
