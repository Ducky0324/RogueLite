#include "ui/animatedSprite.hpp"
#include "ui/sprite.hpp"
#include "ui/spritesheet.hpp"

AnimatedSprite::AnimatedSprite(SpriteSheet &sheet, int imgX, int imgY, int pnumFrames, int pdelay)
    : numFrames(pnumFrames), delay(pdelay) {
  for (int fx = 0; fx < 4; fx++) {
    auto frame1 = new Sprite(sheet, imgX + fx, imgY);
    auto frame2 = new Sprite(sheet, imgX + fx, imgY + 1);
    frames[fx] = {frame1, frame2};
  }
}

AnimatedSprite::~AnimatedSprite() {
  for (int fx = 0; fx < 4; fx++) {
    for (auto ptr : frames[fx]) {
      delete ptr;
    }
  }
}

void AnimatedSprite::setFacing(Facing direction) {
  switch (direction) {
  case Facing::UP:
    facing = 2;
    break;
  case Facing::DOWN:
    facing = 1;
    break;
  case Facing::LEFT:
    facing = 3;
    break;
  case Facing::RIGHT:
    facing = 0;
    break;
  default:
    facing = 0;
  }
}

void AnimatedSprite::drawAt(SDL_Renderer *r, int x, int y) {
  auto now = (int)SDL_GetTicks();
  if (now - lastUpdate > delay) {
    lastUpdate = now;
    currentFrame = (currentFrame + 1) % numFrames;
  }
  frames[facing][currentFrame]->drawAt(r, x, y);
}