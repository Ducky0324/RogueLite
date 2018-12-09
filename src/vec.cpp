#include "util/vec.hpp"

Vec::Vec(int px, int py) : x(px), y(py) {}

Vec &Vec::operator+=(const Vec &b) {
  this->x += b.x;
  this->y += b.y;
  return *this;
}

Vec &Vec::operator-=(const Vec &b) {
  this->x -= b.x;
  this->y -= b.y;
  return *this;
}

Vec &Vec::operator*=(const Vec &b) {
  this->x *= b.x;
  this->y *= b.y;
  return *this;
}

Vec &Vec::operator*=(const int b) {
  this->x *= b;
  this->y *= b;
  return *this;
}

Vec operator*(const Vec &a, const Vec &b) { return Vec(a.x * b.x, a.y * b.y); }
Vec operator*(const Vec &a, const int b) { return Vec(a.x * b, a.y * b); }
Vec operator+(const Vec &a, const Vec &b) { return Vec(a.x + b.x, a.y + b.y); }
Vec operator-(const Vec &a, const Vec &b) { return Vec(a.x - b.x, a.y - b.y); }

bool operator==(const Vec &a, const Vec &b) { return (a.x == b.x && a.y == b.y); }
bool operator!=(const Vec &a, const Vec &b) { return (a.x != b.x && a.y != b.y); }