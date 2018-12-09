#pragma once
#include "../../util/array2D.hpp"
#include "../../util/vec.hpp"
#include "tile.hpp"
#include <array>

class Stage {

public:
  Stage(int width, int height);
  ~Stage();

  void setTile(const Vec &pos, const TileType &type);
  TileType *getTile(const Vec &pos);

  void setInteractable(const Vec &pos, const TileType &type);
  TileType *getInteractable(const Vec &pos);

  std::array<TileType *, 8> getNeighbors(const Vec &pos);

  Tile *operator[](const Vec &pos);

private:
  int width;
  int height;

  Array2D<Tile *> interactables;
  Array2D<Tile *> tiles;
};