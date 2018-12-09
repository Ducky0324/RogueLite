#pragma once
#include "ui/animatedSprite.hpp"
#include "ui/sprite.hpp"
#include "ui/spritesheet.hpp"
#include <SDL2/SDL.h>

class GameEngine {
public:
  GameEngine(int screenWidth, int screenHeight);
  ~GameEngine();

  void start();

private:
  int screenWidth;
  int screenHeight;
  bool running = true;

  SDL_Window *window = nullptr;
  SDL_Renderer *renderer = nullptr;
  SDL_Event evt;

  SpriteSheet testSheet = SpriteSheet("res/img/tiny_dungeon_world.png");
  SpriteSheet actorSheet = SpriteSheet("res/img/tiny_dungeon_monsters.png");
  Sprite testSprite = Sprite(testSheet, 0, 0);
  AnimatedSprite testAnimatedSprite = AnimatedSprite(actorSheet, 0, 16);

  void handleEvents();
  void update();
  void render();
};