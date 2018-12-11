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
static Sprite voidTile = Sprite(worldTiles, 0, 6);
// Textures for the actual floor and wall tiles
static std::map<std::string, std::array<Sprite *, 6>> tiles = {
    {"wallNS",
     {new Sprite(worldTiles, 6, 0), new Sprite(worldTiles, 7, 0), new Sprite(worldTiles, 8, 0),
      new Sprite(worldTiles, 9, 0), new Sprite(worldTiles, 10, 0), new Sprite(worldTiles, 11, 0)}},
    {"wallEW",
     {new Sprite(worldTiles, 0, 0), new Sprite(worldTiles, 1, 0), new Sprite(worldTiles, 2, 0),
      new Sprite(worldTiles, 3, 0), new Sprite(worldTiles, 4, 0), new Sprite(worldTiles, 5, 0)}},
    {"stoneFlat",
     {new Sprite(worldTiles, 0, 4), new Sprite(worldTiles, 1, 4), new Sprite(worldTiles, 2, 4),
      new Sprite(worldTiles, 3, 4), new Sprite(worldTiles, 4, 4), new Sprite(worldTiles, 5, 4)}},
    {"stoneTile",
     {new Sprite(worldTiles, 1, 6), new Sprite(worldTiles, 1, 6), new Sprite(worldTiles, 2, 6),
      new Sprite(worldTiles, 3, 6), new Sprite(worldTiles, 4, 6), new Sprite(worldTiles, 5, 6)}},
    {"dirt",
     {new Sprite(worldTiles, 1, 5), new Sprite(worldTiles, 2, 5), new Sprite(worldTiles, 3, 5),
      new Sprite(worldTiles, 4, 5), new Sprite(worldTiles, 5, 5), new Sprite(worldTiles, 1, 5)}},
    {"grass",
     {new Sprite(worldTiles, 8, 5), new Sprite(worldTiles, 9, 5), new Sprite(worldTiles, 10, 5),
      new Sprite(worldTiles, 11, 5), new Sprite(worldTiles, 12, 5), new Sprite(worldTiles, 13, 5)}},
    {"carpet",
     {new Sprite(worldTiles, 11, 6), new Sprite(worldTiles, 12, 6), new Sprite(worldTiles, 13, 6),
      new Sprite(worldTiles, 14, 6), new Sprite(worldTiles, 15, 6), new Sprite(worldTiles, 15, 6)}},
};
// Textures for interactable things like doors, levers and chests
static std::map<std::string, std::array<Sprite *, 2>> interactable = {
    // 0 = closed, 1 = open
    {"woodenDoorEW", {new Sprite(worldTiles, 0, 10), new Sprite(worldTiles, 1, 10)}},
    {"woodenDoorNS", {new Sprite(worldTiles, 2, 10), new Sprite(worldTiles, 5, 10)}},
};
// Textures for decorations like bookshelves
static std::map<std::string, Sprite *> decorations = {
    {"bookshelf", new Sprite(worldTiles, 0, 15)},
};

} // namespace Textures

class TileRenderer {
public:
  TileRenderer();

  void applyTextures(Stage *stage);
  void drawStageTo(SDL_Renderer *r, Stage *stage, int offsetX = 0, int offsetY = 0);

private:
  std::vector<int> textureDist = {0, 0, 0, 0, 1, 1, 2, 2, 2, 3};
};