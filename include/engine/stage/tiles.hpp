#pragma once
#include "tileType.hpp"

namespace Tiles {
static const TileType floor = TileType{"floor", true, true, false};
static const TileType wall = TileType{"wall", false, false, false};

static const TileType open_door = TileType{"open_door", true, true, true};
static const TileType chest = TileType{"chest", false, false, true};
} // namespace Tiles