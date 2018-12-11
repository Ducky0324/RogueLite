#include "util/rect.hpp"
#include "engine/constants.hpp"

Rect::Rect(int px, int py, int pwidth, int pheight) : x(px), y(py), width(pwidth), height(pheight) {
  left = x;
  right = x + width;

  top = y;
  bottom = y + height;
}

Rect::Rect(const Vec &pos, const Vec &size) : x(pos.x), y(pos.y), width(size.x), height(size.y) {
  left = pos.x;
  right = pos.x + size.x;

  top = pos.y;
  bottom = pos.y + size.y;
}

Vec Rect::center() const {
  int centerX = (x + right) / 2;
  int centerY = (y + bottom) / 2;
  return Vec(centerX, centerY);
}

bool Rect::intersects(const Rect &other) const {
  return (left <= other.right && right >= other.left && top >= other.bottom && bottom <= other.top);
}

bool Rect::contains(const Vec &point) {
  return (point.x >= x && point.x <= right && point.y >= y && point.y <= bottom);
}

Rect Rect::scale(const int xScale, const int yScale) const {
  return Rect(x * xScale, y * yScale, width, height);
}

Rect Rect::join(const Rect &other) {
  return Rect(x, y, width + other.width, height + other.height);
}

Rect Rect::inflate(const int xSize, const int ySize) {
  return Rect(x + xSize, y + ySize, width + (xSize * 2), height + (ySize * 2));
}

std::vector<Vec> Rect::bounds() {
  std::vector<Vec> bounds;
  for (int i = x; i < right; i++) {
    for (int j = y; j < bottom; j++) {
      bounds.push_back(Vec(i, j));
    }
  }
  return bounds;
}

void Rect::draw(SDL_Renderer *r) {
  SDL_Rect drawRect = SDL_Rect{x, y, width * constants::TILE_SIZE, height * constants::TILE_SIZE};
  SDL_RenderDrawRect(r, &drawRect);
}