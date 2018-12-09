#pragma once
#include <vector>

struct Vec {
  Vec(int x, int y);
  int x;
  int y;

  Vec &operator+=(const Vec &b);
  Vec &operator-=(const Vec &b);
  Vec &operator*=(const Vec &b);
  Vec &operator*=(const int b);
};

Vec operator*(const Vec &a, const Vec &b);
Vec operator*(const Vec &a, const int b);
Vec operator+(const Vec &a, const Vec &b);
Vec operator-(const Vec &a, const Vec &b);

bool operator==(const Vec &a, const Vec &b);
bool operator!=(const Vec &a, const Vec &b);

namespace Directions {
static const Vec N = Vec(0, -1);
static const Vec S = Vec(0, 1);
static const Vec W = Vec(-1, 0);
static const Vec E = Vec(1, 0);

static const Vec NE = Vec(1, -1);
static const Vec NW = Vec(-1, -1);
static const Vec SE = Vec(1, 1);
static const Vec SW = Vec(-1, 1);

static const std::vector<Vec> CARDINAL = {N, S, W, E};
static const std::vector<Vec> INTER_CARDINAL = {NE, NW, SE, SW};
static const std::vector<Vec> ALL = {N, S, E, W, NW, NE, SE, SW};
}; // namespace Directions