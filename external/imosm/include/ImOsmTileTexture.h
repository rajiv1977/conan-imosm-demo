#pragma once
#include "GL/glew.h"
//#include "GLFW/glfw3.h"
#include <array>
#include <imgui.h>
#include <memory.h>
#include <memory>
#include <stb_image.h>
#include <vector>

namespace ImOsm {
namespace Old {
struct TextureColor {
  static constexpr int RGBA_SZ{4};
  static constexpr std::array<uint8_t, RGBA_SZ> Snow{255, 250, 250, 255};
  static constexpr std::array<uint8_t, RGBA_SZ> Gold{255, 215, 0, 255};
  static constexpr std::array<uint8_t, RGBA_SZ> Aqua{0, 255, 255, 255};
  static constexpr std::array<uint8_t, RGBA_SZ> Lime{0, 255, 0, 255};
  static constexpr std::array<uint8_t, RGBA_SZ> Slate{112, 128, 144, 255};
  static constexpr std::array<uint8_t, RGBA_SZ> Coral{255, 127, 80, 255};

  TextureColor() : rgba(Snow) {}
  TextureColor(const std::array<uint8_t, RGBA_SZ> &color) : rgba{color} {};

  const std::array<uint8_t, RGBA_SZ> rgba{Snow};
};

class TileTexture {
public:
  TileTexture(int size = 256, TextureColor color = TextureColor::Snow);
  TileTexture(int size, const std::vector<std::byte> &blob);
  ~TileTexture();

  inline GLuint glID() const {
    if (_id == 0) {
      loadTexture();
    }
    return _id;
  }
  inline ImTextureID imID() const { return (ImTextureID)(intptr_t)glID(); }

private:
  int _width{256}, _height{256}, _channels{};
  std::vector<std::byte> _blob;
  mutable GLuint _id{0};

  void loadTexture() const;
};
} // namespace Old
} // namespace ImOsm
