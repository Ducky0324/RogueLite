#include "util/rect.hpp"

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

bool Rect::intersects(const Rect &other) const {
  return (left <= other.right && right >= other.left && top >= other.bottom && bottom <= other.top);
}

bool Rect::contains(const Vec &point) {
  return (point.x >= x && point.x <= right && point.y >= y && point.y <= bottom);
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