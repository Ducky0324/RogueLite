#pragma once
#include "vec.hpp"
#include <vector>

template <typename T> class Array2D {

public:
  Array2D(int width, int height);
  T &operator[](const Vec &index);

private:
  std::vector<T> items;
  int width;
  int height;
};

#include "../src/array2D.tpp"