#include "ui/spritesheet.hpp"
#include <stdio.h>

SpriteSheet::SpriteSheet(const std::string &filename) {
  if ((sheet = IMG_Load(filename.c_str())) == NULL) {
    printf("Failed to load image. Error: %s\n", SDL_GetError());
  }
}

SpriteSheet::~SpriteSheet() { SDL_FreeSurface(sheet); }

SDL_Surface *SpriteSheet::getImage(int imgX, int imgY, int spriteSize) {
  SDL_Surface *image =
      SDL_CreateRGBSurface(0, spriteSize, spriteSize, 32, 0, 0, 0, SDL_ALPHA_TRANSPARENT);
  SDL_SetColorKey(image, SDL_TRUE, SDL_MapRGB(image->format, 0, 0, 0));
  SDL_Rect imgRect = SDL_Rect{imgX * spriteSize, imgY * spriteSize, spriteSize, spriteSize};
  if (SDL_BlitSurface(sheet, &imgRect, image, NULL) < 0) {
    printf("Failed to blit surface. Error: %s\n", SDL_GetError());
    return nullptr;
  }
  return image;
}