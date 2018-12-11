#pragma once
#include "stage/dungeon.hpp"
#include "stage/stage.hpp"
#include "ui/animatedSprite.hpp"
#include "ui/tileRenderer.hpp"
#include "util/rect.hpp"
#include <SDL2/SDL.h>
#include <vector>

class GameEngine {
public:
  GameEngine(int screenWidth, int screenHeight);
  ~GameEngine();

  void start();

private:
  int screenWidth;
  int screenHeight;
  bool running = true;

  TileRenderer tileRender = TileRenderer();
  Stage testStage = Stage(10, 10);
  Dungeon dungeonGen = Dungeon(&testStage);

  SDL_Window *window = nullptr;
  SDL_Renderer *renderer = nullptr;
  SDL_Event evt;

  std::vector<Rect *> tileRects;

  void handleEvents();
  void update();
  void render();
};