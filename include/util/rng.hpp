#pragma once
#include <iostream>
#include <random>
#include <vector>

namespace rng {
inline int rangeInclusive(int min, int max) {
  std::random_device rd;
  std::mt19937 eng(rd());
  std::uniform_int_distribution<> dist(min, max);
  return dist(eng);
}

inline int range(int min, int max) {
  std::random_device rd;
  std::mt19937 eng(rd());
  std::uniform_int_distribution<> dist(min, max - 1);
  return dist(eng);
}

inline bool oneIn(int chance) { return range(0, chance) == 1; }

template <typename T> inline T popRand(std::vector<T> &items) {
  int index = range(0, items.size());
  T item = items[index];
  items.erase(items.begin() + index);
  return item;
}

} // namespace rng