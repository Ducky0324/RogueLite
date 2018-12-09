#pragma once
#include "engine/stage/stage.hpp"
#include "sprite.hpp"
#include "spritesheet.hpp"
#include <array>
#include <map>
#include <string>

namespace Textures {
static SpriteSheet worldTiles = SpriteSheet("res/img/tiny_dungeon_world.png");
// Represents the area where there are no tiles.
static const Sprite voidTile = Sprite(worldTiles, 0, 6);
// Textures for the actual floor and wall tiles
static const std::map<std::string, std::array<Sprite, 6>> tiles = {
    {"wallNS",
     {Sprite(worldTiles, 6, 0), Sprite(worldTiles, 7, 0), Sprite(worldTiles, 8, 0),
      Sprite(worldTiles, 9, 0), Sprite(worldTiles, 10, 0), Sprite(worldTiles, 11, 0)}},
    {"wallEW",
     {Sprite(worldTiles, 0, 0), Sprite(worldTiles, 1, 0), Sprite(worldTiles, 2, 0),
      Sprite(worldTiles, 3, 0), Sprite(worldTiles, 4, 0), Sprite(worldTiles, 5, 0)}},
    {"stoneFlat",
     {Sprite(worldTiles, 0, 4), Sprite(worldTiles, 1, 4), Sprite(worldTiles, 2, 4),
      Sprite(worldTiles, 3, 4), Sprite(worldTiles, 4, 4), Sprite(worldTiles, 5, 4)}},
    {"stoneTile",
     {Sprite(worldTiles, 1, 6), Sprite(worldTiles, 1, 6), Sprite(worldTiles, 2, 6),
      Sprite(worldTiles, 3, 6), Sprite(worldTiles, 4, 6), Sprite(worldTiles, 5, 6)}},
    {"dirt",
     {Sprite(worldTiles, 6, 0), Sprite(worldTiles, 7, 0), Sprite(worldTiles, 8, 0),
      Sprite(worldTiles, 9, 0), Sprite(worldTiles, 10, 0), Sprite(worldTiles, 11, 0)}},
    {"grass",
     {Sprite(worldTiles, 8, 5), Sprite(worldTiles, 9, 5), Sprite(worldTiles, 10, 5),
      Sprite(worldTiles, 11, 5), Sprite(worldTiles, 12, 5), Sprite(worldTiles, 13, 5)}},
    {"carpet",
     {Sprite(worldTiles, 11, 6), Sprite(worldTiles, 12, 6), Sprite(worldTiles, 13, 6),
      Sprite(worldTiles, 14, 6), Sprite(worldTiles, 15, 6), Sprite(worldTiles, 15, 6)}},
};
// Textures for interactable things like doors, levers and chests
static const std::map<std::string, std::array<Sprite, 2>> interactable = {
    // 0 = closed, 1 = open
    {"woodenDoorEW", {Sprite(worldTiles, 0, 10), Sprite(worldTiles, 1, 10)}},
    {"woodenDoorNS", {Sprite(worldTiles, 2, 10), Sprite(worldTiles, 3, 10)}},
};
// Textures for decorations like bookshelves
static const std::map<std::string, Sprite> decorations = {
    {"bookshelf", Sprite(worldTiles, 0, 15)},
};

} // namespace Textures

class TileRenderer {
public:
  TileRenderer();

  void applyTextures(Stage *stage);
  void drawStageTo(SDL_Renderer *r, const Stage *stage);

private:
};