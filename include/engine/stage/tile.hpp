#pragma once
#include "tileType.hpp"
#include "ui/sprite.hpp"

class Tile {
public:
  Tile(const TileType &ptype);
  Sprite *appearance = nullptr;
  int textureVal;

  TileType &getType();
  void printTileInfo();

private:
  TileType type;
};