#include "engine/stage/tile.hpp"

Tile::Tile(const TileType &ptype) { type = ptype; }

TileType &Tile::getType() { return type; }