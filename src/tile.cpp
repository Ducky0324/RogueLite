#include "engine/stage/tile.hpp"

Tile::Tile(const TileType &ptype) { type = ptype; }

void Tile::printTileInfo() {
  printf("Tile Type: %s\tTexture Val: %d\n", type.name.c_str(), textureVal);
}

TileType &Tile::getType() { return type; }