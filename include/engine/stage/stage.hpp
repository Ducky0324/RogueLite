#pragma once
#include "../../util/array2D.hpp"
#include "../../util/vec.hpp"
#include "tile.hpp"
#include <array>

class Stage {

public:
  Stage(int width, int height);
  ~Stage();

  int width;
  int height;
  void fill(const TileType &type);
  void setTile(const Vec &pos, const TileType &type);
  TileType *getTile(const Vec &pos);

  void setInteractable(const Vec &pos, const TileType &type);
  Tile *getInteractable(const Vec &pos);

  std::array<TileType *, 8> getNeighboringWalls(const Vec &pos);
  std::array<TileType *, 8> getNeighboringFloors(const Vec &pos);

  Tile *operator[](const Vec &pos);
  Tile *get(const Vec &pos);

private:
  Array2D<Tile *> interactables;
  Array2D<Tile *> tiles;
};