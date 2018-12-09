#pragma once
#include <SDL2/SDL.h>

class SpriteSheet;

class Sprite {
public:
  Sprite(SpriteSheet &sheet, int imgX, int imgY);
  ~Sprite();

  void drawAt(SDL_Renderer *r, int x, int y);

private:
  SDL_Surface *tempSurf = nullptr;
  SDL_Texture *texture = nullptr;
};
