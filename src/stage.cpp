#include "engine/stage/stage.hpp"

Stage::Stage(int pwidth, int pheight)
    : width(pwidth), height(pheight), tiles(pwidth, pheight), interactables(pwidth, pheight) {}

Stage::~Stage() {
  for (int x = 0; x < width; x++) {
    for (int y = 0; y < height; y++) {
      auto pos = Vec(x, y);
      if (tiles[pos]) {
        delete tiles[pos];
      }
    }
  }
}

void Stage::fill(const TileType &type) {
  for (int x = 0; x < width; x++) {
    for (int y = 0; y < height; y++) {
      auto pos = Vec(x, y);
      if (tiles[pos]) {
        delete tiles[pos];
      }
      tiles[pos] = new Tile(type);
    }
  }
}

void Stage::setTile(const Vec &pos, const TileType &type) {
  if (tiles[pos]) {
    delete tiles[pos];
  }
  tiles[pos] = new Tile(type);
}

TileType *Stage::getTile(const Vec &pos) {
  if (0 > pos.x || pos.x >= width || 0 > pos.y || pos.y >= height) {
    return nullptr;
  } else {
    return &tiles[pos]->getType();
  }
}

void Stage::setInteractable(const Vec &pos, const TileType &type) {
  if (type.isInteractable) {
    if (interactables[pos]) {
      delete tiles[pos];
    }
    interactables[pos] = new Tile(type);
  } else {
    return;
  }
}

Tile *Stage::getInteractable(const Vec &pos) {
  if ((0 > pos.x || pos.x >= width || 0 > pos.y || pos.y >= height) &&
      !getTile(pos)->isInteractable && !getTile(pos)->isWalkable) {
    return nullptr;
  } else {
    return interactables[pos];
  }
}

std::array<TileType *, 8> Stage::getNeighboringWalls(const Vec &pos) {
  /*
    NW N NE
    W  ~  E
    SW S SE

    5 1 6
    4 0 2
    8 3 7

  */

  static std::array<TileType *, 8> neighbors;
  int idx = 0;
  for (auto dir : Directions::ALL) {
    if (getTile(pos + dir) && !getTile(pos + dir)->isWalkable)
      neighbors[idx] = getTile(pos + dir);
    else
      neighbors[idx] = nullptr;
    idx++;
  }
  return neighbors;
}

std::array<TileType *, 8> Stage::getNeighboringFloors(const Vec &pos) {
  /*
    NW N NE
    W  ~  E
    SW S SE

    5 1 6
    4 0 2
    8 3 7

  */

  static std::array<TileType *, 8> neighbors;
  int idx = 0;
  for (auto dir : Directions::ALL) {
    if (getTile(pos + dir) && getTile(pos + dir)->isWalkable)
      neighbors[idx] = getTile(pos + dir);
    else
      neighbors[idx] = getTile(pos + dir);
    idx++;
  }
  return neighbors;
}

Tile *Stage::operator[](const Vec &pos) { return tiles[pos]; }

Tile *Stage::get(const Vec &pos) { return tiles[pos]; }