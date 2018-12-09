#pragma once
#include "engine/constants.hpp"
#include <SDL2/SDL.h>
#include <array>
#include <map>

using constants::Facing;

class SpriteSheet;
class Sprite;

class AnimatedSprite {
public:
  AnimatedSprite(SpriteSheet &sheet, int imgX, int imgY, int numFrames = 2, int delay = 350);
  ~AnimatedSprite();

  void setFacing(Facing direction);
  void drawAt(SDL_Renderer *r, int x, int y);

private:
  std::map<int, std::array<Sprite *, 2>> frames;
  int numFrames;
  int delay;
  int facing = 0;
  int currentFrame = 0;
  int lastUpdate = 0;
};