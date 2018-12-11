#pragma once
#include "vec.hpp"
#include <SDL2/SDL.h>
#include <vector>

struct Rect {
  Rect(int px, int py, int pwidth, int pheight);
  Rect(const Vec &pos, const Vec &size);
  int x;
  int y;

  int right;
  int left;
  int top;
  int bottom;

  int width;
  int height;

  Vec center() const;

  bool intersects(const Rect &other) const;
  bool contains(const Vec &point);

  Rect join(const Rect &other);
  Rect scale(const int xScale, const int yScale) const;
  Rect inflate(const int xSize, const int ySize);

  std::vector<Vec> bounds();

  void draw(SDL_Renderer *r);
};