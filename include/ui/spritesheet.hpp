#pragma once
#include <SDL2/SDL_image.h>
#include <string>

#include "engine/constants.hpp"

class SpriteSheet {
public:
  SpriteSheet(const std::string &filename);
  ~SpriteSheet();

  SDL_Surface *getImage(int imgX, int imgY, int spriteSize = constants::SPRITE_SIZE);

private:
  SDL_Surface *sheet = nullptr;
};