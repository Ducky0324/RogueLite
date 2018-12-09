#pragma once
#include <string>
struct TileType {
  std::string name;
  bool isWalkable;
  bool isTransparent;
  bool isInteractable;

  TileType *opensTo = nullptr;
  TileType *closesTo = nullptr;
};

inline bool operator==(const TileType &a, const TileType &b) { return (a.name == b.name); }