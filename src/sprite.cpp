#include "ui/sprite.hpp"
#include "engine/constants.hpp"
#include "ui/spritesheet.hpp"
#include <stdio.h>

Sprite::Sprite(SpriteSheet &sheet, int imgX, int imgY) {
  IMG_Init(IMG_INIT_PNG);
  tempSurf = sheet.getImage(imgX, imgY);
  if (tempSurf == NULL) {
    printf("Failed to load image. Error: %s\n", SDL_GetError());
  }
}

Sprite::~Sprite() { SDL_DestroyTexture(texture); }

void Sprite::drawAt(SDL_Renderer *r, int x, int y) {
  SDL_Rect posRect = SDL_Rect{x * constants::TILE_SIZE, y * constants::TILE_SIZE,
                              constants::TILE_SIZE, constants::TILE_SIZE};
  if (!texture) {
    texture = SDL_CreateTextureFromSurface(r, tempSurf);
    SDL_FreeSurface(tempSurf);
  }
  if (SDL_RenderCopy(r, texture, NULL, &posRect) < 0) {
    printf("Failed to render. Error: %s\n", SDL_GetError());
  }
}